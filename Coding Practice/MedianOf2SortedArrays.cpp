
#include <bits/stdc++.h>
using namespace std;

int findMedian(std::vector<int>::const_iterator A, int m, std::vector<int>::const_iterator B, int n, int k)
{
    //always assume that m is equal or smaller than n
    if(m > n)
        return findMedian(B, n, A, m, k);
    if(m == 0)
        return *(B + k - 1);
    if(k == 1)
        return min(*A, *B);
    //divide k into two parts
    int ia = min(k / 2, m), ib = k - ia;
    if (*(A + ia - 1) < *(B + ib - 1))
        return findMedian(A + ia, m - ia, B, n, k - ia);
    else if (*(A + ia - 1) > *(B + ib - 1))
        return findMedian(A, m, B + ib, n - ib, k - ib);
    else
        return A[ia - 1];
}

double findMedianSortedArrays(const vector<int>& A, const vector<int>& B)
{
    const int m = A.size();
    const int n = B.size();
    int total = m + n;
    if(total & 0x1)
        return findMedian(A.begin(), m, B.begin(), n, total / 2 + 1);
    else
        return (findMedian(A.begin(), m, B.begin(), n, total / 2) + findMedian(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
}

double findMedianSortedArrays2(vector<int>& A, vector<int>& B)
{
    int m = A.size();
    int n = B.size();
    if(m > n)
        return findMedianSortedArrays(B, A);
    int st = 0, end = m;
    int midInMerged = (m+n+1)/2;
    while(st <= end)
    {
        int mid = (st+end)/2;
        int leftA_sz = mid;
        int leftB_sz = midInMerged - leftA_sz;
        int leftA = leftA_sz > 0 ? A[leftA_sz-1] : INT_MIN;
        int rightA = leftA_sz < m ? A[leftA_sz] : INT_MAX;
        int leftB = leftB_sz > 0 ? B[leftB_sz-1] : INT_MIN;
        int rightB = leftB_sz < n ? B[leftB_sz] : INT_MAX;
        if(leftA <= rightB and leftB <= rightA)
        {
            if((m+n)&1)
                return max(leftA, leftB);
            else
                return (max(leftA, leftB) + min(rightA, rightB))/2.0;
        }
        if(leftA > rightB) // left part of A need to be decreased
            end = mid-1;
        else
            st = mid+1;
    }
    return 0.0;
}