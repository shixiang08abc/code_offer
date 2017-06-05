#include <iostream>

using namespace std;

int getMaxUgly(int num)
{
    if(num<2)
        return 0;
    int *uglyNums = new int[num];
    int index = 0;
    uglyNums[index] = 1;
    int ugly2_idx = 0;
    int ugly3_idx = 0;
    int ugly5_idx = 0;
    while(uglyNums[index]<num)
    {
        while(uglyNums[index]>=uglyNums[ugly2_idx]*2)
            ugly2_idx++;
        int ugly2 = uglyNums[ugly2_idx]*2;
        while(uglyNums[index]>=uglyNums[ugly3_idx]*3)
            ugly3_idx++;
        int ugly3 = uglyNums[ugly3_idx]*3;
        while(uglyNums[index]>=uglyNums[ugly5_idx]*5)
            ugly5_idx++;
        int ugly5 = uglyNums[ugly5_idx]*5;

        if(ugly2<=ugly3 && ugly2<=ugly5)
            uglyNums[++index] = ugly2;
        else if(ugly3<=ugly2 && ugly3<=ugly5)
            uglyNums[++index] = ugly3;
        else
            uglyNums[++index] = ugly5;
    }
    int ugly = uglyNums[index - 1];
    delete [] uglyNums;

    return ugly;
}

int main()
{
    int maxUgly = getMaxUgly(1500);
    cout << maxUgly << endl;

    return 0;
}
