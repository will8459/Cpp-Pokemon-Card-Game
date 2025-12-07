#ifndef TP2_TIMESERIESGENERATOR_H
#define TP2_TIMESERIESGENERATOR_H
#include <vector>
using namespace std;


class TimeSeriesGenerator {
public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    virtual vector<double> generateTimeSeries(int size) = 0;
    static void printTimeSeries(const vector<double>& series);
protected:
    int seed;
};


#endif //TP2_TIMESERIESGENERATOR_H