#include<bits/stdc++.h>
using namespace std;

int SubsequenceCount(int idx1, int idx2, string s1, string s2)
{
    if(idx2 == -1)
        return 1;
    if(idx1 == -1)
        return 0;
    if(s1[idx1] != s2[idx2])
        return SubsequenceCount(idx1-1, idx2, s1, s2);
    return SubsequenceCount(idx1-1, idx2, s1, s2) + SubsequenceCount(idx1-1, idx2-1, s1, s2);
}

int SubsequenceCountBottomUp(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    for(int i = 0; i < len1; ++i)
        dp[i][0] = 1; // if string s2 is null
    for(int i = 1; i <= len1; ++i)
    {
        for(int j = 1; j <= len2; ++j)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[len1][len2];
}

int main(void)
{
    string s1 = "abcdce", s2 = "abc";
    cout << SubsequenceCount(s1.length()-1, s2.length()-1, s1, s2) << endl;
    cout << SubsequenceCountBottomUp(s1, s2) << endl;
    return 0;
}