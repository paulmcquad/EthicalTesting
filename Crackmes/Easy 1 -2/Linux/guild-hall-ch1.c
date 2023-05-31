//ker2x's guild hall adventure Ch.1
//https://crackmes.one/crackme/5d0fa1ac33c5d41c6d56e172


//$ ./guild-hall-ch1 hello
//Friendly greetings to you, hacker from another world !
//So, why are you here ? : ./guild-hall-ch1
//./guild-hall-ch1 ?  good, good, welcome to the guild hall!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char **argv)

{
  int iVar1;
  size_t s_program;
  char s_Input [136];
  
  if (argc == 2) {
                    /* Length of argument 1 be 5 - hello */
    s_program = strlen(argv[1]);
    if (s_program == 5) {
                    /* Type "hello" to enter the program. */
      iVar1 = strncmp(argv[1],"hello",5);
      if (iVar1 == 0) {
        puts("Friendly greetings to you, hacker from another world !");
        printf("So, why are you here ? : ");
                    /* Read a string */
            __isoc99_scanf(&"%s",s_Input);
                    /* Print a String */
        printf("%s ?  ",s_Input);
                    /* Strlen - Returns the length of the C string str (local_98). */
        s_program = strlen(s_Input);
                    /* Strncmp - input string is compared against arg1 (./ + program name) */
        iVar1 = strncmp(*argv,s_Input,s_program);
        if (iVar1 == 0) {
          puts("good, good, welcome to the guild hall!");
          iVar1 = 0;
        }
        else {
          puts(
              "This is the guild hall, i can\'t let you in, sorry, i need to kill you now. Byyye~~~"
              );
          iVar1 = -3;
        }
        goto LAB_00100967;
      }
    }
    puts("no no no ! it\'s not a socially appropriate greeting !");
    iVar1 = -2;
  }
  else {
    puts("Woaaa ! what about being polite ? huh ?");
    iVar1 = -1;
  }
LAB_00100967:
    return 0;
}