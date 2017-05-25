#include<iostream>
#include<stack>

using namespace std;

bool isPopOrder(int* pPush, int* pPop, int length)
{
    bool bPossible = false;
    if(pPush==NULL || pPop==NULL || length<=0)
        return bPossible;
    stack<int> stk;
    int idx = 0;
    for(int i=0;i<length;i++)
    {
        stk.push(pPush[i]);
        while(idx<length && stk.top()==pPop[idx])
        {
            stk.pop();
            idx++;
        }
    }

    while(idx<length && stk.top()==pPop[idx])
    {
        stk.pop();
        idx++;
    }

    if(idx==length && stk.empty())
        bPossible = true;

    return bPossible;
}

int main()
{
    int pPush[5] = {1,2,3,4,5};
    int pPop1[5] = {4,5,3,2,1};
    int pPop2[5] = {4,3,5,1,2};

    cout << isPopOrder(pPush,pPop1,5) << endl;
    cout << isPopOrder(pPush,pPop2,5) << endl;

    return 0;
}
