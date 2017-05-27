#include <iostream>

using namespace std;

struct ComplexListNode
{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

ComplexListNode* createNode(int value)
{
    ComplexListNode* pNode = new ComplexListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;
    pNode->m_pSibling = NULL;

    return pNode;
}

void connectListNodes(ComplexListNode* pHead, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    pHead->m_pNext = pNext;
    pHead->m_pSibling = pSibling;
}

void cloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode!=NULL)
    {
        ComplexListNode* pClone = createNode(pNode->m_nValue);
        pClone->m_pNext = pNode->m_pNext;
        pNode->m_pNext = pClone;
        pNode = pNode->m_pNext->m_pNext;
    }
}

void connectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode!=NULL)
    {
        if(pNode->m_pSibling!=NULL)
            pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
        pNode = pNode->m_pNext->m_pNext;
    }
}

ComplexListNode* reConnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pCHead = NULL;
    ComplexListNode* pCNode = NULL;

    if(pNode!=NULL)
    {
        pCHead = pNode->m_pNext;
        pCNode = pCHead;
        pNode->m_pNext = pCNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while(pNode!=NULL)
    {
        pCNode->m_pNext = pNode->m_pNext;
        pCNode = pCNode->m_pNext;
        pNode->m_pNext = pCNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    return pCHead;
}

ComplexListNode* cloneComplexList(ComplexListNode* pHead)
{
    cloneNodes(pHead);
    connectSiblingNodes(pHead);
    ComplexListNode* pCHead = reConnectNodes(pHead);

    return pCHead;
}

void printComplexList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode!=NULL)
    {
        cout << pNode->m_nValue;
        if(pNode->m_pSibling!=NULL)
            cout << "(" << pNode->m_pSibling->m_nValue << ")";
        cout << "\t" ;
        pNode = pNode->m_pNext;
    }
    cout << endl;
}

int main()
{
    ComplexListNode* pNode1 = createNode(1);
    ComplexListNode* pNode2 = createNode(2);
    ComplexListNode* pNode3 = createNode(3);
    ComplexListNode* pNode4 = createNode(4);
    ComplexListNode* pNode5 = createNode(5);

    connectListNodes(pNode1,pNode2,pNode3);
    connectListNodes(pNode2,pNode3,pNode5);
    connectListNodes(pNode3,pNode4,NULL);
    connectListNodes(pNode4,pNode5,pNode2);

    printComplexList(pNode1);

    ComplexListNode* pCHead = cloneComplexList(pNode1);

    printComplexList(pCHead);

    return 0;
}
