#ifndef KNN_H
#define KNN_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class KNN {
protected:
    int k; // le nombre de proche voisin

public:
    KNN() : k(1) {}
    KNN(int _k) : k(_k) {}
    virtual ~KNN() {}

    int getK() const { return k; }

    virtual double similarityMeasure(const T& a, const T& b) = 0;

    // --- Fonction Principale : findNearestNeighbors ---
    // Prend les données d'entrainement et la cible, renvoie les indices des k voisins les plus proches.
    vector<int> findNearestNeighbors(const vector<T>& trainData, const T& target) {
        // Cette structure va stocker des paires : {distance, index_original}
        // On a besoin de l'index pour savoir de quel animal il s'agit dans le Zoo.
        vector<pair<double, int>> distances;

        // 1. Calculer la distance entre la cible et TOUS les éléments d'entrainement
        for (size_t i = 0; i < trainData.size(); ++i) {
            // Appel de la fonction virtuelle (sera celle de l'enfant)
            double dist = similarityMeasure(trainData[i], target);
            
            // On stocke la distance et l'indice i
            distances.push_back(make_pair(dist, (int)i));
        }

        // 2. Trier les distances du plus petit au plus grand
        // On utilise une fonction lambda pour comparer uniquement les distances (first)
        sort(distances.begin(), distances.end(), 
            [](const pair<double, int>& a, const pair<double, int>& b) {
                return a.first < b.first; 
            });

        // 3. Récupérer les k premiers indices
        vector<int> neighborsIndices;
        
        // On prend k éléments, mais on fait attention si k > taille des données
        int limit = (k < (int)distances.size()) ? k : (int)distances.size();

        for (int i = 0; i < limit; ++i) {
            neighborsIndices.push_back(distances[i].second);
        }

        return neighborsIndices;
    }
};

#endif