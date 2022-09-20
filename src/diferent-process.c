#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid;
  // Creates another process.
  pid = fork();
  if (pid < 0) { // Error case.
    fprintf(stderr, "Creation failed");
    exit(-1);
  }
  else if (pid == 0) { // Child process.
    execlp("/bin/ls", "ls", "-l", NULL);
  }
  else { // Father process.
    // The father will wait for the child to complete the execution.
    wait(NULL);
    printf("Child completed the execution");
    exit(0);
  }
}
