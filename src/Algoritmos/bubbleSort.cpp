#include "../include/raylib.h"
#include "../include/View.h"
#include "../include/Algoritmos.h"
#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int *vet, int tam)
{
    int aux;
    for (int i = 0; i < tam; i++)
    {
        for (int j = 1; j < tam - i; j++)
        {
            if(viewIt(vet, tam, j, j-1)){
                return ;
            };

            if (vet[j] < vet[j - 1])
            {
                swap(vet[j-1], vet[j]);
            }
        }
    }

    return;
}