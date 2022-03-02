#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include "includes.h"

void prvy(int x) {
	int temp = x;
	int zvysok[32];
	int y = 0;

	printf("DEC: %d | HEX: %X | BIN: ", x, x);
	while (temp >= 1) {
		temp /= 2;
		y++;	//Kolko bitov v cisle
	}

	temp = x;

	for (int x = y; x >= 1; x--) {	//Zapisujem do pola zvysky
		zvysok[x - 1] = temp % 2;
		temp /= 2;
	}

	for (int x = 0; x < y; x++) {	//Vypisem zvysky
		printf("%d", zvysok[x]);
	}
}

int druha(int x) {
	if (x > 100) {
		printf("Cislo nie je z rozsahu 1 - 100");
		return -1;
	}

	int temp = x;
	while (temp != 0) {
		if (temp == 100) {
			printf("C");
			temp -= 100;
		}
		else if (temp < 100 && temp > 49) {
			if (temp > 90) {
				temp -= 90;
				printf("XC");
			}
			else {
				temp -= 50;
				printf("L");
			}
		}
		else if (temp < 50 && temp >= 10) {
			if (temp > 40) {
				temp -= 40;
				printf("XL");
			}
			else {
				temp -= 10;
				printf("X");
			}
		}
		else if (temp < 10 && temp >= 5) {
			if (temp == 9) {
				printf("IX");
				temp -= 9;
			}
			else {
				printf("V");
				temp -= 5;
			}
		}
		else if (temp < 5 && temp >= 1) {
			if (temp == 4) {
				printf("IV");
				temp -= 4;
			}
			else {
				printf("I");
				temp -= 1;
			}
		}

	}
	return 1;
}

int tretia(int k) {
	int x = 1, p1 = 1, p2 = 0, aktualne = 0;
	if (k < 2) {
		printf("k nie je vyssie alebo rovne ako 2");
		return -1;
	}

	while (x <= k) {
		if (x == 1) {
			printf("1, ");
		}
		else {
			aktualne = p1 + p2;
			printf("%d, ", aktualne);
			p2 = p1;
			p1 = aktualne;
		}
		x++;
	}

}

void stvrta(float Epsilon) {
	float predosle = 0;
	while ((1 + Epsilon) != 1) {
		predosle = Epsilon;
		Epsilon /= 2;
	}
	printf("Vypocitane Epsilon: %.20f \nFloat.h FLOAT Epsilon: %.20f \nFloat.h DOUBLE Epsilon: %.20lf", predosle, FLT_EPSILON, DBL_EPSILON);

}

void piata(float radians, float epsilon) {
	long float max = 0;
	int y = 1;

	if (radians >= 2 * PI) {
		int otocenia = (int)(radians / (2 * PI));
		for (int x = 0; x < otocenia; x++)
			radians -= (2 * PI);
	}

	for (int x = 0; x < 200; x++) {
		float previous = max;
		y = 1;
		long float citatel = (pow((-1), x) * pow(radians, (2 * x) + 1));
		long float menovatel = 1;
		while (y <= ((2 * x) + 1)) {
			menovatel = menovatel * y;
			y++;
		}
		max += citatel / menovatel;
	}
	printf("\n\nsin(%f): %f", radians, max);
}

void siesta(char* intelHexRow) {
	int rowLength = strlen(intelHexRow);
	char tempStorage[2];
	int sum = 0;
	int y = 0;
	for (int x = 0; x < rowLength; x++) {
		if (x != 0) {
			if (x < rowLength - 1) {
				if (y != 2) {
					tempStorage[y] = intelHexRow[x];
					y++;
				}
				else {
					y = 0;
					sum += (int)strtol(tempStorage, NULL, 16);
					tempStorage[y] = intelHexRow[x];
					y++;
				}
			}
		}
	}

	printf("Sum: %d (%X) \n", sum, sum);
	printf("Sum mod256: %d (%X) \n", sum % 256, sum % 256);
	printf("Sum complement: %d (%X) \n", (255 - (sum % 256)), (255 - (sum % 256)));
	printf("Final checksum: %d (%X) \n", (256 - (sum % 256)), (256 - (sum % 256)));
	printf("IntelHexRow (with checksum): ");
	for (int x = 0; x < rowLength - 2; x++) {
		printf("%c", intelHexRow[x]);
	}
	printf("%X", (256 - (sum % 256)));
}

int main() {
	//prvy(33777);
	//druha(44);
	//tretia(10);
	//stvrta(0.5);
	//piata(100, FLT_EPSILON);
	siesta(":10010000214601360121470136007EFE09D21901XX");
	return 0;
} 