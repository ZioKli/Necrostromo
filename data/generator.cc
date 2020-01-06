#include "generator.h"
#include "board.h"

using namespace noise;

///constructors 

/**
*   Default constructor.
*   @param none
*   @return a default Generator
*/
Generator::Generator(){
    seed = 0;
    lines = 29;
    columns = 100;
    zedLevels = 1;
}

/**
*   Constructor taking only height and width of the map to generate.
*   @param newLines the number of lines the generator should have
*   @param newColumns the number of columns the generator should have
*   @return a generator of the specified dimensions
*/
Generator::Generator(int newLines,int newColumns){
    seed = 0;
    zedLevels = 1;

    if(newLines > 0){
        lines = newLines;
    }
    else{
        lines = 29;
    }

    if(newColumns > 0){
        columns = newColumns;
    }
    else{
        columns = 100;
    }
}

/**
*   Constructor taking height, width, depth, and seed of the map to generate.
*   @param newLines the number of lines the generator should have
*   @param newColumns the number of columns the generator should have
*   @param newZedLevels the number of zed levels that the generator should create;
*   @param newSeed the seed to be used to generate the noisemap
*   @return a generator of the specified dimensions using the given seed
*/
Generator::Generator(int newLines, int newColumns, int newZedLevels, int newSeed){
    if(newSeed >= 0) {
        seed = newSeed;
    }
    else{
        seed = 0;
    }

    if(newZedLevels > 0){
        zedLevels = newZedLevels;
    }
    else{
        zedLevels = 1;
    }

    if(newLines > 0){
        lines = newLines;
    }
    else{
        lines = 29;
    }

    if(newColumns > 0){
        columns = newColumns;
    }
    else{
        columns = 100;
    }
}
///setters and generators

void Generator::setSeed(int newSeed){
    if(newSeed >= 0) {
        seed = newSeed;
    }
}

void Generator::setLines(int newLineCount){
    if(newLineCount > 0){
        lines = newLineCount;
    }
}

void Generator::setColumns(int newColumnsCount){
    if(newColumnsCount > 0){
        columns = newColumnsCount;
    }
}

void Generator::generateNoiseMap2D(){
    perlin.SetSeed(seed);
    perlin.SetFrequency(1);
    perlin.SetLacunarity(.1);
    perlin.SetPersistence(.5);
    perlin.SetOctaveCount(6);
    for(size_t y = 0; y < size_t(lines); y++){
        vector<double> line;
        for(size_t x = 0; x < size_t(columns); x++){
            line.push_back(perlin.GetValue(x, y, zedLevels));
        }
        noisemap2D.push_back(line);
    }
    
    double high = -MAXFLOAT;
    double low = MAXFLOAT;
    for(vector<double> line : noisemap2D){
        for(double val : line){
            if(val < low) {
                low = val;
            }
            else if(val > high) {
                high = val;
            }
        }
    }

    high = high - low;

    for(size_t line = 0; line < noisemap2D.size(); line++){
        for (size_t col = 0; col < noisemap2D.at(line).size(); col++){
            double val = noisemap2D.at(line).at(col);
            val = val - low;
            val = val / high;
            noisemap2D.at(line).at(col) = val;

        }
    }    
}

void Generator::generateNoiseMap2D(int newSeed){

}

void Generator::generateNoiseMap2D(int newLines, int newColumns, int newSeed){

}

void Generator::generateNoiseMap3D(){

}

void Generator::generateNoiseMap3D(int newSeed){

}

void Generator::generateNoiseMap3D(int newLines, int newColumns, int newZedLevels, int newSeed){

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

vector<vector<double>> & Generator::getNoiseMap2D() {
    vector<vector<double>> & noisemapRef = noisemap2D;
    return noisemapRef;
}

vector<vector<vector<double>>> & Generator::getNoiseMap3D(){
    vector<vector<vector<double>>> & noisemapRef = noisemap3D;
    return noisemapRef;
}
