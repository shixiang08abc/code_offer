#include <iostream>
#include <stack>

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

void printReverseList(ListNode *pHead)
{
    ListNode *pNode = pHead;
    stack <int> valueStack;
    while(pNode!=NULL)
    {
        valueStack.push(pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    cout << "Reverse List:";
    while(!valueStack.empty())
    {
        cout << " " << valueStack.top();
        valueStack.pop();
    }
    cout << endl;
}

int main()
{
    int arrayList[6] = {1,8,3,6,7,4};
    ListNode* pHead = createList(arrayList,6);
    printList(pHead);
    printReverseList(pHead);

    return 0;
}
