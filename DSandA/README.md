Sprint 3 — Estruturas de Dados e Evolução do Simulador de Recarga

Contexto

Nas Sprints anteriores, o grupo desenvolveu um simulador de sessão de recarga de veículos elétricos utilizando os fundamentos da linguagem C.

Nesta Sprint, o sistema deverá evoluir para conseguir armazenar, organizar, pesquisar e analisar múltiplas sessões de recarga.

O objetivo é aplicar os novos conteúdos da disciplina:

struct
typedef
vetores de estruturas
funções
busca
ordenação
algoritmos
análise de complexidade
notação Big-O

Desafio

Transformar o simulador desenvolvido anteriormente em um pequeno Sistema de Gerenciamento de Estação de Recarga.

O programa não deverá mais trabalhar apenas com uma única recarga.

Agora deverá ser capaz de registrar e manipular múltiplas sessões.



1. Estrutura da sessão

O grupo deverá criar obrigatoriamente uma estrutura utilizando typedef e struct.

Exemplo conceitual:

typedef struct {
    int id;
    float energia;
    float tempo;
    float custo;
    /* demais informações */
} Sessao;


A estrutura deverá representar uma sessão de recarga.

O grupo poderá acrescentar outros campos que considerar relevantes.



2. Registro de múltiplas sessões

O programa deverá permitir registrar várias sessões de recarga utilizando um vetor de estruturas.

Exemplo:

Sessao sessoes[100];

Cada nova recarga deverá ser armazenada nesse vetor.

O sistema deverá controlar quantas posições do vetor estão efetivamente ocupadas.

3. Menu principal

O programa deverá possuir um menu semelhante a:

=====================================
      ESTAÇÃO DE RECARGA
=====================================

1 - Nova sessão de recarga
2 - Listar sessões
3 - Buscar sessão
4 - Ordenar sessões
5 - Estatísticas
6 - Encerrar

Escolha:

O menu deverá continuar sendo exibido até que o usuário escolha encerrar o programa.

4. Busca de sessões

O sistema deverá permitir pesquisar uma sessão.

Exemplo:

Digite o ID da sessão: 15

O programa deverá informar os dados correspondentes.

O grupo deverá implementar pelo menos um algoritmo de busca estudado na disciplina.

Exemplos:

Busca Linear
Busca Binária

Caso utilize busca binária, deverá garantir previamente que os dados utilizados na busca estejam ordenados.

5. Ordenação

O sistema deverá permitir ordenar as sessões.

O grupo deverá implementar manualmente pelo menos um algoritmo de ordenação.

Exemplos:

Bubble Sort
Selection Sort
Insertion Sort
Não utilizar uma função pronta da biblioteca para substituir a implementação do algoritmo.
O usuário poderá, por exemplo, escolher ordenar por:
ID;
energia consumida;
custo da sessão;
tempo de recarga.

6. Estatísticas da estação

Utilizando os dados armazenados, o programa deverá calcular pelo menos:

quantidade total de sessões;
energia total fornecida;
faturamento total;
custo médio das sessões;
maior consumo registrado;
menor consumo registrado.

Exemplo:

========= ESTATÍSTICAS ==========

Sessões realizadas: 27
Energia fornecida: 684.50 kWh
Faturamento: R$ 821,40
Ticket médio: R$ 30,42

Maior consumo: 57.30 kWh
Menor consumo: 8.70 kWh

7. Funções

O código deverá utilizar funções para organizar as principais operações.

Exemplos:

void cadastrarSessao(...);
void listarSessoes(...);
void buscarSessao(...);
void ordenarSessoes(...);
void mostrarEstatisticas(...);


A divisão exata das funções fica a critério do grupo.

8. Análise de algoritmos

O grupo deverá selecionar dois algoritmos utilizados no próprio projeto e analisar sua complexidade.

Por exemplo:

Busca Linear

Para um vetor com n sessões, no pior caso o algoritmo poderá percorrer todas as posições.

Complexidade:

O(n)

Bubble Sort

Para ordenar n elementos, existem comparações realizadas por laços aninhados.

Complexidade aproximada:

O(n²)

O grupo deverá explicar de onde surge essa complexidade utilizando o código desenvolvido.

Entregáveis obrigatórios — Sprint 3

Código-fonte .c compilável e executável.

Uso obrigatório de struct e typedef.

Vetor de estruturas para armazenar múltiplas sessões.

Implementação de busca.

Implementação manual de pelo menos um algoritmo de ordenação.

Menu funcional.

Estatísticas das sessões.

Documento contendo:

explicação da estrutura criada;
funcionamento do programa;
algoritmo de busca utilizado;
algoritmo de ordenação utilizado;
análise Big-O dos dois algoritmos.



Critérios de Avaliação — Sprint 3 (0–100)

1. struct, typedef e armazenamento — 20 pontos

0–5: não implementado ou incorreto6–10: implementação parcial11–15: estrutura funcional16–20: estrutura bem utilizada no sistema

2. Funções e organização do programa — 15 pontos

0–5: código concentrado e pouco organizado6–10: algumas funções implementadas11–13: boa separação das funcionalidades14–15: funções claras e coerentes

3. Busca — 15 pontos

0–5: não implementada ou incorreta6–10: parcialmente funcional11–13: busca correta14–15: busca correta e bem integrada ao sistema

4. Ordenação — 15 pontos

0–5: não implementada6–10: algoritmo parcialmente funcional11–13: algoritmo correto14–15: algoritmo correto e integrado ao sistema

5. Lógica e funcionamento — 15 pontos

Avaliar:

cadastro;
listagem;
consulta;
cálculos;
estatísticas;
funcionamento geral.

6. Análise de complexidade — 10 pontos

Avaliar se o grupo consegue relacionar os algoritmos implementados às respectivas complexidades Big-O.

7. Entrada, saída e apresentação — 10 pontos

Avaliar:

clareza do menu;
mensagens;
relatório;
facilidade de utilização.

Resultado esperado da Sprint 3

Ao final desta Sprint, o projeto deixa de ser apenas um simulador de uma recarga e passa a funcionar como um pequeno sistema de gerenciamento de sessões, aplicando estruturas de dados e algoritmos desenvolvidos manualmente em C.