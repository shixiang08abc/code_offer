#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* createList(int arrayList[],int length)
{
    if(arrayList==NULL || length<=0)
        return NULL;

    ListNode* pNext = new ListNode();
    pNext->m_nValue = arrayList[0];
    pNext->m_pNext = NULL;
    ListNode* pHead = pNext;

    for(int i=1;i<length;i++)
    {
        ListNode* pNode = new ListNode();
        pNode->m_nValue = arrayList[i];
        pNode->m_pNext = NULL;
        pNext->m_pNext = pNode;
        pNext = pNode;
    }
    return pHead;
}

ListNode* reverseList(ListNode* pHead)
{
    if(pHead==NULL || pHead->m_pNext==NULL)
        return pHead;

    ListNode* pNewHead = pHead;
    ListNode* pNode = pHead->m_pNext;
    pNewHead->m_pNext = NULL;

    while(pNode!=NULL)
    {
        ListNode* pTemp = pNode->m_pNext;
        pNode->m_pNext = pNewHead;
        pNewHead = pNode;
        pNode = pTemp;
    }

    return pNewHead;
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

int main()
{
    int arrayList[6] = {1,2,3,4,5,6};
    ListNode* pHead = createList(arrayList,6);
    printList(pHead);

    ListNode* pNewHead = reverseList(pHead);
    printList(pNewHead);

    return 0;
}


