/* Успадкування файлових дескрипторів
 Відкрити файл у батьківському процесі. 
 Після fork() дочірній процес зміщує покажчик у файлі, 
 а батьківський читає з цієї позиції. Продемонструвати спільність дескриптора. */

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int rd;
    off_t p;
    pid_t childPid;
    rd = open(“some_file.txt”, O_CREAT | O_RDONLY, 0644);
    if (rd < 0) {
        printf("Error opening/creating file");
        return 1;
    }
    write(rd, "Hi, I am Anhelina :)", 20);
    lseek(rd, 0, SEEK_SET);
    switch (childPid = fork()) {
        case -1: /* fork() failed */
            printf("Error fork"); /* Handle error */
            break;

        case 0: /* Child of successful fork() comes here */
            printf("Hello, I am child!"); /* Perform actions specific to child */
            lseek(rd, 5, SEEK_SET);
            p = lseek(rd, 0, SEEK_CUR);
            printf("Child: %ld\n", (long)p);
            exit(0);
        default: /* Parent comes here after successful fork() */
            sleep(1);
            printf("Hello, I am super mama!"); /* Perform actions specific to parent */
            p = lseek(rd, 0, SEEK_CUR);
            printf("Parent: %ld\n", (long)p);
    }
    close(rd);
    return 0;
}
