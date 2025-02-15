#include <stdio.h>
#include <locale.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.

// BY DEVYAT009

#define MAX_ESTADOS 8
#define MAX_CIDADES 4

typedef struct {
    char codigo[4];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Cidade;

typedef struct {
    char nome[50];
    Cidade cidades[MAX_CIDADES];
} Estado;

void compararCartas(Cidade c1, Cidade c2) {
    printf("\n===== Comparação de Cartas =====\n");
    printf("%s vs %s\n", c1.nome, c2.nome);
    
    printf("Densidade Populacional: %.2f vs %.2f\n", c1.densidadePopulacional, c2.densidadePopulacional);
    if (c1.densidadePopulacional < c2.densidadePopulacional) printf("%s vence\n", c1.nome);
    else if (c1.densidadePopulacional > c2.densidadePopulacional) printf("%s vence\n", c2.nome);
    else printf("Empate\n");
    
    printf("PIB per Capita: %.2f vs %.2f\n", c1.pibPerCapita, c2.pibPerCapita);
    if (c1.pibPerCapita > c2.pibPerCapita) printf("%s vence\n", c1.nome);
    else if (c1.pibPerCapita < c2.pibPerCapita) printf("%s vence\n", c2.nome);
    else printf("Empate\n");
    
    printf("Super Poder: %.2f vs %.2f\n", c1.superPoder, c2.superPoder);
    if (c1.superPoder > c2.superPoder) printf("%s vence\n", c1.nome);
    else if (c1.superPoder < c2.superPoder) printf("%s vence\n", c2.nome);
    else printf("Empate\n");
}


int main() {
    // Configuração de Localização para não da print errado:
    setlocale(LC_ALL, "Portuguese");
    char nomePais[50];
    Estado estados[MAX_ESTADOS];
    int dificuldade;
    
    // Seleção de dificuldade:
    printf("Digite a dificuldade desejada (1, 2 ou 3), 1 sendo Novato, 2 para Aventureiro e 3 para Mestre:\n");
    scanf("%d", &dificuldade);
    if (dificuldade){
            printf("Qual o nome do pais a ser criado?\n");
            scanf("%s", nomePais);
            for (int i = 0; i < MAX_ESTADOS; i++){
                printf("Qual o nome do estado %c a ser criado?\n", 'A' + i);
                scanf(" %49[^\n]", estados[i].nome);
                for (int j = 0; j < MAX_CIDADES; j++) {
                    sprintf(estados[i].cidades[j].codigo, "%c%02d", 'A' + i, j + 1);
                    printf("Qual o nome da cidade %d do estado %s?\n", j + 1, estados[i].nome);
                    scanf("%s", estados[i].cidades[j].nome);
    
                    printf("Qual a população da cidade %s?\n", estados[i].cidades[j].nome);
                    scanf("%lu", &estados[i].cidades[j].populacao);
    
                    printf("Qual a área da cidade %s em km²?\n", estados[i].cidades[j].nome);
                    scanf("%f", &estados[i].cidades[j].area);
    
                    printf("Qual o PIB da cidade %s?\n", estados[i].cidades[j].nome);
                    scanf("%f", &estados[i].cidades[j].pib);
    
                    printf("Qual o número de pontos turísticos da cidade %s?\n", estados[i].cidades[j].nome);
                    scanf("%d", &estados[i].cidades[j].pontosTuristicos);

                    // Cálculo das novas propriedades (apenas para dificuldade 2)
                    if (dificuldade == 2) {
                        if (estados[i].cidades[j].area > 0) {
                            estados[i].cidades[j].densidadePopulacional = estados[i].cidades[j].populacao / estados[i].cidades[j].area;
                        } else {
                            estados[i].cidades[j].densidadePopulacional = 0;
                        }
                        
                        if (estados[i].cidades[j].populacao > 0) {
                            estados[i].cidades[j].pibPerCapita = estados[i].cidades[j].pib / estados[i].cidades[j].populacao;
                        } else {
                            estados[i].cidades[j].pibPerCapita = 0;
                        }
                    }
                    if (dificuldade == 3) {
                        if (estados[i].cidades[j].area > 0) {
                            estados[i].cidades[j].densidadePopulacional = estados[i].cidades[j].populacao / estados[i].cidades[j].area;
                        } else {
                            estados[i].cidades[j].densidadePopulacional = 0;
                        }
                        
                        if (estados[i].cidades[j].populacao > 0) {
                            estados[i].cidades[j].pibPerCapita = estados[i].cidades[j].pib / estados[i].cidades[j].populacao;
                        } else {
                            estados[i].cidades[j].pibPerCapita = 0;
                        }
                        estados[i].cidades[j].superPoder = estados[i].cidades[j].populacao + estados[i].cidades[j].area + estados[i].cidades[j].pib + estados[i].cidades[j].pontosTuristicos;
                    }
                }
            }
            printf("\n===== LOG FINAL =====\n");
            printf("País: %s\n", nomePais);

            for (int i = 0; i < MAX_ESTADOS; i++) {
                printf("\nEstado %c: %s\n", 'A' + i, estados[i].nome);

                for (int j = 0; j < MAX_CIDADES; j++) {
                    printf("  Cidade %s: %s\n", estados[i].cidades[j].codigo, estados[i].cidades[j].nome);
                    printf("    População: %lu habitantes\n", estados[i].cidades[j].populacao);
                    printf("    Área: %.2f km²\n", estados[i].cidades[j].area);
                    printf("    PIB: %.2f bilhões\n", estados[i].cidades[j].pib);
                    printf("    Pontos turísticos: %d\n", estados[i].cidades[j].pontosTuristicos);
                    if (dificuldade == 2) {
                        printf("    Densidade Populacional: %.2f hab/km²\n", estados[i].cidades[j].densidadePopulacional);
                        printf("    PIB per Capita: %.2f\n", estados[i].cidades[j].pibPerCapita);
                    }
                    if (dificuldade == 3) {
                        printf("    Densidade Populacional: %.2f hab/km²\n", estados[i].cidades[j].densidadePopulacional);
                        printf("    PIB per Capita: %.2f\n", estados[i].cidades[j].pibPerCapita);
                        printf("    Super Poder: %.2f\n", estados[i].cidades[j].superPoder);
                    }
                }
            }

            if (dificuldade == 3) {
                int estadoEscolhido, cidade1, cidade2;
                printf("\n===== COMPARAÇÃO =====\n");
                printf("Escolha um estado (1 a %d): ", MAX_ESTADOS);
                scanf("%d", &estadoEscolhido);
                estadoEscolhido--;

                printf("Escolha a primeira cidade (1 a %d): ", MAX_CIDADES);
                scanf("%d", &cidade1);
                cidade1--;
                
                printf("Escolha a segunda cidade (1 a %d): ", MAX_CIDADES);
                scanf("%d", &cidade2);
                cidade2--;

                if (estadoEscolhido >= 0 && estadoEscolhido < MAX_ESTADOS && cidade1 >= 0 && cidade1 < MAX_CIDADES && cidade2 >= 0 && cidade2 < MAX_CIDADES && cidade1 != cidade2) {
                    compararCartas(estados[estadoEscolhido].cidades[cidade1], estados[estadoEscolhido].cidades[cidade2]);
                } else {
                    printf("Seleção inválida. Certifique-se de escolher cidades diferentes dentro de um estado válido.\n");
                }
            }
        }
    return 0;
}