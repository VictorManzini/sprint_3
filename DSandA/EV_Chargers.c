#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define MAX_SESSOES 100

typedef struct{
    char placa[8];
    char modelo[50];
    float potencia_bateria;
}Veiculo;

typedef struct{
    int id;
    char nome[70];
    Veiculo carro; 
    float energia; 
    time_t inicio;
    time_t fim;
    float custo;
    int status; // 0 = sessao em andamento | 1 = concluida
}Sessao; 

void formatarDataHora(time_t momento, char saida[], int tamanho){
    time_t momento = time(NULL);
}

int iniciarSessao(Sessao sessoes[], int total){
    int confirma_nome = 0;
    int confirma_placa = 0;
    int confirma_modelo = 0;
    int confirma_bateria = 0;

    if (total >= MAX_SESSOES){
        printf("TODAS AS VAGAS FORAM PREENCHIDAS\n");
        printf("Por favor, volte mais tarde quando houver vagas disponiveis\n");
        return 1;
    }
    // Criando o ID da sessao
    sessoes[total].id = total + 1;
    printf("ID da sessao: %d\n", sessoes[total].id);
    // Registrando o nome do cliente
    do{
        printf("Por favor digite o seu nome e sobrenome: ");
        fgets(sessoes[total].nome, sizeoff(sessoes[total].nome), "\n");
        sessoes[total].nome[strcspn(sessoes[total].nome, "\n")] = '\0'; //Usa o strcspn para tirar o "\n" que sobra do fgets, assim nao da erro no print
        printf("Nome digitado: %s\n", sessoes[total].nome);
        printf("O nome acima esta correto? (Digite 1 para sim | 2 para nao)\n");
        printf("Resposta: ");
        scanf("%d", &confirma_nome);
        printf("\n");
        if(confirma_nome < 1 || confirma_nome > 2){
            printf("Opcao digitada invalida... tente novamente\n");
        }
        else if(confirma_nome == 2){
            printf("Sem problemas, vamos voltar essa etapa\n");
        }
    }while(confirma_nome != 1);
    printf("\n");
    // Registrando as infos do veiculo
    // Placa do veiculo
    do{
        printf("Digite a placa do carro: ");
        fgets(sessoes[total].carro.placa, sizeoff(sessoes[total].carro.placa), "\n");
        sessoes[total].carro.placa[strcspn(sessoes[total].carro.placa, "\n")] = '\0';
        printf("Placa digitada: %s\n", sessoes[total].carro.placa);
        printf("A placa do carro esta certa? (Digite 1 para sim | 2 para nao)");
        printf("Resposta: ");
        scanf("%d", &confirma_placa);
        printf("\n");
        if(confirma_placa < 1 || confirma_placa > 2){
            printf("Opcao invalida... tente novamente\n");
        }
        else if(confirma_placa == 2){
            printf("Sem problemas, vamos voltar essa etapa\n");
        }
    }while(confirma_placa != 1);

    do{
        printf("Digite o modelo do veiculo: ");
        fgets(sessoes[total].carro.modelo, sizeoff(sessoes[total].carro.modelo), "\n");
        sessoes[total].carro.modelo[strcspn(sessoes[total].carro.modelo, "\n")] = '\0';
        printf("Modelo do carro: %s\n", sessoes[total].carro.modelo);
        printf("O modelo do caro esta certo? (Digite 1 para sim | 2 para nao)\n");
        printf("Resposta: ");  
        scanf("%d", &confirma_modelo);
        printf("\n");
        if(confirma_modelo < 1 || confirma_modelo > 2){
            printf("Opcao invalida... tente novamente\n");
        }
        else if(confirma_modelo == 2){
            printf("Sem problemas, vamos voltar essa etapa\n");
        }
    }while(confirma_modelo != 1);

    do{
        printf("Digite a potencia da bateria em kW: ");
        scanf("%f", &sessoes[total].carro.potencia_bateria);
        printf("\n");
        printf("A potencia da bateria esta correta? (Digite q para sim | 2 para nao)\n");
        printf("Resposta: ");
        scanf("%d", &confirma_bateria);
        printf("\n");
        if(confirma_bateria < 1 || confirma_bateria > 2){
            printf("Opcao invalida... tente novamente\n");
        }
        else if(confirma_bateria == 2){
            printf("Sem problemas, vamos voltar essa etapa\n");
        }
    }while(confirma_bateria != 1);
}

void finalizarSessao(Sessao sessoes[], int total){

}

void listarSessoes(Sessao sessoes[], int total){

}

int buscarSessaoPorId(Sessao sessoes[], int tltal, int id){

}

void ordenarSessoes(Sessao sessoes[], int total){

}

void mostrarEstatisticas(Sessao sessoes[], int total){

}

int main(){ 
    Sessao sessoes[MAX_SESSOES];
    int total_sessoes = 0;
    int opcao;

    do{

    }while (opcao != 0);
    return 0;
}