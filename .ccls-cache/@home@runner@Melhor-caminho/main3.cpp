#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;

int main() {
  auto start_time = std::chrono::high_resolution_clock::now();
  
    double matriz[8][8] = {
        {0.0, 1418.18, 2257.78, 1999.43, 1527.34, 2146.76, 1583.07, 4.69},
        {1428.26, 0.0, 1396.6, 1760.27, 1535.65, 2194.93, 1343.9, 1432.95},
        {2232.85, 1317.03, 0.0, 943.18, 1660.95, 2930.88, 1048.83, 2237.53},
        {1935.89, 1850.79, 1243.16, 0.0, 722.31, 1992.24, 689.71, 1940.58},
        {1585.47, 1514.45, 1686.92, 778.61, 0.0, 1327.6, 765.9, 1590.16},
        {2644.37, 2569.23, 3583.8, 2658.34, 1802.44, 0.0, 2645.62, 2649.05},
        {1368.0, 1161.08, 1456.39, 969.82, 795.41, 1949.74, 0.0, 1372.69},
        {52.52, 1413.49, 2253.09, 1994.74, 1522.65, 2142.07, 1578.38, 0.0}
    };

    srand(static_cast<unsigned int>(time(0))); // Para gerar números aleatórios diferentes a cada execução

    vector<int> melhor;
    double melhor_distancia = 9999999999999999999999.0;

    for (int i = 0; i < 99999999; ++i) {
        double distan = 0.0;
        int origem = 0;
        vector<int> caminho;

        for (int i = 0; i < 8; ++i) {
            int aleatorio = rand() % 8;
            while (find(caminho.begin(), caminho.end(), aleatorio) != caminho.end() || aleatorio == origem) {
                aleatorio = rand() % 8;
            }
            distan += matriz[origem][aleatorio];
            origem = aleatorio;
            caminho.push_back(origem);
        }

        if (distan <= melhor_distancia) {
            melhor_distancia = distan;
            melhor = caminho;
        }
    }

    cout << melhor_distancia << endl;
    for (int cidade : melhor) {
        cout << cidade << " ";
    }
    cout << endl;
  
    // Finaliza a medição do tempo
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calcula o tempo decorrido
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;

    cout << "Tempo de execucao: " << elapsed_seconds.count() << " segundos" << endl;

    return 0;
}
