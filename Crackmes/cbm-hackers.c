//cbm-hackers's easy_reverse
//https://crackmes.one/crackme/5b8a37a433c5d45fc286ad83

//  Ghidra quickstart & tutorial: Solving a simple crackme 
//https://www.youtube.com/watch?v=fTGTnrgjuGA

//./cbm-hackers 1234@67890
//Nice Job!!
//flag{1234@67890}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char **argv)

{
  printf("USAGE: %s <password>\n",argv);
  puts("try again!");
                    /* WARNING: Subroutine does not return */
  exit(0);
}

int main(int argc,char **argv)
{
  size_t arg1_length;
  
                    /* Check if we have 1 argument */
  if (argc == 2) {
    arg1_length = strlen(argv[1]);
                    /* Check if argument1 is 10 characters long */
    if (arg1_length == 10) {
                    /* Check if 5. character in argument1 is an "@" character */
      if (argv[1][4] == '@') {
        puts("Nice Job!!");
        printf("flag{%s}\n",argv[1]);
      }
      else {
        usage(argv);
      }
    }
    else {
      usage(argv);
    }
  }
  else {
    usage(argv);
  }
  return 0;
}


