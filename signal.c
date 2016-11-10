#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>


static void sighandler (int signo){
  if (signo == SIGINT){
    printf("Signal caught: %d\n", signo);
    int fd = open("file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    write(fd,"\nFile exiting: SIGINT\n",25);
    close(fd);
    exit(0);
  }

  else if (signo == SIGUSR1)
    printf("PID of parent process: %d \n", getppid());
}

int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
  while(1){
    printf("Current PID: %d\n",getpid());
    sleep(1);
  }

  return 0;
}
