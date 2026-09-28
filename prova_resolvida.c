#include <stdio.h>
#include <string.h>

#define QTD_COLUNAS 3

/* ---------- a) removerRepetidos ---------- */
int removerRepetidos(int v[], int tam) {
    if (tam == 0) return 0;
    int novoTam = 1;
    for (int i = 1; i < tam; i++) {
        if (v[i] != v[novoTam - 1]) {
            v[novoTam] = v[i];
            novoTam++;
        }
    }
    return novoTam;
}

/* ---------- b) ordenar (bubble sort) ---------- */
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenar(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                trocar(&v[j], &v[j + 1]);
            }
        }
    }
}

/* ---------- c) preencherPrimos ---------- */
int ehPrimo(int v[], int qtdPrimos, int numero) {
    for (int i = 0; i < qtdPrimos; i++) {
        if (numero % v[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void preencherPrimos(int v[], int tam) {
    int qtdEncontrados = 0;
    int candidato = 2;
    while (qtdEncontrados < tam) {
        if (ehPrimo(v, qtdEncontrados, candidato)) {
            v[qtdEncontrados] = candidato;
            qtdEncontrados++;
        }
        candidato++;
    }
}

/* ---------- d) maiorPorLinha ---------- */
void maiorPorLinha(int m[][QTD_COLUNAS], int lin, int col, int v[]) {
    for (int i = 0; i < lin; i++) {
        int maior = m[i][0];
        for (int j = 1; j < col; j++) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }
        v[i] = maior;
    }
}

/* ---------- e) inverterPalavras ---------- */
void inverterTrecho(char str[], int inicio, int fim) {
    while (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
}

void inverterPalavras(char str[]) {
    int inicio = 0;
    int i = 0;
    while (1) {
        if (str[i] == ' ' || str[i] == '\0') {
            inverterTrecho(str, inicio, i - 1);
            if (str[i] == '\0') break;
            inicio = i + 1;
        }
        i++;
    }
}

/* ---------- funcao auxiliar so para imprimir vetores nos testes ---------- */
void imprimirVetor(int v[], int tam) {
    printf("{ ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("}\n");
}

/* ---------- main de teste (nao faz parte da prova, so serve para conferir) ---------- */
int main(void) {
    /* Teste a) removerRepetidos */
    int a[] = {3, 3, 4, 5, 6, 6, 6, 7};
    int tamA = removerRepetidos(a, 8);
    printf("a) removerRepetidos -> tam = %d, vetor = ", tamA);
    imprimirVetor(a, tamA);

    /* Teste b) ordenar */
    int b[] = {5, 2, 9, 1, 5, 6};
    int tamB = 6;
    ordenar(b, tamB);
    printf("b) ordenar -> ");
    imprimirVetor(b, tamB);

    /* Teste c) preencherPrimos */
    int c[5];
    preencherPrimos(c, 5);
    printf("c) preencherPrimos -> ");
    imprimirVetor(c, 5);

    /* Teste d) maiorPorLinha */
    int m[2][QTD_COLUNAS] = {{10, 5, 20}, {1, 30, 15}};
    int v[2];
    maiorPorLinha(m, 2, QTD_COLUNAS, v);
    printf("d) maiorPorLinha -> ");
    imprimirVetor(v, 2);

    /* Teste e) inverterPalavras */
    char frase[] = "o rato roeu";
    inverterPalavras(frase);
    printf("e) inverterPalavras -> \"%s\"\n", frase);

    return 0;
}
