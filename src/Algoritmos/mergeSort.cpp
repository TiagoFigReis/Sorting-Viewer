#include "../include/raylib.h"
#include "../include/view.h"
#include "../include/Algoritmos.h"
#include <bits/stdc++.h>

using namespace std;

int mergeSort(int *vet, int tam, int ini, int fim){
    int meio = (ini + fim)/2, flag;
    if(ini < fim){
        if(mergeSort(vet,tam, ini,meio)){
            return 1;
        }
        if(mergeSort(vet, tam, meio + 1, fim)){
            return 1;
        }
        if(merge(vet, tam, ini, meio, fim) < 0){
            return 1;
        }
    }

    return 0;
}

int merge(int *vet,int tam, int ini, int meio, int fim){
    int vetAux[(fim-ini) + 1], i = ini, j = meio + 1, k = 0;

    while(i <= meio && j <= fim){
        if(viewIt(vet, tam, i, j)){
            return -1;
        };

        if(vet[i] <= vet[j]){
            vetAux[k] = vet[i];
            i++;
        }else{
            vetAux[k] = vet[j];
            j++;
        }
        k++;
    }

    if(i <= meio){
        while(i <= meio){
            vetAux[k] = vet[i];
            i++;
            k++;
        }
    }else{
       while(j <= fim){
            vetAux[k] = vet[j];
            j++;
            k++;
        }
    }

    k = 0;

    for(int i = ini; i <= fim; i++){
        vet[i] = vetAux[k];
        k++;
    }

    return 0;
}