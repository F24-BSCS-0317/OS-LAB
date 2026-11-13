#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        int input = open("names.txt", O_RDONLY);
        int output = open("sorted.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

        dup2(input, STDIN_FILENO);
        dup2(output, STDOUT_FILENO);

        close(input);
        close(output);

        char *cmds[] = {"sort", NULL};
        execvp("sort", cmds);

        perror("execvp");
        exit(1);
    }
    else {
        wait(NULL);
    }

    return 0;
}

