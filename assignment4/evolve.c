#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
	Individual *img;
	char format[] = "image%d.ppm";
	char filename[sizeof(format) + 100];
	img = generate_population(population_size, image -> width, image -> height, image -> max_color);
	comp_fitness_population(image -> data, img, population_size);
	int num = 1;
	while(num == 1){
		int i = 0;
		num = 0;
        	while (i < population_size - 1){ 
           		if (img[i].fitness > img[i + 1].fitness){
				Individual swap;
				swap = img[i]; 
				img[i] = img[i + 1]; 
				img[i + 1] = swap; 
				num = 1; 
			}
			i++;
		} 
	}

	for(int j = 1; j <= num_generations; j++){
		crossover(img, population_size);
		mutate_population(img, population_size, rate);
		comp_fitness_population(image -> data, img, population_size);
		int num2 = 1;
		while(num2 == 1){
			num2 = 0;
			int i2 = 0;
        		while (i2 < population_size - 1){ 
           			if (img[i2].fitness > img[i2 + 1].fitness){
					Individual swap2;
					swap2 = img[i2]; 
					img[i2] = img[i2 + 1]; 
					img[i2 + 1] = swap2; 
					num2 = 1; 
				}
				i2++;
			} 
		}
		printf("%d %f\n", j, img[0].fitness);
		if(j%400 == 0){
			sprintf(filename, format, j);
			write_ppm(filename, &((img) -> image));
		}
	}
	return &(img[0].image);
}




void free_image(PPM_IMAGE *p)
{
	free(p);
}
