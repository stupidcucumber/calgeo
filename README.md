# calgeo
Hello there! A repository you're currently looking at was created for fun, but then we realized how useful it can be in the future for the developer's community! Once in a while we make some minor changes to this library :). With your help we can make it great!

## Features
Our library contain functionality to deal with:
1. Complex numbers
2. Matrices
3. Vectors
4. Primitive geometry objects, such as: points, lines, planes of any dimension
5. Limited functionality for curves in 2D-space

###   Complex numbers
Our library adds a new `ComplexNumber` class, which contains all the necessary methods for working with complex numbers.

#### getRealPart() ⟹ `long double`
returns the real part of a complex number.
#### getImaginaryPart() ⟹ `long double`
returns the imaginary part of a complex number.
#### setRealPart(long double a) ⟹ `void`
sets the real part of a complex number.
#### setImaginaryPart(long double b) ⟹ `void`
sets the imaginary part of a complex number.
#### length() ⟹ `long double`
returns the magnitude of a complex number.
#### showNumber() ⟹ `void`
sends a complex number to the standard output.
#### root(long long int r) ⟹ `vector<ComplexNumber>`
returns all roots of a given complex number.
*not implemented*
#### operators 
a bunch of methods to make work with complex numbers easier. 

The library also provides some useful global functions:
#### multiplyComplexNumber(ComplexNumber z, long double coefficient) ⟹ `ComplexNumber`
multiplies a complex number by a given real coefficient.
#### complexConjugate(ComplexNumber z) ⟹ `ComplexNumber`
returns the conjugate of a complex number.
#### multiplicativeInverse(ComplexNumber z) ⟹ `ComplexNumber`
 returns the multiplicative inverse version of a complex number.

###   Matrices
Provides two different classes for work with complex Matrix `cMatrix` and real Matrix `Matrix`. They contain the following methods:
#### showMatrix() ⟹ `void`
sends the matrix to the standard output.
#### clearMatrix() ⟹ `void`
clears the matrix.
#### getRows() / getColumns() ⟹ `long long int`
returns the number of rows and columns accordingly.
#### getMatrix() ⟹ `vector<vector<long double>>&`
returns the matrix by reference.
#### rank(), cRank() ⟹ `unsigned int`
returns the rank of a real / complex matrix.
#### rankofExtended(vector<long double> v) / cRankOfExtended(vector<ComplexNumber> v) ⟹ `unsigned int`
returns the rank of an extended matrix.
#### randValues(long double min, long double max) ⟹ `void`
assigns random values to a matrix between minimum and maximum values.
#### setMatrix(vector<vector<long double/int/float/double/long long int>> v) ⟹ `void`
assigns specific values to a matrix.
#### changeColumns(long long int prevColumn, long long int nextColumn) ⟹ `void`
swaps columns.
#### changeRows(long long int previousRow, long long int nextRow) ⟹ `void`
swaps rows.
#### addColumns(long double coefficient, long long int targetRow, long long int additionRow) ⟹ `void`

#### addRows(long double coefficient, long long int targetColumn, long long int additionColumn) ⟹ `void`

#### tMatrix() ⟹ `void`
transposes the matrix of an arbitrary size.
#### triangle(bool side = false) ⟹ `void`
makes upper (if f = false) or lower triangular matrix.
#### determinant() ⟹ `long double` 
returns the determinant of a matrix, if it is square matrix.
#### matrixRProduct(vector<vector<long double>> m) / matrixLProduct(vector<vector<long double>> m) ⟹ `vector<vector<long double>>`
returns the matrix (represented as `vector<vector<long double>>` rather than object of type Matrix/cMatrix) multiplied from right or left by a given matrix.
#### inverseMatrix() ⟹ `vector<vector<ld>>`
returns the inverse matrix.
#### solveEquation(vector<long double> c) (solveEquasion() in code) ⟹ `vector<long double>`
returns the solution to the corresponding linear equation system.
#### findGeneralSolution(vector<long double> c) ⟹ `vector<vector<long double>>`
returns a general solution to a corresponding linear equation system.
#### operators 
a bunch of operators (-, +, *, /, ^) to make work with matrices easier.

