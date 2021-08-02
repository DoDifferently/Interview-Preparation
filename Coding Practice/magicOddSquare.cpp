#include <bits/stdc++.h>
using namespace std;

int a[51][51];

int main() 
{
    int n;
    scanf("%d",&n);
    int r = 0, c = n/2;
    for(int i = 1; i < n*n+1; ++i)
    {
        a[r][c] = i;
        r = (r-1+n)%n;
        c = (c+1)%n;
        if(a[r][c])
        {
            r = (r+2)%n;   // (r-1) + 2 => r+1      (for same row)
            c = (c-1+n)%n; // (c+1) - 1 => c        (for same column)
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}