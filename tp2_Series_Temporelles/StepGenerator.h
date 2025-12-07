#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

using namespace std;

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    StepGenerator(int seed);

    vector<double> generateTimeSeries(int size) override;
};

#endif // STEPGENERATOR_H