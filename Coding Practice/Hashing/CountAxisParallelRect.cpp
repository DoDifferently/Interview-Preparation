#include <bits/stdc++.h>
using namespace std;

class Point
{
    public:
        int x, y;
        Point(int x, int y): x(x), y(y) {}
};

// Need to define comparator class for set and map
class Compare
{
    public:
        bool operator()(const Point& pt1, const Point& pt2)
        {
            if(pt1.x == pt2.x)
                return pt1.y < pt2.y;
            return pt1.x < pt2.x;
        }
};

int CountAxisParallelRectangles(vector<Point>& points, int n)
{
    int res = 0;
    set<Point, Compare> uniquePts;
    for(auto pt: points)
        uniquePts.insert(pt);
    for(auto it1 = uniquePts.begin(); it1 != prev(uniquePts.end()); it1++)
    {
        for(auto it2 = next(it1); it2 != uniquePts.end(); it2++)
        {
            Point pt1 = *it1;
            Point pt2 = *it2;
            if(pt1.x == pt2.x or pt1.y == pt2.y)
                continue;
            Point pt3(pt1.x, pt2.y);
            Point pt4(pt2.x, pt2.y);
            if(uniquePts.find(pt3) != uniquePts.end() and uniquePts.find(pt4) != uniquePts.end())
                res++;
        }
    }
    return res/2;
}

int main(void)
{
    int n;
    cin >> n;
    int x, y;
    vector<Point> points;
    for(int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    cout << CountAxisParallelRectangles(points, n) << endl;
    return 0;
}