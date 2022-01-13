
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr)
{
    int numDupAllowed = 2;
    if(arr.size() < numDupAllowed)
        return arr.size();
    int curr = numDupAllowed;
    for(int next = numDupAllowed; next < arr.size(); ++next)
    {
        if(arr[next] != arr[curr-numDupAllowed])
        {
            arr[curr++] = arr[next];
        }
    }
    return curr;
}

int main(void)
{
    vector<int> arr = {1, 1, 1, 1, 2, 2, 2, 3};
    cout << removeDuplicates(arr) << endl;
    return 0;
}