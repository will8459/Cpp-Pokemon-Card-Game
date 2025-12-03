#include "KNNString.h"

KNNString::KNNString(int _k) : KNN<vector<string>>(_k) {}

KNNString::~KNNString() {}

// Implémentation Itérative (Matrice) de Levenshtein
int KNNString::levenshteinDistance(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Création d'une matrice (m+1) x (n+1)
    // dp[i][j] stockera la distance entre les i premiers char de s1 et les j premiers de s2
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Initialisation de la première colonne et première ligne
    // Transformer une chaine de taille i en chaine vide demande i suppressions
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    // Remplissage de la matrice
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // Si les caractères sont identiques, pas de coût supplémentaire
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Sinon, on prend le minimum des 3 opérations + 1
                dp[i][j] = 1 + min({
                    dp[i - 1][j],    // Suppression
                    dp[i][j - 1],    // Insertion
                    dp[i - 1][j - 1] // Substitution
                });
            }
        }
    }

    return dp[m][n];
}

double KNNString::similarityMeasure(const vector<string>& a, const vector<string>& b) {
    double totalDist = 0.0;
    
    // On suppose que les deux vecteurs ont la même taille (4 attributs)
    // On somme la distance de Levenshtein pour chaque attribut correspondant
    // Couleur vs Couleur, Diet vs Diet, etc.
    size_t size = min(a.size(), b.size());
    
    for (size_t i = 0; i < size; ++i) {
        totalDist += levenshteinDistance(a[i], b[i]);
    }
    
    return totalDist;
}