#ifndef CALGEO_VECTORS_H
#define CALGEO_VECTORS_H
#include "CONSTANTS.h"

ld vectorLength(const vector<ld>& v){
    ld result = 0;

    for(ld i : v){
        result += pow(i, 2);
    }

    return sqrt(result);
}


vector<ld> vectorProduct(vector<ld> vector1, vector<ld> vector2){
    vector<ld> result = {};
    if(vector1.size() != vector2.size()) throw std::logic_error("Vectors have different dimensions!");

    result.push_back(vector1[1] * vector2[2] - vector1[2] * vector2[1]);
    result.push_back(vector1[2] * vector2[0] - vector1[0] * vector2[2]);
    result.push_back(vector1[0] * vector2[1] - vector1[1] * vector2[0]);

    return result;
}

ld scalarProduct(vector<ld> v1, vector<ld> v2){
    ld s = 0;
    try{
        if (v1.size()!=v2.size()) throw 1;

        const unsigned int sizeOfVectors = v1.size();

        for (ui i=0; i < sizeOfVectors; i++){
            s+=v1[i]*v2[i];
        }
    }

    catch (int){
        throw std::logic_error("Different dimensions!");
    }

    return s;
}

ld angle(const vector<ld>& vector1, const vector<ld>& vector2){ //needs to be done pi
    if(vector1.size() != vector2.size()) throw std::logic_error("Vectors have different dimensions!");
    return acos( scalarProduct(vector1, vector2) / (vectorLength(vector1) * vectorLength(vector2)) );
}

vector<ld> addVectors(vector<ld> vector1, vector<ld> vector2){
    vector<ld> result;
    if(vector1.size() != vector2.size()) throw std::logic_error("Vectors have different dimensions!");

    for(ui i = 0; i < vector1.size(); i++){
        result.push_back(vector1[i] + vector2[i]);
    }

    return result;
}

vector<ld> subtractionVectors(vector<ld> v1, vector <ld> v2){
    vector <ld> answer;
    if (v1.size()!=v2.size()) throw std::logic_error("Vectors have different dimensions!");

    const unsigned int sizeOfVectors = v1.size();
    ld s = 0;

    for (ui i=0;i<sizeOfVectors;i++){
        answer.push_back(v1[i]-v2[i]);
    }
    return answer;
}

vector<ld> vectorNormalization(vector<ld> v){
    vector<ld> normalized;

    if(vectorLength(v) == 0) throw std::logic_error("Vector cannot be normalized!");

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



#endif //CALGEO_VECTORS_H
