#include "SinWaveGenerator.h"
#include <cmath>

using namespace std;

// Constructeur par défaut
SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(), A(1.0), omega(1.0), phi(0.0)
{
    // On choisit les valeurs de référence mathématiques du cercle trigonométrique (A=1, w=1) pour éviter un signal nul,
    // sachant que la normalisation Z compensera l'amplitude de toute façon.
}

// Constructeur paramétré
SinWaveGenerator::SinWaveGenerator(int _seed, double _A, double _omega, double _phi)
    : TimeSeriesGenerator(_seed), A(_A), omega(_omega), phi(_phi) 
{
    // On stocke le seed via la classe mère, mais comme la fonction sinus est déterministe, on n'a pas besoin d'appeler srand() ici.
}

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> series;
    series.reserve(size);

    for (int i = 0; i < size; ++i) {
        // Application de la formule : f(x) = A * sin(w*x + phi)
        // Ici 'x' correspond à l'indice 'i' (le temps)
        double value = A * sin(omega * i + phi);
        series.push_back(value);
    }

    return series;
}