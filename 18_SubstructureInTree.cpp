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

bool doesTree1HaveTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
    if(pRoot2==NULL)
        return true;

    if(pRoot1==NULL)
        return false;

    if(pRoot1->m_nValue!=pRoot2->m_nValue)
        return false;

    return (doesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft) && doesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight));
}

bool hasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;
    if(pRoot1!=NULL && pRoot2!=NULL)
    {
        if(pRoot1->m_nValue==pRoot2->m_nValue)
            result = doesTree1HaveTree2(pRoot1,pRoot2);
        if(!result)
            result = hasSubTree(pRoot1->m_pLeft,pRoot2);
        if(!result)
            result = hasSubTree(pRoot1->m_pRight,pRoot2);
    }

    return result;
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

int main()
{
    BinaryTreeNode* pNode1 = createNode(8);
    BinaryTreeNode* pNode2 = createNode(8);
    BinaryTreeNode* pNode3 = createNode(7);
    BinaryTreeNode* pNode4 = createNode(9);
    BinaryTreeNode* pNode5 = createNode(2);
    BinaryTreeNode* pNode6 = createNode(4);
    BinaryTreeNode* pNode7 = createNode(7);
    connectTreeNodes(pNode1,pNode2,pNode3);
    connectTreeNodes(pNode2,pNode4,pNode5);
    connectTreeNodes(pNode5,pNode6,pNode7);

    BinaryTreeNode* pNode8 = createNode(8);
    BinaryTreeNode* pNode9 = createNode(9);
    BinaryTreeNode* pNode10 = createNode(2);
    connectTreeNodes(pNode8,pNode9,pNode10);

    cout << "print tree1 by pre order:";
    printPreOrder(pNode1);
    cout << endl;

    cout << "print tree2 by pre order:";
    printPreOrder(pNode8);
    cout << endl;

    bool Flag = hasSubTree(pNode1,pNode8);
    cout << Flag << endl;

    return 0;
}
