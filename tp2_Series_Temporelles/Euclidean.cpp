#include "Euclidean.h"
#include <algorithm>

using namespace std;

double euclidean_distance(const vector<double>& x, const vector<double>& y) {
    double sum = 0.0;

    // Sécurité : On s'assure de ne pas dépasser la taille du plus petit vecteur
    // La distance euclidienne suppose normalement x.size() == y.size()
    size_t n = min(x.size(), y.size());

    for (size_t i = 0; i < n; ++i) {
        double diff = x[i] - y[i];
        sum += diff * diff;
    }

    return sqrt(sum);
}