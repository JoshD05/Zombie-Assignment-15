#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void algorithm(int n) {
    while (n != 1) {
        printf("%d ", n);
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
    }
    printf("1\n");
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) running n=27\n", getpid());
        algorithm(27);
        exit(0);
    } else {
        // Parent process
        printf("Parent process (PID: %d) created child (PID: %d)\n", getpid(), pid);
        printf("Parent sleeping for 20 seconds.\n");
        sleep(20);
    }

    return 0;
}