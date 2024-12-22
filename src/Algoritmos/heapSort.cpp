#include <bits/stdc++.h>
#include "../include/raylib.h"
#include "../include/View.h"
#include "../include/Algoritmos.h"

using namespace std;

void heapify(int *vet, int tam, int i)
{
    int maior;

    maior = i;

    if ((2 * i) + 1 < tam && vet[(2 * i) + 1] > vet[maior])
    {
        maior = (2 * i) + 1;
    }

    if ((2 * i) + 2 < tam && vet[(2 * i) + 2] > vet[maior])
    {
        maior = (2 * i) + 2;
    }

    if (maior != i)
    {
        swap(vet[i], vet[maior]);
        heapify(vet, tam, maior);
    }
}

void heapSort(int *vet, int tam)
{
    for (int i = (tam / 2) - 1; i >= 0; i--)
    {
        heapify(vet, tam, i);
    }

    for (int i = tam - 1; i > 0; i--)
    {
        swap(vet[0], vet[i]);

        viewIt(vet, tam, vet[0], vet[i]);

        heapify(vet, i, 0);
    }
}