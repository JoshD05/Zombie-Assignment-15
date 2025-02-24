#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process is running. PID: %d\n", getpid());
        exit(0);
    } else {
        // Parent process
        printf("Parent process is running. PID: %d\n", getpid());
        printf("Zombie process created. Check zombie process in ps -l\n");
        printf("Parent will wait for 20 seconds before exiting.\n");
        sleep(20); // Sleep for 20 seconds
    }

    return 0;
}
