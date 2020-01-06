#include <vector>
#include <cmath>
#include <iostream>
#include <libnoise/module/modulebase.h>
#include <libnoise/exception.h>
#include <libnoise/model/model.h>
#include <libnoise/noise.h>
#include <cstdlib>
#ifndef GENERATOR_H
#define GENERATOR_H
using namespace noise;
using std::vector;
class Generator{
    
    public:
    Generator();
    Generator(int newLines,int newColumns);
    Generator(int newLines, int newColumns, int newZedLevels, int newSeed);
    module::Perlin perlin;

    ///setters and generators    
    void setSeed(int newSeed);
    void setLines(int newLineCount);
    void setColumns(int newColumnsCount);
    void generateNoiseMap2D();
    void generateNoiseMap2D(int seed);
    void generateNoiseMap2D(int lines, int columns, int seed);
    void generateNoiseMap3D();
    void generateNoiseMap3D(int seed);
    void generateNoiseMap3D(int lines, int columns, int zLevels, int seed);

    ///getters
    int getSeed();
    int getLines();
    int getColumns();
    vector<vector<double>> & getNoiseMap2D();
    vector<vector<vector<double>>> & getNoiseMap3D();
    private:

    int seed;
    int lines;
    int columns;
    int zedLevels;
    vector<vector<double>> noisemap2D;
    vector<vector<vector<double>>> noisemap3D;


};
#endif