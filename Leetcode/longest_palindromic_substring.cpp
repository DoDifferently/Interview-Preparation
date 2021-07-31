#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        void lenPalString(string str, int& left, int& right, int& len)
        {
            int len = 0;
            while(left >= 0 and right < str.size())
            {
                if(str[left] == str[right])
                {
                    len += 2;
                    left--;
                    right++;
                }
                else
                    break;
            }
        }
        pair<int, int> palindromeLen(string str, int idx)
        {
            int start = idx, pal_len = 0;
            int left = idx, right = idx+1, len = 0; // for even-length string
            lenPalString(str, left, right, len);
            if(len > pal_len)
            {
                pal_len = len;
                start = left+1;
            }
            left = idx-1, right = idx+1, len = 1; // for odd-length string
            lenPalString(str, left, right, len);
            if(len > pal_len)
            {
                pal_len = len;
                start = left+1;
            }
            return {start, pal_len};
        }
        
        string longestPalindrome(string s)
        {
            int start = 0, maxPal_len = 0;
            for(int mid = 0; mid < s.size(); ++mid)
            {
                pair<int, int> curr_len = palindromeLen(s, mid);
                if(curr_len.second > maxPal_len)
                {
                    maxPal_len = curr_len.second;
                    start = curr_len.first;
                }
            }
            cout << start << ", " << maxPal_len << endl;
            return s.substr(start, maxPal_len);
        }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindrome("cbbd") << endl;
    return 0;
}