#include "TimeSeriesDataset.h"
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

TimeSeriesDataset::TimeSeriesDataset(bool _znormalize, bool _isTrain)
    : znormalize(_znormalize), isTrain(_isTrain), maxLength(0), numberOfSamples(0) {
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    // 1. Copie locale de la série pour pouvoir la modifier (normaliser) si besoin
    vector<double> seriesToProcess = series;

    // 2. Application de la Z-normalization si demandée
    if (znormalize) {
        _znormalizeSeries(seriesToProcess);
    }

    // 3. Ajout au dataset
    data.push_back(seriesToProcess);
    labels.push_back(label);

    // 4. Mise à jour des métadonnées
    numberOfSamples++;
    if (seriesToProcess.size() > maxLength) {
        maxLength = static_cast<int>(seriesToProcess.size());
    }
}

// Implémentation de la formule : x = (x - mean) / stddev
void TimeSeriesDataset::_znormalizeSeries(vector<double>& series) const {
    if (series.empty()) return;

    // Calcul de la moyenne
    double sum = accumulate(series.begin(), series.end(), 0.0);
    double mean = sum / series.size();

    // Calcul de l'écart-type (Standard Deviation)
    double sq_sum = 0.0;
    for (double val : series) {
        sq_sum += pow(val - mean, 2);
    }
    double stddev = sqrt(sq_sum / series.size());

    // Protection contre la division par zéro (si la série est constante)
    if (stddev == 0) return;

    // Application de la transformation sur chaque élément
    for (double& val : series) {
        val = (val - mean) / stddev;
    }
}

const vector<vector<double>>& TimeSeriesDataset::getData() const {
    return data;
}

const vector<int>& TimeSeriesDataset::getLabels() const {
    return labels;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}