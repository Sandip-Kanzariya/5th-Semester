#include <bits/stdc++.h>

using namespace std;

// Point : (x, y)
class Point
{

public:
    int a, b;

    Point(int x, int y)
    {
        a = x;
        b = y;
    }
};

//
int Deter(Point i, Point j)
{

    int xi = i.a;
    int yi = i.b;
    int xj = j.a;
    int yj = j.b;

    int ans = xi * yj - xj * yi;
    // cout << ans;
    return ans;
}

// Direction : (ik) w.r.t (ij) => ik X ij
int Direction(Point i, Point j, Point k)
{

    int x = k.a - i.a;
    int y = k.b - i.b;

    int p = j.a - i.a;
    int q = j.b - i.b;

    return Deter(Point(x, y), Point(p, q));
}

// i------------k-----j
bool onSegment(Point i, Point j, Point k)
{

    int xi = i.a;
    int yi = i.b;

    int xj = j.a;
    int yj = j.b;

    int xk = k.a;
    int yk = k.b;

    if ((min(xi, xj) <= xk && max(xi, xj) >= xk) &&
        (min(yi, yj) <= yk && max(yi, yj) >= yk))
        return true;

    return false;
}

// Segment : p1p2
// Segment : p3p4
bool intersect(Point p1, Point p2, Point p3, Point p4)
{
    int d1 = Direction(p3, p4, p1);
    int d2 = Direction(p3, p4, p2);
    int d3 = Direction(p1, p2, p3);
    int d4 = Direction(p1, p2, p4);

    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;

    else if (d1 == 0 && onSegment(p3, p4, p1))
    {
        return true;
    }

    else if (d2 == 0 && onSegment(p3, p4, p2))
    {
        return true;
    }

    else if (d3 == 0 && onSegment(p1, p2, p3))
    {
        return true;
    }

    else if (d4 == 0 && onSegment(p1, p2, p4))
    {
        return true;
    }

    else
    {
        return false;
    }
}
int main()
{

    // p1p2
    Point p1 = Point(1, 1);
    Point p2 = Point(4, 8);
    // p3p4
    Point p3 = Point(2, 6);
    Point p4 = Point(6, 3);

    if(intersect(p1, p2, p3, p4)){
        cout << "Intersect";
    }
    else{
        cout << "Not Intersect";
    }
    return 0;
}