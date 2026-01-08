#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {

        while (1) {
            int seq[1001];
            if (scanf("%d", &seq[0]) != 1) return 0;

            if (seq[0] == 0) {
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &seq[i]);
            }
            int pilha[1001], topo = -1;
            int prox = 1;
            int ok = 1;

            for (int i = 0; i < n; i++) {

                int desejado = seq[i];

                while (prox <= n && (topo == -1 || pilha[topo] != desejado)) {
                    pilha[++topo] = prox++;
                }

                if (pilha[topo] == desejado) {
                    topo--;
                }
                else {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                printf ("Yes\n");
            }
            else {
                printf ("No\n");
            }
        }
    }

    return 0;
}