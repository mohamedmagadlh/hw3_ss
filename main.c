#include "functions.h"
#include <stdio.h>
#include<string.h>
#define WORD 30
# define TXT 1024

int main(){  

char res [TXT]="";
char txt[TXT]="";
char Word[WORD]="";
int i=-1;
	scanf("%s", Word); 		
	char c;
	do{				
		scanf("%c", &c);
		if(c == '~'){			
			txt[i] = '\0';
			break;
		}
		txt[i] = c;		
		i++;
	} while(i <= TXT); 		
	
    getchar();
    printf("Gematria Sequences: ");
    funcA(txt,Word,res);
    printf("%s\n",res);
    printf("Atbash Sequences : ");
    funcB(txt,Word);
	printf("\n");
    printf("Anagram Sequences : ");
    funcC(txt,Word);
	printf("\n");
    return 0;
}
