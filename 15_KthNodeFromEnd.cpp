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

ListNode* findKthToTail(ListNode* pHead,int k)
{
    if(pHead==NULL || k<=0)
        return NULL;
    ListNode* pAhead = pHead;
    ListNode* pAfter = NULL;
    for(int i=1;i<k;i++)
    {
        if(pAhead->m_pNext!=NULL)
            pAhead = pAhead->m_pNext;
        else
            return pAfter;
    }

    pAfter = pHead;

    while(pAhead->m_pNext!=NULL)
    {
        pAhead = pAhead->m_pNext;
        pAfter = pAfter->m_pNext;
    }

    return pAfter;
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

    ListNode* kNode = findKthToTail(pHead,4);
    cout << "4th to tail:" << kNode->m_nValue << endl;

    return 0;
}


