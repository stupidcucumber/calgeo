#include "Matrices.h"

using namespace std;

int main(){
    cMatrix m(110,110);
    m.randValues(-10, 100);

    m.showMatrix();
    cout << endl;

    ComplexNumber c = m.determinant();
    c.showNumber();
}