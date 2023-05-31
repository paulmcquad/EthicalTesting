//  Reversing CrackMe with Ghidra (Part 1) 
// https://www.youtube.com/watch?v=6p5Qviusskk


// https://github.com/Maijin/radare2-workshop-2015/blob/master/IOLI-crackme/bin-linux/crackme0x02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)

{
  int pass;
  
  printf("IOLI Crackme Level 0x02\n");
  printf("Password: ");
  scanf("%d",&pass);
                    /* Password: 338724 (0x52b24) Hex -> Dec */
  if (pass == 0x52b24) {
    printf("Password OK :)\n");
  }
  else {
    printf("Invalid Password!\n");
  }
  return 0;
}

