#include <iostream>
#include "calgeo.h"

using namespace std;

int main(){
    srand(time(0));
    Matrix test(4,7);
    vector<vector<ld>> testv={
            {5,6,3,2,2,4,1},
            {5,5,3,2,2,7,2},
            {5,5,8,1,1,7,3},
            {5,5,8,1,1,7,3}
    };
    test.setMatrix(testv);
    vector<vector<ld>> testt=test.findGeneralSolution({2,2,9,9});
    for(int j=0;j<testt.size();j++){
        for(int i=0;i<testt[0].size();i++) {
            cout << testt[j][i] << endl;
        }
        cout<<endl;
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