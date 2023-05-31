//  Reversing CrackMe with Ghidra (Part 1) 
// https://www.youtube.com/watch?v=6p5Qviusskk


// https://github.com/Maijin/radare2-workshop-2015/blob/master/IOLI-crackme/bin-linux/crackme0x03

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void shift(char *sub3)

{
  size_t len;
  uint counter;
  char arr_char [120];
  
  counter = 0;
  while( true ) {
    len = strlen(sub3);
                    /* if "len" is greater than or equal to "counter" continue */
    if (len <= counter) break;
                    /* Use Cyber Chef - Arithmetic/Logic - SUB 3 Decimal */
    arr_char[counter] = sub3[counter] + -3;
    counter++;
  }
  arr_char[counter] = '\0';
  printf("%s\n",arr_char);
  return;
}

void test(int pass,int hex)

{
                    /* Use Cyber Chef - Arithmetic/Logic - SUB 3 Decimal */
  if (pass == hex) {
                    /* Password OK!!! :) */
    shift("Sdvvzrug#RN$$$#=,");
  }
  else {
                    /* Invalid Password! */
    shift("Lqydolg#Sdvvzrug$");
  }
  return;
}


int main(void)

{
  int pass;
  
  printf("IOLI Crackme Level 0x03\n");
  printf("Password: ");
                    /* Password: 338724 (0x52b24) Hex -> Dec */
  scanf("%d",&pass);
  test(pass,0x52b24);
  return 0;
}
