/*
Pergunta 09 - b
Implemente o algoritmo de pesquisa binária para encontrar um elemento em uma lista ordenada.*/

int pesquisaBinaria(int *v, int dado, int inicio, int fim){
	int pivot = (inicio+fim)/2;
	if(v[pivot] == dado) return pivot;
	if(inicio >= fim) return -1;
	if(v[pivot] < dado) return pesquisaBinaria(v, dado, pivot+1, fim);
	else return pesquisaBinaria(v, dado, inicio, pivot-1);
}