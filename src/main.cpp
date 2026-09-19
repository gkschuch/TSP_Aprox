#include "leitor.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> matriz = lerArquivoTSP("graphs/tsp4_7013.txt");

  for (size_t i = 0; i < matriz.size(); i++) {
    for (size_t j = 0; j < matriz[i].size(); j++) {
      std::cout << matriz[i][j] << "\t";
    }
    std::cout << "\n";
  }
  return 0;
}
