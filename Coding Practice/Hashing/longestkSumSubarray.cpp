#include<bits/stdc++.h>
using namespace std;

int longestSubarrayKSum(vector<int> arr, int k)
{
    unordered_map<int, int> PrefixSumIdx;
    int prefix_sum = 0, maxLen = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        prefix_sum += arr[i];
        if(prefix_sum == k)
            maxLen = i+1;
        int target_sum = prefix_sum - k;
        if(PrefixSumIdx.find(prefix_sum-k) != PrefixSumIdx.end())
            maxLen = max(maxLen, i - PrefixSumIdx[prefix_sum-k]);
        /**
         * We need to store indices as 1-based else map will
         * return 0 for 0th index and will not enter in above
         * condition if we use "if(PrefixSumIdx[prefix_sum-k])"
         * For 0-based index -> use "find()" function of map
         */
        PrefixSumIdx[prefix_sum] = i;
    }
    return maxLen;
}

int main(void)
{
    vector<int> arr{ 10, 5, 2, 7, 1, 9 };
    int K = -5;
    cout << longestSubarrayKSum(arr, K) << endl;
    return 0;
}