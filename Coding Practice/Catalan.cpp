#include <iostream>
using namespace std;

unsigned long int catalan(unsigned int n)
{
    if (n <= 1)
        return 1;
    // catalan(n) is sum of catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i)*catalan(n - i - 1);
    return res;
}

unsigned long int catalanDP(unsigned int n)
{
    unsigned long int catalan[n + 1];
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j]*catalan[i - j - 1];
    }
    return catalan[n];
}

unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

unsigned long int catalanBC(unsigned int n)
{
    unsigned long int bc = binomialCoeff(2*n, n);
    return bc / (n + 1);
}

int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalanBC(i) << " ";
    return 0;
}