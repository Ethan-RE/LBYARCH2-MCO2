#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Assuming this function is implemented in assembly
extern int imgCvtGrayDoubleToInt(int height, int width, double** pixels, int** results);

int main() {
	srand(time(NULL));
    int a, b;
    double** pixels;
    int** results;

    // Get height and width
    printf("Height: ");
    scanf("%d", &a);
    printf("Width: ");
    scanf("%d", &b);
    
    // Allocate memory for `pixels`
	pixels = (double**)malloc(a * sizeof(double*));
    for (int i = 0; i < a; i++) {
        pixels[i] = (double*)malloc(b * sizeof(double));
    }
	
	// Input values inside `pixels`
	for(int x = 0; x < a; x++){
		for(int y = 0; y < b ; y++){
			pixels[x][y] = (double)rand() / RAND_MAX;
		}
	}
	
    // Allocate memory for `results`
    results = (int**)malloc(a * sizeof(int*));
    for (int i = 0; i < a; i++) {
        results[i] = (int*)malloc(b * sizeof(int));
    }

    // Call the external function
    imgCvtGrayDoubleToInt(a, b, pixels, results);
    
    // Print `pixel` values and `results`
    printf("\nOriginal Values: \n");    
    for(int x = 0; x < a; x++){
		for(int y = 0; y < b ; y++){
			printf("%f ", pixels[x][y]);
		}
		printf("\n");
	}
	
	
	printf("\nResults: \n");
	for(int x = 0; x < a; x++){
		for(int y = 0; y < b ; y++){
			printf("%d ", results[x][y]);
		}
		printf("\n");
	}
    return 0;
}
