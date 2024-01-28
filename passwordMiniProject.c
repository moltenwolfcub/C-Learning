/* main.c */
/* 0 copyright/licensing */
/* 1 includes */
#include <stdio.h>
#include <string.h>
/* 2 defines */
/* 3 external declarations */
/* 4 typedefs */
/* 5 global variable declarations */

int getPassword(char*, int);

int main(int argc, char const *argv[]) {
	
	char password[11];
	if (getPassword(password, sizeof(password) / sizeof(password[0]) -1) != 0) {
		return 1;
	}

	FILE* fp;
	fp = fopen("passwordStorage.txt", "w");
	
	if (fputs(password, fp) == EOF) {
		printf("Failed to write to file.\n");
		return 1;
	}

	fclose(fp);

	return 0;
}

int getPassword(char* passwordPtr, int maxCharacters) {
	char input[maxCharacters+2];
	printf("Please enter your password: ");
	fgets(input, sizeof(input), stdin);

	input[strcspn(input, "\n\r")] = 0;

	if (input[maxCharacters] != '\0') {
		printf("Password can only be %d characters long.\n", maxCharacters);
		return 1;
	}

	char password[maxCharacters+1];
	strncpy(password, input, maxCharacters+1);
	
	printf("Your password is: %s\n", password);
	strcpy(passwordPtr, password);

	return 0;
}
