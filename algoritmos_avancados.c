#include <stdio.h>
#include <stdlib.h>
#include <string.h>

                        // Estrutura da sala "nó da árvore binária"

typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

                        // Cria dinamicamente uma sala com nome

Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória para a sala.\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

                        // Permite a exploração interativa das salas

void explorarSalas(Sala *atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

                        // Se não há mais caminhos, a exploração termina

        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Não há mais caminhos. Fim da exploração!\n");
            break;
        }

        printf("Escolha um caminho:\n");
        if (atual->esquerda != NULL)
            printf("  (e) Ir para a esquerda: %s\n", atual->esquerda->nome);
        if (atual->direita != NULL)
            printf("  (d) Ir para a direita: %s\n", atual->direita->nome);
        printf("  (s) Sair do jogo\n");
        printf("Opção: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (escolha == 's') {
            printf("Você decidiu sair. Até mais!\n");
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

int main() {
                // Criação das salas "nós"

    Sala *hall = criarSala("Hall de entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *jardim = criarSala("Jardim");
    Sala *escritorio = criarSala("Escritório");

                // Montagem da árvore "mapa fixo"

    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;
    cozinha->direita = escritorio;

                // Início da exploração

    printf("=== Detective Quest: Exploração da Mansão ===\n");
    explorarSalas(hall);

                // Liberação de memória "boa prática"

    free(hall);
    free(salaEstar);
    free(cozinha);
    free(biblioteca);
    free(jardim);
    free(escritorio);

    return 0;
}
