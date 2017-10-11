#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const double eps = 1e-9;

int dblcmp(double d){
    if(fabs(d) < eps)   return 0;

    return (d > eps) ? 1 : -1;
}
struct point{
    double x,y;

    point(double _x = 0, double _y = 0){
        x = _x;
        y = _y;
    }

    void input(){
        scanf(" %lf %lf",&x,&y);
    }
    point sub(point p){
        return point(x - p.x, y - p.y);
    }
    double det(point p){
        return (x*p.y - y*p.x);
    }
    double dot(point p){
        return (x*p.x) + (y*p.y);
    }

    double distance(point p){
        return hypot(x - p.x,y-p.y);
    }

};

struct line{
    point a,b;

    line(point _a = point(0,0), point _b = point(0,0)){
        a = _a;
        b = _b;
    }

    void input(){
        a.input();
        b.input();
    }
    bool pointonseg(point p){
        return dblcmp(p.sub(a).det(b.sub(a))) == 0 && dblcmp(p.sub(a).dot(p.sub(b))) <= 0;
    }
    int segcrossseg(line v){
        if(v.pointonseg(a) || v.pointonseg(b) || pointonseg(v.a) || pointonseg(v.b)) return 1;
        int d1 = dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2 = dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3 = dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4 = dblcmp(v.b.sub(v.a).det(b.sub(v.a)));

        if((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 1;

        return (d1 == 0 && dblcmp(v.a.sub(a).dot(v.a.sub(b))) <= 0 ||
           d2 == 0 && dblcmp(v.b.sub(a).dot(v.b.sub(b))) <= 0 ||
           d1 == 0 && dblcmp(a.sub(v.a).dot(a.sub(v.b))) <= 0 ||
           d1 == 0 && dblcmp(b.sub(v.a).dot(b.sub(v.b))) <= 0);
    }
     int linecrossseg(line v){//*this seg v line
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
};

int main(){
}
