#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct Name_Part {
	char* fileName;
	FILE* fp;
	int len;
	char** arr;
} name_part_t;

bool isNumber(char num[]);

int getNumSounds(FILE* fp);

void constructNamePart(name_part_t* part, char* file);

void printCharArray(name_part_t part);

void freeUpPart(name_part_t part);