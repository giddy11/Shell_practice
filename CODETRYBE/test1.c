#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    char *store = NULL;
    size_t size = 0;
    ssize_t r_val;
    pid_t pid;
    int running = 1, wait_status;

    while (running) {
        printf("#cisfun$ ");
        r_val = getline(&store, &size, stdin);

        if (r_val == -1) {
            free(store);
            exit(0);
        }

        // Remove the trailing newline character from the input
        if (store[r_val - 1] == '\n') {
            store[r_val - 1] = '\0';
        }

        pid = fork();
        if (pid == -1) {
            perror("Error creating a new process");
            return (-1);
        }

        if (pid == 0) {
            // Tokenize the input and execute the command
            char *args[64]; // Adjust the size as needed
            int i = 0;
            char *token = strtok(store, " ");
            while (token != NULL) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            int exeRV = execvp(args[0], args);
            if (exeRV == -1) {
                perror("Error ");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(&wait_status);
            printf("Child PID is %u\n", pid);
            printf("Parent has been called with PPID: %u\n", getppid());
        }
    }

    free(store);
    return (0);
}

