#include <stdio.h>
#include <string.h>

int main () {
   char command[50];

   strcpy( command, "pwd" );
   system(command);

   return(0);
} 