#include "calgeo.h"
#include "vector"
#include "iostream"
#include "iomanip"
#include "cmath"
#include "exception"

using namespace std;

/*
 * Points
 */
bool isOnLine(vector<vector<ld>> v){
    if(v.empty()) throw logic_error("This function is valid for at least 1 point");
    if(v.size() == 2 || v.size() == 1) return true;

    Line line(subtractionVectors(v[0], v[1]), v[0]);

    for(long long int i = 2; i < v.size(); i++){
        if(!line.isPointBelong(v[i])) return false;
    }

    return true;
}

bool isOnPlane(vector<vector<ld>> v){
    if(v.empty()) throw logic_error("This function is valid for at least 1 point");
    if(!v.empty() && v.size() <= 3) return true;

    Plane plane(vectorProduct(subtractionVectors(v[0], v[1]), subtractionVectors(v[0], v[2])), v[0]);

    for(long long int i = 3; i < v.size(); i++){
        if(!plane.isPointBelong(v[i])) return false;
    }

    return true;
}

/*
 * Vectors
 */
ld vectorLength(const vector<ld>& v){
    ld result = 0;

    for(ld i : v){
        result += pow(i, 2);
    }

    return sqrt(result);
}


ld scalarProduct(vector <ld> v1, vector <ld> v2){
    try{
    if (v1.size()!=v2.size()) throw 1;

    const unsigned int sizeOfVectors = v1.size();
    ld s = 0;

    for (ui i=0; i < sizeOfVectors; i++){
        s+=v1[i]*v2[i];
        }
    return s;
    }

    catch (int){
        cout<<"Different vector bases"<<endl;
        return 0;
    }
}


/**
 * This function takes two vectors as an arguments and returns the angle between them in radians.
 * @param vector1
 * @param vector2
 * @return angle in radians
 */
ld angle(const vector<ld>& vector1, const vector<ld>& vector2){ //needs to be done pi
        if(vector1.size() != vector2.size()) throw logic_error("Vectors have different dimensions!");
        return acos( scalarProduct(vector1, vector2) / (vectorLength(vector1) * vectorLength(vector2)) );
}


vector<ld> vectorProduct(vector<ld> vector1, vector<ld> vector2){
    vector<ld> result = {};
    if(vector1.size() != vector2.size()) throw logic_error("Vectors have different dimensions!");

    result.push_back(vector1[1] * vector2[2] - vector1[2] * vector2[1]);
    result.push_back(vector1[2] * vector2[0] - vector1[0] * vector2[2]);
    result.push_back(vector1[0] * vector2[1] - vector1[1] * vector2[0]);

    return result;
}


vector<ld> addVectors(vector<ld> vector1, vector<ld> vector2){
    vector<ld> result;
    if(vector1.size() != vector2.size()) throw logic_error("Vectors have different dimensions!");

    for(ui i = 0; i < vector1.size(); i++){
        result.push_back(vector1[i] + vector2[i]);
    }

    return result;
}

vector<ld> subtractionVectors(vector<ld> v1, vector <ld> v2){
    vector <ld> answer;
    if (v1.size()!=v2.size()) throw logic_error("Vectors have different dimensions!");

    const unsigned int sizeOfVectors = v1.size();
    ld s = 0;

    for (ui i=0;i<sizeOfVectors;i++){
        answer.push_back(v1[i]-v2[i]);
    }
    return answer;
}

vector<ld> vectorNormalization(vector<ld> v){
    vector<ld> normalized;

    if(vectorLength(v) == 0) throw logic_error("Vector cannot be normalized!");

    ld t = 0;

    for(long double i : v){
        t += pow(i, 2);
    }

    t = sqrt(t);
    normalized.reserve(v.size());
    for(long double i : v){
        normalized.push_back(i / t);
    }

    return normalized;
}

/*
 * Complex numbers
 */

void ComplexNumber::setRealPart(ld r){realPart = r;}
void ComplexNumber::setImaginaryPart(ld i){imaginaryPart = i;}
void ComplexNumber::showNumber(){cout.precision(1); cout << fixed << realPart << (imaginaryPart >= 0 ? "+" : "") << imaginaryPart << "i";}

ld ComplexNumber::length(){return sqrt(realPart * realPart + imaginaryPart * imaginaryPart);}

ComplexNumber multiplicativeInverse(ComplexNumber z){
    ld sq = pow(z.getRealPart(), 2) + pow(z.getImaginaryPart(), 2);
    if(sq == 0) throw logic_error("You can't divide by 0");
    ComplexNumber inverse(z.getRealPart() / sq, (-1) * z.getImaginaryPart() / sq);
    return inverse;
}

ComplexNumber multiplyComplexNumber(ComplexNumber z, ld alpha){
    z.setRealPart(z.getRealPart() * alpha);
    z.setImaginaryPart(z.getImaginaryPart() * alpha);
    return z;
}

ComplexNumber complexConjugate(ComplexNumber z){
    ComplexNumber conjugate(z.getRealPart(), (-1) * z.getImaginaryPart());
    return conjugate;
}
/*
ComplexNumber complexOpposite(ComplexNumber z){
    
}*/
ld ComplexNumber::getRealPart(){
    return realPart;
}

ld ComplexNumber::getImaginaryPart(){
    return imaginaryPart;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber z){
    ComplexNumber z1(realPart + z.getRealPart(), imaginaryPart + z.getImaginaryPart());
    return z1;
}
ComplexNumber ComplexNumber::operator-(ComplexNumber z){
    ComplexNumber z1(realPart - z.getRealPart(), imaginaryPart - z.getImaginaryPart());
    return z1;
}
ComplexNumber ComplexNumber::operator*(ComplexNumber z){//come again
    ComplexNumber result(realPart * z.getRealPart() - imaginaryPart * z.getImaginaryPart(),
                         realPart * z.getImaginaryPart() + imaginaryPart * z.getRealPart());
    return result;
}
ComplexNumber ComplexNumber::operator/(ComplexNumber z){return (*this) * multiplicativeInverse(z);}
bool ComplexNumber::operator==(ComplexNumber z){return (realPart == z.getRealPart()) && (imaginaryPart == z.getImaginaryPart());}
bool ComplexNumber::operator!=(ComplexNumber z){return (realPart != z.getRealPart() || imaginaryPart != z.getImaginaryPart());}
void ComplexNumber::operator=(ComplexNumber z){realPart = z.getRealPart(); imaginaryPart = z.getImaginaryPart();}
ComplexNumber ComplexNumber::operator+=(ComplexNumber z){
    ComplexNumber k(realPart + z.getRealPart(), imaginaryPart + z.getImaginaryPart());
    return k;
}
ComplexNumber ComplexNumber::operator-=(ComplexNumber z){
    ComplexNumber k(realPart - z.getRealPart(), imaginaryPart - z.getImaginaryPart());
    return k;
}

/*
 * Lines
 */
