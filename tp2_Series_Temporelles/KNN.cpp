#include "KNN.h"
#include "Distances.h"

#include <cmath>
#include <algorithm>
#include <map>
#include <iostream>
#include <limits>

using namespace std;

KNN::KNN(int _k, string _similarity_measure)
    : k(_k), similarity_measure(_similarity_measure) {
}

double KNN::evaluate(const TimeSeriesDataset& trainData, 
                     const TimeSeriesDataset& testData, 
                     const vector<int>& ground_truth) 
{
    int correct_predictions = 0;
    
    const vector<vector<double>>& trainSamples = trainData.getData();
    const vector<int>& trainLabels = trainData.getLabels();
    
    const vector<vector<double>>& testSamples = testData.getData();

    // Vérification de sécurité
    if (ground_truth.size() != testSamples.size()) {
        cout << "Erreur : La taille du ground_truth ne correspond pas au dataset de test." << endl;
        return 0.0;
    }

    // 1. Pour chaque série du dataset de test
    for (size_t i = 0; i < testSamples.size(); ++i) {
        
        // Vecteur de paires (distance, label_du_train)
        vector<pair<double, int>> distances;
        distances.reserve(trainSamples.size());

        // 2. Calculer la distance avec chaque série d'entraînement
        for (size_t j = 0; j < trainSamples.size(); ++j) {
            double dist = 0.0;

            if (similarity_measure == "dtw" || similarity_measure == "DTW") {
                dist = Distances::dtw(testSamples[i], trainSamples[j]);
            } else if (similarity_measure == "euclidean_distance" || similarity_measure == "Euclidean") {
                dist = Distances::euclidean_distance(testSamples[i], trainSamples[j]);
            } else if (similarity_measure == "edr" || similarity_measure == "EDR") {
                dist = Distances::edr(testSamples[i], trainSamples[j]);
            } else {
                // Par défaut ou erreur, on met une distance infinie
                cout << "Erreur: Mesure inconnue '" << similarity_measure << "'" << endl;
                dist = numeric_limits<double>::infinity();
            }

            distances.push_back({dist, trainLabels[j]});
        }

        // 3. Trier les distances par ordre croissant (du plus proche au plus loin)
        sort(distances.begin(), distances.end());

        // 4. Sélectionner les k plus proches voisins et voter
        map<int, int> class_counts;
        for (int n = 0; n < k && n < (int)distances.size(); ++n) {
            int label = distances[n].second;
            class_counts[label]++;
        }

        // Trouver la classe avec le plus de votes
        int predicted_label = -1;
        int max_votes = -1;

        for (auto const& [label, count] : class_counts) {
            if (count > max_votes) {
                max_votes = count;
                predicted_label = label;
            }
        }

        // 5. Comparer la prédiction avec la vérité terrain (ground_truth)
        if (predicted_label == ground_truth[i]) {
            correct_predictions++;
        }
    }

    // 6. Retourner l'accuracy
    if (testSamples.empty()) return 0.0;
    return static_cast<double>(correct_predictions) / testSamples.size();
}