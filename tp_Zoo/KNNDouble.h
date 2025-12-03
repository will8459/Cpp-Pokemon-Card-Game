#ifndef KNNDOUBLE_H
#define KNNDOUBLE_H

#include "KNN.h"
#include <utility>
#include <cmath>

using namespace std;

// Héritage : On spécifie que T est une paire de doubles (Poids, Taille)
class KNNDouble : public KNN<pair<double, double>> {
public:
    KNNDouble(int _k);
    ~KNNDouble();

    // Calcule la distance Euclidienne entre deux paires (poids/taille)
    double similarityMeasure(const pair<double, double>& a, const pair<double, double>& b) override;
};

#endif