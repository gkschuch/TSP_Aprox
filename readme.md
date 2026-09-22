# Trabalho prático de AED III - TSP

## Alunos: Gabriel K. Schuch e Henrique W. Voigt

## Sobre o Projeto
Este repositório contém a implementação de duas abordagens distintas para a resolução do **Problema do Caixeiro-Viajante (TSP)**:
1. **Algoritmo Aproximativo (Heurística):** Constrói uma solução viável rápida baseada em Árvore Geradora Mínima (Prim), travessia em pré-ordem (DFS) e refinamento local por 2-opt.
2. **Algoritmo Exato:** Utiliza busca exata (*Branch and Bound* / *Backtracking*) com podas baseadas em custo e controle de tempo limite (*timeout*) para evitar a explosão combinatória.

## Estrutura do Projeto

* `src/main.cpp`: Ponto de entrada do programa, gerencia leitura de arquivos, medição de tempo e execução dos algoritmos.
* `src/aproximativo.cpp` e `include/aproximativo.hpp`: Implementação do algoritmo aproximativo (Prim + DFS + 2-opt).
* `src/exato.cpp` / `include/exato.hpp`: Implementação da busca exata com limite de tempo e podas.
* `src/leitor.cpp` / `include/leitor.hpp`: Módulo responsável pela leitura e parsing dos arquivos de instâncias do TSP.
* `graphs/`: Diretório contendo as instâncias de teste (`.txt`).
* `Makefile`: Automação do processo de compilação.

## Instruções de Compilação e Execução

O projeto possui um `Makefile` configurado para facilitar a compilação utilizando o compilador `g++`.

Para instalação do Makefile em Linux, basta rodar no terminal: 

* DNF (Fedora, etc): `sudo dnf install make gcc-c++`
* APT (Ubuntu, etc): `sudo apt install make g++`

### Compilando e Executando o projeto:

Na raiz do projeto (`TSP/Aprox`), execute o comando "`make`". O executável gerado espera receber como argumento o caminho para o arquivo de instância do grafo, são eles:

* `./output/main graphs/tsp1_253.txt`
* `./output/main graphs/tsp2_1248.txt`
* `./output/main graphs/tsp3_1194.txt`
* `./output/main graphs/tsp4_7013.txt`
* `./output/main graphs/tsp5_27603.txt`

