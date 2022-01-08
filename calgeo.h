#include "vector"
#include "iostream"
#include "cmath"

using namespace std;
typedef long double ld;
typedef unsigned int ui;
typedef long long int lli;


const ld accuracy = 1e-11;
const lli sci = 4;

/*
 * Some useful functions for points
 */
bool isOnLine(vector<vector<ld>>);
bool isOnPlane(vector<vector<ld>>);

/*
 * Complex numbers class
 */
class ComplexNumber{
private:
    ld realPart;
    ld imaginaryPart;
public:
    ComplexNumber(ld r, ld i){realPart = r;imaginaryPart = i;}
    ComplexNumber(){}

    void setRealPart(ld);
    void setImaginaryPart(ld);
    void showNumber();
    ld length();
    ld getRealPart();
    ld getImaginaryPart();

    ComplexNumber operator+(ComplexNumber);
    ComplexNumber operator-(ComplexNumber);
    ComplexNumber operator*(ComplexNumber);
    ComplexNumber operator/(ComplexNumber);
    ComplexNumber operator+=(ComplexNumber);
    ComplexNumber operator-=(ComplexNumber);
    bool operator==(ComplexNumber);
    bool operator!=(ComplexNumber);
    void operator=(ComplexNumber);

    vector<ComplexNumber> root(ComplexNumber);
};

ComplexNumber multiplyComplexNumber(ComplexNumber z, ld);
ComplexNumber complexConjugate(ComplexNumber);
ComplexNumber multiplicativeInverse(ComplexNumber);
//ComplexNumber complexOpposite(ComplexNumber);

/*
 * Class line
 */
class Line{
    private:
    vector <ld> direct;  // Directing vector of the line
    vector <ld> point;   // Point that belongs to the line
    public:

    Line (const vector<ld>&, const vector<ld>&);

    vector <ld> getDirectV();
    vector <ld> getDefPoint();

    bool isPointBelong(const vector <ld>& point);
    bool isPerpendicular(Line);
    bool isParallel(Line);
    bool isOnOnePlane(Line);
    bool isCross(Line);
};

vector<ld> pointLineCross(Line line1, Line line2);

class Plane{
private:
    vector<ld> direct;
    vector<ld> point;
public:
    vector <ld> getDirectPlane();
    vector <ld> getPointPoint();
    Plane(vector<ld>, vector<ld>);
    bool isParallel(Line);
    bool isParallel(Plane);
    bool isPerpendicular(Line);
    bool isPointBelong(vector <ld>);
};


/*
 * Matrices
 */
vector<vector<ld>> matrixProduct(vector<vector<ld>>, vector<vector<ld>>, bool side = true);
void showMatrix(vector<vector<ld>>);

class Quadric{
protected:
    vector<ld> coeficients;
    //ld p;

    ld exc; //excetricity
    ld drx; //directix
public:
    virtual bool isEquasionCanonic() = 0;
    virtual bool isPointBelongs(vector<ld>) = 0;

    virtual ld findExcetricity() = 0;
    virtual vector<pair<string, ld>> findDirectrix() = 0;
    //virtual vector<ld> findFocuses() = 0;

    //virtual vector<vector<ld>> pointsLineCross(Line);

    //virtual Line findTangentLine(vector<ld>) = 0;
    //virtual Plane findTangentPlane(vector<ld>) = 0;
};
class Elipsoid : public Quadric{
public:
    bool isEquasionCanonic();
    bool isPointBelongs(vector<ld>);
    /**
     * @return the coordinate of directrix
     */
     // pair< ld , ld > first – real part, second – imaginary part
     /*
      *     first row
      *     second row * ( 'a21 ) - first row * ( 'a11 )
      */
    vector<pair<string, ld>> findDirectrix();
    ld findExcetricity();
};
class Hyperboloid : public Quadric{
public:

};
class Paraboloid : public Quadric{
public:

};

vector<vector<ld>> matrixProduct(vector<vector<ld>>, vector<vector<ld>>, bool side);
void showMatrix(vector<vector<ld>>);

class Matrix{
private:
    lli columns;
    lli rows;
    vector<vector<ld>> matrix;
public:
    /**
     * Construct calls when an instance is being created and sets the width and the height of the matrix.
     * @param column
     * @param row
     */
    Matrix(lli row, lli column){
        columns = column;
        rows = row;
    }

    Matrix();
    void showMatrix();
    void clearMatrix();
    void randValues(ld, ld);


    void setMatrix(vector<vector<ld>> inputMatrix);
    void setMatrix(vector<vector<long long int>> inputMatrix);
    void setMatrix(vector<vector<int>> inputMatrix);
    void setMatrix(vector<vector<float>> inputMatrix);
    void setMatrix(vector<vector<double>> inputMatrix);

    void changeColumns(lli prevColumn, lli nextColumn);
    void changeRows(lli previousRow, lli nextRow);
    void addRows(ld,lli, lli);
    void addColumns(ld, lli, lli);

    void tMatrix();
    void triangle(bool side = true);

    ld determinant();

    vector<vector<ld>> matrixRProduct(vector<vector<ld>>);
    vector<vector<ld>> matrixLProduct(vector<vector<ld>>);

    vector<vector<ld>> inverseMatrix();

    vector<vector<ld>> & getMatrix();
    lli getRows() const;
    lli getColumns() const;

    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    Matrix operator/(Matrix);
    Matrix operator^(int);

    vector<ld> solveEquasion(vector<ld>);
    vector<vector<ld>> findGeneralSolution(vector<ld> constantT);
    unsigned int rank();
    unsigned int rankofExtended(vector<ld>);
};
class cMatrix{
private:
    lli columns;
    lli rows;
    vector<vector<ComplexNumber>> matrix;
public:
    cMatrix(lli row, lli column){
        columns = column;
        rows = row;
    }

    lli getRows();
    lli getColumns();
    vector<vector<ComplexNumber>> getMatrix();

    void changeColumns(lli prevColumn, lli nextColumn);
    void changeRows(lli previousRow, lli nextRow);
    void addColumns (ComplexNumber coefficient, lli targetColumn, lli additionColumn);
    void addRows (ComplexNumber coefficient, lli targetRow, lli additionRow);
    void randValues(ld, ld);
    void showMatrix();
    void setMatrix(vector<vector<ComplexNumber>>);

    unsigned int cRank();
    unsigned int cRankOfExtended(vector<ComplexNumber>);

    ComplexNumber determinant();

    void triangle (bool side = true);

    vector<vector<ComplexNumber>> inverseMatrix();

    vector<ComplexNumber> solveEquasion(vector<ComplexNumber>);
    vector<vector<ComplexNumber>> findGeneralSolution(vector<ComplexNumber> constantT);

    cMatrix operator+(cMatrix);
    cMatrix operator-(cMatrix);
    cMatrix operator*(cMatrix);
    cMatrix operator/(cMatrix);
    cMatrix operator^(int);
};