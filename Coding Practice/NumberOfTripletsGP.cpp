#include<bits/stdc++.h>
using namespace std;

int numberOfTriplets(vector<int> array, int r)
{
    int res = 0;
    unordered_map<int, int> left, right;
    for(int i = 1; i < array.size(); ++i)
        right[array[i]]++;
    left[array[0]]++;
    for(int i = 1; i < array.size(); ++i)
    {
        int curr = array[i];
        right[curr]--;
        if(curr%r == 0) // check if a[i]/r is int or not
            res += (left[curr/r]*right[curr*r]);
        left[curr]++;
    }
    return res;
}

int main(void)
{
    vector<int> array{1,1,1,1};
    int r = 1;
    cout << numberOfTriplets(array, r);
    return 0;
}