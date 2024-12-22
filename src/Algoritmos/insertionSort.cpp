#include "../include/raylib.h"
#include "../include/View.h"
#include "../include/Algoritmos.h"
#include <bits/stdc++.h>

using namespace std;

void insertionSort(int *vet, int tam)
{
    int valor, pos;

    for(int i = 1; i < tam; i++){
        valor = vet[i];
        pos = i - 1;

        while(pos >= 0 && valor < vet[pos]){
            vet[pos+1] = vet[pos];

            if(viewIt(vet, tam, pos, i)){
                return;
            };

            pos--;
        }

        vet[pos+1] = valor;
    }

    return;

}