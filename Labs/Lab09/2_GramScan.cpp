#include <bits/stdc++.h>
using namespace std;

/*
Time : 
WorstCase-Time : 
7
0 0 
3 1 
4 4
1 2
0 5
2 2
-1 3
*/

// Point : (x, y)
class Point {
    
    public : 
    int a, b;
    
    Point(int x, int y){
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

// Sort all points based on Polar Angle with P 
int cmp(pair<int, Point> a, pair<int, Point> b){
    
}

int main()
{

    cout << "Enter Number of Points : ";
    int n;
    cin >> n;
    cout << "Enter " << n << " Points : \n";
    
    vector <Point> points;
    for(int i = 0;i < n;i++){
        int x, y;
        cin >> x >> y;
        
        
        Point p = Point(x, y);
        
        points.push_back(p);        
    }    
    
    // Find Number which have X-min as well as Y-min (Left)
    // sort(points.begin(), points.end());
    
    Point p = Point(INT_MAX, INT_MAX);
    
    for(int i = 0;i < n;i++){
        // cout << points[i].a << " " << points[i].b << "\n";
        
        if(points[i].b < p.b){
            p = points[i];
        }
        else if(points[i].b == p.b && points[i].a < p.a){
            p = points[i];
        }
    }       
    
    // cout << p.a << " " << p.b << "\n";
    vector<pair<int, Point>> polar;
    int x0 = p.a;  
    int y0 = p.b;  
    
    for(int i = 0;i < n;i++){
        
        int x = points[i].a;
        int y = points[i].b;
        
        if(x != x0 || y != y0){
            int up = y - y0;
            int lw = x - x0;
            
            double t = atan2(up, lw) * 180 / 3.14;
            
            if(t < 0){
                t += 180;      
            }
            cout << t << "\n";
            polar.push_back({t, points[i]});
        }
    }
    sort(polar.begin(), polar.end(), cmp);
    
    /*
    for(int i = 0;i < polar.size();i++){
        cout << polar[i].first << "\n";
    }
    */
    return 0;
}

