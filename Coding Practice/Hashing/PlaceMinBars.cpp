#include <bits/stdc++.h>
using namespace std;

int MinBars(string str, int idx, unordered_set<string>& dictionary)
{
    if(str[idx] == '\0')
        return 0;
    int ans = INT_MAX;
    string curr_str = "";
    // consider all prefix and all subproblems
    for(int i = idx; str[i]; ++i)
    {
        curr_str += str[i];
        // check this prefix in set
        if(dictionary.find(curr_str) != dictionary.end())
        {
            int remaining = MinBars(str, i+1, dictionary);
            // if it is possible to break remaining subproblem
            if(remaining != -1)
                ans = min(ans, 1+remaining);
        }
    }
    // if we can't break this particular string into valid words
    if(ans == INT_MAX)
        return -1;
    return ans;
}

int NumMinBars(string str, vector<string> listOfWords)
{
    unordered_set<string> dictionary;
    for(string word: listOfWords)
        dictionary.insert(word);
    int res = MinBars(str, 0, dictionary);
    return res-1;
}

int main(void)
{
    string str = "thequickbrownfoxjumpsoverthehighbridge";
    vector<string> words = {"the","fox","thequickbrownfox", "jumps",
    "lazy","lazyfox","highbridge","the","over", "bridge","high",
    "tall","quick","brown"};
    cout << NumMinBars(str, words) << endl;
    return 0;
}