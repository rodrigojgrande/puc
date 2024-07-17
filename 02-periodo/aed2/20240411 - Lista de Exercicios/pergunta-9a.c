/*
Pergunta 09 - a
Escreva um algoritmo de ordenação de bolha (bubble sort) para ordenar uma lista de números.
*/

void bubble_sort(int vet[], int tam){
	int i, j, aux;
	for(i = 0; i < tam - 1; i++){
		for(j = tam - 1; j > i; j--){
			if(vet[j] < vet[j - 1]){
			aux = vet[j];
			vet[j] = vet[j - 1];
			vet[j - 1] = aux;
			}
		}
	}
}
/*FIM A*/