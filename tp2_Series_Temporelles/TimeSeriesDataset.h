#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>

using namespace std;

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    vector<vector<double>> data; // Vecteur de vecteurs pour stocker plusieurs séries
    vector<int> labels;
    int maxLength;
    int numberOfSamples;

    // Méthode interne pour effectuer la Z-normalization sur une série
    void _znormalizeSeries(vector<double>& series) const;

public:
    TimeSeriesDataset(bool znormalize, bool isTrain);

    // Méthode pour ajouter une série temporelle et son étiquette (label)
    // Elle gère la normalisation si nécessaire et met à jour maxLength
    void addTimeSeries(const vector<double>& series, int label);

    const vector<vector<double>>& getData() const;
    const vector<int>& getLabels() const;
    int getNumberOfSamples() const;
};

#endif // TIMESERIESDATASET_H