#include "a4.h"
#include <stdlib.h>
#include <stdio.h>


PPM_IMAGE *read_ppm(const char *file_name){
	FILE *a1 = fopen(file_name, "r");
	PIXEL *k;
	int num, num2;
	char arr[100];
	PPM_IMAGE *img = malloc(sizeof(PPM_IMAGE));
	num = fscanf(a1, "%[^\n] %d %d %d", arr, &img -> width, &img -> height, &img -> max_color);
	if(num == 4){
		img -> data = malloc(sizeof(PIXEL) * (img -> width) * (img -> height));
		for (int i = 0; i < (img -> width) * (img -> height); i++){
			k = malloc(sizeof(PIXEL));
			num2 = fscanf(a1, "%d %d %d", &k -> r, &k -> g, &k -> b);
			if(num2 == 3){
				(img -> data + i) -> r = k -> r;
				(img -> data + i) -> g = k -> g;
				(img -> data + i) -> b = k -> b;
			}
		}
	}
	fclose(a1);
	return img;
}




void write_ppm(const char *file_name, const PPM_IMAGE *image){
	int b = 0;
	FILE *a1 = fopen(file_name, "w");
	fprintf(a1, "P3\n");
	fprintf(a1, "%d %d\n", image -> width, image -> height);
	fprintf(a1, "%d\n", image -> max_color);
	for(int i = 0; i < (image -> height) * (image -> width); i++){
		fprintf(a1, "%d %d %d ", (image -> data + i) -> r, (image -> data + i) -> g, (image -> data + i) -> b);
		b++;
		if(b == image -> width){
			fprintf(a1, "\n");
			b = 0;
		}
	}

	fclose(a1);
}
