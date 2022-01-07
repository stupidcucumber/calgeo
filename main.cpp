#include <iostream>
#include "calgeo.h"

using namespace std;
long double squareRoot(long double n)
{

    long double x = n;
    long double y = 1;
    long double e = 1e-10;
    while (x - y > e)
    {
        x = (x + y) / 2;
        y = n / x;
    }
    //cout << x << "\n";
    return x;
}

int main(){
    srand(time(0));
    vector<ld> l = {1 , 1};
    Elipsoid e(l);

    vector<ld> direct = {1, 1, 1};

    Line line({1, 1, 1}, {0, 0, 0});
    Line line2({-1, 1, 0}, {0, 0, 0});
    Plane plane1(direct, {1, 1, 1}), plane2({1, 1, 2}, {1, 1, 1});

    cout << plane1.isParallel(plane2) << endl;
    cout << plane1.isPerpendicular(line) << endl;
    cout << plane1.isParallel(line2) << endl;
    cout << plane1.isPointBelong({1,1,1}) << endl;
/*
    vector<pair<string, ld>> d = e.findDirectrix();
    ld ext = e.findExcetricity();
    cout<<ext<<endl;
    cout << e.isEquasionCanonic() << endl;
    cout<<e.isPointBelongs({1 / sqrtl(2),1 / sqrtl(2)})<<endl;
    for(auto i : d){
        cout << i.first << " = " << i.second << endl;
    }*/

    return 0;
}