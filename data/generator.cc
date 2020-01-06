#include "generator.h"

using namespace noise;

//constructors 
Generator::Generator(){

}

Generator::Generator(int lines,int columns){

}

///setters and generators
void Generator::setSeed(int newSeed){
    if(newSeed >= 0) {
        seed = newSeed;
    }
}

void Generator::setLines(int newLineCount){
    if(newLineCount >= 0){
        lines = newLineCount;
    }
}

void Generator::setColumns(int newColumnsCount){
    if(newColumnsCount >= 0){
        columns = newColumnsCount;
    }
}

void Generator::generateNoiseMap2D(){

}

void Generator::generateNoiseMap2D(int seed){

}

void Generator::generateNoiseMap2D(int lines, int columns, int seed){

}

void Generator::generateNoiseMap3D(){

}

void Generator::generateNoiseMap3D(int seed){

}

void Generator::generateNoiseMap3D(int lines, int columns, int zLevels, int seed){

}


///getters
int Generator::getSeed(){
    return seed;
}

int Generator::getLines(){
    return lines;
}

int Generator::getColumns(){
    return columns;
}

vector<vector<double>> Generator::getNoiseMap2D() const {
    if(noisemap2D.size() != 0) {
        return noisemap2D;
    }
}

vector<vector<vector<double>>> Generator::getNoiseMap3D() const{
    if(noisemap3D.size() != 0){
        return noisemap3D;
    }
}
