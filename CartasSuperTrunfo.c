#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da Carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float superPoder;
} Carta;

// Função para calcular o Super Poder
float calcularSuperPoder(Carta *carta) {
    float densidade = (float)carta->populacao / carta->area;
    float pibPerCapita = carta->pib / carta->populacao;
    return carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + pibPerCapita + (1.0 / densidade);
}

// Função para ler os dados de uma carta com melhorias
void lerCarta(Carta *carta) {
    printf("\n--- Insira os dados da carta ---\n");

    printf("Digite a letra do estado (A-Z): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (Ex: A01, B03): ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    getchar(); // Limpa o buffer para evitar problemas na leitura de strings
    fgets(carta->nomeCidade, 50, stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0'; // Remove a quebra de linha

    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->superPoder = calcularSuperPoder(carta);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numCarta) {
    float densidade = (float)carta.populacao / carta.area;
    float pibPerCapita = carta.pib / carta.populacao;

    printf("\n========= Carta %d =========\n", numCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("PIB per capita: %.2f reais\n", pibPerCapita);
    printf("Densidade populacional: %.2f habitantes/km²\n", densidade);
    printf("Super Poder: %.2f\n", carta.superPoder);
    printf("============================\n");
}

// Função para comparar e exibir os resultados
void compararCartas(Carta carta1, Carta carta2) {
    printf("\n=== Comparação das Cartas ===\n");

    if (carta1.superPoder > carta2.superPoder) {
        printf("🏆 Carta 1 vence com Super Poder %.2f\n", carta1.superPoder);
    } else if (carta1.superPoder < carta2.superPoder) {
        printf("🏆 Carta 2 vence com Super Poder %.2f\n", carta2.superPoder);
    } else {
        printf("⚖ Empate no Super Poder: %.2f\n", carta1.superPoder);

}
  if (carta1.populacao > carta2.populacao) {
        printf("🏆 Carta 1 vence com população %d\n", carta1.populacao);
    } else if (carta1.populacao < carta2.populacao) {
        printf("🏆 Carta 2 vence com população %d\n", carta2.populacao);
    } else {
        printf("⚖ Empate na população: %d\n", carta1.populacao);
    }

    if (carta1.area > carta2.area) {
        printf("🏆 Carta 1 vence com área %.2f km²\n", carta1.area);
    } else if (carta1.area < carta2.area) {
        printf("🏆 Carta 2 vence com área %.2f km²\n", carta2.area);
    } else {
        printf("⚖ Empate na área: %.2f km²\n", carta1.area);
    }
    if (carta1.pib > carta2.pib) {
        printf("🏆 Carta 1 vence com PIB %.2f bilhões de reais\n", carta1.pib);
    } else if (carta1.pib < carta2.pib) {
        printf("🏆 Carta 2 vence com PIB %.2f bilhões de reais\n", carta2.pib);
    } else {
        printf("⚖ Empate no PIB: %.2f bilhões de reais\n", carta1.pib);
    }

// Função principal
int main() {
    // Exemplo de uso das funções
    Carta carta1, carta2;

    lerCarta(&carta1);
    lerCarta(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    compararCartas(carta1, carta2);

    return 0;
}