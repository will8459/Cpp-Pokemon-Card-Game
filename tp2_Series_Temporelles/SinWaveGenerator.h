#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double A;     // Amplitude
    double omega; // Fréquence
    double phi;   // Phase

public:
    SinWaveGenerator();
    SinWaveGenerator(int seed, double A, double omega, double phi);

    vector<double> generateTimeSeries(int size) override;
};

#endif // SINWAVEGENERATOR_H