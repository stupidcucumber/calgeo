# calgeo
Hello out there! A repository you're currently looking at was created once for fun, but then we realized how useful it can be in the future for the developer's community! Once in a while we make some minor changes to this library, but functionality is still far from what you can expect from a fresh students :) With your help we can make it great!

## What our library can do?
Our library contain functionality to deal with:
1. Complex numbers;
2. Matrices;
3. Vectors;
4. Primitive geometry objects, such as: points, lines, planes of any dimension;
5. Limited functionality for curles in 2D-space.

###   Complex numbers
Our library adds a new type "ComplexNumber" and contain all necessary methods for working with cimplex numbers. This methods are:
1. getRealPart()/getImaginaryPart() – returns real and imaginary part of a number accordingly.
2. setRealPart(long double a)/setImaginaryPart(long double b) – returns real and imaginary part of a number accordingly.
3. length() – returns the module of a complex number
4. showNumber() – outputs number in a terminal.
5. root(long long int r) – returns all roots of a given complex number.
6. operator – a bunch of methods to make work with complex numbers easier.

Apart from above methods library provides useful functions:
1. multiplyComplexNumber(ComplexNumber z, long double coefficient) – multiplies specific complex number on a given real coefficient.
2. complexConjugate(ComplexNumber z) – returns the conjugate of a specific complex number.
3. multiplicatieInverse(ComplexNumber z) – returns the multiplicative inverse version of a specific cimplex number.

###   Matrices
Provides two different classes for work with complex Matrix (cMatrix) and real Matrix (Matrix). The two contain the following methods:
1. showMatrix() – shows the matrix as it is.
2. clearMatrix() – clears the matrix.
3. getRows()/getColumns() – returns the number of rows and columns accordingly.
4. getMarix() – returns the matrix itself by reference.
5. rank()/cRank() – returns the rank of a matrix.
6. rankOfExtended(vector<long double> v)/cRankOfExtended(vector<ComplexNumber> v) – returns the rank of an extended matix.
7. randValues(long double min, long double max) – assigns random values to a matrix between minimum and maximum values.
8. setMatrix(vector<vector<long double/int/float/double/long long int>> v) – assigns specific values to a matrix.
9. changeColumns(lli row, lli column)/changeRows(lli row, lli column)/addColumns(lli row, lli column)/addRows(lli row, lli column) – elementary transformations of columns and rows. ('lli' stands for long long int)
10. tMatrix() – transponents the matrix of a free size.
11. triangle(bool f = false) – makes upper-(if f = false) or lower-triangle-looking matrix.
12. determinant() – returns the determinant of a matrix, if it is square matrix.
13. matrixRProduct(vector<vector<ld>> m)/matrixLProduct(vector<vector<ld>> m) – returns the matrix (represented as vector<vector<long double>> rather than object of type Matrix/cMatrix) multiplied from right or left by a given matrix.
14. inverseMatrix() – returns the matrix, but inversed to the initial.
15. solveEquation(vector<ld> c) – returns the solution to a correspoding liniar system.
16. findGeneralSolution(vector<ld> c) – returns the solution to a correspoding liniar system.
17. operator – a bunch of operators (-, +, *, /, ^) to make work with matrices easier.

Also there is some useful functions:
1. matrixProduct(vector<vector<ld>> m1, vector<vector<ld>> m2, bool side = false) – returns the product of matrices.
2. showMatrix(vector<vector<ld>> m) – shows any matrix.

###   Vectors
The following functions were included:
1. vectorLength(const vector<ld>& v) – returns the length of the given vector.
2. vectorProduct(vector<ld> vector1, vector<ld> vector2) – returns the vector as a result of a multiplication of two vectors.
3. scalarProduct(vector<ld> v1, vector<ld> v2) – returns a scalar product of a vectors.
4. angle(const vector<ld>& vector1, const vector<ld>& vector2) – returns the angle between vectors.
5. addVectors(vector<ld> vector1, vector<ld> vector2) – adds two vectors and returns corresponding vector.
6. subtractionVectors(vector<ld> v1, vector <ld> v2) – subtracts two vectors and returns corresponding vector.
7. vectorNormalization(vector<ld> v) – returns the normalized vector.

###   Primitive objects
Primitive objects include points, lines and planes. Functionality for working with points includes:
1. isOnLine(vector<vector<long double>> p) – returns true if all given points lie on one line.
2. isOnPlane(vector<vector<long double>> p) – returns true if all given points lie on one plane.

Class 'Line' provides the following methods:
1. getDirectV() – returns the direct vector of a line.
2. getPointV() – returns the point of a line.
3. isPointBelong(vector<long double> v) – returns true if point belongs to a line.
4. isPerpendicular(Line line) – returns true if a given line is perpendicular.
5. isParallel(Line line) – returns true if a given line is parallel.
6. isOnOnePlane(Line line) – returns true if lines are on one plane.
7. isCross(Line line) – returns true if lines cross.

Class 'Plane' provides the following methods:
1. getDirectPlane() – returns the direct vector of a plane.
2. getPointPoint() – returns the point of a plane.
3. isParallel(Line line) – returns true if a given line is parallel to the plane.
4. isParallel(Plane plane) – returns true if a given plane is parallel to the plane.
5. isPerpendicular(Line line) – returns true if a given line is perpendicular to the plane.
6. isPointBelong(vector <ld> p) – checks whether the point belong to a plane.
	
Primitive objects also have functions:
1. pointLineCross(Line line1, Line line2) – returns the point of cross.
	
###   Curles
Currently we are working on it and trying to learn more about shapes in multidimentional space. Our library works only with ellips and provides class "Ellipsoid" which contains such methods:
1. isEquationCanonic() – checks whether the equation is canonic.
2. isPointBelongs(vector<ld> p) – checks whether the point belongs to the ellips.
3. findExcetricity() – returns the excentricity of the ellips.
4. findDirectrix() – returns the directrix of the ellips.
## Future plans
1. Make faster algorithms.
2. Include functions for working with multidimensional figures.
3. Implement UI for drawing graphs and working with 3D and 2D figures.

## Future plans
1. Make faster algorithms.
2. Include functions for working with multidimensional figures.
3. Implement UI for drawing graphs and working with 3D and 2D figures.
	
## What are our goals?
Our main goal is to make a reliable library which can help modeling/solving complex mathematical problems. Every mathematician needs a simple and at the same time a powerful instrument to work with numbers. By building such instrument we can vaguely help scientific community in further math exploration.
