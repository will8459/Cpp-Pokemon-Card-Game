#include "Distances.h"
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// --- 1. Distance Euclidienne ---
double Distances::euclidean_distance(const vector<double>& x, const vector<double>& y) {
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

// --- 2. Dynamic Time Warping (DTW) ---
double Distances::dtw(const vector<double>& x, const vector<double>& y) {
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

// --- 3. Edit Distance on Real sequences (EDR) ---
double Distances::edr(const vector<double>& x, const vector<double>& y) {
    size_t n = x.size();
    size_t m = y.size();
    const double EPSILON = 0.25; // Seuil de tolérance

    // Matrice de taille (n+1) x (m+1)
    vector<vector<double>> D(n + 1, vector<double>(m + 1, 0.0));

    // Initialisation des coûts de base (insertions/suppressions pures)
    for (size_t i = 0; i <= n; ++i) D[i][0] = i;
    for (size_t j = 0; j <= m; ++j) D[0][j] = j;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            // Coût 0 si match (différence < epsilon), sinon 1
            double subCost = (abs(x[i - 1] - y[j - 1]) < EPSILON) ? 0.0 : 1.0;

            D[i][j] = min({
                D[i - 1][j - 1] + subCost, // Substitution
                D[i - 1][j] + 1.0,         // Suppression
                D[i][j - 1] + 1.0          // Insertion
            });
        }
    }
    return D[n][m];
}