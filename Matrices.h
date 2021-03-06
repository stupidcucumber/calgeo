#ifndef CALGEO_MATRICES_H
#define CALGEO_MATRICES_H

#include "CONSTANTS.h"
#include "ComplexNumbers.h"



class Matrix {
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
    Matrix(lli row, lli column) {
        columns = column;
        rows = row;
    }

    Matrix();

    void showMatrix();

    void clearMatrix();

    void randValues(ld min, ld max);

    void setMatrix(vector<vector<ld>> inputMatrix);

    void setMatrix(vector<vector<long long int>> inputMatrix);

    void setMatrix(vector<vector<int>> inputMatrix);

    void setMatrix(vector<vector<float>> inputMatrix);

    void setMatrix(vector<vector<double>> inputMatrix);

    void changeColumns(lli prevColumn, lli nextColumn);

    void changeRows(lli previousRow, lli nextRow);

    void addRows(ld coefficient, lli targetColumn, lli additionColumn);

    void addColumns(ld coefficient, lli targetRow, lli additionRow);

    void tMatrix();

    void triangle(bool side = true);

    ld determinant();

    vector<vector<ld>> matrixRProduct(vector<vector<ld>>);

    vector<vector<ld>> matrixLProduct(vector<vector<ld>>);

    vector<vector<ld>> inverseMatrix();

    vector<vector<ld>> &getMatrix();

    lli getRows() const;

    lli getColumns() const;

    Matrix operator+(Matrix);

    Matrix operator-(Matrix);

    Matrix operator*(Matrix);

    Matrix operator/(Matrix);

    Matrix operator^(int);

    vector<ld> solveEquation(vector<ld> constantT);

    vector<vector<ld>> findGeneralSolution(vector<ld> constantT);

    unsigned int rank();

    unsigned int rankOfExtended(vector<ld> constantT);

    static void showMatrix(vector<vector<ld>> v);

    static void showMatrix(vector<vector<float>> v);

    static void showMatrix(vector<vector<double>> v);

    static void showMatrix(vector<vector<int>> v);

    static void showMatrix(vector<vector<lli>> v);

    static vector<vector<ld>> matrixProduct(vector<vector<ld>>, vector<vector<ld>>, bool side);
};

class cMatrix {
private:
    lli columns;
    lli rows;
    vector<vector<ComplexNumber>> matrix;
public:
    cMatrix(lli row, lli column) {
        columns = column;
        rows = row;
    }

    lli getRows();

    lli getColumns();

    vector<vector<ComplexNumber>> getMatrix();

    void changeColumns(lli prevColumn, lli nextColumn);

    void changeRows(lli previousRow, lli nextRow);

    void addColumns(ComplexNumber coefficient, lli targetColumn, lli additionColumn);

    void addRows(ComplexNumber coefficient, lli targetRow, lli additionRow);

    void randValues(ld min, ld max);

    void showMatrix();

    void setMatrix(vector<vector<ComplexNumber>> inputMatrix);

    unsigned int cRank();

    unsigned int cRankOfExtended(vector<ComplexNumber> constantT);

    ComplexNumber determinant();

    void triangle(bool side = true);

    vector<vector<ComplexNumber>> inverseMatrix();

    vector<ComplexNumber> solveEquation(vector<ComplexNumber> constantT);

    vector<vector<ComplexNumber>> findGeneralSolution(vector<ComplexNumber> constantT);

    cMatrix operator+(cMatrix);

    cMatrix operator-(cMatrix);

    cMatrix operator*(cMatrix);

    cMatrix operator/(cMatrix);

    cMatrix operator^(int);
};


#endif //CALGEO_MATRICES_H
