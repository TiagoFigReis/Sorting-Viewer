#include "../include/raylib.h"
#include "../include/View.h"
#include "../include/Algoritmos.h"
#include <bits/stdc++.h>

using namespace std;

int particiona(int *vet, int tam, int ini, int fim)
{
    int pivo, pos = ini + (rand() % ((fim - ini) + 1));

    swap(vet[ini], vet[pos]);

    pivo = vet[ini];

    pos = ini;

    for (int i = ini + 1; i <= fim; i++)
    {
        if (vet[i] <= pivo)
        {

            pos++;
            if (i != pos)
            {
                swap(vet[i], vet[pos]);
            }
        }

        if(viewIt(vet, tam, i, pos)){
            return -1;
        }
    }

    swap(vet[ini], vet[pos]);

    return pos;
}

int quickSort(int *vet, int tam, int ini, int fim)
{
    int pivo;

    if (ini < fim)
    {
        pivo = particiona(vet, tam, ini, fim);

        if(pivo < 0){
            return 1;
        }

        if(quickSort(vet, tam, ini, pivo - 1)){
            return 1;
        }

        if(quickSort(vet, tam, pivo + 1, fim)){
            return 1;
        }
    }
    return 0;
}