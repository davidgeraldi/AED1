#include <stdio.h>

int main () {
    double f[61];
    int t, n, i;

    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= 60; i++)
        f[i] = f[i-1] + f[i-2];

    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        printf ("Fib(%d) = %.0f\n", n, f[n]);
    }

    return 0;
}