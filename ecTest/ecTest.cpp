#include <stdio.h>

int main(int argc, char** argv) {
	int bigArray[1000];

	for (int i = 0; i<1000; ++i) {
		bigArray[i] = i * i;
	}

	for (int i = 0; i<1000; ++i) {
		printf ("%d ",bigArray[i]);
	}

	return 0;
}

