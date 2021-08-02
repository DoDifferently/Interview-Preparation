#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> m_Values;
    int m_findMaxValue(int start, int end)
    {
        if(start == end)
            return m_Values[start];
        if(end == start+1)
            return max(m_Values[start], m_Values[end]);
        return max(m_Values[start] + min(m_findMaxValue(start+2, end), m_findMaxValue(start+1, end-1)),
                    m_Values[end] + min(m_findMaxValue(start+1, end-1), m_findMaxValue(start, end-2)));
    }
    public:
        int MaxValueForPlayer1(vector<int>& nums)
        {
            m_Values.assign(nums.begin(), nums.end());
            int res = m_findMaxValue(0, nums.size()-1);
            return res;
        }
};

int main(void)
{
    vector<int> V{1, 2, 3, 4};
    Solution sol;
    cout << sol.MaxValueForPlayer1(V) << endl;
    return 0;
}