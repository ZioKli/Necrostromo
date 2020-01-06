#include "generator.h"

using namespace noise;

//constructors 
Generator::Generator(){
    seed = 0;
    lines = 30;
    columns = 130;
    zedLevels = 1;
}

Generator::Generator(int newLines,int newColumns){
    seed = 0;
    zedLevels = 1;

    if(newLines > 0){
        lines = newLines;
    }
    else{
        lines = 30;
    }

    if(newColumns > 0){
        columns = newColumns;
    }
    else{
        columns = 130;
    }
}

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
        lines = 30;
    }

    if(newColumns > 0){
        columns = newColumns;
    }
    else{
        columns = 130;
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

    std::cout << "highest: " << high << std::endl;
    std::cout << "lowest: " << low << std::endl;   
    high = high - low;

    for(size_t line = 0; line < noisemap2D.size(); line++){
        for (size_t col = 0; col < noisemap2D.at(line).size(); col++){
            double val = noisemap2D.at(line).at(col);
            val = val - low;
            val = val / high;
            noisemap2D.at(line).at(col) = val;

        }
    }

    high = -MAXFLOAT;
    low = MAXFLOAT;

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

    std::cout << "new highest: " << high << std::endl;
    std::cout << "new lowest: " << low << std::endl;   

    
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
