#include <iostream>

using namespace std;

void permutation(char* pStr, char* pBegin)
{
    if(*pBegin=='\0')
        cout << pStr << endl;
    else
    {
        for(char* pCh=pBegin; *pCh!='\0'; pCh++)
        {
            char pTemp = *pBegin;
            *pBegin = *pCh;
            *pCh = pTemp;

            permutation(pStr,pBegin+1);

            pTemp = *pBegin;
            *pBegin = *pCh;
            *pCh = pTemp;
        }
    }
}

void permutation(char* pStr)
{
    if(pStr==NULL)
        return;
    permutation(pStr,pStr);
}

int main()
{
    char str[] = "abcd";
    permutation(str);

    return 0;
}
