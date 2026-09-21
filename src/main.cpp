#include "leitor.hpp"
#include "aproximativo.hpp"
#include "exato.hpp"
#include <iostream>
#include <chrono>

using namespace std::chrono;

int main(int argc, char *argv[]) {

  std::vector<std::vector<int>> matriz = lerArquivoTSP("graphs/tsp4_7013.txt");

  for (size_t i = 0; i < matriz.size(); i++) {
    for (size_t j = 0; j < matriz[i].size(); j++) {
      std::cout << matriz[i][j] << "\t";
    }
    std::cout << "\n";
  }

  auto inicio = high_resolution_clock::now();

  std::vector<int> rotaAprox = executarHeuristica(matriz);
  int custoAprox = calcularCustoRota(rotaAprox, matriz);

  auto fim = high_resolution_clock::now();
  duration<double> tempo = fim - inicio;

  std::cout << "\n\t||| aproximativo: |||\n";
  std::cout << "custo: " << custoAprox << "\n";
  std::cout << "tempo: " << tempo.count() << " segundos\n";

  double limiteSegundos = 180.0;
  inicio = high_resolution_clock::now();

  int custoExato = executarExato(matriz, limiteSegundos);

  fim = high_resolution_clock::now();
  tempo = fim - inicio;

  std::cout << "\n\t||| exato: |||\n";
  std::cout << "custo: " << custoExato << "\n";
  std::cout << "tempo: " << tempo.count() << " segundos\n";

  return 0;
}