Also there are some useful functions:
#### matrixProduct(vector<vector<long double>> m1, vector<vector<long double>> m2, bool side = false) ⟹ `vector<vector<long double>>`
returns the product of matrices.
#### showMatrix(vector<vector<long double>> m) ⟹ `void`
sends the matrix to the standard output.

###   Vectors
The following functions are included:
#### vectorLength(const vector<long double>& v) ⟹ `long double`
returns the length of the given vector.
#### vectorProduct(vector<long double> vector1, vector<long double> vector2) ⟹ `vector<long double>`
returns the vector as a result of a multiplication of two vectors.
#### scalarProduct(vector<long double> v1, vector<long double> v2) ⟹ `long double`
returns a scalar product of a vectors.
#### angle(const vector<long double>& vector1, const vector<long double>& vector2) ⟹ `long double`
returns the angle between vectors.
#### addVectors(vector<long double> vector1, vector<long double> vector2) ⟹ `vector<long double>`
adds two vectors and returns corresponding vector.
#### subtractionVectors(vector<long double> v1, vector <long double> v2) ⟹ `vector<long double>`
subtracts two vectors and returns corresponding vector.
#### vectorNormalization(vector<long double> v) ⟹ `vector<long double>`
returns the normalized vector.

###   Primitive objects
Primitive objects include points, lines and planes. Functionality for working with points:
#### isOnLine(vector<vector<long double>> p) ⟹ `bool`
returns true if all given points lie on one line.
#### isOnPlane(vector<vector<long double>> p) ⟹ `bool`
returns true if all given points lie on one plane.

Class `Line` provides following methods:
#### getDirectV() ⟹ `vector<long double>` 
returns the direct vector of a line.
#### getPointV() ⟹ `vector<long double>` 
returns the point of a line. *not implemented (?)*
#### isPointBelong(vector<long double> v) ⟹ `bool`
returns true if point belongs to a line.
#### isPerpendicular(Line line) ⟹ `bool`
returns true if a given line is perpendicular.
#### isParallel(Line line) ⟹ `bool`
returns true if a given line is parallel.
#### isOnOnePlane(Line line) ⟹ `bool`
returns true if lines are on one plane.
#### isCross(Line line) ⟹ `bool`
returns true if lines cross.

Class 'Plane' provides following methods:
#### getDirectPlane() ⟹ `vector<long double>` 
returns the direct vector of a plane.
#### getPointPoint() ⟹ `vector<long double>` 
returns the point of a plane.
#### isParallel(Line line) ⟹ `bool`
returns true if a given line is parallel to the plane.
#### isParallel(Plane plane) ⟹ `bool`
returns true if a given plane is parallel to the plane.
#### isPerpendicular(Line line) ⟹ `bool`
returns true if a given line is perpendicular to the plane.
#### isPointBelong(vector <long double> p) ⟹ `bool`
checks whether the point belong to a plane.
	
Primitive objects also have functions:
#### pointLineCross(Line line1, Line line2) ⟹ `vector<long double>` 
returns the point of cross.
	
###   Curves
Currently we are working on it and trying to learn more about shapes in multidimensional space. Our library works only with ellipse and provides class "Ellipsoid" which contains such methods:
#### isEquationCanonic() ⟹ `bool`
checks whether the equation is canonic.
#### isPointBelongs(vector<long double> p) ⟹ `bool`
checks whether the point belongs to the ellipse.
#### findExcetricity() ⟹ `long double`
returns the eccentricity of the ellipse.
#### findDirectrix() ⟹ `vector<pair<string, long double>>`
returns the directrix of the ellipse.

## Future plans
1. Make faster algorithms.
2. Include functions for working with multidimensional figures.
3. Implement UI for drawing graphs and working with 3D and 2D figures.
	
## What are our goals?
Our main goal is to make a reliable library which can help modeling/solving complex mathematical problems. Every mathematician needs a simple but powerful tool to work with numbers. By building such a tool we can help the scientific community in further maths exploration.
