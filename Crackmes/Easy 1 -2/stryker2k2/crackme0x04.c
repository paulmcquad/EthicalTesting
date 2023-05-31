//  Reversing CrackMe with Ghidra (Part 1) 
// https://www.youtube.com/watch?v=6p5Qviusskk


// https://github.com/Maijin/radare2-workshop-2015/blob/master/IOLI-crackme/bin-linux/crackme0x04

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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
    if (len <= counter) {
      printf("Password Incorrect!\n");
      return;
    }
    arr_char = pass[counter];
    sscanf(&arr_char,"%d",&arr_int);
    total = total + arr_int;
                    /* 15 - 0xf - Hex -> Dec. Password: 555 / 654 / 96 (Any Password that adds to
                       15) */
    if (total == 0xf) break;
    counter++;
  }
  printf("Password OK!\n");
                    /* WARNING: Subroutine does not return */
  exit(0);
}


int main(void)

{
  char pass [120];
  
  printf("IOLI Crackme Level 0x04\n");
  printf("Password: ");
  scanf("%s",pass);
  check(pass);
  return 0;
}
