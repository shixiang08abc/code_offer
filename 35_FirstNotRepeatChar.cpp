#include <iostream>

using namespace std;

char getFirstNotRepeatChar(char* pString)
{
    if(pString==NULL)
        return '\0';
    int *hashtable = new int[256];
    for(int i=0;i<256;i++)
        hashtable[i] = 0;
    char* pstr = pString;
    while(*pstr!='\0')
    {
        hashtable[*pstr]++;
        pstr++;
    }

    char result = '\0';
    pstr = pString;
    while(*pstr!='\0')
    {
        if(hashtable[*pstr]==1)
        {
            result = *pstr;
            break;
        }
        pstr++;
    }

    return result;
}

int main()
{
    char pString[] = "abaccdeff";
    char ch = getFirstNotRepeatChar(pString);
    cout << ch << endl;

    return 0;
}
