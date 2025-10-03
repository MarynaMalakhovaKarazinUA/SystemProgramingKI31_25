/* Успадкування файлових дескрипторів
 Відкрити файл у батьківському процесі. 
 Після fork() дочірній процес зміщує покажчик у файлі, 
 а батьківський читає з цієї позиції. Продемонструвати спільність дескриптора. */

#include <stdio.h>
int main() {
    pid_t childPid;
    switch (childPid = fork()) {
        case -1: /* fork() failed */
            printf("Error"); /* Handle error */
            break;

        case 0: /* Child of successful fork() comes here */
            printf("Hello, I am child!"); /* Perform actions specific to child */
            break;

        default: /* Parent comes here after successful fork() */
            printf("Hello, I am super mama!"); /* Perform actions specific to parent */
    }
    return 0;
}