Line::Line(const vector<ld>& direct_answer, const vector<ld>& point_answer){
        if (direct_answer.size() != point_answer.size()) throw logic_error("Vectors have different dimensions!");

        bool checkfor0 = true;
        for (long double i : direct_answer) {
            if (i != 0) checkfor0 = false;
        }
        if (checkfor0) throw logic_error("Directing vector cannot be zero!");

        direct=direct_answer;
        point=point_answer;
}

vector <ld> Line::getDirectV(){return direct;}
vector <ld> Line::getDefPoint(){return point;}

bool Line::isPointBelong(const vector <ld>& p){
    if(p.size() != point.size()) {
        throw logic_error("Points have different dimensions!");
    }

    vector<ld> parameters;
    for(ui i = 0; i < direct.size(); i++){
        if(direct[i] == 0 && p[i] != point[i]){
            return false;
        }else if(direct[i] != 0){
            parameters.push_back((point[i] - p[i]) / direct[i]);
        }
    }
     for(ui i = 0; i < parameters.size(); i++){
         for(ui j = i + 1; j < parameters.size(); j++){
             if(parameters[i] != parameters[j]){
                 return false;
             }
         }
     }

     return true;
}

bool Line::isPerpendicular(Line line) {return scalarProduct(direct, line.getDirectV()) == 0;}
bool Line::isOnOnePlane(Line line) {return scalarProduct(vectorProduct(direct, line.getDirectV()), subtractionVectors(point, line.getDefPoint())) == 0;}

bool Line::isParallel(Line input){
    if ((angle(input.getDirectV(),direct)==0) && isOnOnePlane(input)) return 1;
    else return 0;
}

bool Line::isCross(Line input){
    if ((angle(input.direct,direct)!=0)&& isOnOnePlane(input)) return 1;
    else return 0;
}

vector<ld> pointLineCross(Line line1, Line line2){
    vector<ld> answer, consts;
    vector<vector<ld>> v;
    Matrix m(3, 2);
    for(lli i = 0; i < 3; i++){
        v.push_back({(line1.getDirectV())[i] , -(line2.getDirectV()[i])});
        consts.push_back( line2.getDefPoint()[i] - line1.getDefPoint()[i] );
    }
    m.setMatrix(v);
    ld t = m.solveEquasion(consts)[0];
    for(lli i = 0; i < 3; i++){
        answer.push_back( line1.getDirectV()[i] * t + line1.getDefPoint()[i] );
    }
    return answer;
}

/*
 * Plane
 */
/**
 *
 * @param d
 * @param p
 */
Plane::Plane(vector<ld> d, vector<ld> p){
    if(vectorLength(d) == 0) throw logic_error("Direct vector cannot be zero!");
    direct = d;
    point = p;
}

bool Plane::isParallel(Line line){return scalarProduct(line.getDirectV(), direct) == 0;}//What if line lies in plane

bool Plane::isParallel(Plane plane){//needs to be revised
    if (angle(plane.getDirectPlane(),direct)== 0) return 1;
    for (long double & i : direct){
        i*=-1;
    }
    if (angle(plane.getDirectPlane(),direct)== 0) return 1;
    else return 0;
}

vector <ld> Plane::getDirectPlane(){return direct;}

vector <ld> Plane::getPointPoint(){return point;}

bool Plane::isPointBelong(vector <ld> input){
    if(input.size()!=direct.size()) throw logic_error("Wrong dimension!");

    ld sum =0;
    for (int i=0; i<direct.size();i++){
        sum+=direct[i]*(input[i]-point[i]);
    }
    if (sum==0) return 1;
    else return 0;
}

bool Plane::isPerpendicular(Line line){
    if (abs(abs(scalarProduct(line.getDirectV(),direct)) - vectorLength(line.getDirectV()) * vectorLength(direct)) < accuracy) return 1;
    else return 0;
}

/*
 * Quadrics
 */

bool Elipsoid::isPointBelongs(vector<ld> v){
    if(v.size() != coeficients.size()) throw logic_error("Different dimensions!");
    if(!isEquasionCanonic()) throw logic_error("Equasion is not canonic!");

    ld t = 0;
    for(ui i = 0; i < v.size(); i++){
        t += pow(v[i]/coeficients[i], 2);
    }

    return t == 1;
}

bool Elipsoid::isEquasionCanonic(){
    bool result= true;
    for(int i=0; i< coeficients.size();i++){
        if (coeficients[i]==0) {result=false;break;}
    }
    return result;
}

ld Elipsoid::findExcetricity(){
    ld result;
    if(coeficients.size()==2){
        if(coeficients[0]>coeficients[1])
            result = pow(pow(coeficients[0],2)-pow(coeficients[1],2),0.5)/coeficients[0];
        else result = pow(-pow(coeficients[0],2)+pow(coeficients[1],2),0.5)/coeficients[0];
    }
    else throw logic_error("i dont know D:");
    return result;
}

vector<pair<string, ld>> Elipsoid::findDirectrix(){
    if(!isEquasionCanonic()) throw logic_error("Equasion is not canonic!");

    vector<pair<string, ld>> result;
    pair<string, ld> resultSmall;
    if(coeficients.size() == 2){
        resultSmall = pair<string, ld>("x" , coeficients[0] * coeficients[0] / findExcetricity());
        result.push_back(resultSmall);
    }else{
        throw logic_error("Coming soon...");
    }

    return result;
}


using namespace std;

void Matrix::setMatrix(vector<vector<ld>> inputMatrix){
    matrix.clear();
    for (int i = 0; i < rows - 1; i++) {
        if (inputMatrix[i].size() != inputMatrix[i + 1].size()) throw logic_error("Different size of rows!");
    }
    //if (inputMatrix.size() != rows || inputMatrix[0].size() != columns) throw logic_error("Different size!");

    matrix.clear();
    vector<ld> temp;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            temp.push_back(inputMatrix[j][i]);
        }
        matrix.push_back(temp);
        temp.clear();
    }
}

void Matrix::setMatrix(vector<vector<long long int>> inputMatrix) {
    for (int i = 0; i < rows - 1; i++) {
        if (inputMatrix[i].size() != inputMatrix[i + 1].size()) throw logic_error("Different size of rows!");
    }
    if (inputMatrix.size() != rows || inputMatrix[0].size() != columns) throw logic_error("Different size!");

    matrix.clear();
    vector<ld> temp;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            temp.push_back( (ld) inputMatrix[j][i]);
        }
        matrix.push_back(temp);
        temp.clear();
    }
}

void Matrix::setMatrix(vector<vector<int>> inputMatrix) {
    for (int i = 0; i < rows - 1; i++) {
        if (inputMatrix[i].size() != inputMatrix[i + 1].size()) throw logic_error("Different size of rows!");
    }
    if (inputMatrix.size() != rows || inputMatrix[0].size() != columns) throw logic_error("Different size!");

    matrix.clear();
    vector<ld> temp;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            temp.push_back( (ld) inputMatrix[j][i]);
        }
        matrix.push_back(temp);
        temp.clear();
    }
}

