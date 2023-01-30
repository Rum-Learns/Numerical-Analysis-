#include <iostream>

using namespace std;

#define error 0.1

double function(double x)
{
    return (x * x * x - x * x + 2);
}

void bisection(double a, double b)
{

    if (function(a) * function(b) >= 0)
    {
        cout << "You have not assumed right values for a and b. ";
    }

    double c;

    while ((b - a) >= error)
    {
        c = (a + b) / 2;

        if (function(c) == 0)
            break;
        else
        {
            if (function(c) * function(a) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
    }
    cout << "Value of the root = "<< c;
}

int main(){

    double a=-200, b=300;
    bisection(a,b);

    return 0;
}