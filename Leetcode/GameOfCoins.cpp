#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> m_Values;
    int m_findMaxValue(int st, int en, int res)
    {
        if(st > en)
            return res;
        return max(m_findMaxValue(st+1, en, res+m_Values[st]), m_findMaxValue(st, en-1, res+m_Values[en]));
    }
    public:
        int PredictTheWinner(vector<int>& nums)
        {
            m_Values.assign(nums.begin(), nums.end());
            int res = m_findMaxValue(0, nums.size()-1, 0);
            return res;
        }
};

int MaxValue(int n, vector<int> v)
{
    Solution sol;
    return sol.PredictTheWinner(v);
}

int main(void)
{
    vector<int> V{1, 2, 3, 4};
    cout << MaxValue(4, V) << endl;
    return 0;
}