#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

PIXEL *generate_random_image(int width, int height, int max_color){
	srand(time(NULL));
	PIXEL *pix = malloc(sizeof(PIXEL) * width * height);
	for(int i = 0; i < width * height; i++){
		(pix + i) -> r = rand()%(max_color-0+1)+0;
		(pix + i) -> g = rand()%(max_color-0+1)+0;
		(pix + i) -> b = rand()%(max_color-0+1)+0;
	}
	return pix;
}


Individual *generate_population(int population_size, int width, int height, int max_color){
	Individual *img = malloc(sizeof(Individual) * population_size);
	for(int i = 0; i < population_size; i++){
		((img + i) -> image).width = width;
		((img + i) -> image).height = height;
		((img + i) -> image).max_color = max_color;
		(img + i) -> image.data = generate_random_image(width, height, max_color);
	}
	return img;
}
