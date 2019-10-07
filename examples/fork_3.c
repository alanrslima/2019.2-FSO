#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{ 
  pid_t r;
  /* fork another process */
  r = fork();
  if (r < 0) { /* error occurred */
    fprintf(stderr, "Fork Failed");
    exit(-1);
  } else if (r == 0) { /* child process */
    execlp("/bin/ls", "ls", NULL);
  } else { /* parent process */
  /* parent will wait for the child to
  complete */
    wait (NULL);
    printf ("Child Complete");
    exit(0);  
  };
};