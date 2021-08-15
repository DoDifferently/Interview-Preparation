#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs)
{
    vector<vector<string>> res;
    map<vector<int>, vector<string>> hash;
    for(auto str: strs)
    {
        vector<int> freq(26, 0);
        for(auto ch: str)
            freq[ch-'a']++;
        hash[freq].push_back(str);
    }
    for(auto i: hash)
        res.push_back(i.second);
    return res;
}