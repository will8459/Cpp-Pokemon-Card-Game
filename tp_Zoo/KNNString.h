#ifndef KNNSTRING_H
#define KNNSTRING_H

#include "KNN.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Héritage : T est un vecteur de string ({Color, Diet, Habitat, Sound})
class KNNString : public KNN<vector<string>> {
public:
    KNNString(int _k);
    ~KNNString();

    // Méthode utilitaire interne (Algorithme pur)
    int levenshteinDistance(const string& s1, const string& s2);

    double similarityMeasure(const vector<string>& a, const vector<string>& b) override;
};

#endif