void Matrix::setMatrix(vector<vector<float>> inputMatrix) {
    for (int i = 0; i < rows - 1; i++) {
        if (inputMatrix[i].size() != inputMatrix[i + 1].size()) throw logic_error("Different size of rows!");
    }
    if (inputMatrix.size() != rows || inputMatrix[0].size() != columns) throw logic_error("Different size!");

    matrix.clear();
    vector<ld> temp;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            temp.push_back( (ld) inputMatrix[j][i]);
        }
        matrix.push_back(temp);
        temp.clear();
    }
}

void Matrix::setMatrix(vector<vector<double>> inputMatrix) {
    for (int i = 0; i < rows - 1; i++) {
        if (inputMatrix[i].size() != inputMatrix[i + 1].size()) throw logic_error("Different size of rows!");
    }
    if (inputMatrix.size() != rows || inputMatrix[0].size() != columns) throw logic_error("Different size!");

    matrix.clear();
    vector<ld> temp;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            temp.push_back( (ld) inputMatrix[j][i]);
        }
        matrix.push_back(temp);
        temp.clear();
    }
}


/**
 * This method belongs to the class 'Matrix'. It shows the object itself.
 */
void Matrix::showMatrix(){//maybe add as parameters precision and whitespaces
    cout.precision(sci);

    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < columns; j++)
            cout << setw(22) << matrix[i][j];
        cout << endl;
    }
}

/**
 * This is the function, which shows any matrix.
 * @param v – user matrix;
 */
void showMatrix(vector<vector<ld>> v){
    cout.precision(2);

    for(lli i = 0; i < v.size(); i++){
        for(lli j = 0; j < v[0].size(); j++)
            cout << setw(7) << v[i][j];
        cout << endl;
    }
}
void showMatrix(vector<vector<float>> v){
    cout.precision(2);

    for(lli i = 0; i < v.size(); i++){
        for(lli j = 0; j < v[0].size(); j++)
            cout << setw(7) << v[i][j];
        cout << endl;
    }
}
void showMatrix(vector<vector<double>> v){
    cout.precision(5);

    for(lli i = 0; i < v.size(); i++){
        for(lli j = 0; j < v[0].size(); j++)
            cout << setw(7) << v[i][j];
        cout << endl;
    }
}
void showMatrix(vector<vector<int>> v){
    cout.precision(5);

    for(lli i = 0; i < v.size(); i++){
        for(lli j = 0; j < v[0].size(); j++)
            cout << setw(7) << v[i][j];
        cout << endl;
    }
}
void showMatrix(vector<vector<long long int>> v){
    cout.precision(5);

    for(lli i = 0; i < v.size(); i++){
        for(lli j = 0; j < v[0].size(); j++)
            cout << setw(7) << v[i][j];
        cout << endl;
    }
}

/**
 * Function generates random matrix by assigning values between absolute max and min value to its elements.
 * @param a – the initial square matrix
 * @param maxW – the number of columns in the matrix at the end of the call
 * @param maxH – the number of rows in the matrix at the end of the call
 */
void Matrix::randValues(ld minValue, ld maxValue){
    matrix.clear();
    vector<ld> vSmall;

    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < columns; j++){
            vSmall.push_back(rand() / (ld) RAND_MAX  * (maxValue - minValue + 1) + minValue);
        }
        matrix.push_back(vSmall);
        vSmall.clear();
    }
}
/**
 * This function changes places of previous and next column
 * @param a – the matrix itself
 * @param prevColumn – previous column
 * @param nextColumn – next column
 */
void Matrix::changeColumns(lli prevColumn, lli nextColumn){
    if(prevColumn < 0 || prevColumn > columns || nextColumn < 0 || nextColumn > columns){
        throw logic_error("Column is out of boundaries!");
    }

    ld t;

    for(lli i = 0; i < rows; i++){
        t = matrix[i][nextColumn];
        matrix[i][nextColumn] = matrix[i][prevColumn];
        matrix[i][prevColumn] = t;
    }
}

/**
 * This function changes places of next and previous row
 * @param a – the matrix itself
 * @param previousRow – the previous row
 * @param nextRow – the next row
 */
void Matrix::changeRows(lli previousRow, lli nextRow){
    if(previousRow < 0 || previousRow > rows || nextRow < 0 || nextRow > rows){
        throw logic_error("Row is out of boundaries!");
    }

    ld t = 0;

    for(lli i = 0; i < columns; i++){
        t = matrix[nextRow][i];
        matrix[nextRow][i] = matrix[previousRow][i];
        matrix[previousRow][i] = t;
    }
}

void Matrix::addRows(ld coefficient, lli targetRow, lli additionRow){
    if(targetRow < 0 || targetRow > rows || additionRow < 0 || additionRow > rows){
        throw logic_error("Rows out of boundaries!");
    }

    for(lli i = 0; i < columns; i++){
        matrix[targetRow][i] += coefficient * (matrix[additionRow][i]);
        if (fabs(matrix[targetRow][i]) < accuracy) matrix[targetRow][i]=0;
    }
}

void Matrix::addColumns(ld coefficient, lli targetColumn, lli additionColumn){
    if(targetColumn < 0 || targetColumn > columns || additionColumn < 0 || additionColumn > columns){
        throw logic_error("Columns are out of boundaries!");
    }

    for(lli i = 0 ; i < rows; i++){
        matrix[i][targetColumn] += coefficient * (matrix[i][additionColumn]);
        if (fabs(matrix[targetColumn][i])< accuracy) matrix[targetColumn][i]=0;
    }
}

/**
 * This function is very useful
 * @param a
 * @param w
 * @param h
 */
void Matrix::tMatrix(){

    vector<vector<ld>> newV;
    vector<ld> newSmallV;
    for(lli i = 0; i < columns; i++){
        for(lli j = 0; j < rows; j++){
            newSmallV.push_back(matrix[j][i]);
        }
        newV.push_back(newSmallV);
        newSmallV.clear();
    }


    lli k;
    k = rows;
    rows = columns;
    columns = k;

    matrix.clear();
    matrix = newV;
}

vector<vector<ld>> & Matrix::getMatrix() {return matrix;}
lli Matrix::getRows() const {return rows;}
lli Matrix::getColumns() const {return columns;}

void Matrix::triangle(bool side){
    if(side) {
        lli i = 0;
        lli g = 0;
        while (g < columns && i < rows) {
            for (lli s = i + 1; s < rows; s++) {
                if (matrix[i][g] != 0) break;
                else changeRows(i, s);
            }
            if (matrix[i][g] != 0) {
                for (lli j = i + 1; j < rows; j++) {
                    addRows((-1) / matrix[i][g] * matrix[j][g], j, i);
                }
                i++;
            }
            g++;
        }
    }
    else{
        lli i = rows-1;
        lli g = columns-1;
        while (g >= 0 && i >= 0) {
            for (lli s = i - 1; s >= 0; s--) {
                if (matrix[i][g] != 0) break;
                else changeRows(i, s);
            }
            if (matrix[i][g] != 0) {
                for (lli j = i - 1; j >= 0; j--) {
                    addRows((-1) / matrix[i][g] * matrix[j][g], j, i);
                }
                i--;
            }
            g--;
        }
    }
}

