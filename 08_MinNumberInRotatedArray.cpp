#include <iostream>

using namespace std;

int MinInOrder(int* data, int startidx, int endidx)
{
    int minNum = data[startidx];
    int minidx = startidx;
    for(int i=startidx+1;i<=endidx;i++)
    {
        if(data[i]<minNum)
        {
            minNum = data[i];
            minidx = i;
        }
    }
    return minidx;
}

int minNumber(int* data, int length)
{
    if(data==NULL || length<=0)
        return -1;
    int index1 = 0;
    int index2 = length - 1;
    int idxMid = index1;
    while(index1<index2)
    {
        if(index2-index1==1)
        {
            if(data[index1]<=data[index2])
                idxMid = index1;
            else
                idxMid = index2;
            break;
        }

        idxMid = (index1+index2)/2;
        if(data[index1]==data[idxMid] && data[index2]==data[idxMid])
            return MinInOrder(data,index1,index2);
        if(data[idxMid]>=data[index2])
            index1 = idxMid;
        else
            index2 = idxMid;
    }
    return idxMid;
}

int main()
{
    int data[5] = {1,2,3,4,5};
    int index = minNumber(data,5);
    cout << index << endl;

    return 0;
}
