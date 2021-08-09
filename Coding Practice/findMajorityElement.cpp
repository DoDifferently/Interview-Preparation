#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int m_getCandidateElement(int arr[], int n)
    {
        int candidateElement = arr[0], count = 1;
        for(int i = 1; i < n; ++i)
        {
            if(arr[i] == candidateElement)
                count++;
            else
                count--;
            if(count == 0)
            {
                candidateElement = arr[i];
                count = 1;
            }
        }
        return candidateElement;
    }

    bool m_bIsMajorityElement(int arr[], int n, int element)
    {
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] == element)
                count++;
            if(count > n/2)
                return true;
        }
        return false;
    }
    
    public:
        void printMajorityElement(int arr[], int n)
        {
            int majorityElement = m_getCandidateElement(arr, n);
            if(m_bIsMajorityElement(arr, n, majorityElement))
                printf("Majority Element = %d\n", majorityElement);
            else
                printf("No Majority Element");
        }
};

int main()
{
    int a[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 };
    int size = (sizeof(a)) / sizeof(a[0]);
    Solution solve;
    solve.printMajorityElement(a, size);
    return 0;
}