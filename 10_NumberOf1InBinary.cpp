#include<iostream>

using namespace std;

int numberOf1(int num)
{
    int cnt = 0;
    while(1)
    {
        if(num==0)
            break;
        cnt++;
        num = num & (num-1);
    }
    return cnt;
}

int main()
{
    cout << numberOf1(10) <<endl;

    return 0;
}
