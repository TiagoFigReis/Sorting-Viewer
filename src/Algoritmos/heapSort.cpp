#include <bits/stdc++.h>
#include "../include/raylib.h"
#include "../include/View.h"
#include "../include/Algoritmos.h"

using namespace std;

void heapify(int *vet, int tam)
{
    int maior;
    for (int i = (tam/2) - 1; i >= 0; i--)
    {
        maior = i;

        if( (2*i) + 1 < tam && vet[(2*i) + 1] > vet[maior]){
            maior = (2*i) + 1;
        }

        if( (2*i) + 2 < tam && vet[(2*i) + 2] > vet[maior]){
            maior = (2*i) + 2;
        }

        if(maior != i){
            swap(vet[i], vet[maior]);
        }
    }
}

void heapSort(int *vet, int tam)
{

    for(int i = tam - 1; i >= 0; i--)
    {
        heapify(vet, i);

        viewIt(vet, tam, vet[0], vet[i]);

        swap(vet[0], vet[i]);
    }
}