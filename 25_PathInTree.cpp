#include <iostream>
#include <vector>

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

void findPath(BinaryTreeNode* pHead, int number, vector<int>& vec)
{
    vec.push_back(pHead->m_nValue);
    number = number - pHead->m_nValue;
    if(pHead->m_pLeft==NULL && pHead->m_pRight==NULL && number==0)
    {
        cout << "find Path:";
        for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
    }

    if(pHead->m_pLeft!=NULL)
        findPath(pHead->m_pLeft,number,vec);
    if(pHead->m_pRight!=NULL)
        findPath(pHead->m_pRight,number,vec);

    vec.pop_back();
    number = number + pHead->m_nValue;
}

void findPath(BinaryTreeNode* pHead, int number)
{
    if(pHead==NULL)
        return;
    vector<int> vec;
    findPath(pHead,number,vec);
}

int main()
{
    BinaryTreeNode* pNode1 = createNode(10);
    BinaryTreeNode* pNode2 = createNode(5);
    BinaryTreeNode* pNode3 = createNode(12);
    BinaryTreeNode* pNode4 = createNode(4);
    BinaryTreeNode* pNode5 = createNode(7);
    connectTreeNodes(pNode1,pNode2,pNode3);
    connectTreeNodes(pNode2,pNode4,pNode5);

    cout << "print tree by pre order:";
    printPreOrder(pNode1);
    cout << endl;

    findPath(pNode1,22);

    return 0;
}
