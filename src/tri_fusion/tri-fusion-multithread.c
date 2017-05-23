#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rdtsc-timer.h"
#include <stdio.h>
#include "tri-fusion.h"
#define N_Tableau (int)pow(2,30)/(int)sizeof(double)

int main(int argc, char *argv[]){
	double * tab = (double *) malloc(N_Tableau * sizeof(double)); // malloc alloue en octet
	double * tmp = (double *) malloc(N_Tableau * sizeof(double));
	double time_0, time_1;
	double avg, average;
	double tpscalcul;
	uint64_t k;
	uint64_t nTest;
	uint64_t j;
	srand48(time(NULL));

	nTest = atoi(argv[1]); // Nbre de test
	k = 0;
	avg = 0.0;
  omp_set_num_threads(4); // on fixe nos thread au maxi des machines enssat

	while(k<nTest){
		for(j = 0; j < N_ARRAY; j++){
			tab[j] = drand48()*64;
		}
		fprintf(stdout,"Init du tableau %ld\n",k);
		TIME_START2(time_0);
		mergesort_multithread(tab, N_ARRAY, tmp, 0);
		TIME_STOP2(time_1);

		tpscalcul = ((double)(time_1-time_0));
		fprintf(stdout,"Fin test #%ld en %e\n", k, tempscalcul);
		avg = avg + tpscalcul;
		k = k + 1;
	}
	average = avg/nTest;
	fprintf(stdout,"Moyenne du temps de calcul : %e\n",average);
	free(tab);
	free(tmp);
}
