#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
 *******************************************************************************/

unsigned fact(unsigned);
unsigned fib(unsigned);
unsigned mult(unsigned, unsigned);
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);

unsigned factTR(unsigned n, unsigned acc);
unsigned multTR(unsigned x, unsigned y, unsigned acc);
unsigned powerTR(unsigned x, unsigned y, unsigned acc);
unsigned productTR(unsigned x, unsigned y, unsigned acc);
unsigned fibTR(unsigned n, unsigned a, unsigned b);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 *
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
 *******************************************************************************/

int main()
{
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;

    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
 *******************************************************************************/

// unsigned fact(unsigned n) {
//     // base cases (combined)
//     if (n <= 1) {
//         return 1;
//     }

//     // recursive case
//     unsigned res = fact(n - 1);
//     return res * n;
// }

// unsigned fib(unsigned n) {
//     // base case 1
//     if (n == 0) {
//         return 0;
//     }

//     // base case 2
//     else if (n == 1) {
//         return 1;
//     }

//     // recursive case
//     return fib(n - 1) + fib(n - 2);
// }

// unsigned mult(unsigned x, unsigned y) {
//     // base case
//     if (y == 0) {
//         return 0;
//     }

//     // recursive case
//     unsigned res = mult(x, y - 1);
//     return res + x;
// }

// unsigned power(unsigned x, unsigned y) {
//     // base case
//     if (y == 0) {
//         return 1;
//     }

//     // recursive case
//     unsigned res = power(x, y - 1);
//     return res * x;
// }

// unsigned product(unsigned x, unsigned y) {
//     // base case
//     if (x == y) {
//         return x;
//     }

//     // recursive case
//     unsigned p = product(x + 1, y);
//     return p * x;
// }

// -------- factorial --------
unsigned fact(unsigned n)
{
    return factTR(n, 1);
}
unsigned factTR(unsigned n, unsigned acc)
{
    if (n <= 1)
        return acc;
    return factTR(n - 1, acc * n);
}

// -------- fibonacci --------
// fibTR(n, a, b): when n==0 -> a, when n==1 -> b
unsigned fib(unsigned n)
{
    return fibTR(n, 0, 1);
}
unsigned fibTR(unsigned n, unsigned a, unsigned b)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibTR(n - 1, b, a + b);
}

// -------- multiply (x * y via repeated addition) --------
unsigned mult(unsigned x, unsigned y)
{
    return multTR(x, y, 0);
}
unsigned multTR(unsigned x, unsigned y, unsigned acc)
{
    if (y == 0)
        return acc;
    return multTR(x, y - 1, acc + x);
}

// -------- power (x^y) --------
unsigned power(unsigned x, unsigned y)
{
    return powerTR(x, y, 1);
}
unsigned powerTR(unsigned x, unsigned y, unsigned acc)
{
    if (y == 0)
        return acc;
    return powerTR(x, y - 1, acc * x);
}

// -------- product (x * (x+1) * ... * y) --------
unsigned product(unsigned x, unsigned y)
{
    return productTR(x, y, 1);
}
unsigned productTR(unsigned x, unsigned y, unsigned acc)
{
    if (x > y)
        return acc; // 안전장치 (혹시 x>y로 들어오면 1 반환)
    if (x == y)
        return acc * x;
    return productTR(x + 1, y, acc * x);
}