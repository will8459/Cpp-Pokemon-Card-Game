#include "DTW.h"
#include <cmath>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

double dtw(const vector<double>& x, const vector<double>& y) {
    size_t n = x.size();
    size_t m = y.size();

    // 1. Initialisation de la matrice D de taille (n+1) x (m+1)
    // On initialise tout à l'infini par défaut
    vector<vector<double>> D(n + 1, vector<double>(m + 1, numeric_limits<double>::infinity()));

    // 2. Point de départ
    D[0][0] = 0.0;

    // 3. Boucle principale
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            // Calcul du coût local : (x[i] - y[j])^2
            double diff = x[i - 1] - y[j - 1];
            double cost = diff * diff;

            // Formule de récurrence
            // D[i][j] = coût + min(insertion, suppression, correspondance)
            D[i][j] = cost + min({
                D[i - 1][j],    // Insertion
                D[i][j - 1],    // Suppression
                D[i - 1][j - 1] // Correspondance (Match)
            });
        }
    }

    // 4. Retour de la racine carrée du coin inférieur droit
    return sqrt(D[n][m]);
}