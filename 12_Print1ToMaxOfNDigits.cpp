#include <iostream>
#include <memory.h>

using namespace std;

bool Increment(char* number, int n)
{
    bool isOverflow = false;
    int takeOver = 0;
    for(int i=n-1;i>=0;i--)
    {
        int nNum = number[i] - '0' + takeOver;
        if(i==n-1)
            nNum++;
        if(nNum>=10)
        {
            if(i==0)
            {
                isOverflow = true;
                break;
            }
            number[i] = nNum - 10 + '0';
            takeOver = 1;
        }
        else
        {
            number[i] = nNum + '0';
            break;
        }
    }
    return isOverflow;
}

void PrintNumber(char* number, int n)
{
    bool isStart = false;
    for(int i=0;i<n;i++)
    {
        if(!isStart && (number[i]!='0'))
            isStart = true;

        if(isStart)
            cout << number[i];
    }
    cout << endl;
}

void Print1ToMaxOfNDigits(int n)
{
    if(n<=0)
        return;
    char* number = new char[n+1];
    memset(number,'0',n+1);
    number[n] = '\0';

    while(!Increment(number,n))
    {
        PrintNumber(number,n);
    }
    delete[] number;
}

int main()
{
    Print1ToMaxOfNDigits(4);
    return 0;
}
