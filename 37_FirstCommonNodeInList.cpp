#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* createNode(int value)
{
    ListNode* pNode = new ListNode();
    if(pNode==NULL)
        return NULL;
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;

    return pNode;
}

void connectNodes(ListNode* pNode1, ListNode* pNode2)
{
    pNode1->m_pNext = pNode2;
}

void printList(ListNode* pHead)
{
    ListNode *pNode = pHead;
    cout << "List:";
    while(pNode!=NULL)
    {
        cout << " " << pNode->m_nValue;
        pNode = pNode->m_pNext;
    }
    cout << endl;
}

int getLengthList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    int nLength = 0;
    while(pNode!=NULL)
    {
        nLength++;
        pNode = pNode->m_pNext;
    }

    return nLength;
}


ListNode* findCommonNode(ListNode* pNode1, ListNode* pNode2)
{
    if(pNode1==NULL || pNode2==NULL)
        return NULL;
    int nLength1 = getLengthList(pNode1);
    int nLength2 = getLengthList(pNode2);

    ListNode* pLongNode = pNode1;
    ListNode* pLessNode = pNode2;
    int diffLength = nLength1 - nLength2;
    if(nLength2>nLength1)
    {
        pLongNode = pNode2;
        pLessNode = pNode1;
        diffLength = nLength2 - nLength1;
    }
    while(diffLength>0)
    {
        pLongNode = pLongNode->m_pNext;
        diffLength--;
    }
    while(pLongNode!=pLessNode)
    {
        pLongNode = pLongNode->m_pNext;
        pLessNode = pLessNode->m_pNext;
    }

    return pLessNode;
}

int main()
{
    ListNode* pNode1 = createNode(1);
    ListNode* pNode2 = createNode(2);
    ListNode* pNode3 = createNode(3);
    ListNode* pNode4 = createNode(4);
    ListNode* pNode5 = createNode(5);
    ListNode* pNode6 = createNode(6);
    ListNode* pNode7 = createNode(7);
    ListNode* pNode8 = createNode(8);
    ListNode* pNode9 = createNode(9);
    connectNodes(pNode1,pNode2);
    connectNodes(pNode2,pNode5);
    connectNodes(pNode5,pNode7);
    connectNodes(pNode7,pNode8);

    connectNodes(pNode3,pNode4);
    connectNodes(pNode4,pNode6);
    connectNodes(pNode6,pNode9);
    connectNodes(pNode9,pNode7);

    printList(pNode1);
    printList(pNode3);

    ListNode* pFirst = findCommonNode(pNode1,pNode3);
    cout << pFirst->m_nValue << endl;

    return 0;
}