/* This is another algorithm for making matrix triangle-looking
void Matrix::triangle(bool side) {
    if(side){
       lli currentRow = 0;
       lli currentColumn = 0;

       while(currentRow < rows && currentColumn < columns){
           if(matrix[currentRow][currentColumn] == 0){
               for(lli i = currentRow + 1; i < rows; i++){
                   if(matrix[i][currentColumn] != 0){
                       changeRows(currentRow, i);
                       break;
                   }
               }
           }

           for(lli i = currentRow + 1; i < rows; i++){
               addRows((-1) * matrix[i][currentColumn] / matrix[currentRow][currentColumn], i, currentRow);
           }

           currentRow++;
           currentColumn++;

       }

    }else{
        lli currentRow = rows - 1;
        lli currentColumn = columns - 1;

        while(currentRow >= 0 && currentColumn >= 0){
            if(matrix[currentRow][currentColumn] == 0){
                for(lli i = currentRow - 1; i >= 0; i--){
                    if(matrix[i][currentColumn] != 0){
                        changeRows(currentRow, i);
                        break;
                    }
                }
            }

            for(lli i = currentRow - 1; i >= 0; i--){
                addRows((-1) * matrix[i][currentColumn] / matrix[currentRow][currentColumn], i, currentRow);
            }
            currentRow--;
            currentColumn--;
        }
    }
}*/

ld Matrix::determinant() {
    ld d = 1;
    if(rows != columns) throw logic_error("Matrix must be triangle!");

    vector<vector<ld>> v;
    v = matrix;
    triangle(true);

    for(lli i = 0; i < rows; i++){
        d *= matrix[i][i];
    }

    matrix = v;
    return d;
}

/**
 * This function returns a matrix which itself is a result of right-side product of 'matrix' * 'v'
 * @param v – user's matrix
 * @return new matrix
 */
vector<vector<ld>> Matrix::matrixRProduct(vector<vector<ld>> v){
    vector<vector<ld>> product;

    if(columns != v.size()){
        throw logic_error("Matrices have different dimensions!"); //We can't perform multiplication of such matrix
    }

    vector<ld> productSmall;
    ld t = 0;
    for(lli i = 0; i < rows; i++){
        for(lli k = 0; k < v[0].size(); k++){
            for(lli j = 0; j < columns; j++){
                t += matrix[i][j] * v[j][k];
            }
            productSmall.push_back(t);
            t = 0;
        }
        product.push_back(productSmall);
        productSmall.clear();
    }

    return product;
}


/**
 * This function returns a matrix which itself is a result of left-side product of 'v' * 'matrix'
 * @param v – user's matrix
 * @return new matrix
 */
vector<vector<ld>> Matrix::matrixLProduct(vector<vector<ld>> v){
    vector<vector<ld>> product;

    if(rows != v[0].size()){
        throw logic_error("Matrices have different dimensions!"); //We can't perform multiplication of such matrix
    }

    vector<ld> productSmall;
    ld t = 0;
    for(lli i = 0; i < v.size(); i++){
        for(lli k = 0; k < columns; k++){
            for(lli j = 0; j < v[0].size(); j++){
                t += v[i][j] * matrix[j][k];
            }
            productSmall.push_back(t);
            t = 0;
        }
        product.push_back(productSmall);
        productSmall.clear();
    }

    return product;
}

vector<vector<ld>> Matrix::inverseMatrix() {
    vector<vector<ld>> result;
    vector<vector<ld>> copy = matrix;

    if(determinant() == 0 || rows != columns) throw logic_error("The inverse matrix doesn't exist!");

    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < columns; j++){
            if(i == j){
                matrix[i].push_back(1);
            }else{
                matrix[i].push_back(0);
            }
        }
    }

    columns = columns * 2;

    triangle();

    lli i = rows - 1;
    lli g = columns - columns / 2 -1;
    while (g >= 0 && i >= 0) {
        for (lli s = i - 1; s >= 0; s--) {
            if (matrix[i][g] != 0) break;
            else changeRows(i, s);
        }
        if (matrix[i][g] != 0) {
            for (lli j = i - 1; j >= 0; j--) {
                addRows((-1) / matrix[i][g] * matrix[j][g], j, i);
            }
            i--;
        }
        g--;
    }
    /*
    lli currentRow = rows - 1;
    lli currentColumn = columns - columns / 2 - 1;

    while(currentRow >= 0 && currentColumn >= 0){
        if(matrix[currentRow][currentColumn] == 0){
            for(lli i = currentRow - 1; i >= 0; i--){
                if(matrix[i][currentColumn] != 0){
                    changeRows(currentRow, i);
                    break;
                }
            }
        }

        for(lli i = currentRow - 1; i >= 0; i--){
            addRows((-1) * matrix[i][currentColumn] / matrix[currentRow][currentColumn], i, currentRow);
        }
        currentRow--;
        currentColumn--;
    }
    */

    vector<ld> resultSmall;
    for(lli k = 0; k < rows; k++){
        for(lli j = columns / 2; j < columns; j++){
            resultSmall.push_back(matrix[k][j] / matrix[k][k]);
        }
        result.push_back(resultSmall);
        resultSmall.clear();
    }

    columns /= 2;

    matrix.clear();
    matrix = copy;

    return result;
}

void Matrix::clearMatrix() {matrix.clear();}


/**
 * Function returns the matrix which itself is a product of matrix1 and matrix2.
 * @param matrix1
 * @param matrix2
 * @param side – if 'false' then (matrix2) * (matrix1), else then (matrix1) * (matrix2). By default set as 'true'
 * @return
 */
vector<vector<ld>> matrixProduct(vector<vector<ld>> matrix1, vector<vector<ld>> matrix2, bool side) {
    vector<vector<ld>> product;
    if(side){
        if(matrix1[0].size() != matrix2.size()){
            throw logic_error("Matrices have different dimensions!"); //We can't perform multiplication of such matrix
        }

        vector<ld> productSmall;
        ld t = 0;
        for(lli i = 0; i < matrix1.size(); i++){
            for(lli k = 0; k < matrix2[0].size(); k++){
                for(lli j = 0; j < matrix1[0].size(); j++){
                    t += matrix1[i][j] * matrix2[j][k];
                }
                productSmall.push_back(t);
                t=0;
            }
            product.push_back(productSmall);
            productSmall.clear();
        }
    }else{

        if(matrix2[0].size() != matrix1.size()){
            throw logic_error("Matrices have different dimensions!"); //We can't perform multiplication of such matrix
        }

        vector<ld> productSmall;
        ld t = 0;
        for(lli i = 0; i < matrix2.size(); i++){
            for(lli k = 0; k < matrix1[0].size(); k++){
                for(lli j = 0; j < matrix2[0].size(); j++){
                    t += matrix2[i][j] * matrix1[j][k];
                }
                productSmall.push_back(t);
                t=0;
            }
            product.push_back(productSmall);
            productSmall.clear();
        }
    }

    return product;
}

