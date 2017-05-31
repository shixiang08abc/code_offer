#include <iostream>
#define LENGTH 8

using namespace std;

void insertSort(int nums[], int len)
{
    if(nums==NULL || len<=1)
        return;
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i]<nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void selectSort(int nums[], int len)
{
    for(int i=0;i<len;i++)
    {
        int minidx = i;
        int minnum = nums[i];
        for(int j=i+1;j<len;j++)
        {
            if(nums[j]<minnum)
            {
                minnum = nums[j];
                minidx = j;
            }
        }
        nums[minidx] = nums[i];
        nums[i] = minnum;
    }
}

void bubbleSort(int nums[], int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=len-1;j>i;j--)
        {
            if(nums[j]<nums[j-1])
            {
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
    }
}

int getPartition(int nums[], int pStart, int pEnd)
{
    int base = nums[pStart];
    while(pStart<pEnd)
    {
        while(nums[pEnd]>=base && pEnd>pStart)
            pEnd--;
        nums[pStart] = nums[pEnd];
        while(nums[pStart]<=base && pStart<pEnd)
            pStart++;
        nums[pEnd] = nums[pStart];
    }
    nums[pStart] = base;
    return pStart;
}

void quickSort(int nums[], int pStart, int pEnd)
{
    if(pStart<pEnd)
    {
        int mid = getPartition(nums,pStart,pEnd);
        quickSort(nums,pStart,mid-1);
        quickSort(nums,mid+1,pEnd);
    }
}

void mergeArray(int nums[], int first, int mid, int last, int data[])
{
    int i = first;
    int j = mid + 1;
    int k = 0;
    while(i<=mid && j<=last)
    {
        if(nums[i]<nums[j])
            data[k++] = nums[i++];
        else
            data[k++] = nums[j++];
    }
    while(i<=mid)
        data[k++] = nums[i++];
    while(j<=last)
        data[k++] = nums[j++];
    for(int a=0;a<k;a++)
        nums[a+first] = data[a];
}

void mergeSort(int nums[], int first, int last, int data[])
{
    if(first<last)
    {
        int mid = (first+last)/2;
        mergeSort(nums,first,mid,data);
        mergeSort(nums,mid+1,last,data);
        mergeArray(nums,first,mid,last,data);
    }
}

void mergeSort(int nums[], int len)
{
    int* data = new int[len];
    if(data==NULL)
        return;
    mergeSort(nums,0,len-1,data);
    delete[] data;
}

int main()
{
    int nums[LENGTH] = {49,38,65,97,49,76,13,27};
    cout << "orginal arrays:";
    for(int i=0;i<LENGTH;i++)
        cout << nums[i] << " ";
    cout << endl;

    //insertSort(nums,LENGTH);
    //selectSort(nums,LENGTH);
    //bubbleSort(nums,LENGTH);
    //quickSort(nums,0,LENGTH-1);
    mergeSort(nums,LENGTH);
    cout << "Sort arrays:";
    for(int i=0;i<LENGTH;i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
