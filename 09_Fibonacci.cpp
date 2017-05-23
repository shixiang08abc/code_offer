#include <iostream>

using namespace std;

long long fibonacciSolution1(int number)
{
    if(number<=0)
        return 0;
    else if(number==1)
        return 1;
    else
        return fibonacciSolution1(number-1)+fibonacciSolution1(number-2);
}

long long fibonacciSolution2(int number)
{
    if(number<=0)
        return 0;
    else if(number==1)
        return 1;
    long long fibN = 0;
    long long fibOnes = 0;
    long long fibTwos = 1;
    for(int i=2;i<=number;i++)
    {
        fibN = fibOnes + fibTwos;
        fibOnes = fibTwos;
        fibTwos = fibN;
    }
    return fibN;
}

int main()
{
    cout << fibonacciSolution1(2) << endl;
    cout << fibonacciSolution2(2) << endl;
    return 0;
}
