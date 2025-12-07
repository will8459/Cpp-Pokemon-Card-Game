#ifndef KNN_H
#define KNN_H

#include <string>
#include <vector>
#include "TimeSeriesDataset.h"

using namespace std;

class KNN {
private:
    int k;
    string similarity_measure;

public:
    KNN(int k, string similarity_measure);

    // Méthode pour évaluer la précision du modèle
    // Renvoie un score entre 0 et 1 (Accuracy)
    double evaluate(const TimeSeriesDataset& trainData,
                    const TimeSeriesDataset& testData,
                    const vector<int>& ground_truth);
};

#endif // KNN_H