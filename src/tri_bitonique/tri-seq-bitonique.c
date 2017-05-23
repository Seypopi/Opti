#include "tri-bitonique.h"

int main(void){
	int i;
	double tab[8];
	tab[0] = 1.0;
	tab[1] = 7.0;
	tab[2] = 0.0;
	tab[3] = 8.0;
	tab[4] = 5.0;
	tab[5] = 7.0;
	tab[6] = 6.0;
	tab[7] = 3.0;
	printf("Tableau non trié : \n");
	for(i=0; i<8; i++){
		printf("%f   \n", tab [i]);
	}
	
	bitonic_sort(tab, 0, 8, 1);
	printf("Tableau trié : \n");
	for(i=0; i<8; i++){
		printf("%f   \n", tab [i]);
	}
	printf("\n");
	return 0;
}
