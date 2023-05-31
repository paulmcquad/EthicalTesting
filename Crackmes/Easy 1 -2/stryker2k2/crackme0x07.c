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
  int __result_strncmp = 1;
  
  counter = 0;
  do {
    if (argw[counter] == (char *)0x0) {
      return 0;
    }
    len = strncmp(argw[counter],"LOLO",3);/* Setup a EV .bashrc $printenv LOLO */
    counter++;
  } while (len != 0);
  __result_strncmp = 1;
  return 1;
}

void parell(char *pass,char **argw)

{
  int result;
  int counter;
  uint u_int;
  int __result_strncmp = 1;

  sscanf(pass,"%d",&u_int);
                    /*  Check a EV .bashrc $printenv LOLO  */
  result = dummy(u_int,argw);
  if (result != 0) {
    for (counter = 0; counter < 10; counter = counter + 1) {
      if ((u_int & 1) == 0) {
        if (__result_strncmp == 1) {
          printf("Password OK!\n");
        }
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
    }
  }
  return;
}

void IncorrectPassword(void)
{
  printf("Password Incorrect!\n");
                    /* WARNING: Subroutine does not return */
  exit(0);
}

void check(char *pass,char **argw)

{
  size_t len;
  int len_2;
  char arr_char;
  uint counter;
  int total;
  uint arr_int;
  
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
  IncorrectPassword();
  len_2 = dummy(arr_int,argw);
  if (len_2 != 0) {
    for (counter = 0; (int)counter < 10; counter = counter + 1) {
      if ((arr_int & 1) == 0) {
        printf("wtf?\n");
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
    }
  }
  return;
}

int main(int argc,char **argv,char **argw)
{
  char pass [120];
  
  printf("IOLI Crackme Level 0x07\n");
  printf("Password: ");
  scanf("%s",pass);
  check(pass,argw);
  return 0;
}