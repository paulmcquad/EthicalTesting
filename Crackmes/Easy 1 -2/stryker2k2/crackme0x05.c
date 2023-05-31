//  Reversing CrackMe with Ghidra (Part 1) 
// https://www.youtube.com/watch?v=6p5Qviusskk


// https://github.com/Maijin/radare2-workshop-2015/blob/master/IOLI-crackme/bin-linux/crackme0x05

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void parell(char *pass)

{
  uint counter;
  
  sscanf(pass,"%d",&counter);
  if ((counter & 1) == 0) { /* Bitwise AND */
    printf("Password OK!\n");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  return;
}

void check(char *pass)

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
                    /* 16 - 0x10 - Hex -> Dec. Password: 556 / 916 / 23236 / 196 (Any Password that
                       adds to 16) */
    if (total == 0x10) {
      parell(pass);
    }
    counter++;
  }
  printf("Password Incorrect!\n");
  return;
}


int main(void)

{
  char pass [120];
  
  printf("IOLI Crackme Level 0x05\n");
  printf("Password: ");
  scanf("%s",pass);
  check(pass);
  return 0;
}