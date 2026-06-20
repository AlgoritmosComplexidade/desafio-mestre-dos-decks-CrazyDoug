// Feito por Douglas Alves Costa
// Nivel Mestre - Quick Sort Multicriterio

#include <stdio.h>
#include <string.h>

struct Carta {
    int id;
    char nome[50];
    int ataque;
    int defesa;
    int energia;
    int raridade;
};

void imprimirCartas(struct Carta lista[], int tamanho) {
    printf("\n");
    printf("%-5s | %-25s | %-7s | %-7s | %-8s | %-8s\n",
           "ID", "Nome", "Ataque", "Defesa", "Energia", "Raridade");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%-5d | %-25s | %-7d | %-7d | %-8d | %-8d\n",
               lista[i].id,
               lista[i].nome,
               lista[i].ataque,
               lista[i].defesa,
               lista[i].energia,
               lista[i].raridade);
    }

    printf("\n");
}

// Comparação customizada:
// Primeiro: raridade decrescente
// Segundo: nome em ordem alfabética crescente
int compararCartas(const struct Carta* c1, const struct Carta* c2) {
    if (c1->raridade > c2->raridade) {
        return -1;
    }

    if (c1->raridade < c2->raridade) {
        return 1;
    }

    return strcmp(c1->nome, c2->nome);
}

void trocarCartas(struct Carta* a, struct Carta* b) {
    struct Carta temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(struct Carta registro[], int baixo, int alto) {
    struct Carta pivo = registro[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if (compararCartas(&registro[j], &pivo) <= 0) {
            i++;
            trocarCartas(&registro[i], &registro[j]);
        }
    }

    trocarCartas(&registro[i + 1], &registro[alto]);

    return i + 1;
}

void quickSortRegistro(struct Carta registro[], int baixo, int alto) {
    if (baixo < alto) {
        int indicePivo = particionar(registro, baixo, alto);

        quickSortRegistro(registro, baixo, indicePivo - 1);
        quickSortRegistro(registro, indicePivo + 1, alto);
    }
}

int main() {
    struct Carta grande_registro[20] = {
        {225, "Elemental de Fogo", 6, 2, 5, 2},
        {105, "Ogro Esmagador", 5, 4, 5, 2},
        {102, "Elfa Arqueira", 2, 1, 2, 1},
        {315, "Paladino da Ordem", 5, 7, 7, 3},
        {201, "Lobo das Sombras", 3, 2, 2, 1},
        {401, "Lich King", 10, 10, 10, 4},
        {107, "Anjo da Furia", 6, 5, 6, 3},
        {301, "Mago de Gelo", 2, 4, 3, 2},
        {101, "Goblin Batedor", 1, 1, 1, 1},
        {205, "Ciclope Brutal", 7, 5, 6, 2},
        {103, "Guardiao de Pedra", 2, 5, 4, 1},
        {305, "Hidra de Nove Cabecas", 8, 8, 9, 4},
        {106, "Cavaleiro de Aco", 3, 3, 3, 2},
        {210, "Grifo Veloz", 4, 3, 4, 1},
        {104, "Dragao das Cinzas", 7, 7, 8, 3},
        {215, "Minotauro Guerreiro", 5, 6, 5, 2},
        {310, "Feiticeira Arcana", 4, 2, 5, 3},
        {220, "Basilisco Petrificante", 3, 5, 4, 2},
        {110, "Clerigo Iluminado", 1, 3, 2, 1},
        {405, "Fenix Imortal", 9, 9, 9, 4}
    };

    printf("=== NIVEL MESTRE ===\n");

    printf("\n--- Grande Registro Antes da Ordenacao ---\n");
    imprimirCartas(grande_registro, 20);

    quickSortRegistro(grande_registro, 0, 19);

    printf("\n--- Grande Registro Restaurado (Raridade Decrescente -> Nome Crescente) ---\n");
    imprimirCartas(grande_registro, 20);

    printf("O grande registro da arena foi restaurado!\n");

    return 0;
}