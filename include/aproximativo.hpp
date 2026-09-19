#ifndef APROXIMATIVO_HPP
#define APROXIMATIVO_HPP

#include <vector>

// recebe matriz de adjacência e retorna rota final otimizada
std::vector<int> executarHeuristica(const std::vector<std::vector<int>>& matriz);

// custo total de uma rota no grafo
int calcularCustoRota(const std::vector<int>& rota, const std::vector<std::vector<int>>& matriz);

#endif