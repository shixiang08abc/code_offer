#include <iostream>
#include <string>

using namespace std;

void ReplaceBlank(char str[],int length)
{
    if(str==NULL || length<=0)
        return;

    int blank = 0;
    for(int i=0;i<length;i++)
    {
        if(str[i]==' ')
            blank++;
    }

    int new_len = length + 2 * blank;
    int old_idx = length - 1;
    int new_idx = new_len - 1;

    while(1)
    {
        if(old_idx==new_idx)
            break;
        if(str[old_idx]==' ')
        {
            str[new_idx--] = '0';
            str[new_idx--] = '2';
            str[new_idx--] = '%';
            old_idx--;
        }
        else
        {
            str[new_idx] = str[old_idx];
            new_idx--;
            old_idx--;
        }
    }
}

int main()
{
    char str[]="we are happy.";
    ReplaceBlank(str,sizeof(str));
    cout << str << " length:" << sizeof(str) << endl;

    return 0;
}
