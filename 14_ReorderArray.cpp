#include <iostream>

using namespace std;

void reorderOddEven(int* data, int length)
{
    if(data==NULL || length<=0)
        return;

    int ahead = 0;
    int after = length - 1;
    while(ahead<after)
    {
        while(ahead<length && data[ahead]%2==1)
            ahead++;
        while(after>0 && data[after]%2==0)
            after--;
        if(ahead<after)
        {
            int temp = data[ahead];
            data[ahead] = data[after];
            data[after] = temp;
        }
    }
}

int main()
{
    int data[5] = {1,2,3,4,5};
    cout << "org data:";
    for(int i=0;i<5;i++)
        cout << " " << data[i];
    cout << endl;

    reorderOddEven(data,5);

    cout << "new data:";
    for(int i=0;i<5;i++)
        cout << " " << data[i];
    cout << endl;

    return 0;
}
