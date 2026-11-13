#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int p1[2];
    int p2[2];
    int p3[2];
    
    pipe(p1);
    pipe(p2);
    pipe(p3);

    pid_t pid = fork();
    if (pid == 0) {
        int input = open("T4names.txt", O_RDONLY);
        dup2(input, STDIN_FILENO);
		dup2(p1[1], STDOUT_FILENO);
        close(input);
        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);
        close(p3[0]);
        close(p3[1]);

        char *cmds[] = {"cat", NULL};
        execvp("cat", cmds);

        perror("execvp");
        exit(1);
    }
    
    
    pid_t pid2 = fork();

    if (pid2 == 0) {
        dup2(p1[0], STDIN_FILENO);
        dup2(p2[1], STDOUT_FILENO);

        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);
        close(p3[0]);
        close(p3[1]);

        execlp("sort", "sort", NULL);
        perror("sort");
        exit(1);
    }
    
    pid_t pid3 = fork();
    if (pid3 == 0) {

        dup2(p2[0], STDIN_FILENO);
        dup2(p3[1], STDOUT_FILENO);

        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);
        close(p3[0]);
        close(p3[1]);

        execlp("uniq", "uniq", "-c", NULL);
        perror("uniq");
        exit(1);
    }

	pid_t pid4 = fork();

    if (pid4 == 0) {
        dup2(p3[0], STDIN_FILENO);

        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);
        close(p3[0]);
        close(p3[1]);

        execlp("sort", "sort", "-rn", NULL);
        perror("sort");
        exit(1);
    }

    close(p1[0]);
    close(p1[1]);
    close(p2[0]);
    close(p2[1]);
    close(p3[0]);
    close(p3[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

