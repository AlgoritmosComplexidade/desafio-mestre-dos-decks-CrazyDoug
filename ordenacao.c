// Feito por Douglas Alves Costa
// Nível Aventureiro - Shell Sort

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

// ============================================================
// NÍVEL AVENTUREIRO: SHELL SORT
// Ordenação por Ataque (Decrescente)
// ============================================================

void shellSortAtaque(struct Carta deck[], int n) {
    int h = 1;

    // Sequência de Knuth
    while (h < n) {
        h = 3 * h + 1;
    }

    while (h > 1) {
        h = h / 3;

        for (int i = h; i < n; i++) {
            struct Carta temp = deck[i];
            int j = i;

            while (j >= h && deck[j - h].ataque < temp.ataque) {
                deck[j] = deck[j - h];
                j -= h;
            }

            deck[j] = temp;
        }
    }
}

int main() {

    struct Carta deck_torneio[40] = {
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
        {405, "Fenix Imortal", 9, 9, 9, 4},

        {501, "Dragao Rubro", 10, 8, 9, 4},
        {502, "Assassino Sombrio", 8, 3, 5, 3},
        {503, "Guerreiro Orc", 6, 4, 4, 2},
        {504, "Arqueiro Real", 4, 2, 3, 1},
        {505, "Titã de Pedra", 9, 10, 8, 4},
        {506, "Serpente Venenosa", 3, 1, 2, 1},
        {507, "Cavaleira Lunar", 7, 6, 5, 3},
        {508, "Demonio Abissal", 10, 7, 9, 4},
        {509, "Golem Antigo", 6, 9, 6, 2},
        {510, "Espadachim Errante", 5, 4, 3, 2},
        {511, "Bruxa da Floresta", 4, 5, 4, 2},
        {512, "Lobo Alfa", 6, 3, 4, 2},
        {513, "Guardiao Celestial", 8, 8, 7, 3},
        {514, "Necromante Sombrio", 7, 4, 6, 3},
        {515, "Fera das Montanhas", 9, 6, 7, 3},
        {516, "Aprendiz Arcano", 2, 2, 1, 1},
        {517, "Cavaleiro Negro", 8, 7, 6, 3},
        {518, "Troll Selvagem", 5, 8, 5, 2},
        {519, "Fada Curandeira", 1, 4, 2, 1},
        {520, "Imperador Draconico", 10, 10, 10, 4}
    };

    printf("=== NIVEL AVENTUREIRO ===\n");

    printf("\n--- Deck do Torneio (Desordenado) ---\n");
    imprimirCartas(deck_torneio, 40);

    shellSortAtaque(deck_torneio, 40);

    printf("\n--- Deck Otimizado (Ataque Decrescente) ---\n");
    imprimirCartas(deck_torneio, 40);

    printf("Deck otimizado e pronto para o torneio!\n");

    return 0;
}