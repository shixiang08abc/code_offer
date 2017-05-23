#include <iostream>

using namespace std;

bool findNum(int *matrix, int rows, int columns, int number)
{
    bool result = false;
    int i=0;
    int j = columns-1;
    while(1)
    {
        cout<<i<<" "<<j<<endl;
        if(matrix==NULL || i>=rows || j<0)
            break;
        if(matrix[i*rows+j]==number)
        {
            result = true;
            break;
        }
        else if(matrix[i*rows+j]>number)
            j--;
        else
            i++;
    }
    return result;
}

int main()
{

    int matrix[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    cout << "matrix find:" << findNum((int *)matrix,4,4,7) << endl;
    return 0;
}
