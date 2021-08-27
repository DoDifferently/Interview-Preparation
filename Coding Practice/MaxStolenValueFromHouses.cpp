#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int idx, int arr[])
{
    if(idx < 0)
        return 0;
    return max(arr[idx] + findMaxSum(idx-2, arr), findMaxSum(idx-1, arr));
}

int findMaxSumDP(int n, int arr[])
{
    vector<int> dp(n, 0);
    dp[0] = max(0, arr[0]);
    dp[1] = max(0, max(arr[0], arr[1]));
    for(int i = 2; i < n; ++i)
        dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
    return dp[n-1];
}

int main(void)
{
    int n = 6;
    int arr[] = {6, 10, 12, 7, 9, 14};
    cout << findMaxSumDP(n, arr);
    return 0;
}