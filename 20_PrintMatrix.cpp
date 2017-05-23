#include<iostream>

using namespace std;

void printMatrixOrder(int** numbers, int rows, int columns)
{
    if(numbers==NULL || rows<1 || columns<1)
        return;

    int row_start = 0;
    int row_end = rows - 1;
    int col_start = 0;
    int col_end = columns - 1;
    while((row_start<=row_end) && (col_start<=col_end))
    {
        for(int i=col_start;i<=col_end;i++)
            cout << numbers[row_start][i] << " ";
        row_start++;

        for(int i=row_start;i<=row_end;i++)
            cout << numbers[i][col_end] << " ";
        col_end--;

        for(int i=col_end;i>=col_start;i--)
            cout << numbers[row_end][i] << " ";
        row_end--;

        for(int i=row_end;i>=row_start;i--)
            cout << numbers[i][col_start] << " ";
        col_start++;
    }
    cout << endl;
}

void Test(int rows, int columns)
{
    cout << "Test Begin: " << rows << " rows. " << columns << " columns." << endl;

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    printMatrixOrder(numbers, rows, columns);

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}


int main()
{
    Test(4,2);

    return 0;
}
