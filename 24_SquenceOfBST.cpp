#include <iostream>

using namespace std;

bool verifySequenceOfBST(int* sequence, int length)
{
    if(sequence==NULL || length<=0)
        return false;
    int root = sequence[length-1];
    int prelen = 0;
    for(;prelen<length-1;prelen++)
    {
        if(sequence[prelen]>root)
            break;
    }

    for(int i=prelen;i<length-1;i++)
    {
        if(sequence[i]<root)
            return false;
    }
    bool left = true;
    if(prelen>0)
        left = verifySequenceOfBST(sequence,prelen);

    bool right = true;
    if(prelen<length-1)
        right = verifySequenceOfBST(sequence+prelen,length-prelen-1);

    return (left && right);
}

int main()
{
    int seq1[7] = {5,7,6,9,11,10,8};
    int seq2[4] = {7,4,6,5};
    cout << "seq1:" << verifySequenceOfBST(seq1,7) << endl;
    cout << "seq2:" << verifySequenceOfBST(seq2,4) << endl;

    return 0;
}
