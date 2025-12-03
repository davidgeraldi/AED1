#include <stdio.h>

int main() {
	int n, me = 0, p = 0, *ponteiro;
	scanf("%d", &n);
	int x[n];
	for(int i = 0; i < n; i++) {
		scanf("%d ", &x[i]);

	}

	me = *x;

	for (ponteiro = x; ponteiro < x + n; ponteiro++)
	{
		if (*ponteiro <= me)
		{
			me = *ponteiro;
			p = ponteiro - x;
		}
	}
	printf("Menor valor: %d\n", me);
	printf("Posicao: %d\n", p);

	return 0;
}