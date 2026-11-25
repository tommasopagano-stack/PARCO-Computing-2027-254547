#include<stdio.h>
#include<stdlib.h>

#include<string.h>

int main (int argc, char **argv) {
	
	// taking input as an adj matrix from input.txt

	int N, E;	// Nodes, and Edges count
	FILE* f = fopen("input.txt", "r");
	if (f == NULL) {
		perror("error in opening the file\n");
		return 1;
	}

	char *buff = (char*)malloc(sizeof(char) * 64);	// buffer for reading

	if (fgets(buff, 64, f) != NULL) {	// getstring
		N = atoi(strtok(buff, " "));	// tokenizes buff using indicated delimiters
		E = atoi(strtok(NULL, " "));	// proceeds spitting out tokens, if passed NULL, until found the \0
	}
	else {
		perror("Error in reading input.txt\n");
		return 1;
	}	
	
	printf("Nodes: %d\nEdges: %d\n", N, E);


	// input elaboration
	bool **M = (bool**)malloc(sizeof(bool*) * N);	// actual adj matrix

	for (int i = 0; i < N; ++i) {			// init M in heap
		M[i] = (bool*)malloc(sizeof(bool) * N);
	}

	
	int src, dst;
	for (int i = 0; i < E; ++i) {			// silly input for M, just crossing adjs
		
		if (fgets(buff, 64, f) == NULL) {
			perror("Error in reading input.txt\n");
		}
		else {
			src = atoi(strtok(buff, " \0"));
			dst = atoi(strtok(NULL, " \0"));
			M[src][dst] = true;
		}
	}

	// conversion to CSR

	int *CSR_index = (int*)malloc(sizeof(int) * N);
	int *CSR_els = (int*)malloc(sizeof(int) * E);

	int count = 0;
	for (int i = 0; i < N; ++i) {
		CSR_index[i] = count;

		for (int j = 0; j < N; ++j) {
			if(M[i][j]) {
				CSR_els[count++] = j;
			}
		}
	}

	// print to stdout

	printf("\nMatrix:\n");
	for (int i = 0; i < N; ++i) {	
		for (int j = 0; j < N; ++j) {
			if (M[i][j]) {
				printf("[%c]", 'x');
			}
			else {
				printf("[%c]", 'o');

			}
		}

		printf("\n");
	}

	printf("\nCSR:\n");
	printf("index:\t\t");
	for (int i = 0; i < N; ++i) {
		printf("[%d]", CSR_index[i]);
	}

	printf("\nelements:\t");
	for (int i = 0; i < E; ++i) {
		printf("[%d]", CSR_els[i]);
	}

	printf("\n");


	return 0;
}
