#include <iostream>
#include <stack>

using namespace std;

class CQueue
{
public:
    CQueue();
    ~CQueue();
    void appendTail(int data);
    int deleteHead();
private:
    stack<int> stack1;
    stack<int> stack2;
};

CQueue::CQueue()
{

}

CQueue::~CQueue()
{

}

void CQueue::appendTail(int data)
{
    stack1.push(data);
}

int CQueue::deleteHead()
{
    int head;
    if(stack2.empty())
    {
        while(stack1.size()>0)
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    if(stack2.empty())
    {
        cout << "ERROR, CQueue is empty!!!" << endl;
        return -1;
    }

    head = stack2.top();
    stack2.pop();

    return head;
}

int main()
{
    CQueue que;
    que.appendTail(1);
    que.appendTail(2);
    que.appendTail(3);
    cout << "CQueue head:" << que.deleteHead() << endl;
    que.appendTail(4);
    cout << "CQueue head:" << que.deleteHead() << endl;
    cout << "CQueue head:" << que.deleteHead() << endl;
    cout << "CQueue head:" << que.deleteHead() << endl;
    cout << "CQueue head:" << que.deleteHead() << endl;

    return 0;
}
