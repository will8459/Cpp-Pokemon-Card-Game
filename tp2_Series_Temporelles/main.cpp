#include "GaussianGenerator.h"
#include "SinWaveGenerator.h"
#include "StepGenerator.h"
#include "TimeSeriesDataset.h"
#include "KNN.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. Initialisation des datasets
    // trainData : znormalize=false, isTrain=true
    // testData  : znormalize=false, isTrain=false
    TimeSeriesDataset trainData(false, true);
    TimeSeriesDataset testData(false, false);

    // 2. Instanciation des générateurs
    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

    // --- Génération des données d'ENTRAÎNEMENT (Train) ---

    // Ajout de 2 séries Gaussiennes (Label 0)
    vector<double> gaussian1 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian1, 0);

    vector<double> gaussian2 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian2, 0);

    // Ajout de 2 séries Sinus (Label 1)
    vector<double> sin1 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin1, 1);

    vector<double> sin2 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin2, 1);

    // Ajout de 2 séries Step (Label 2)
    vector<double> step1 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step1, 2);

    vector<double> step2 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step2, 2);


    // --- Génération des données de TEST et Ground Truth ---

    vector<int> ground_truth;

    // Test 1 : Gaussien (attendu 0)
    testData.addTimeSeries(gsg.generateTimeSeries(11), 0); // Le label ici sert juste au stockage interne, mais pour l'eval on utilise ground_truth
    ground_truth.push_back(0);

    // Test 2 : Sinus (attendu 1)
    testData.addTimeSeries(swg.generateTimeSeries(11), 1);
    ground_truth.push_back(1);

    // Test 3 : Step (attendu 2)
    testData.addTimeSeries(stg.generateTimeSeries(11), 2);
    ground_truth.push_back(2);


    // --- Évaluation avec KNN ---

    // Premier KNN : k=1, distance=dtw
    KNN knn_1(1, "dtw");
    cout << "Accuracy KNN (k=1, dtw) : "
         << knn_1.evaluate(trainData, testData, ground_truth) << endl;

    // Deuxième KNN : k=2, distance=euclidean_distance
    KNN knn_2(2, "euclidean_distance");
    cout << "Accuracy KNN (k=2, euclidean) : "
         << knn_2.evaluate(trainData, testData, ground_truth) << endl;

    // Troisième KNN : k=3, distance=euclidean_distance
    KNN knn_3(3, "euclidean_distance");
    cout << "Accuracy KNN (k=3, euclidean) : "
         << knn_3.evaluate(trainData, testData, ground_truth) << endl;

    return 0;
}