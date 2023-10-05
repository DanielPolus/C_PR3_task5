#include <stdio.h>
#include <stdlib.h>

double* space;
int size, i, j, minIndex;
double min;

void add(double item) {
	size += 1;
	space = (double*)realloc(space, sizeof(double) * (size));
	space[size - 2] = item;
}

void show() {
	int i;
	printf("\n");
	for (i = 0; i < size - 1; i++) {
		printf_s("%.2lf ", space[i]);
	}
}


void removeFromList(int index) {
	if (index >= size - 1) {
		printf_s("\ninvalid index\n");
		return;
	}
	int i;
	for (i = index; i < size - 2; i++) {
		space[i] = space[i + 1];
	}
	size -= 1;
}

int main() {
	space = (double*)malloc(space, sizeof(double));
	size = 1;

	add(4.0);


	add(5.1);
	add(6.4);
	add(7.9);
	add(8.2);
	add(1.2);
	add(2.4);
	add(6.1);
	add(0.4);
	add(10.3);

	//removeFromList(2); // нельзя просто "remove" (

	show();

	for (i = 0; i < 10; i++) {
		min = space[0];
		minIndex = 0;
		for (j = 0; j < size - 1; j++) {
			//printf("\nit%d", j);
			if (min > space[j] && space[j] != 0) {
				min = space[j];
				minIndex = j;
				//printf("\nMin: %lf     minIndex: %d", min, minIndex);
			}
		}
		if (space[minIndex + 1] > space[minIndex - 1]) {
			space[minIndex + 1] += space[minIndex];
		}
		else {
			space[minIndex - 1] += space[minIndex];
		}
		removeFromList(minIndex);

		show();
		//printf("\nsize: %d", size);
	}


	free(space);
	return 0;
}