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

void createBinaryTree(BinaryTreeNode *pHead, int left, int right)
{
    BinaryTreeNode* pLeft = createNode(left);
    BinaryTreeNode* pRight = createNode(right);

    pHead->m_pLeft = pLeft;
    pHead->m_pRight = pRight;
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

BinaryTreeNode* constructTreeCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder)
{
    int value = startPreOrder[0];
    BinaryTreeNode* pHead = new BinaryTreeNode();
    pHead->m_nValue = value;
    pHead->m_pLeft = NULL;
    pHead->m_pRight = NULL;

    if(startPreOrder==endPreOrder)
    {
        if(startInOrder == endInOrder && *startPreOrder == *startInOrder)
            return pHead;
        else
        {
            cout << "Invalid input." <<endl;
            return NULL;
        }
    }

    int* rootInOrder = startInOrder;
    while((rootInOrder<=endInOrder) && (*rootInOrder!=value))
        ++rootInOrder;

    int leftLength = rootInOrder - startInOrder;
    if(leftLength>0)
    {
        pHead->m_pLeft = constructTreeCore(startPreOrder+1,startPreOrder+leftLength,startInOrder,rootInOrder-1);
    }
    if(leftLength<endInOrder-rootInOrder)
    {
        pHead->m_pRight = constructTreeCore(startPreOrder+leftLength+1,endPreOrder,rootInOrder+1,endInOrder);
    }

    return pHead;
}

BinaryTreeNode* constructTree(int* preOrder, int* midOrder, int length)
{
    if(preOrder==NULL || midOrder==NULL || length<=0)
        return NULL;
    return constructTreeCore(preOrder, preOrder+length-1, midOrder, midOrder+length-1);
}

int main()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode* pHead = constructTree(preorder,inorder,length);

 /*   BinaryTreeNode* pHead = createNode(10);
    createBinaryTree(pHead,6,14);
    createBinaryTree(pHead->m_pLeft,4,8);
    createBinaryTree(pHead->m_pRight,12,16);*/

    cout << "print tree by pre order:";
    printPreOrder(pHead);
    cout << endl;

    cout << "print tree by mid order:";
    printMidOrder(pHead);
    cout << endl;

    cout << "print tree by back order:";
    printBackOrder(pHead);
    cout << endl;

    return 0;
}
