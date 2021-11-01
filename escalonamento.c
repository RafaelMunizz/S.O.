#include<stdio.h>
#include<string.h>
#include <unistd.h>


int main() {

    int quantProcessos;

    printf("Quantidade de processos: ");
    scanf("%d", &quantProcessos);

    char cpu[10][10];
    int tempoExecucao[10], tempoEspera[10], timer = 3, tempoProcessamento[10], rt;
    int i, j, totalTempoEspera = 0, aux;
    float tempoEstimado;
    
    // Lendo dados
    for(i = 0; i < quantProcessos; i++) {
        printf("Nome do processo : ");
        scanf("%s", cpu[i]);
        printf("Tempo do processo : ");
        scanf("%d", &tempoProcessamento[i]);
        sleep(2);
        printf("\nProcessando %s ...\n\n", cpu[i]);
        sleep(2);

    }
    
    aux = quantProcessos;
    tempoEspera[0] = 0;

    i = 0;
    do {
        if(tempoProcessamento[i] > timer) {

            rt = tempoProcessamento[i] - timer;
            strcpy(cpu[quantProcessos], cpu[i]);
            tempoProcessamento[quantProcessos] = rt;
            tempoExecucao[i] = timer;
            quantProcessos++;

        } else {

            tempoExecucao[i] = tempoProcessamento[i];
        }

        i++;
        tempoEspera[i] = tempoEspera[i-1] + tempoExecucao[i-1];

    } while(i < quantProcessos);

    int achado = 0, soma = 0;

    for(i = 0; i < aux; i++) {
        for(j = i+1; j <= quantProcessos; j++) {

            if(strcmp(cpu[i], cpu[j]) == 0) {

                soma++;
                achado = j;
            }
        }

        if(achado != 0) {

            tempoEspera[i] = tempoEspera[achado] - (soma * timer);
            soma = 0;
            achado = 0;
        }
    }

    for(i = 0; i < aux; i++) {

        totalTempoEspera += tempoEspera[i];
    }

    tempoEstimado = (float)totalTempoEspera/aux;
    
    for(i = 0; i < aux; i++) {
        
        printf("\n####################");
        printf("\nNomeProcesso: %s", cpu[i]); 
        printf("\nTempoProcesso: %d", tempoProcessamento[i]);
        printf("\nTempoEsperando: %d", tempoEspera[i]);
    }

    printf("\n####################");
    printf("\nTotal de tempo esperando: %d\n", totalTempoEspera);
    printf("Tempo esperando estimado: %f\n", tempoEstimado);

  return 0;
}