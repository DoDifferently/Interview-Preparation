#include<bits/stdc++.h>
using namespace std;

char firstRepeatChar(string input)
{
    unordered_map<char, bool> hash;
    for(char ch: input)
    {
        if(hash[ch])
            return ch;
        hash[ch] = true;
    }
}