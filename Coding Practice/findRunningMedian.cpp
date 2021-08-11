#include <queue>
#include <iostream>
using namespace std;

int main(void)
{
    int n, a_i;
    cin >> n;
    priority_queue<int> MaxHeap;
    priority_queue<int, vector<int>, greater<int> > MinHeap;
    while(n--)
    {
        cin >> a_i;
        if(MinHeap.empty())
        {
            MinHeap.push(a_i);
        }
        else if(MinHeap.size() > MaxHeap.size())
        {
            if(MinHeap.top() < a_i)
            {
                MaxHeap.push(MinHeap.top());
                MinHeap.pop();
                MinHeap.push(a_i);
            }
            else
                MaxHeap.push(a_i);
        }
        else // same size
        {
            if(MaxHeap.top() > a_i)
            {
                MinHeap.push(MaxHeap.top());
                MaxHeap.pop();
                MaxHeap.push(a_i);
            }
            else
                MinHeap.push(a_i);
        }
        if(MinHeap.size() > MaxHeap.size())
            cout << (float)MinHeap.top() << endl;
        else
            cout << (float)(MinHeap.top()+MaxHeap.top())/2.0 << endl;
    }
    return 0;
}