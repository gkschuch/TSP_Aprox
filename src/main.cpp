#include "leitor.hpp"
#include "aproximativo.hpp"
#include "exato.hpp"
#include <iostream>
#include <chrono>
#include <string>

using namespace std::chrono;

int extrairOtimoDoNome(const std::string& nomeArquivo) {
    size_t posUnderscore = nomeArquivo.find_last_of('_');
    size_t posPonto = nomeArquivo.find_last_of('.');
    
    if (posUnderscore != std::string::npos && posPonto != std::string::npos && posUnderscore < posPonto) {
        std::string strOtimo = nomeArquivo.substr(posUnderscore + 1, posPonto - posUnderscore - 1);
        try {
            return std::stoi(strOtimo);
        } catch (...) {
            return -1;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "./tsp_solver <caminho_do_arquivo.txt>\n";
        return 1;
    }

    std::string caminhoArquivo = argv[1];
    std::vector<std::vector<int>> matriz = lerArquivoTSP(caminhoArquivo);

    if (matriz.empty()) {
        std::cout << "falha pra carregar.\n";
        return 1;
    }

    std::cout << "grafo: " << caminhoArquivo << " (tamanho: " << matriz.size() << ")\n";
    
    int valorOtimo = extrairOtimoDoNome(caminhoArquivo);

    // ====================== aproximativo =========================
    auto inicio = high_resolution_clock::now();

    std::vector<int> rotaAprox = executarHeuristica(matriz);
    int custoAprox = calcularCustoRota(rotaAprox, matriz);

    auto fim = high_resolution_clock::now();
    duration<double> tempoAprox = fim - inicio;

    std::cout << "\n\t||| aproximativo: |||\n";
    std::cout << "custo: " << custoAprox << "\n";
    std::cout << "tempo: " << tempoAprox.count() << " segundos\n";
    
    if (valorOtimo != -1) {
        double gap = ((double)(custoAprox - valorOtimo) / valorOtimo) * 100.0;
        std::cout << "gap em relacao ao otimo (" << valorOtimo << "): " << gap << "%\n";
    }

    // ======================= exato =============================

    double limiteSegundos = 180.0;
    std::cout << "\n\t||| exato |||  (limite de " << limiteSegundos << "segundos)\n";
    
    inicio = high_resolution_clock::now();

    int custoExato = executarExato(matriz, limiteSegundos);

    fim = high_resolution_clock::now();
    duration<double> tempoExato = fim - inicio;

    if (custoExato == -1) {
        std::cout << "status: TIMEOUT (" << tempoExato.count() << " segundos)\n";
    } else {
        std::cout << "custo: " << custoExato << "\n";
        std::cout << "tempo: " << tempoExato.count() << " segundos\n";
    }

    return 0;
}