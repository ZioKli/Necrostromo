#include "generator.h"
#include "board.h"

using namespace noise;
using namespace std;

///constructors 

Generator::Generator(){
    seed = 0;
    lines = 29;
    columns = 100;
    zedLevels = 1;
    frequency = 1;
    lacunarity = .2;
    persistance = .5;
    octaveCount = 6;
}


Generator::Generator(int newLines,int newColumns){
    seed = 0;
    zedLevels = 1;
    frequency = 1;
    lacunarity = .2;
    persistance = .5;
    octaveCount = 6;

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
    frequency = 1;
    lacunarity = .2;
    persistance = .5;
    octaveCount = 6;
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

void Generator::setZedLevels(int newZedLevelsCount){
    if(newZedLevelsCount >= 1){
        zedLevels = newZedLevelsCount;
    }
}

void Generator::setPersistance(double newPersistance) {
    if (newPersistance > 0 && newPersistance < 1.0) {
        persistance = newPersistance;
    }
}


void Generator::setLacunarity(double newLacunarity) {
    if (newLacunarity >= 1.0 && newLacunarity < 6.0){
        lacunarity = newLacunarity;
    }
}


void Generator::setFrequency(double newFrequency) {
    if(newFrequency < 16.0 && newFrequency >= 1) {
        frequency = newFrequency;
    }
}


void Generator::setOctaveCount(int newOctaveCount) {
    if(newOctaveCount >= 1 && newOctaveCount <= 12) {
        octaveCount = newOctaveCount;
    }
}


void Generator::generateNoiseMap2D(){
    perlin.SetSeed(seed);
    perlin.SetFrequency(frequency);
    perlin.SetLacunarity(lacunarity);
    perlin.SetPersistence(persistance);
    perlin.SetOctaveCount(octaveCount);
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
    setSeed(newSeed);
    perlin.SetSeed(seed);
    perlin.SetFrequency(frequency);
    perlin.SetLacunarity(lacunarity);
    perlin.SetPersistence(persistance);
    perlin.SetOctaveCount(octaveCount);
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

void Generator::generateNoiseMap2D(int newLines, int newColumns, int newSeed){
    setSeed(newSeed);
    setColumns(newColumns);
    setLines(newLines);
    perlin.SetSeed(seed);
    perlin.SetFrequency(frequency);
    perlin.SetLacunarity(lacunarity);
    perlin.SetPersistence(persistance);
    perlin.SetOctaveCount(octaveCount);
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

void Generator::generateNoiseMap3D(){
    perlin.SetSeed(seed);
    perlin.SetFrequency(frequency);
    perlin.SetLacunarity(lacunarity);
    perlin.SetPersistence(persistance);
    perlin.SetOctaveCount(octaveCount);
    for (size_t z = 0; z < size_t(zedLevels); z++){
        vector<vector<double>> zed;
        for(size_t y = 0; y < size_t(lines); y++){
            vector<double> line;
            for(size_t x = 0; x < size_t(columns); x++){
                line.push_back(perlin.GetValue(x, y, z));
            }
            zed.push_back(line);
        }
        noisemap3D.push_back(zed);
    }

    double high = -MAXFLOAT;
    double low = MAXFLOAT;
    double val;

    for(vector<vector<double>> zed : noisemap3D){
        for(vector<double> line : zed){
            for(double val : line){
                if(val < low){
                    low = val;
                }
                else if(val > high) {
                    high = val;
                }
            }
        }
    }

    high = high - low;

    for (size_t z = 0; z < size_t(zedLevels); z++){
        for(size_t y = 0; y < size_t(lines); y++){
            for(size_t x = 0; x < size_t(columns); x++){
                val = noisemap3D.at(z).at(y).at(x);
                val = val - low;
                val = val / high;
                noisemap3D.at(z).at(y).at(x) = val;
            }
        }
    }
}

void Generator::generateNoiseMap3D(int newSeed){
    setSeed(newSeed);
    perlin.SetSeed(seed);
    perlin.SetFrequency(frequency);
    perlin.SetLacunarity(lacunarity);
    perlin.SetPersistence(persistance);
    perlin.SetOctaveCount(octaveCount);
    for (size_t z = 0; z < size_t(zedLevels); z++){
        vector<vector<double>> zed;
        for(size_t y = 0; y < size_t(lines); y++){
            vector<double> line;
            for(size_t x = 0; x < size_t(columns); x++){
                line.push_back(perlin.GetValue(x, y, z));
            }
            zed.push_back(line);
        }
        noisemap3D.push_back(zed);
    }

    double high = -MAXFLOAT;
    double low = MAXFLOAT;
    double val;

    for(vector<vector<double>> zed : noisemap3D){
        for(vector<double> line : zed){
            for(double val : line){
                if(val < low){
                    low = val;
                }
                else if(val > high) {
                    high = val;
                }
            }
        }
    }

    high = high - low;

    for (size_t z = 0; z < size_t(zedLevels); z++){
        for(size_t y = 0; y < size_t(lines); y++){
            for(size_t x = 0; x < size_t(columns); x++){
                val = noisemap3D.at(z).at(y).at(x);
                val = val - low;
                val = val / high;
                noisemap3D.at(z).at(y).at(x) = val;
            }
        }
    }
}

void Generator::generateNoiseMap3D(int newLines, int newColumns, int newZedLevels, int newSeed){
    setLines(newLines);
    setColumns(newColumns);
    setZedLevels(newZedLevels);
    setSeed(newSeed);
    perlin.SetFrequency(frequency);
    perlin.SetLacunarity(lacunarity);
    perlin.SetPersistence(persistance);
    perlin.SetOctaveCount(octaveCount);
    for (size_t z = 0; z < size_t(zedLevels); z++){
        vector<vector<double>> zed;
        for(size_t y = 0; y < size_t(lines); y++){
            vector<double> line;
            for(size_t x = 0; x < size_t(columns); x++){
                line.push_back(perlin.GetValue(x, y, z));
            }
            zed.push_back(line);
        }
        noisemap3D.push_back(zed);
    }

    double high = -MAXFLOAT;
    double low = MAXFLOAT;
    double val;

    for(vector<vector<double>> zed : noisemap3D){
        for(vector<double> line : zed){
            for(double val : line){
                if(val < low){
                    low = val;
                }
                else if(val > high) {
                    high = val;
                }
            }
        }
    }

    high = high - low;

    for (size_t z = 0; z < size_t(zedLevels); z++){
        for(size_t y = 0; y < size_t(lines); y++){
            for(size_t x = 0; x < size_t(columns); x++){
                val = noisemap3D.at(z).at(y).at(x);
                val = val - low;
                val = val / high;
                noisemap3D.at(z).at(y).at(x) = val;
            }
        }
    }
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
int Generator::getZedLevels(){
    return zedLevels;
}

vector<vector<double>> & Generator::getNoiseMap2D() {
    vector<vector<double>> & noisemapRef = noisemap2D;
    return noisemapRef;
}

vector<vector<vector<double>>> & Generator::getNoiseMap3D(){
    vector<vector<vector<double>>> & noisemapRef = noisemap3D;
    return noisemapRef;
}

double Generator::getPersistance(){
    return persistance;
}

double Generator::getLacunarity(){
    return lacunarity;
}

double Generator::getFrequency(){
    return frequency;
}

int Generator::getOctaveCount(){
    return octaveCount;
}

