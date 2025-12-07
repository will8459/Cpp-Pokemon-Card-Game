#include "GaussianGenerator.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

GaussianGenerator::GaussianGenerator():
TimeSeriesGenerator(), mean(0), stddev(1)
{
    srand(static_cast<unsigned int>(time(nullptr))); // initialiser le générateur de nombres aléatoires
}

GaussianGenerator::GaussianGenerator(int _seed, double _mean, double _stddev):
TimeSeriesGenerator(_seed), mean(_mean), stddev(_stddev)
{
    srand(_seed);
}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> series;
    series.reserve(size);

    for (int i = 0; i < size; ++i) {
        series.push_back(boxMuller());
    }
    return series;
}

double GaussianGenerator::boxMuller() {
    double u1 = (rand() + 1.0) / (RAND_MAX + 1.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 1.0);

    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

    return mean + (z * stddev);
}