Matrix Matrix::operator+(Matrix m){
    if(rows != m.getRows() || columns != m.getColumns()) throw logic_error("Matrices must be of the same size!");

    Matrix result(m.getRows(), m.getColumns());

    vector<vector<ld>> copyM = m.getMatrix();
    vector<vector<ld>> z;
    vector<ld> smallZ;
    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < columns; j++){
            smallZ.push_back(matrix[i][j] + copyM[i][j]);
        }
        z.push_back(smallZ);
        smallZ.clear();
    }

    result.setMatrix(z);

    return result;
}
Matrix Matrix::operator-(Matrix m){
    if(rows != m.getRows() || columns != m.getColumns()) throw logic_error("Matrixes must be of the same size!");

    Matrix result(m.getRows(), m.getColumns());

    vector<vector<ld>> copyM = m.getMatrix();
    vector<vector<ld>> z;
    vector<ld> smallZ;
    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < columns; j++){
            smallZ.push_back(matrix[i][j] - copyM[i][j]);
        }
        z.push_back(smallZ);
        smallZ.clear();
    }

    return result;
}
Matrix Matrix::operator*(Matrix m) {
    Matrix result (rows,m.getColumns());

    if( columns!=m.getRows() ) {
        throw logic_error("Matrices have different dimensions!"); //We can't perform multiplication of such matrix
    }

    vector<ld> productSmall;
    ld t = 0;
    for(lli i = 0; i < rows; i++){
        for(lli k = 0; k < m.getColumns(); k++){
            for(lli j = 0; j < columns; j++){
                t += matrix[i][j] * m.matrix[j][k];
            }
            if(abs(t)>accuracy) productSmall.push_back(t);
            else productSmall.push_back(0);
            t = 0;
        }
        result.matrix.push_back(productSmall);
        productSmall.clear();
    }
    return result;
}
Matrix Matrix::operator/(Matrix m){
    if(m.getRows() != m.getColumns()) throw logic_error("Only square matrixes!");
    if( columns != m.getRows() ) throw logic_error("Matrices have different dimensions!");

    Matrix newM(m.getRows(), m.getRows());
    newM.setMatrix(m.inverseMatrix());
    return (*this) * newM;
}
Matrix Matrix::operator^(int power){
    Matrix result(rows,columns);

    if (rows!=columns) throw logic_error("You can use only squere matrix!");

    if (power == 0) {
        Matrix z(rows,columns);
        z.setMatrix((*this).inverseMatrix());
        result = ((*this) * z);
    }
    else if(power >0) {
        Matrix copy(rows,columns);
        copy.setMatrix(matrix);
        result.setMatrix(matrix);
        for (int i = 1; i < power; i++) {
            result=result*copy;
        }
    }
    else if (power <0){
        Matrix copy (rows,columns);
        copy.setMatrix(inverseMatrix());
        result.setMatrix(copy.getMatrix());
        for (int i = -1; i > power; i--) {
            result=result*copy;
        }
    }
    return result;
}

vector<ld> Matrix::solveEquasion(vector<ld> constantT){
    vector<ld>result={};
    unsigned int rank =(*this).rank();

    if(rank!=(*this).rankofExtended(constantT)){
        cout<<"System does not have solutions (rank of matrix != rank of extended matrix)"<<endl;
    }
    else if ((rank<columns)&&(rank==(*this).rankofExtended(constantT))){
        throw logic_error("Endless number of solutions! Use findGeneralSolution() instead");
    }
    else {
        Matrix copy(rows,columns);
        copy.setMatrix(matrix);

        lli i = rows - 1;
        lli g = columns - 1;
        while (g >= 0 && i >= 0) {
            for (lli s = i - 1; s >= 0; s--) {
                if (copy.matrix[i][g] != 0) break;
                else copy.changeRows(i, s);
                ld d = constantT[s];
                constantT[s] = constantT[i];
                constantT[i] = d;

            }
            if (copy.matrix[i][g] != 0) {
                lli j;
                ld c;
                for (j = i - 1; j >= 0; j--) {
                    c = (-1) / copy.matrix[i][g] * copy.matrix[j][g];
                    copy.addRows(c, j, i);
                    constantT[j] += constantT[i] * c;
                }
                i--;
            }
            g--;
        }

        i = 0;
        g = 0;
        while (g < columns && i < rows) {
            for (lli s = i + 1; s < rows; s++) {
                if (copy.matrix[i][g] != 0) break;
                else copy.changeRows(i, s);

                ld d = constantT[i];
                constantT[i] = constantT[s];
                constantT[s] = d;
            }
            if (copy.matrix[i][g] != 0) {
                lli j;
                ld c;
                for (j = i + 1; j < rows; j++) {
                    c = (-1) / copy.matrix[i][g] * copy.matrix[j][g];
                    copy.addRows(c, j, i);
                    constantT[j] += constantT[i] * c;
                }

                i++;
            }
            g++;
        }

        for (int i = 0; i < columns; i++) {
            // cout << constantT[i] << endl;
            if(abs(constantT[i] / copy.matrix[i][i])>accuracy) {
                result.push_back(constantT[i] / copy.matrix[i][i]);
            }else result.push_back(0);
        }
    }
    return result;
}

