#include "Geometry.h"

using namespace std;

int main(){

    Line line({1, 1, 1}, {0, 1, 0});
    Plane plane({1, 1, 1}, {0, 0, 0});

    cout << plane.isPerpendicular(line) << endl;

}