#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define MAX_SESSOES 100
#define LIMITE_POTENCIA_TOTAL 50.0 

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
    time_t hora_inicio;
    time_t hora_fim;
    float custo;
    float tarifa_kWh;
    float potencia_atual;
    int tipo_carga; // 1 = recarga rapida | 2 = recarga lenta
    int status; // 0 = sessao em andamento | 1 = concluida
}Sessao; 

struct tm formatarDataHora(time_t momento){
    struct tm resultado;
    resultado = *localtime(&momento);
    return resultado;
}

float determinarTarifa(struct tm dataInicio, int tipo_carga){
    int dia_sem = dataInicio.tm_wday;
    int tempo_atual = dataInicio.tm_hour * 60 + dataInicio.tm_min;

    float tarifa; 
    if((dia_sem > 0 && dia_sem < 6) && (tempo_atual >= 1050 && tempo_atual <=1230)){
        tarifa = 1.12;
    }
    else if((dia_sem > 0 && dia_sem < 6) && (tempo_atual >= 990 && tempo_atual <= 1290)){
        tarifa = 0.72;
    }
    else{
        tarifa = 0.51;
    }

    if(tipo_carga == 1) tarifa *= 1.3;
}

int iniciarSessao(Sessao sessoes[], int total){
    int confirma_nome;
    int confirma_placa;
    int confirma_modelo;
    int opcao_bateria;
    int confirma_bateria;
    int confirma_potencia_bateria;

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
        fgets(sessoes[total].nome, sizeof(sessoes[total].nome), stdin);
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
        fgets(sessoes[total].carro.placa, sizeof(sessoes[total].carro.placa), stdin);
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

    // Modelo do veiculo
    do{
        printf("Digite o modelo do veiculo: ");
        fgets(sessoes[total].carro.modelo, sizeof(sessoes[total].carro.modelo), stdin);
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

    // Potencia da bateria
    do{
        printf("Deseja digitar a potencia da bateria manualmente ou deixar o sistema escolher automaticamente (padrao 38.8kWh)? \n");
        printf("(Digite 1 para manual | 2 para automatico)\n");
        printf("Resposta: ");
        scanf("%d", &opcao_bateria);
        printf("\n");
        if(opcao_bateria != 1 && opcao_bateria != 2){
            printf("Opcao invalida... tente novamente\n");
            
        }
        else if(opcao_bateria == 2){
            sessoes[total].carro.potencia_bateria = 38.8; // 38.8 kWh
        }
        else{
            do{
                printf("Digite a potencia da bateria em kW: ");
                scanf("%f", &sessoes[total].carro.potencia_bateria);
                printf("\n");
                printf("Potencia da bateria: %f\n", sessoes[total].carro.potencia_bateria);
                printf("A potencia da bateria esta correta? (Digite q para sim | 2 para nao)\n");
                printf("Resposta: ");
                scanf("%d", &confirma_potencia_bateria);
                printf("\n");
                if(confirma_potencia_bateria < 1 || confirma_potencia_bateria > 2){
                    printf("Opcao invalida... tente novamente\n");
                }
                else if(confirma_potencia_bateria == 2){
                    printf("Sem problemas, vamos voltar essa etapa\n");
                }
            }while(confirma_potencia_bateria != 1);
            confirma_potencia_bateria = 1;

        }
    }while(opcao_bateria !=1 && opcao_bateria !=2);
 
    // Pega qual o tipo de recarga que o usuário deseja
    do{
        printf("Qual o tipo de carga que deseja: 1 Carga Rapida | 2 Carga Lenta\n");
        printf("Resposta: ");
        scanf("%d", &sessoes[total].tipo_carga);
        printf("\n");
        if(sessoes[total].tipo_carga > 1 && sessoes[total].tipo_carga < 2){
            printf("Tipo de carga selecionada incorreta... tente novamente\n");
        }
        else if(sessoes[total].tipo_carga == 2){
            printf("Carga Lenta selecionada\n");
        }
        else{
            printf("Carga Rapida selecionada\n");
        }
    }while(sessoes[total].tipo_carga != 1 && sessoes[total].tipo_carga != 2);

    // Pega o horario de inicio da sessao
    sessoes[total].hora_inicio = time(NULL);
    struct tm dataInicio = formatarDataHora(sessoes[total].hora_inicio);

    sessoes[total].tarifa_kWh = determinarTarifa(dataInicio, sessoes[total].tipo_carga);
    sessoes[total].hora_fim = 0;
    sessoes[total].energia = 0;
    sessoes[total].custo = 0;
    sessoes[total].status = 0;
    return total + 1;
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