vector<vector<ld>> Matrix::findGeneralSolution(vector<ld> constantT){
    vector<vector<ld>>result;
    unsigned int rank =(*this).rank();

    if(rank!=(*this).rankofExtended(constantT)){
        cout<<"System does not have solutions (rank of matrix != rank of extended matrix)"<<endl;
        return result;
    }
    else if(rank>columns){
        cout<<"System does not have solutions"<<endl;
        return result;
    }
    else if ((rank==columns)&&(rank==(*this).rankofExtended(constantT))) {
        result.push_back((*this).solveEquasion(constantT));
        return result;
    }
    else if ((rank<columns)&&(rank==(*this).rankofExtended(constantT))) {
        Matrix input(rows, columns);
        input.setMatrix(matrix);
        vector<ld> copyofinput = constantT;

        lli i = 0;
        lli g = 0;
        while (g < columns && i < rows) {
            for (lli s = i + 1; s < rows; s++) {
                if (input.matrix[i][g] != 0) break;
                else input.changeRows(i, s);

                ld d = constantT[i];
                constantT[i] = constantT[s];
                constantT[s] = d;
            }
            if (input.matrix[i][g] != 0) {
                lli j;
                ld c;
                for (j = i + 1; j < rows; j++) {
                    c = (-1) / input.matrix[i][g] * input.matrix[j][g];
                    input.addRows(c, j, i);
                    constantT[j] += constantT[i] * c;
                }

                i++;
            }
            g++;
        }

        int freevariables= columns-rank;
        Matrix copy(rank,rank);
        vector<int> indexbasic; //Indexes of basic and free variables
        vector<int> indexfree;
        int c=0,r=0;
        for(; columns > c; c++){
            if(r<rows){
                if(input.matrix[r][c]!=0){
                    indexbasic.push_back(c);
                    r++;
                }else {
                    indexfree.push_back(c);
                }
            }
            else {
                indexfree.push_back(c);
            }
        }

        for(int i=0;i<indexbasic.size();i++){
            if(i!=indexbasic[i]){
                input.changeColumns(i,indexbasic[i]);
            }
        }

        vector<ld> temp;
        for (int j = 0; j < rank; j++) {
            for (int i = 0; i < rank; i++) {
                temp.push_back( (ld) input.matrix[j][i]);
            }
            copy.matrix.push_back(temp);
            temp.clear();
        }

        {   //finds partial solution
            vector <ld> t=copy.solveEquasion(constantT);
            vector <ld> tempresult;
            for(int i=0,j=0,h=0;h<columns;h++){
                if(i<indexbasic.size()){
                    if(h==indexbasic[i]){
                        tempresult.push_back(t[i]);
                        i++;
                    }else {
                        tempresult.push_back(0);
                        j++;
                    }
                }
                else {
                    tempresult.push_back(0);
                    j++;
                }
            }
            result.push_back(tempresult);
        }

        //finds solutions when one of the free variables equals to 1 and other to 0
        for(int k=0,b=rank;k<indexfree.size();k++){
            vector <ld> copyfree=constantT;
            for(int j =0; j<copy.rows;j++){
                copyfree[j]=(-1)*input.matrix[j][b];
            }
            b++;
            vector <ld> t=copy.solveEquasion(copyfree);
            vector <ld> tempresult;
            for(int n=0,j=0,h=0; h < columns; h++){
                if(n<indexbasic.size()){
                    if(h==indexbasic[n]){
                        tempresult.push_back(t[n]);
                        n++;
                    }else if(h==indexfree[k]){
                        tempresult.push_back(1);
                        j++;
                    }else {
                        tempresult.push_back(0);
                        j++;
                    }
                }
                else if(h==indexfree[k]){
                    tempresult.push_back(1);
                    j++;
                }
                else {
                    tempresult.push_back(0);
                    j++;
                }
            }
            result.push_back(tempresult);
        }
    }

    // result[0] = partial solution
    // other elements in result = vectors of the fundamental system of solutions
    return result;
}

unsigned int Matrix::rank(){
    unsigned int result=0;

    Matrix copy(rows,columns);
    copy.setMatrix(matrix);
    copy.triangle(true);
    for(lli i = 0; i<rows; i++ ){
        for(lli j = columns-1; j>=0;j--){
            if (copy.matrix[i][j]!=0) {
                result++;
                break;
            }
            else if (j==0) return result;
        }
    }
    return result;
}

unsigned int Matrix::rankofExtended(vector<ld> constantT){
    Matrix copy(rows,columns+1);

    vector<ld> temp;
    vector<vector<ld>> copyex;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            temp.push_back( (ld) (*this).matrix[j][i]);
        }
        copyex.push_back(temp);
        copyex[j].push_back(constantT[j]);
        temp.clear();
    }

    copy.setMatrix(copyex);
    return copy.rank();
}

void cMatrix::showMatrix() {
    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < columns; j++){
            cout << setw(10);
            matrix[i][j].showNumber();
        }
        cout << endl;
    }
}

lli cMatrix::getRows() {return rows;}
lli cMatrix::getColumns(){return columns;}
vector<vector<ComplexNumber>> cMatrix::getMatrix(){return matrix;}

void cMatrix::randValues(ld min, ld max){
    vector<ComplexNumber> smallMatrix;
    ComplexNumber z;
    for(lli j = 0; j < rows; j++){
        for(lli k = 0; k < columns; k++){
            z.setRealPart( (ld) rand() / RAND_MAX * (max - min + 1)* pow(-1, rand() % 100) ) ;
            z.setImaginaryPart( (ld) rand() / RAND_MAX * (max - min + 1) * pow(-1, rand() % 100) );
            smallMatrix.push_back(z);
        }
        matrix.push_back(smallMatrix);
        smallMatrix.clear();
    }
}
void cMatrix::setMatrix(vector<vector<ComplexNumber>> inputMatrix){
    matrix.clear();
    for (int i = 0; i < rows - 1; i++) {
        if (inputMatrix[i].size() != inputMatrix[i + 1].size()) throw logic_error("Different size of rows!");
    }
    if (inputMatrix.size() != rows || inputMatrix[0].size() != columns) throw logic_error("Different size!");

    matrix.clear();
    vector<ComplexNumber> temp;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            temp.push_back(inputMatrix[j][i]);
        }
        matrix.push_back(temp);
        temp.clear();
    }
}


void cMatrix::changeColumns(lli prevColumn, lli nextColumn){
    if(prevColumn < 0 || prevColumn > columns || nextColumn < 0 || nextColumn > columns){
        throw logic_error("Column is out of boundaries!");
    }

    ComplexNumber t;

    for(lli i = 0; i < rows; i++){
        t = matrix[i][nextColumn];
        matrix[i][nextColumn] = matrix[i][prevColumn];
        matrix[i][prevColumn] = t;
    }
}
void cMatrix::changeRows(lli previousRow, lli nextRow){
    if(previousRow < 0 || previousRow > rows || nextRow < 0 || nextRow > rows){
        throw logic_error("Row is out of boundaries!");
    }

    ComplexNumber t;

    for(lli i = 0; i < columns; i++){
        t = matrix[nextRow][i];
        matrix[nextRow][i] = matrix[previousRow][i];
        matrix[previousRow][i] = t;
    }
}

void cMatrix::addColumns(ComplexNumber coefficient, lli targetColumn, lli additionColumn){
    if(targetColumn < 0 || targetColumn > columns || additionColumn < 0 || additionColumn > columns){
        throw logic_error("Columns are out of boundaries!");
    }

    for(lli i = 0 ; i < rows; i++){
        matrix[i][targetColumn] = matrix[i][targetColumn] + coefficient*matrix[i][additionColumn];
        if (fabs(matrix[targetColumn][i].getRealPart())< accuracy) matrix[targetColumn][i].setRealPart(0);
        if (fabs(matrix[targetColumn][i].getImaginaryPart())< accuracy) matrix[targetColumn][i].setImaginaryPart(0);
    }
}

void cMatrix::addRows(ComplexNumber coefficient, lli targetRow, lli additionRow) {
    if (targetRow < 0 || targetRow > rows || additionRow < 0 || additionRow > rows) {
        throw logic_error("Columns are out of boundaries!");
    }
    for (lli i = 0; i < columns; i++) {
        matrix[targetRow][i] = matrix[targetRow][i] + coefficient*matrix[additionRow][i];
        if (fabs(matrix[targetRow][i].getRealPart()) < accuracy) matrix[targetRow][i].setRealPart(0);
        if (fabs(matrix[targetRow][i].getImaginaryPart()) < accuracy) matrix[targetRow][i].setImaginaryPart(0);
    }
}

