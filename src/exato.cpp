#include "exato.hpp"
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int melhorCusto = INF;
bool estourouTempo = false;
chrono::time_point<chrono::high_resolution_clock> inicioTempo;
double limiteSegundos;

void tsp_backtracking(int u, int countVistados, int custoAtual,
                      const vector<vector<int>> &matriz,
                      vector<bool> &visitado) {
  int n = matriz.size();

  if (estourouTempo)
    return;

  auto agora = chrono::high_resolution_clock::now();
  chrono::duration<double> decorrido = agora - inicioTempo;
  if (decorrido.count() > limiteSegundos) {
    estourouTempo = true;
    return;
  }

  if (custoAtual >= melhorCusto)
    return;

  if (countVistados == n) {
    int custoFinal = custoAtual + matriz[u][0];
    if (custoFinal < melhorCusto)
      melhorCusto = custoFinal;
    return;
  }

  for (int v = 0; v < n; v++) {
    if (!visitado[v]) {
      visitado[v] = true;
      tsp_backtracking(v, countVistados + 1, custoAtual + matriz[u][v], matriz,
                       visitado);

      visitado[v] = false;
    }
  }
}

int executarExato(const vector<vector<int>> &matriz, double tempoLimite) {
  int n = matriz.size();

  melhorCusto = INF;
  estourouTempo = false;
  limiteSegundos = tempoLimite;
  inicioTempo = chrono::high_resolution_clock::now();

  vector<bool> visitado(n, false);

  visitado[0] = true;

  tsp_backtracking(0, 1, 0, matriz, visitado);

  if (estourouTempo)
    return -1;

  return melhorCusto;
}