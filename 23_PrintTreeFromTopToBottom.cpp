#include <iostream>
#include <queue>

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

void printTreeFromTopToBottom(BinaryTreeNode* pHead)
{
    if(pHead==NULL)
        return;
    queue<BinaryTreeNode*> que;
    que.push(pHead);
    while(!que.empty())
    {
        BinaryTreeNode* pNode = que.front();
        que.pop();
        if(pNode->m_pLeft!=NULL)
            que.push(pNode->m_pLeft);
        if(pNode->m_pRight!=NULL)
            que.push(pNode->m_pRight);
        cout << pNode->m_nValue << " ";
    }
    cout << endl;
}

int main()
{
    BinaryTreeNode* pNode1 = createNode(8);
    BinaryTreeNode* pNode2 = createNode(6);
    BinaryTreeNode* pNode3 = createNode(10);
    BinaryTreeNode* pNode4 = createNode(5);
    BinaryTreeNode* pNode5 = createNode(7);
    BinaryTreeNode* pNode6 = createNode(9);
    BinaryTreeNode* pNode7 = createNode(11);
    connectTreeNodes(pNode1,pNode2,pNode3);
    connectTreeNodes(pNode2,pNode4,pNode5);
    connectTreeNodes(pNode3,pNode6,pNode7);

    cout << "print tree by pre order:";
    printPreOrder(pNode1);
    cout << endl;

    cout << "print tree from top to bottom:";
    printTreeFromTopToBottom(pNode1);
    cout << endl;

    return 0;
}
