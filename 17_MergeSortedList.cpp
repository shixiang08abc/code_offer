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

ListNode* mergeList(ListNode* pNode1,ListNode* pNode2)
{
    if(pNode1==NULL)
        return pNode2;
    if(pNode2==NULL)
        return pNode1;

    ListNode* pTemp;
    ListNode* p1 = pNode1;
    ListNode* p2 = pNode2;

    if(p1->m_nValue>p2->m_nValue)
    {
        pTemp = p2;
        p2 = p2->m_pNext;
    }
    else
    {
        pTemp = p1;
        p1 = p1->m_pNext;
    }

    ListNode* pHead = pTemp;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->m_nValue>p2->m_nValue)
        {
            pTemp->m_pNext = p2;
            p2 = p2->m_pNext;
        }
        else
        {
            pTemp->m_pNext = p1;
            p1 = p1->m_pNext;
        }
        pTemp = pTemp->m_pNext;
    }

    if(p1==NULL)
        pTemp->m_pNext = p2;
    else
        pTemp->m_pNext = p1;

    return pHead;
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
    int arrayList1[4] = {1,3,5,7};
    ListNode* pNode1 = createList(arrayList1,4);
    printList(pNode1);

    int arrayList2[4] = {2,4,6,8};
    ListNode* pNode2 = createList(arrayList2,4);
    printList(pNode2);

    ListNode* pHead = mergeList(pNode1,pNode2);
    printList(pHead);

    return 0;
}


