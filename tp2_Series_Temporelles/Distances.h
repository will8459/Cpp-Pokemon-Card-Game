#ifndef DISTANCES_H
#define DISTANCES_H

#include <vector>
#include <cmath>

using namespace std;

class Distances {
public:
    // Méthodes statiques : accessibles sans instancier la classe
    static double euclidean_distance(const vector<double>& x, const vector<double>& y);
    static double dtw(const vector<double>& x, const vector<double>& y);
    static double edr(const vector<double>& x, const vector<double>& y);
};

#endif // DISTANCES_H