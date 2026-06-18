// Feito por Douglas Alves Costa
// Nivel NOVATO

#include <stdio.h>
#include <string.h> // Necessário para a função strcmp() no Nível Mestre

// ALGORITMOS DE ORDENAÇÃO AVANÇADOS - Desafio Mestre dos Decks
// Escolha o nível que deseja focar (Novato, Aventureiro ou Mestre)
// e implemente a lógica correspondente.

// ====================================================================
// ESTRUTURA DE DADOS COMPARTILHADA
// ====================================================================

struct Carta {
    int id;
    char nome[50];
    int ataque;
    int defesa;
    int energia;
    int raridade;
};

// Função auxiliar para exibir uma lista de cartas
void imprimirCartas(struct Carta lista[], int tamanho) {
    printf("%-5s | %-25s | %-7s | %-7s | %-8s | %-8s\n", 
           "ID", "Nome", "Ataque", "Defesa", "Energia", "Raridade");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%-5d | %-25s | %-7d | %-7d | %-8d | %-8d\n",
               lista[i].id, lista[i].nome, lista[i].ataque, 
               lista[i].defesa, lista[i].energia, lista[i].raridade);
    }

    printf("\n");
}


// ====================================================================
// FUNÇÃO DE ORDENAÇÃO - NÍVEL NOVATO
// ====================================================================


// NÍVEL NOVATO: Insertion Sort (Ordenação por Energia - Crescente)
void insertionSortEnergia(struct Carta mao[], int n) {
    // Dica: Crie um laço a partir do índice 1.
    // Salve a carta atual em uma variável chave.
    // Desloque as cartas anteriores que tiverem energia MAIOR que a chave para a direita.
    // Insira a chave na posição correta.
}

// ====================================================================
// FUNÇÕES DOS OUTROS NÍVEIS - MANTIDAS COMO BASE
// ====================================================================

// NÍVEL AVENTUREIRO: Shell Sort (Ordenação por Ataque - Decrescente)
void shellSortAtaque(struct Carta deck[], int n) {
    // Não implementado neste desafio.
}

// NÍVEL MESTRE: Quick Sort com Múltiplos Critérios
// 1º Raridade (Decrescente) -> 2º Nome (Alfabética Crescente)

// Função de comparação customizada
int compararCartas(const struct Carta* c1, const struct Carta* c2) {
    // Não implementado neste desafio.
    return 0;
}

// Função de particionamento (Quick Sort)
int particionar(struct Carta registro[], int baixo, int alto) {
    // Não implementado neste desafio.
    return 0;
}

// Função principal do Quick Sort
void quickSortRegistro(struct Carta registro[], int baixo, int alto) {
    // Não implementado neste desafio.
}


// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    printf("=== ARENA DE CODIGO - MESTRE DOS DECKS ===\n\n");

    // ---------------------------------------------------------
    // NÍVEL NOVATO
    // ---------------------------------------------------------

    struct Carta mao_inicial[7] = {
        {105, "Ogro Esmagador", 5, 4, 5, 2}, 
        {102, "Elfa Arqueira", 2, 1, 2, 1}, 
        {107, "Anjo da Furia", 6, 5, 6, 3}, 
        {101, "Goblin Batedor", 1, 1, 1, 1}, 
        {103, "Guardiao de Pedra", 2, 5, 4, 1}, 
        {106, "Cavaleiro de Aco", 3, 3, 3, 2}, 
        {104, "Dragao das Cinzas", 7, 7, 8, 3} 
    };

    printf("--- Nivel Novato: Mao Inicial (Desordenada) ---\n");
    imprimirCartas(mao_inicial, 7);

    // Chamada da função que ordena a mão por energia
    insertionSortEnergia(mao_inicial, 7);

    printf("--- Nivel Novato: Mao Organizada (Por Energia) ---\n");
    imprimirCartas(mao_inicial, 7);

    printf("Mao organizada! Pronto para a batalha!\n\n");

    return 0;
}