#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* createNode(int value)
{
    BinaryTreeNode *pHead = new BinaryTreeNode();
    pHead->m_nValue = value;
    pHead->m_pLeft = NULL;
    pHead->m_pRight = NULL;

    return pHead;
}

void connectTreeNodes(BinaryTreeNode* pBoot,BinaryTreeNode* pLeft,BinaryTreeNode* pRight)
{
    pBoot->m_pLeft = pLeft;
    pBoot->m_pRight = pRight;
}

void printPreOrder(BinaryTreeNode* pHead)
{
    if(pHead==NULL)
        return;
    cout << " " << pHead->m_nValue;
    printPreOrder(pHead->m_pLeft);
    printPreOrder(pHead->m_pRight);
}

void printMidOrder(BinaryTreeNode* pHead)
{
    if(pHead==NULL)
        return;
    printMidOrder(pHead->m_pLeft);
    cout << " " << pHead->m_nValue;
    printMidOrder(pHead->m_pRight);
}

void printBackOrder(BinaryTreeNode* pHead)
{
    if(pHead==NULL)
        return;
    printBackOrder(pHead->m_pLeft);
    printBackOrder(pHead->m_pRight);
    cout << " " << pHead->m_nValue;
}

void convertNodes(BinaryTreeNode* pHead, BinaryTreeNode** pLNode)
{
    if(pHead==NULL)
        return;

    BinaryTreeNode* pNode = pHead;
    if(pNode->m_pLeft!=NULL)
        convertNodes(pNode->m_pLeft,pLNode);

    pNode->m_pLeft = *pLNode;
    if(*pLNode!=NULL)
        (*pLNode)->m_pRight = pNode;
    *pLNode = pNode;

    if(pNode->m_pRight!=NULL)
        convertNodes(pNode->m_pRight,pLNode);
}

BinaryTreeNode* convert(BinaryTreeNode* pHead)
{
    BinaryTreeNode* pLNode = NULL;
    convertNodes(pHead,&pLNode);
    BinaryTreeNode *pLHead = pLNode;
    while(pLHead!=NULL && pLHead->m_pLeft!=NULL)
        pLHead = pLHead->m_pLeft;

    return pLHead;
}

void connectDoubleList(BinaryTreeNode* pNode1, BinaryTreeNode* pNode2)
{
    pNode1->m_pRight = pNode2;
    pNode2->m_pLeft = pNode1;
}

void printDoubleList(BinaryTreeNode* pHead)
{
    BinaryTreeNode* pNode = pHead;
    cout << "print from left to right:";
    while(pNode!=NULL)
    {
        cout << pNode->m_nValue << " ";
        if(pNode->m_pRight==NULL)
            break;
        pNode = pNode->m_pRight;
    }
    cout <<endl;

    cout << "print from right to left:";
    while(pNode!=NULL)
    {
        cout << pNode->m_nValue << " ";
        if(pNode->m_pLeft==NULL)
            break;
        pNode = pNode->m_pLeft;
    }
    cout << endl;
}

int main()
{
    BinaryTreeNode* pNode1 = createNode(10);
    BinaryTreeNode* pNode2 = createNode(6);
    BinaryTreeNode* pNode3 = createNode(4);
    BinaryTreeNode* pNode4 = createNode(8);
    BinaryTreeNode* pNode5 = createNode(14);
    BinaryTreeNode* pNode6 = createNode(12);
    BinaryTreeNode* pNode7 = createNode(16);
    connectTreeNodes(pNode1,pNode2,pNode5);
    connectTreeNodes(pNode2,pNode3,pNode4);
    connectTreeNodes(pNode5,pNode6,pNode7);

    BinaryTreeNode* pNode10 = createNode(1);
    BinaryTreeNode* pNode11 = createNode(2);
    BinaryTreeNode* pNode12 = createNode(3);
    connectDoubleList(pNode10,pNode11);
    connectDoubleList(pNode11,pNode12);
    printDoubleList(pNode10);

    cout << "print tree by mid order:";
    printMidOrder(pNode1);
    cout << endl;

    BinaryTreeNode* pHead = convert(pNode1);
    printDoubleList(pHead);

    return 0;
}
