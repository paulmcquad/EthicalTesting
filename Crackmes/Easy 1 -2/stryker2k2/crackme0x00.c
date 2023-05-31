//  Reversing CrackMe with Ghidra (Part 1) 
// https://www.youtube.com/watch?v=6p5Qviusskk


// https://github.com/Maijin/radare2-workshop-2015/blob/master/IOLI-crackme/bin-linux/crackme0x00

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)

{
  int result;
  char pass [24];
  
  printf("IOLI Crackme Level 0x00\n");
  printf("Password: ");
  scanf("%s",pass);
                    /* strcmp: Password: 250382 */
  result = strcmp(pass,"250382");
  if (result == 0) {
    printf("Password OK :)\n");
  }
  else {
    printf("Invalid Password!\n");
  }
  return 0;
}
