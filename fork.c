#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int global_var = 10;

int main() {
    int local_var = 20; 
    pid_t pid;

    printf("global_var = %d, local_var = %d\n", global_var, local_var);

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        global_var += 5;
        local_var += 5;
        printf("\n[Child process]\n");
        printf("PID: %d\n", getpid());
        printf("global_var = %d, local_var = %d\n", global_var, local_var);
    }
    else {
        global_var -= 5;
        local_var -= 5;
        printf("\n[Parent process]\n");
        printf("PID: %d\n", getpid());
        printf("global_var = %d, local_var = %d\n", global_var, local_var);
    }

    return 0;
}
