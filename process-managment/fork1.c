#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   pid_t cpid = vfork();
   if (cpid == 0)
   {
      sleep(1);
      printf("Hello I am child..\n");
      sleep(2);
      printf("Hello I am child again, I am exitting.\n");
      sleep(2);
      exit(0);
   }
   else
   {
      printf("\nHello I am parent, my child has terminated\n");
      exit(0);
   }
}
