#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void mutate(Individual *individual, double rate){
	int n = (individual -> image.width) * (individual -> image.height);
	int size = (int)(rate/100*n);
	for(int i = 0; i < size; i++){
		int a = rand()%n;
		individual->image.data[a].r = rand()%((individual->image.max_color-0+1)+0);
		individual->image.data[a].g = rand()%((individual->image.max_color-0+1)+0);
		individual->image.data[a].b = rand()%((individual->image.max_color-0+1)+0);
	}
}


void mutate_population(Individual *individual, int population_size, double rate){
	for(int i = population_size / 4; i < population_size; i++){
		mutate(&individual[i], rate);
	}
}
