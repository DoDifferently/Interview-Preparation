#include <bits/stdc++.h>
using namespace std;

class Point
{
    public:
        int x, y;
        Point(int x, int y): x(x), y(y) {}
};

int CountRightAngledTriangles(vector<Point>& points)
{
    int res = 0;
    unordered_map<int, int> freqX;
    unordered_map<int, int> freqY;
    for(auto pt: points)
        freqX[pt.x]++, freqY[pt.y]++;
    for(Point pt: points)
    {
        res += (freqX[pt.x]-1)*(freqY[pt.y]-1);
    }
    return res;
}

int main(void)
{
    vector<Point> points{{1, 2}, {2, 1}, {2, 2}, {2, 3}, {3, 2}};
    cout << CountRightAngledTriangles(points) << endl;
    return 0;
}