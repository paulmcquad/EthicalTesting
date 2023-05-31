//  Reversing CrackMe with Ghidra (Part 1) 
// https://www.youtube.com/watch?v=6p5Qviusskk


// https://github.com/Maijin/radare2-workshop-2015/blob/master/IOLI-crackme/bin-linux/crackme0x06

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int dummy(uint input,char **argw)

{
  int len;
  int counter;
  
  counter = 0;
  do {
    if (argw[counter] == (char *)0x0) {
      return 0;
    }
    len = strncmp(argw[counter],"LOLO",3); /* Setup a EV .bashrc $printenv LOLO */
    counter = counter + 1;
  } while (len != 0);
  return 1;
}

void parell(char *pass,char **argw)

{
  int result;
  int counter;
  uint u_int;
  
  sscanf(pass,"%d",&u_int);
  result = dummy(u_int,argw);
  if (result != 0) {
                    /* Counter is below 10 */
    for (counter = 0; counter < 10; counter = counter + 1) {
                    /* Bitwise AND - u_int is even number */
      if ((u_int & 1) == 0) {
        printf("Password OK!\n");
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
    }
  }
  return;
}

void check(char *pass,char **argw)

{
  size_t len;
  char arr_char;
  uint counter;
  int total;
  int arr_int;
  
  total = 0;
  counter = 0;
  while( true ) {
    len = strlen(pass);
    if (len <= counter) break;
    arr_char = pass[counter];
    sscanf(&arr_char,"%d",&arr_int);
    total = total + arr_int;
    if (total == 0x10) {
      parell(pass,argw);
    }
    counter = counter + 1;
  }
  printf("Password Incorrect!\n");
  return;
}


int main(int argc,char **argv,char **argw)

{
  char pass [120];
  
  printf("IOLI Crackme Level 0x06\n");
  printf("Password: ");
  scanf("%s",pass);
  check(pass,argw);
  return 0;
}