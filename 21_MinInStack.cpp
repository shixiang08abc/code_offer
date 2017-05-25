#include<iostream>
#include<stack>

using namespace std;

class StackWithMin
{
public:
    StackWithMin(void){}
    ~StackWithMin(void){}
    void push(int value);
    int pop();
    int stackMin();

private:
    stack<int> m_data;
    stack<int> m_min;
};

void StackWithMin::push(int value)
{
    m_data.push(value);
    if(m_min.empty())
        m_min.push(value);
    else
    {
        int preMin = m_min.top();
        if(preMin>value)
            m_min.push(value);
        else
            m_min.push(preMin);
    }
}

int StackWithMin::pop()
{
    m_min.pop();
    int value = m_data.top();
    m_data.pop();
    return value;
}

int StackWithMin::stackMin()
{
    return m_min.top();
}

int main()
{
    StackWithMin stk;
    stk.push(3);
    cout << stk.stackMin() << endl;
    stk.push(4);
    cout << stk.stackMin() << endl;
    stk.push(2);
    cout << stk.stackMin() << endl;
    stk.push(3);
    cout << stk.stackMin() << endl;
    stk.pop();
    cout << stk.stackMin() << endl;
    stk.pop();
    cout << stk.stackMin() << endl;
    stk.pop();
    cout << stk.stackMin() << endl;

    return 0;
}
