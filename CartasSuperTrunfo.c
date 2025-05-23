#include <stdio.h>

// Jogo de Super Trunfo
// Este programa simula um jogo de cartas do tipo Super Trunfo, onde cada carta contém informações sobre uma cidade.
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;
// Função para ler os dados de uma carta
void lerCarta(Carta *carta) {
    // Lê os dados da carta do usuário
    printf("Digite a letra do estado (A-Z): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (Ex: A01, B03): ");
    scanf("%s", carta->codigo);
   
    printf("Digite o nome da cidade: ");
    scanf(" %s[^\n]", carta->nomeCidade);

    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    // Exibe os dados lidos
    float densidade = (float)carta->populacao / carta->area;
    //calculo de densidade populacao dividida pela area da cidade
    
    float pibPerCapita = carta->pib / carta->populacao;
    //calculo de pibpercapita pib divido pela populacao

}// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numCarta) {
    float densidade = (float)carta.populacao / carta.area;
    // Calcula a densidade populacional
    float pibPerCapita = carta.pib / carta.populacao;
    // Calcula o PIB per capita
    printf("\nCarta %d:\n", numCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("PIB per capita: %.2f reais\n", pibPerCapita);
    printf("Densidade populacional: %.2f habitantes/km²\n", densidade);

}// Função principal
// Lê os dados de duas cartas e exibe as informações

int main() {
    Carta carta1, carta2;

    printf("Insira os dados da primeira carta:\n");
    lerCarta(&carta1);

    printf("\nInsira os dados da segunda carta:\n");
    lerCarta(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
// Exibe as informações das cartas
    return 0;
}
