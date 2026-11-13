#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	
	pid_t pid = fork();
	
	char* cmds[] = {"date", NULL};
	
	if(pid == 0){
		int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(fd, STDOUT_FILENO);
		execvp("date", cmds);
	}
	
	return 0;
}
