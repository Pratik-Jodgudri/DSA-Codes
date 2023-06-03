#include <bits/stdc++.h>
using namespace std;

struct P
{
    int x, y;
};

int min(int a, int b)
{
    return a < b ? a : b;
}

struct P diff(struct P Pj, struct P Pi)
{
    struct P temp;
    temp.x = Pj.x - Pi.x;
    temp.y = Pj.y - Pi.y;
    return temp;
}

int cross(struct P P1, struct P P2)
{
    return ((P1.x * P2.y) - (P2.x * P1.y));
}

int dir(struct P Pi, struct P Pj, struct P Pk)
{
    return (cross(diff(Pk, Pi), diff(Pj, Pi)));
}

bool online(struct P Pi, struct P Pj, struct P Pk)
{
    int minx = min(Pi.x, Pj.x);
    int miny = min(Pi.x, Pj.x);
    int maxx = max(Pi.x, Pj.x);
    int maxy = max(Pi.y, Pj.y);

    return (Pk.x >= minx && Pk.x <= maxx && Pk.y >= miny && Pk.y <= maxy);
}

bool intersect(struct P P1, struct P P2, struct P P3, struct P P4)
{
    int d1 = dir(P3, P4, P1);
    int d2 = dir(P3, P4, P2);
    int d3 = dir(P1, P2, P3);
    int d4 = dir(P1, P2, P4);

    if ((d1 > 0 && d2 > 0 || d1 < 0 && d2 > 0) && (d3 > 0 && d4 < 0 || d3 < 0 && d4 > 0))
    {
        return true;
    }
    if (d1 == 0 && online(P3, P4, P1))
    {
        return true;
    }
    if (d2 == 0 && online(P3, P4, P2))
    {
        return true;
    }
    if (d3 == 0 && online(P1, P2, P3))
    {
        return true;
    }
    if (d4 == 0 && online(P1, P2, P4))
    {
        return true;
    }

    return false;
}

int main()
{
    struct P P1, P2, P3, P4;
    cout << "Enter the coordinates of the points P1, P2, P3, P4: \n";
    cin >> P1.x; // = 8;
    cin >> P1.y; // = 8;
    cin >> P2.x; // = 1;
    cin >> P2.y; // = 1;
    cin >> P3.x; // = 1;
    cin >> P3.y; // = 4;
    cin >> P4.x; // = 7;
    cin >> P4.y; // = 1;

    if(intersect(P1, P2, P3, P4))
        cout << "They Intersect\n";
    else
        cout << "Dont Intersect\n";
    return 0;
}