#include <stdio.h>

int eh_bloco_valido(int *bloco) {
    int verificador[10] = {0};
    int i;

    for (i = 0; i < 9; i++) {
        int num = *(bloco + i);
        if (num < 1 || num > 9 || verificador[num] == 1) {
            return 0;
        }
        verificador[num] = 1;
    }
    return 1;
}

int verifica_linhas(int *matriz) {
    int i;
    for (i = 0; i < 9; i++) {
        if (!eh_bloco_valido(matriz + i * 9)) {
            return 0;
        }
    }
    return 1;
}

int verifica_colunas(int *matriz) {
    int i, j;
    int coluna_temp[9];

    for (j = 0; j < 9; j++) {
        for (i = 0; i < 9; i++) {
            coluna_temp[i] = *(matriz + i * 9 + j);
        }
        if (!eh_bloco_valido(coluna_temp)) {
            return 0;
        }
    }
    return 1;
}

int verifica_sub_blocos(int *matriz) {
    int i, j, k;
    int bloco_temp[9];

    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            k = 0;
            for (int linha = i; linha < i + 3; linha++) {
                for (int col = j; col < j + 3; col++) {
                    bloco_temp[k++] = *(matriz + linha * 9 + col);
                }
            }
            if (!eh_bloco_valido(bloco_temp)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d", &n);

    for (k = 1; k <= n; k++){
        int sudoku[9][9];
        int i, j;

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }
        
        int *ptr_sudoku = (int *)sudoku;

        printf("Instancia %d\n", k);

        if (verifica_linhas(ptr_sudoku) && verifica_colunas(ptr_sudoku) && verifica_sub_blocos(ptr_sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}