#include <iostream>

using namespace std;

double Power(double base, unsigned int exponent)
{
    if(exponent==0)
        return 1;
    else if(exponent==1)
        return base;
    double result = Power(base,exponent>>1);
    result *= result;
    if((exponent&0x1)==1)
        result *= base;

    return result;
}

int main()
{
    cout << Power(2.0,2) << endl;
    return 0;
}
