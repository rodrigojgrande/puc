/*
Pergunta 10 - c
Implemente uma função recursiva para calcular o n-ésimo termo de uma sequência de Fibonacci.
*/

int ff(int n) {
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return ff(n/2);
	return ff((n-1)/2) + ff((n+1)/2);
}
