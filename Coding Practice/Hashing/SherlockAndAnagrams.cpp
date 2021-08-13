#include <bits/stdc++.h>
using namespace std;

int CountAllAnagramSubstringPairs(string str)
{
    map<vector<int>, int> substrFreqs;
    // generate all substrings
    for(int i = 0; i < str.length(); ++i)
    {
        vector<int> currSubStrfreq(26, 0);
        for(int j = i; str[j]; ++j)
        {
            currSubStrfreq[str[j]-'a']++;
            substrFreqs[currSubStrfreq]++;
        }
    }
    int res = 0;
    for(auto substr: substrFreqs)
    {
        int freq = substr.second;
        res += (freq*(freq-1))/2;
    }
    return res;
}

int main(void)
{
    string str = "abba";
    cout << CountAllAnagramSubstringPairs(str) << endl;
    return 0;
}