#include <stdio.h>
#include <stdlib.h>

int array[5] = {};

// int tamanhoArray(int array[]){

//     int sum = 0;

//     for (int i = 0; array[i]; i++){
//         sum++;
//     }

//     return sum;
// }

void imprimirArray(){

    int tamanho = sizeof(array)/sizeof(array[0]);

    printf("\nArray = [ ");
    for (int i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void main() {

    array[0] = 4;
    array[1] = 0;
    array[2] = 10;

    imprimirArray();
}

