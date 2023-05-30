//ker2x's guild hall adventure Ch.1
//https://crackmes.one/crackme/5d0fa1ac33c5d41c6d56e172


//$ ./guild-hall-ch1-kf hello
//Friendly greetings to you, hacker from another world !
//So, why are you here ? : ./guild-hall-ch1-kf
//good, good, welcome to the guild hall!

// Solution by kawaii-flesh:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Woaaa ! what about being polite ? huh ?\n");
    }
    else
    {
        if(strlen(argv[1])==5 && !strcmp(argv[1], "hello"))
        {
            char str[50];
            printf("Friendly greetings to you, hacker from another world !\n");
            printf("So, why are you here ? : ");
            scanf("%49s", str);
            if(strlen(argv[0])==strlen(str) && !strcmp(str, argv[0]))
            {
                printf("good, good, welcome to the guild hall!\n");
            }
            else printf("This is the guild hall, i can't let you in, sorry, i need to kill you now. Byyye~~~\n");

        }
        else printf("no no no ! it's not a socially appropriate greeting !\n");
    }
    return 0;
}