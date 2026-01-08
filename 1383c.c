#include <stdio.h>

int EhBlocoValido (int *bloco) {
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

int VerificarLinhas (int *matriz) {
    int i;
    for (i = 0; i < 9; i++) {
        if (!EhBlocoValido  (matriz + i * 9)) {
            return 0;
        }
    }
    return 1;
}

int VerificarColunas (int *matriz) {
    int i, j;
    int coluna_temp[9];

    for (j = 0; j < 9; j++) {
        for (i = 0; i < 9; i++) {
            coluna_temp[i] = *(matriz + i * 9 + j);
        }
        if (!EhBlocoValido  (coluna_temp)) {
            return 0;
        }
    }
    return 1;
}

int VerificarSubBlocos (int *matriz) {
    int i, j, k;
    int bloco_temp[9];// bloco temporario

    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            k = 0;
            for (int linha = i; linha < i + 3; linha++) {
                for (int col = j; col < j + 3; col++) {
                    bloco_temp[k++] = *(matriz + linha * 9 + col);
                }
            }
            if (!EhBlocoValido  (bloco_temp)) {
                return 0;
            }
        }
    }
    return 1;
}

int main () {
    int n, k;
    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        int sudoku[9][9];
        int i, j;

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }
        
        int *ptr_sudoku = (int *)sudoku; //ponteiro para o inicio da matriz

        printf ("Instancia %d\n", k);

        if (VerificarLinhas (ptr_sudoku) && VerificarColunas (ptr_sudoku) && VerificarSubBlocos (ptr_sudoku)) {
            printf ("SIM\n");
        } 
        else {
            printf ("NAO\n");
        }
        printf ("\n");
    }

    return 0;
}