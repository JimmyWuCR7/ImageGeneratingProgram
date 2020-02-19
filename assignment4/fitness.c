#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
	PIXEL *c = malloc(sizeof(PIXEL) * image_size);
	PIXEL *d = malloc(sizeof(PIXEL) * image_size);
	double a, b = 0, distance;
	for(int i = 0; i < image_size; i++){
		c[i].r = A[i].r;
		c[i].g = A[i].g;
		c[i].b = A[i].b;
		d[i].r = B[i].r;
		d[i].g = B[i].g;
		d[i].b = B[i].b;
		a = pow((c[i].r - d[i].r), 2) + pow((c[i].g - d[i].g), 2) + pow((c[i].b - d[i].b), 2);
		b = b + a;
	}
	distance = sqrt(b);
	return distance;
}


void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
	for(int i = 0; i < population_size; i++){
		individual[i].fitness = comp_distance(individual[i].image.data, image, individual[i].image.width * individual[i].image.height);
	}
}
