#include "aproximativo.hpp"
#include <algorithm>

using namespace std;

const int INF = 1e9; 

vector<vector<int>> primMST(const vector<vector<int>>& grafo) {
    int n = grafo.size();
    vector<int> chave(n, INF);
    vector<int> pai(n, -1);
    vector<bool> inMST(n, false);

    chave[0] = 0;

    for (int i = 0; i < n; i++) { // vertice com menor chave que nao ta incluso
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && (u == -1 || chave[v] < chave[u])) {
                u = v;
            }
        }

        if (u == -1) break;
        inMST[u] = true;

        for (int v = 0; v < n; v++) { // atualiza os vizinhos
            if (u != v && !inMST[v] && grafo[u][v] < chave[v]) {
                pai[v] = u;
                chave[v] = grafo[u][v];
            }
        }
    }

    vector<vector<int>> adj(n); // monta lista de adjacencia da arvore
    for (int i = 1; i < n; i++) {
        if (pai[i] != -1) {
            adj[pai[i]].push_back(i);
            adj[i].push_back(pai[i]);
        }
    }
    return adj;
}

// dfs
void dfs(int u, const vector<vector<int>>& adj, vector<bool>& vis, vector<int>& rota) {
    vis[u] = true;
    rota.push_back(u);
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj, vis, rota);
    }
}

void opt2(vector<int>& rota, const vector<vector<int>>& matriz) {
    bool mudou = true;
    int n = rota.size();
    
    while (mudou) {
        mudou = false;
        for (int i = 1; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                
                // calcula variacao de custo dos idnices
                int atual = matriz[rota[i-1]][rota[i]] + matriz[rota[j]][rota[j+1]];
                int novo = matriz[rota[i-1]][rota[j]] + matriz[rota[i]][rota[j+1]];
                
                if (novo < atual) {
                    reverse(rota.begin() + i, rota.begin() + j + 1);
                    mudou = true;
                }
            }
        }
    }
}

vector<int> executarHeuristica(const vector<vector<int>>& matriz) {
    int n = matriz.size();

    vector<vector<int>> adjMST = primMST(matriz);
    vector<bool> vis(n, false);
    vector<int> rota;
    
    dfs(0, adjMST, vis, rota);
    rota.push_back(0); // fecha o ciclo
    
    opt2(rota, matriz);

    return rota;
}

int calcularCustoRota(const vector<int>& rota, const vector<vector<int>>& matriz) {
    int custo = 0;
    for (size_t i = 0; i < rota.size() - 1; i++) {
        custo += matriz[rota[i]][rota[i + 1]];
    }
    return custo;
}