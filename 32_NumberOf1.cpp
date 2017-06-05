#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int powerBase10(int n)
{
    int result = 1;
    for(int i=0;i<n;i++)
        result *= 10;
    return result;
}

int numberOf1(const char* strN)
{
    if(strN==NULL || *strN=='\0' || *strN<'0' || *strN>'9')
        return 0;
    int first = *strN - '0';
    int length = strlen(strN);
    if(length==1 && first==0)
        return 0;
    int numFirst = 0;
    if(first>1)
        numFirst = powerBase10(length-1);
    else if(first==1)
        numFirst = atoi(strN+1) + 1;
    int numOther = first * (length-1) * powerBase10(length-2);
    int numRecursive = numberOf1(strN+1);
    return numFirst+numOther+numRecursive;
}

int numberOf1Between1ToN(int n)
{
    if(n<=0)
        return 0;
    char strN[50];
    sprintf(strN,"%d",n);

    return numberOf1(strN);
}

int main()
{
    int n = 21345;
    int num = numberOf1Between1ToN(n);
    cout << num << endl;

    return 0;
}
