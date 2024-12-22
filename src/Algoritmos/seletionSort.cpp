#include "../include/raylib.h"
#include "../include/View.h"
#include "../include/Algoritmos.h"
#include <bits/stdc++.h>

using namespace std;


void seletionSort(int *vet, int tam)
{
    int men, aux;
    for (int i = 0; i < tam - 1; i++)
    {
        men = i;
        for (int j = i + 1; j < tam; j++)
        {
            if (vet[j] < vet[men])
            {
                men = j;
            }
        }

        if(viewIt(vet, tam, i, men)){
            return;
        };

        if (vet[men] < vet[i])
        {
            aux = vet[men];
            vet[men] = vet[i];
            vet[i] = aux;
        }
    }

    return;
}