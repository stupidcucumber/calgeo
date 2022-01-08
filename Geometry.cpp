#include "Geometry.h"
#include "Vectors.h"
#include "Matrices.h"

/*
 * Points
 */
bool isOnLine(vector<vector<ld>> v){
    if(v.empty()) throw std::logic_error("This function is valid for at least 1 point");
    if(v.size() == 2 || v.size() == 1) return true;

    Line line(subtractionVectors(v[0], v[1]), v[0]);

    for(long long int i = 2; i < v.size(); i++){
        if(!line.isPointBelong(v[i])) return false;
    }

    return true;
}

bool isOnPlane(vector<vector<ld>> v){
    if(v.empty()) throw std::logic_error("This function is valid for at least 1 point");
    if(!v.empty() && v.size() <= 3) return true;

    Plane plane(vectorProduct(subtractionVectors(v[0], v[1]), subtractionVectors(v[0], v[2])), v[0]);

    for(long long int i = 3; i < v.size(); i++){
        if(!plane.isPointBelong(v[i])) return false;
    }

    return true;
}

/*
 * Lines
 */
Line::Line(const vector<ld>& direct_answer, const vector<ld>& point_answer){
    if (direct_answer.size() != point_answer.size()) throw std::logic_error("Vectors have different dimensions!");

    bool checkfor0 = true;
    for (long double i : direct_answer) {
        if (i != 0) checkfor0 = false;
    }
    if (checkfor0) throw std::logic_error("Directing vector cannot be zero!");

    direct=direct_answer;
    point=point_answer;
}

vector <ld> Line::getDirectV(){return direct;}
vector <ld> Line::getDefPoint(){return point;}

bool Line::isPointBelong(const vector <ld>& p){
    if(p.size() != point.size()) {
        throw std::logic_error("Points have different dimensions!");
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
    if(vectorLength(d) == 0) throw std::logic_error("Direct vector cannot be zero!");
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
    if(input.size()!=direct.size()) throw std::logic_error("Wrong dimension!");

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
    if(v.size() != coeficients.size()) throw std::logic_error("Different dimensions!");
    if(!isEquasionCanonic()) throw std::logic_error("Equasion is not canonic!");

    ld t = 0;
    for(ui i = 0; i < v.size(); i++){
        t += pow(v[i]/coeficients[i], 2);
    }
    if(abs(t-1)<accuracy) return true;
    else return false;
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
    else throw std::logic_error("i dont know D:");
    return result;
}

vector<std::pair<std::string, ld>> Elipsoid::findDirectrix(){
    if(!isEquasionCanonic()) throw std::logic_error("Equasion is not canonic!");

    vector<std::pair<std::string, ld>> result;
    std::pair<std::string, ld> resultSmall;
    if(coeficients.size() == 2){
        resultSmall = std::pair<std::string, ld>("x" , coeficients[0] * coeficients[0] / findExcetricity());
        result.push_back(resultSmall);
    }else{
        throw std::logic_error("Coming soon...");
    }

    return result;
}
