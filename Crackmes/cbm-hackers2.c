//cbm-hackers's jumpjumpjump
//https://crackmes.one/crackme/5c1a939633c5d41e58e005d1

#include <stdio.h>
#include <string.h>

char flag[10];
char inputString[64];
char *part1 = "flag is flag{";
char *part2 = "}";

char *strcat_str() {
	flag[0] = '!';
	int counter = 1;
	while (counter < 10) {
		flag[counter] = flag[counter-1] + counter + 1;
		counter++;
	}	
	return flag;
}
int main() {
	int asciiSum = 0;
	puts("enter the magic string");
	fgets(inputString, 64, stdin);
	if (strlen(inputString) >= 11) {
		puts("too long...sorry no flag for you!!!");
	} else {
		int counter = 0;
		while (counter < strlen(inputString)) {
			asciiSum += inputString[counter];
			counter++;
		}
		if (asciiSum == 1000) {
			strcat_str();
			printf(part1);
			int count = 0;
			while (count < 10) {
				putchar(flag[count]);
				count++;
			}
			puts(part2);
		} else {
			puts("wrong string\nNo flag for you.");
		}
	}
    return 0;
}