cMatrix cMatrix::operator+(cMatrix m) {
    if(rows != m.getRows() || columns != m.getColumns()) throw logic_error("Matrices must be of the same size!");

    cMatrix result(m.getRows(), m.getColumns());

    vector<vector<ComplexNumber>> copyM = m.getMatrix();
    vector<vector<ComplexNumber>> z;
    vector<ComplexNumber> smallZ;
    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < columns; j++){
            smallZ.push_back(matrix[i][j] + copyM[i][j]);
        }
        z.push_back(smallZ);
        smallZ.clear();
    }

    result.setMatrix(z);

    return result;
}
cMatrix cMatrix::operator-(cMatrix m){

    if(rows != m.getRows() || columns != m.getColumns()) throw logic_error("Matrixes must be of the same size!");

    cMatrix result(m.getRows(), m.getColumns());

    vector<vector<ComplexNumber>> copyM = m.getMatrix();
    vector<vector<ComplexNumber>> z;
    vector<ComplexNumber> smallZ;
    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < columns; j++){
            smallZ.push_back(matrix[i][j] - copyM[i][j]);
        }
        z.push_back(smallZ);
        smallZ.clear();
    }

    return result;
}
cMatrix cMatrix::operator*(cMatrix m) {
    cMatrix result (rows,m.getColumns());

    if( columns!=m.getRows() ) {
        throw logic_error("Matrices have different dimensions!"); //We can't perform multiplication of such matrix
    }

    vector<ComplexNumber> productSmall;
    ComplexNumber t;
    t.setImaginaryPart(0);
    t.setRealPart(0);
    for(lli i = 0; i < rows; i++){
        for(lli k = 0; k < m.getColumns(); k++){
            for(lli j = 0; j < columns; j++){
                t = t + matrix[i][j] * m.matrix[j][k];
            }
            if(abs(t.getRealPart()) < accuracy){
                t.setRealPart(0);
            }
            if(abs(t.getImaginaryPart()) < accuracy){
                t.setImaginaryPart(0);
            }
            productSmall.push_back(t);
            t.setImaginaryPart(0);
            t.setRealPart(0);
        }
        result.matrix.push_back(productSmall);
        productSmall.clear();
    }
    return result;
}
cMatrix cMatrix::operator/(cMatrix m){
    if(m.getRows() != m.getColumns()) throw logic_error("Only square matrixes!");
    if( columns != m.getRows() ) throw logic_error("Matrices have different dimensions!");

    cMatrix newM(m.getRows(), m.getRows());
    newM.setMatrix(m.inverseMatrix());
    return (*this) * newM;
}
cMatrix cMatrix::operator^(int power){
    cMatrix result(rows,columns);

    if (rows!=columns) throw logic_error("You can use only squere matrix!");

    if (power == 0) {
        cMatrix z(rows,columns);
        z.setMatrix((*this).inverseMatrix());
        result = ((*this) * z);
    }
    else if(power >0) {
        cMatrix copy(rows,columns);
        copy.setMatrix(matrix);
        result.setMatrix(matrix);
        for (int i = 1; i < power; i++) {
            result=result*copy;
        }
    }
    else if (power <0){
        cMatrix copy (rows,columns);
        copy.setMatrix(inverseMatrix());
        result.setMatrix(copy.getMatrix());
        for (int i = -1; i > power; i--) {
            result=result*copy;
        }
    }
    return result;
}

ComplexNumber cMatrix::determinant(){
    ComplexNumber d(1, 1);
    if(rows != columns) throw logic_error("Matrix must be triangle!");

    vector<vector<ComplexNumber>> v;
    v = matrix;
    triangle(true);

    for(lli i = 0; i < rows; i++){
        d = d * matrix[i][i];
    }

    matrix = v;
    return d;
}

vector<vector<ComplexNumber>> cMatrix::inverseMatrix() {
    vector<vector<ComplexNumber>> result;
    ComplexNumber t(1, 0);
    ComplexNumber k(0, 0);
    vector<vector<ComplexNumber>> copy = matrix;

    if(determinant() == k || rows != columns) throw logic_error("The inverse matrix doesn't exist!");

    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < columns; j++){
            if(i == j){
                matrix[i].push_back(t);
            }else{
                matrix[i].push_back(k);
            }
        }
    }

    columns = columns * 2;

    triangle();

    lli i = rows - 1;
    lli g = columns - columns / 2 -1;
    while (g >= 0 && i >= 0) {
        for (lli s = i - 1; s >= 0; s--) {
            if (matrix[i][g] != k) break;
            else changeRows(i, s);
        }
        if (matrix[i][g] != k) {
            for (lli j = i - 1; j >= 0; j--) {
                addRows(multiplyComplexNumber(t / matrix[i][g] * matrix[j][g], -1), j, i);
            }
            i--;
        }
        g--;
    }
    /*
    lli currentRow = rows - 1;
    lli currentColumn = columns - columns / 2 - 1;

    while(currentRow >= 0 && currentColumn >= 0){
        if(matrix[currentRow][currentColumn] == 0){
            for(lli i = currentRow - 1; i >= 0; i--){
                if(matrix[i][currentColumn] != 0){
                    changeRows(currentRow, i);
                    break;
                }
            }
        }

        for(lli i = currentRow - 1; i >= 0; i--){
            addRows((-1) * matrix[i][currentColumn] / matrix[currentRow][currentColumn], i, currentRow);
        }
        currentRow--;
        currentColumn--;
    }
    */

    vector<ComplexNumber> resultSmall;
    for(lli k = 0; k < rows; k++){
        for(lli j = columns / 2; j < columns; j++){
            resultSmall.push_back(matrix[k][j] / matrix[k][k]);
        }
        result.push_back(resultSmall);
        resultSmall.clear();
    }

    columns /= 2;

    matrix.clear();
    matrix = copy;

    return result;
}

/*
 * z, z2
 *
 *  z
 *  z2
 */

void cMatrix::triangle(bool side){
    ComplexNumber k(0, 0);
    ComplexNumber t(1, 0);
    ComplexNumber result(1,1);
    if(side) {
        lli i = 0;
        lli g = 0;
        while (g < columns && i < rows) {
            for (lli s = i + 1; s < rows; s++) {
                if (matrix[i][g] != k) break;
                else changeRows(i, s);
            }
            /*
            if (matrix[i][g] != k){
                for(int j=i;j<rows;j++){
                    matrix[j][i]=matrix[j][i]* complexConjugate(matrix[j][i]);
                    result = result*complexConjugate(matrix[j][i]);
                }
            }
             */
            if (matrix[i][g] != k) {
                for (lli j = i + 1; j < rows; j++) {
                    addRows(multiplyComplexNumber(t / matrix[i][g] * matrix[j][g], -1), j, i);
                }
                i++;
            }
            g++;
        }
    }
    else{
        lli i = rows-1;
        lli g = columns-1;

        while (g >= 0 && i >= 0) {
            for (lli s = i - 1; s >= 0; s--) {
                if (matrix[i][g] != k) break;
                else changeRows(i, s);
            }
            if (matrix[i][g] != k) {
                for (lli j = i - 1; j >= 0; j--) {
                    addRows(multiplyComplexNumber(t / matrix[i][g] * matrix[j][g], -1), j, i);
                }
                i--;
            }
            g--;
        }
    }
}

