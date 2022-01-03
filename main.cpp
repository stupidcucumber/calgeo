#include <iostream>
#include "calgeo.h"

using namespace std;

int main(){
    srand(time(0));
    vector<vector<ld>> system={
            {1,1,1},
            {1,1,1},
            {1,1,1},
            {1,1,1},
            {1,1,1},
            {1,4,0},
            {1,2,4}
    };
    vector<ld> coefs = {4,4,4,4,4, 1, 45};
    vector<ld> results;
    Matrix m (7, 3);
    m.setMatrix(system);
    results = m.solveEquasion(coefs);

    for(auto i : results){
        cout << i << endl;
    }

    vector<ld> direct1 = {1, 1, 0};
    vector<ld> direct2 = {-1, 1, 0};
    vector<ld> point1 = {0.5,0.5,0};
    vector<ld> point2 = {-2,-3,0};
    Line line1(direct1, point1);
    Line line2(direct2, point2);
    vector<ld> point = pointLineCross(line1, line2);

    for(auto i : point){
        cout << i << endl;
    }

    return 0;
}