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


class Generator{
    
    public:

    /**
    *   Default constructor.
    *   @param none
    *   @return a default Generator
    */
    Generator();

    /**
    *   Constructor taking only height and width of the map to generate.
    *   @param newLines the number of lines the generator should have
    *   @param newColumns the number of columns the generator should have
    *   @return a generator of the specified dimensions
    */
    Generator(int newLines,int newColumns);

    /**
    *   Constructor taking height, width, depth, and seed of the map to generate.
    *   @param newLines the number of lines the generator should have
    *   @param newColumns the number of columns the generator should have
    *   @param newZedLevels the number of zed levels that the generator should create;
    *   @param newSeed the seed to be used to generate the noisemap
    *   @return a generator of the specified dimensions using the given seed
    */
    Generator(int newLines, int newColumns, int newZedLevels, int newSeed);

    ///setters and generators    
    void setSeed(int newSeed);
    void setLines(int newLineCount);
    void setColumns(int newColumnsCount);
    void setZedLevels(int newZedLevelCount);
    void setPersistance(double newPersistance);
    void setLacunarity(double newLacunarity);
    void setFrequency(double newFrequency);
    void setOctaveCount(int newOctaveCount);
    ///Done
    void generateNoiseMap2D();

    ///todo
    void generateNoiseMap2D(int seed);
    void generateNoiseMap2D(int lines, int columns, int seed);
    void generateNoiseMap3D();
    void generateNoiseMap3D(int seed);
    void generateNoiseMap3D(int lines, int columns, int zLevels, int seed);

    ///getters
    int getSeed();
    int getLines();
    int getColumns();
    int getZedLevels();
    double getPersistance();
    double getLacunarity();
    double getFrequency();
    int getOctaveCount();

    std::vector<std::vector<double>> & getNoiseMap2D();
    std::vector<std::vector<std::vector<double>>> & getNoiseMap3D();
    private:

    int seed;
    int lines;
    int columns;
    int zedLevels;
    double lacunarity;
    double frequency;
    double persistance;
    int octaveCount;
    std::vector<std::vector<double>> noisemap2D;
    std::vector<std::vector<std::vector<double>>> noisemap3D;
    noise::module::Perlin perlin;


};
#endif