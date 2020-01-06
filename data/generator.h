#include <vector>
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
    Generator(int lines,int columns);
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
    vector<vector<double>> getNoiseMap2D() const;
    vector<vector<vector<double>>> getNoiseMap3D() const;
    private:

    int seed;
    int lines;
    int columns;
    vector<vector<double>> noisemap2D;
    vector<vector<vector<double>>> noisemap3D;


};
#endif