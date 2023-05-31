//sudo0x18's Level1
//https://crackmes.one/crackme/646627a933c5d439389131d9

// gcc sudo0x18_level1.c -o sudo0x18_level1
// ./sudo0x18_level1
// Welcome to Easy Crack MeWhat is the Secret ?sudo0x18
// You are correct :)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char checkPass(char *a1)

{
  char result;
  
  if (*a1 == 's') {
    result = a1[1];
    if ((((result == 'u') && (result = a1[2], result == 'd')) && (result = a1[3], result == 'o')) &&
       (((result = a1[4], result == '0' && (result = a1[5], result == 'x')) &&
        ((result = a1[6], result == '1' && (result = a1[7], result == '8')))))) {
      result = '\x01';
    }
  }
  else {
    result = '\0';
  }
  return result;
}

int main(void)

{
    char v4 [64];

    printf("Welcome to Easy Crack Me");
    printf("What is the Secret ?");
    scanf("%63s", v4);
    if ( (unsigned int)checkPass(v4) )
        printf("You are correct :)\n");
    else
        printf("Better luck next time. :(\n");
    return 0;
}
