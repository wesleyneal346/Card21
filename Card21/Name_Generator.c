#include "Name_Generator.h"

bool isNumber(char num[]) {
	int i = 0;
	if (num[0] == '-') i = 1;

	for (; num[i] != 0; i++) {
		if (!isdigit(num[i])) return false;
	}
	return true;
}

int getNumSounds(FILE* fp) {
	char ch;
	int lines = 0;
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == ' ')
			lines++;
	}
	fseek(fp, 0L, SEEK_SET);
	return lines + 1;
}

void constructNamePart(name_part_t* part, char* file) {
	errno_t err;
	part->fileName = file;
	err = fopen_s(&part->fp, part->fileName, "r");
	if (err != 0) {
		perror("Failed to open file: ");
	}
	part->len = getNumSounds(part->fp);
	part->arr = calloc(part->len, sizeof(char*));
	if (part->arr == NULL) {
		perror("Error: out of memory");
	}
	for (int i = 0; i < part->len; i++) {
		part->arr[i] = calloc(4, sizeof(char));
		fscanf_s(part->fp, "%s", part->arr[i]);
		if (part->arr[i] == NULL) {
			perror("Error in reading");
		}
	}
}

void printCharArray(name_part_t part) {
	for (int i = 0; i < part.len; i++) {
		printf("%3d: ", i + 1);
		printf("%s\n", part.arr[i]);
	}
}

void freeUpPart(name_part_t part) {
	for (int i = 0; i < part.len; i++) {
		free(part.arr[i]);
	}
	fclose(part.fp);
}
void nameGen(int argc, char* argv[]) {
	int soundCount, nameCount;
	name_part_t begs, cons, vows, ends;
	name_part_t begd, cond, vowd, endd;
	/* ERROR CHECK ARGS*/
	if (argc < 2) {
		printf("%s usage: \n", argv[0]);
		printf("\t%s #_of_names\n", argv[0]);
		printf("\t%s #_of_sounds_per_name #_of_names\n\n", argv[0]);
		printf("This program will generate random names givien the specified parameters.");
		return;
	} else if (argc < 3) {
		if (isNumber(argv[1])) {
			nameCount = atoi(argv[1]);
		} else {
			printf("That was not a number. Using 10 instead.\n");
			nameCount = 10;
		}
			soundCount = 5;
	} else {
		if (isNumber(argv[1]) && isNumber(argv[2])) {
			soundCount = atoi(argv[1]);
			nameCount = atoi(argv[2]);
		} else {
			printf("Those were not numbers. Using 10 and 5 instead.\n");
			nameCount = 10;
			soundCount = 5;
		}
	}
	printf("Generating %d names with %d sounds.\n", nameCount, soundCount);
	
	/* INITIALIZE ARRAYS */
	constructNamePart(&begs, "text_files/begin_s.txt");
	constructNamePart(&cons, "text_files/cons_s.txt");
	constructNamePart(&vows, "text_files/vow_s.txt");
	constructNamePart(&ends, "text_files/end_s.txt");
	
	constructNamePart(&begd, "text_files/begin_d.txt");
	constructNamePart(&cond, "text_files/cons_d.txt");
	constructNamePart(&vowd, "text_files/vow_d.txt");
	constructNamePart(&endd, "text_files/end_d.txt");
	
	/* GENERATE NAMES */
	srand(time(NULL));
	for (int i = 0; i < nameCount; i++){
		
		if (rand() % 10 < 6)
			printf("%s", begs.arr[rand() % begs.len]);
		else
			printf("%s", begd.arr[rand() % begd.len]);
		
		for (int j = 1; j < soundCount - 1; j++) {
			if (j % 2 == 1) {
				if (rand() % 10 < 7)
					printf("%s", vows.arr[rand() % vows.len]);
				else
					printf("%s", vowd.arr[rand() % vowd.len]);
			} else {
				if (rand() % 10 < 8)
					printf("%s", cons.arr[rand() % cons.len]);
				else
					printf("%s", cond.arr[rand() % cond.len]);
			}
		}
		if (rand() % 2 == 0)
			printf("%s\n", ends.arr[rand() % ends.len]);
		else
			printf("%s\n", endd.arr[rand() % endd.len]);
	}
	
	freeUpPart(begs);
	freeUpPart(cons);
	freeUpPart(vows);
	freeUpPart(ends);
	
	freeUpPart(begd);
	freeUpPart(cond);
	freeUpPart(vowd);
	freeUpPart(endd);
	
	return;
}