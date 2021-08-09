#include <bits/stdc++.h>
using namespace std;
 
vector<int> find(int n)
{
    vector<int> ans;    // Steps sequence
    int sum = 0;
    int i;
 
    // Sign of the number
    int sign = (n >= 0 ? 1 : -1);
    n = abs(n);
 
    // Basic steps required to get
    // sum >= required value.
    for (i = 1; sum < n; i++)
    {
        ans.push_back(sign * i);
        sum += i;
    }
 
    // If we have reached ahead to destination.
    if (sum > sign * n)
    {
        /*If the last step was an odd number,
         then it has following mechanism for
         negating a particular number and
         decreasing the sum to required number
         Also note that it may require
         1 more step in order to reach the sum. */
        if (i % 2) {
            sum -= n;
            if (sum % 2) {
                ans.push_back(sign * i);
                sum += i++;
            }
            ans[(sum / 2) - 1] *= -1;
        }
        else {
            /* If the current time instance is even
            and sum is odd than it takes
            2 more steps and few
            negations in previous elements
            to reach there. */
            sum -= n;
            if (sum % 2) {
                sum--;
                ans.push_back(sign * i);
                ans.push_back(sign * -1 * (i + 1));
            }
            ans[(sum / 2) - 1] *= -1;
        }
    }
    return ans;
}
 
// Driver Program
int main()
{
    int n = 20;
    if (n == 0)
        cout << "Minimum number of Steps: 0\nStep sequence:\n0";
    else
    {
        vector<int> a = find(n);
        cout << "Minimum number of Steps: " << a.size() << "\nStep sequence:\n";
        for (int i : a)
            cout << i << " ";
    }
    return 0;
}