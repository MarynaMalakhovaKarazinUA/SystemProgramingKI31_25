#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int openFile(uint8_t* flag);
void readData(const int* file, uint8_t* flag);

int main() {

	uint8_t menubar = 0, flag = 0;
	int fData = 0;

	while (1) {

		printf("\n");
        printf("|=======================================|\n");
        printf("|=[1]             Open file             |\n");
        printf("|=======================================|\n");
        printf("|=[2]             Read data             |\n");
        printf("|=======================================|\n");
        printf("|=[0]                Exit               |\n");
        printf("|=======================================|\n");
        printf("\nEnter _> ");

		if (scanf("%hhd", &menubar) >= 1) {

			switch (menubar) {

				case 1:

					system("clear");
					if (flag) close(fData);
					fData = openFile(&flag);

					break;

				case 2:

					system("clear");
					readData(&fData, &flag);

					break; 
					
				case 0:

					system("clear");
                    printf("\n\e[3;32m|| WORK COMPLETE ||\e[0m\n");
                    return 0;

				default:

					system("clear");
                    printf("\n\e[7;31mERROR_UKNOWN!\e[0m\n");
                    break;

			}

		} else {

			while(getchar() != '\n');
            system("clear");
            printf("\n\e[7;31mERROR:\e[0m Invalid value!\n");
		}
	}

	return 0;
}

int openFile(uint8_t* flag) {

	int file = 0;
	char path[50];

	printf("\nEnter path: ");
	scanf("%s", path);

	file = open(path, O_RDONLY);

	if (file == -1) {
		
		printf("\n\e[7;31mERROR:\e[0m Unable to access file!\n");

		*flag = 0;
		return -1;

	} else {

		system("clear");
		printf("\n\e[3;32m File access successfully obtained \e[0m\n");

		*flag = 1;
		return file;
	}
}

void readData(const int* file, uint8_t* flag) {

	if (*flag == 0) {

		printf("\n\e[7;31mERROR:\e[0m Access denied!\n");
		return;
	}

	char buffer[255];
	int rBytes = 0;

	rBytes = read(*file, buffer, sizeof(buffer) - 1);

	if (rBytes == -1) {
		
		printf("\n\e[7;31mERROR:\e[0m Error reading file!\n");

		*flag = 0;
		close(*file);
		return;
	}

	buffer[rBytes] = '\0';

	printf("\nRead data: \n\n%s\n", buffer);

	*flag = 0;
	close(*file);
}