unsigned int cMatrix::cRank(){
    unsigned int result=0;
    ComplexNumber k(0,0);
    cMatrix copy(rows,columns);
    copy.setMatrix(matrix);
    copy.triangle(true);
    for(lli i = 0; i<rows; i++ ){
        for(lli j = columns-1; j>=0;j--){
            if (copy.matrix[i][j]!=k) {
                result++;
                break;
            }
            else if (j==0) return result;
        }
    }
    return result;
}

vector<ComplexNumber> cMatrix::solveEquasion(vector<ComplexNumber> constantT){//This doesn't work properly
    //if(determinant() == 0 || rows != columns) throw logic_error("The inverse matrix doesn't exist!");

    vector<ComplexNumber> result;
    vector<vector<ComplexNumber>> copy = matrix;

    for(lli i = 0; i < rows; i++){
        matrix[i].push_back(constantT[i]);
    }

    ComplexNumber k(0, 0);
    ComplexNumber t(1, 0);
    columns = columns + 1;

    showMatrix();
    cout << endl;

    triangle();

    lli i = rows - 1;
    lli g = columns - 2;
    while (g >= 0 && i >= 0) {
        for (lli s = i - 1; s >= 0; s--) {
            if (matrix[i][g] != k) break;
            else changeRows(i, s);
        }
        if (matrix[i][g] != k) {
            for (lli j = i - 1; j >= 0; j--) {
                addRows(multiplyComplexNumber(t / matrix[i][g] * matrix[j][g], -1), j, i);
            }
            i--;
        }
        g--;
    }

    showMatrix();
    cout << endl;

    for(lli h = 0; h < rows; h++){
        if(abs((matrix[h][columns - 1] / matrix[h][h]).getRealPart()) > accuracy || abs((matrix[h][columns - 1] / matrix[h][h]).getImaginaryPart()) > accuracy)
            result.push_back(matrix[h][columns - 1] / matrix[h][h]);
        else result.push_back(k);
    }

    matrix.clear();
    matrix = copy;

    columns--;

    return result;
}

vector<vector<ComplexNumber>> cMatrix::findGeneralSolution(vector<ComplexNumber> constantT) {
        vector<vector<ComplexNumber>>result;
        unsigned int rank =(*this).cRank();
        unsigned int extendedRank = (*this).cRankOfExtended(constantT);

        if(rank!=extendedRank){
            cout<<"System does not have solutions (rank of matrix != rank of extended matrix)"<<endl;
            return result;
        }
        else if(rank>columns){
            cout<<"System does not have solutions"<<endl;
            return result;
        }
        else if ((rank==columns)&&(rank==extendedRank)) {
            result.push_back((*this).solveEquasion(constantT));
            return result;
        }

        else if ((rank<columns)&&(rank==extendedRank)) {
            cMatrix input(rows, columns);
            ComplexNumber zero(0, 0);
            ComplexNumber minusOne(-1, 0);
            input.setMatrix(matrix);
            vector<ComplexNumber> copyofinput = constantT;

            lli i = 0;
            lli g = 0;
            while (g < columns && i < rows) {
                for (lli s = i + 1; s < rows; s++) {
                    if (input.matrix[i][g] != zero) break;
                    else input.changeRows(i, s);

                    ComplexNumber d = constantT[i];
                    constantT[i] = constantT[s];
                    constantT[s] = d;
                }
                if (input.matrix[i][g] != zero) {
                    lli j;
                    ComplexNumber c;
                    for (j = i + 1; j < rows; j++) {
                        c = minusOne / input.matrix[i][g] * input.matrix[j][g];
                        input.addRows(c, j, i);
                        constantT[j] = constantT[j] + constantT[i] * c;
                    }

                    i++;
                }
                g++;
            }

            int freevariables= columns-rank;
            cMatrix copy(rank,rank);
            vector<int> indexbasic; //Indexes of basic and free variables
            vector<int> indexfree;
            int c=0,r=0;
            for(; columns > c; c++){
                if(r<rows){
                    if(input.matrix[r][c] != zero){
                        indexbasic.push_back(c);
                        r++;
                    }else {
                        indexfree.push_back(c);
                    }
                }
                else {
                    indexfree.push_back(c);
                }
            }

            for(int i=0;i<indexbasic.size();i++){
                if(i!=indexbasic[i]){
                    input.changeColumns(i,indexbasic[i]);
                }
            }

            vector<ComplexNumber> temp;
            for (int j = 0; j < rank; j++) {
                for (int i = 0; i < rank; i++) {
                    temp.push_back(input.matrix[j][i]);
                }
                copy.matrix.push_back(temp);
                temp.clear();
            }

            {   //finds partial solution
                vector <ComplexNumber> t=copy.solveEquasion(constantT);
                vector <ComplexNumber> tempresult;
                for(int i=0,j=0,h=0;h<columns;h++){
                    if(i<indexbasic.size()){
                        if(h==indexbasic[i]){
                            tempresult.push_back(t[i]);
                            i++;
                        }else {
                            tempresult.push_back(zero);
                            j++;
                        }
                    }
                    else {
                        tempresult.push_back(zero);
                        j++;
                    }
                }
                result.push_back(tempresult);
            }

            //finds solutions when one of the free variables equals to 1 and other to 0
            for(int k=0,b=rank;k<indexfree.size();k++){
                ComplexNumber one(1, 0);
                vector <ComplexNumber> copyfree=constantT;
                for(int j =0; j<copy.rows;j++){
                    copyfree[j]=minusOne*input.matrix[j][b];
                }
                b++;
                vector <ComplexNumber> t=copy.solveEquasion(copyfree);
                vector <ComplexNumber> tempresult;
                for(int n=0,j=0,h=0; h < columns; h++){
                    if(n<indexbasic.size()){
                        if(h==indexbasic[n]){
                            tempresult.push_back(t[n]);
                            n++;
                        }else if(h==indexfree[k]){
                            tempresult.push_back(one);
                            j++;
                        }else {
                            tempresult.push_back(zero);
                            j++;
                        }
                    }
                    else if(h==indexfree[k]){
                        tempresult.push_back(one);
                        j++;
                    }
                    else {
                        tempresult.push_back(zero);
                        j++;
                    }
                }
                result.push_back(tempresult);
            }
        }

    // result[0] = partial solution
    // other elements in result = vectors of the fundamental system of solutions
    return result;
}

unsigned int cMatrix::cRankOfExtended(vector<ComplexNumber> constantT){
    cMatrix copy(rows,columns+1);

    vector<ComplexNumber> temp;
    vector<vector<ComplexNumber>> copyex;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            temp.push_back((*this).matrix[j][i]);
        }
        copyex.push_back(temp);
        copyex[j].push_back(constantT[j]);
        temp.clear();
    }

    copy.setMatrix(copyex);
    return copy.cRank();
}