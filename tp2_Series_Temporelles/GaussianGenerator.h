#ifndef TP2_GAUSSIANGENERATOR_H
#define TP2_GAUSSIANGENERATOR_H

#include <vector>
#include "TimeSeriesGenerator.h"
#include <iostream>

using namespace std;

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stddev;
public:
    GaussianGenerator();
    GaussianGenerator(int seed, double mean, double stddev);

    vector<double> generateTimeSeries(int size) override;
protected:
    double boxMuller();
};


#endif //TP2_GAUSSIANGENERATOR_H