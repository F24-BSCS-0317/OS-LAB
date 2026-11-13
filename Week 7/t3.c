#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int p1[2];
    int p2[2];
    
    pipe(p1);
    pipe(p2);

    pid_t pid = fork();
    if (pid == 0) {
        int output = open("error.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(output, STDERR_FILENO);
		dup2(p1[1], STDOUT_FILENO);
        close(output);
        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);

        char *cmds[] = {"ls", "-l", NULL};
        execvp("ls", cmds);

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

        execlp("grep", "grep", "txt", NULL);
        perror("grep");
        exit(1);
    }
    
    pid_t pid3 = fork();
    if (pid3 == 0) {
        int out = open("unique.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

        dup2(p2[0], STDIN_FILENO);
        dup2(out, STDOUT_FILENO);

        close(out);
        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);

        execlp("uniq", "uniq", NULL);
        perror("uniq");
        exit(1);
    }

    close(p1[0]);
    close(p1[1]);
    close(p2[0]);
    close(p2[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

