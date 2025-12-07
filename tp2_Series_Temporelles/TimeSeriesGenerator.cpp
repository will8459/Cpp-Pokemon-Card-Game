#include "TimeSeriesGenerator.h"
#include <iostream>
#include <vector>
using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() :
seed(0) {
}

TimeSeriesGenerator::TimeSeriesGenerator(int seed) :
seed(seed) {
}

void TimeSeriesGenerator::printTimeSeries(const vector<double>& series) {
    cout << "Série temporelle (" << series.size() << " éléments) :" << endl;

    for (size_t i = 0; i < series.size(); ++i) {
        cout << series[i];
        if (i < series.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}