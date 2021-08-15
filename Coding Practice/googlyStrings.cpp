#include<bits/stdc++.h>
using namespace std;

int countMinBars(int idx, string str, unordered_set<string>& dict)
{
    if(str[idx] == '\0')
        return 0;
    int ans = INT_MIN;
    string curr_str = "";
    for(int i = idx; str[i]; ++i)
    {
        curr_str += str[i];
        if(dict.find(curr_str) != dict.end())
        {
            int remainingCnt = countMinBars(i+1, str, dict);
            if(remainingCnt != -1)
                ans = max(ans, 1+remainingCnt);
        }
    }
    if(ans == INT_MIN)
        return -1;
    return ans;
}

vector<string>  googlyStrings(vector<string> input)
{
    vector<string> res;
    unordered_set<string> dict;
    for(auto word: input)
        dict.insert(word);
    for(auto word: input)
    {
        int cnt = countMinBars(0, word, dict);
        if(cnt > 1)
            res.push_back(word);
    }
    return res;
}

int main(void)
{
    vector<string> input{"goo", "gle", "google", "le", "g", "googly", "ly", "googoole"};
    vector<string> res = googlyStrings(input);
    for(auto word: res)
        cout << word << endl;
    return 0;
}