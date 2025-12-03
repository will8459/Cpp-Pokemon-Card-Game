#include "KNNDouble.h"

KNNDouble::KNNDouble(int _k) : KNN<pair<double, double>>(_k) {
}

KNNDouble::~KNNDouble() {}

double KNNDouble::similarityMeasure(const pair<double, double>& a, const pair<double, double>& b) {
    // a.first = Poids, a.second = Taille
    double diffWeight = a.first - b.first;
    double diffHeight = a.second - b.second;

    return sqrt(pow(diffWeight, 2) + pow(diffHeight, 2));
}