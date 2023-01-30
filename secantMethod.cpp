// // C++ Program to find root of an
// // equations using secant method
// #include <bits/stdc++.h>
// using namespace std;
// // function takes value of x and returns f(x)
// float f(float x)
// {
//     // we are taking equation as x^3+x-1
//     float f = pow(x, 3) + x - 1;
//     return f;
// }

// void secant(float x1, float x2, float E)
// {
//     float n = 0, xm, x0, c;
//     if (f(x1) * f(x2) < 0)
//     {
//         do
//         {
//             // calculate the intermediate value
//             x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

//             // check if x0 is root of equation or not
//             c = f(x1) * f(x0);

//             // update the value of interval
//             x1 = x2;
//             x2 = x0;

//             // update number of iteration
//             n++;

//             // if x0 is the root of equation then break the loop
//             if (c == 0)
//                 break;
//             xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
//         } while (fabs(xm - x0) >= E); // repeat the loop
//                                       // until the convergence

//         cout << "Root of the given equation=" << x0 << endl;
//         cout << "No. of iterations = " << n << endl;
//     }
//     else
//         cout << "Can not find a root in the given interval";
// }

// // Driver code
// int main()
// {
//     // initializing the values
//     float x1 = 0, x2 = 1, E = 0.0001;
//     secant(x1, x2, E);
//     return 0;
// }

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

/* Defining equation to be solved.
   Change this equation to solve another problem. */
#define f(x) x *x *x - 2 * x - 5

int main(){
    
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1, N;
    // clrscr();
    /* Inputs */
    printf("\nEnter initial guesses:\n");
    scanf("%f%f", &x0, &x1);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);
    printf("Enter maximum iteration:\n");
    scanf("%d", &N);

    /* Implementing Secant Method */
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do
    {
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1)
        {
            printf("Mathematical Error.");
            exit(0);
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        step = step + 1;

        if (step > N)
        {
            printf("Not Convergent.");
            exit(0);
        }
    } while (fabs(f2) > e);

    printf("\nRoot is: %f", x2);
    getch();

    return 0;
}