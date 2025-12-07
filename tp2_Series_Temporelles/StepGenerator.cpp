#include "StepGenerator.h"
#include <cstdlib>
#include <ctime>

using namespace std;

StepGenerator::StepGenerator() : TimeSeriesGenerator() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

StepGenerator::StepGenerator(int _seed) :
TimeSeriesGenerator(_seed)
{
    srand(_seed);
}

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> series;
    series.reserve(size);

    double currentValue = 0;
    
    if (size > 0) {
        series.push_back(currentValue);
    }

    for (int i = 1; i < size; ++i) {
        // Probabilité 50% (rand() % 2 renvoie 0 ou 1)
        if (rand() % 2 == 0) {
            // Nouvelle valeur aléatoire entre 0 et 100
            currentValue = rand() % 101; 
        }
        series.push_back(currentValue);
    }

    return series;
}