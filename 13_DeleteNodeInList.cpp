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

ListNode* createNode(int num)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = num;
    pNode->m_pNext = NULL;
    return pNode;
}

void connectListNodes(ListNode* pNode1,ListNode* pNode2)
{
    pNode1->m_pNext = pNode2;
}

ListNode* deleteNode(ListNode* pHead,ListNode* pNode)
{
    if(pHead==NULL || pNode==NULL)
        return pHead;

    if(pNode->m_pNext==NULL)
    {
        ListNode* pPre = pHead;
        while(pPre->m_pNext!=pNode)
            pPre = pPre->m_pNext;
        pPre->m_pNext = NULL;
    }
    else
    {
        pNode->m_nValue = pNode->m_pNext->m_nValue;
        ListNode* pPre = pNode->m_pNext;
        pNode->m_pNext = pPre->m_pNext;
        delete pPre;
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

int main()
{
    ListNode* pNode1 = createNode(6);
    ListNode* pNode2 = createNode(3);
    ListNode* pNode3 = createNode(5);
    ListNode* pNode4 = createNode(8);
    ListNode* pNode5 = createNode(1);
    connectListNodes(pNode1,pNode2);
    connectListNodes(pNode2,pNode3);
    connectListNodes(pNode3,pNode4);
    connectListNodes(pNode4,pNode5);
    deleteNode(pNode1,pNode3);
    printList(pNode1);

    return 0;
}
