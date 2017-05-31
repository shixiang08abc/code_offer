#include <iostream>
#define LENGTH 9

using namespace std;

int moreThanHalfNum(int nums[], int len)
{
    int data = 0;
    int times = 0;
    for(int i=0;i<len;i++)
    {
        if(times==0)
        {
            data = nums[i];
            times = 1;
        }
        else if(nums[i]==data)
            times++;
        else
            times--;
    }
    return data;
}

int main()
{
    int nums[LENGTH] = {1,2,3,2,2,2,5,4,2};
    int data = moreThanHalfNum(nums,LENGTH);
    cout << data << endl;

    return 0;
}
