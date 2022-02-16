#ifndef CALGEO_GEOMETRY_H
#define CALGEO_GEOMETRY_H

#include "CONSTANTS.h"

/*
 * Some useful functions for points
 */
bool isOnLine(vector<vector<ld>>);

bool isOnPlane(vector<vector<ld>>);

/*
 * Class line
 */
class Line {
private:
    vector<ld> direct;  // Directing vector of the line
    vector<ld> point;   // Point that belongs to the line
public:

    Line(const vector<ld> &, const vector<ld> &);

    vector<ld> getDirectV();

    vector<ld> getDefPoint();

    bool isPointBelong(const vector<ld> &point);

    bool isPerpendicular(Line);

    bool isParallel(Line);

    bool isOnOnePlane(Line);

    bool isCross(Line);
};

vector<ld> pointLineCross(Line line1, Line line2);

class Plane {
private:
    vector<ld> direct;
    vector<ld> point;
public:
    vector<ld> getDirectPlane();

    vector<ld> getPointPoint();

    Plane(vector<ld>, vector<ld>);

    bool isParallel(Line);

    bool isParallel(Plane);

    bool isPerpendicular(Line);

    bool isPointBelong(vector<ld>);
};

class Quadric {
protected:
    vector<ld> coeficients;
    //ld p;

    ld ecc; //eccetricity
    ld drx; //directix
public:
    virtual bool isEquationCanonic() = 0;

    virtual bool isPointBelongs(vector<ld>) = 0;

    virtual ld findEccentricity() = 0;

    virtual vector<std::pair<std::string, ld>> findDirectrix() = 0;
    //virtual vector<ld> findFocuses() = 0;

    //virtual vector<vector<ld>> pointsLineCross(Line);

    //virtual Line findTangentLine(vector<ld>) = 0;
    //virtual Plane findTangentPlane(vector<ld>) = 0;
};

class Ellipsoid : public Quadric {
public:
    explicit Ellipsoid(vector<ld> e) {
        coeficients = e;
    }

    bool isEquationCanonic() override;

    bool isPointBelongs(vector<ld> v) override;
    /**
     * @return the coordinate of directrix
     */
    // pair< ld , ld > first – real part, second – imaginary part
    /*
     *     first row
     *     second row * ( 'a21 ) - first row * ( 'a11 )
     */
    vector<std::pair<std::string, ld>> findDirectrix() override;

    ld findEccentricity() override;
};

class Hyperboloid : public Quadric {
public:

};

class Paraboloid : public Quadric {
public:

};

#endif //CALGEO_GEOMETRY_H
