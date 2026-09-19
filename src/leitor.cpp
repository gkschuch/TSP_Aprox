#include "leitor.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::vector<int>> lerArquivoTSP(const std::string &nomeArquivo) {
  std::ifstream arquivo(nomeArquivo);
  std::vector<std::vector<int>> matriz;
  std::string linha;

  while (std::getline(arquivo, linha)) {
    if (linha.empty())
      continue;
    std::istringstream streamLinha(linha);
    std::vector<int> linhaAtual;
    int valor;

    while (streamLinha >> valor) {
      linhaAtual.push_back(valor);
    }
    if (!linhaAtual.empty()) {
      matriz.push_back(linhaAtual);
    }
  }
  arquivo.close();
  return matriz;
}