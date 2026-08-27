#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct{
    int id;
    char nome;
    float energia; 
    float tempo;
    float custo;
}Sessao; 

typedef struct{
    char placa[8];
    char modelo[50];
    float potencia_bateria;
}Veiculo;