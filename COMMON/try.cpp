#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

inline int read() {
    int w=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){w=w*10+c-'0';c=getchar();}
    return w*f;
}

class Point_Coordinate{
public:
    double coordinate_x, coordinate_z;
    double line_k, line_b;
    Point_Coordinate();
    Point_Coordinate(double x, double z) :
        coordinate_x(x), coordinate_z(z){}
};

class Line {
public:
    double line_k, line_b;

    void Calc_Line(Point_Coordinate a, Point_Coordinate b) {
        line_k = (a.coordinate_z - b.coordinate_z) / (a.coordinate_x - b.coordinate_x);
        line_b = a.coordinate_z - line_k * a.coordinate_x;
    }
}L[2];

class Intersection {
public:
    double x, z;

    void calc(Line a, Line b) {
        x = (a.line_b - b.line_b) / (a.line_k - b.line_k);
        z = a.line_k * x + a.line_b;
    }
};

inline void init() {
    double x1, z1, x2, z2;

    scanf("%lf%lf%lf%lf", &x1, &z1, &x2, &z2);

    Point_Coordinate P1(x1, z1);
    Point_Coordinate P2(x2, z2);
    L[1].Calc_Line(P1, P2);
}

// 去上厕所

int main() {
    int p = 0;

    init();

    while (true) {
        double x1, z1, x2, z2;

        scanf("%lf%lf%lf%lf", &x1, &z1, &x2, &z2);

        if (x1 == -1 && z1 == -1 && x2 == -1 && z2 == -1)
            break;

        Point_Coordinate P1(x1, z1);
        Point_Coordinate P2(x2, z2);
        L[p].Calc_Line(P1, P2);

        Intersection I;
        I.calc(L[p], L[p ^ 1]);
        printf("%lf %lf\n", I.x, I.z);

        p ^= 1;
    }

    return 0;
}

