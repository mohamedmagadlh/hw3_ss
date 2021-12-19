#include "functions.h"
#include <stdio.h>
#include<string.h>
#define WORD 30
# define TXT 1024
 
void main()
{   
char res [TXT]="";
char resC [TXT]="";
char atbsh[WORD]="";
char resAtbsh[TXT]="";
char txt[TXT]="";
char Word[WORD]="";
int i=-1;
do{
   i++;
   scanf("%c", &Word[i]);
}while ((Word[i]!=32)&&(Word[i]!='\t')&&(Word[i]!='\n'));
   int j=-1;
do{
    j++;
 scanf("%c", &txt[j]);
}while ((txt[j]!='~'));

  
    printf("Gematria Sequences: ");
    funcA(txt,Word,res);
    printf("%s\n",res);
    strcpy(atbsh,Word);
    AtbshWord(atbsh);
    printf("Atbash Sequences : ");
    funcB(txt,atbsh,resAtbsh);
    printf("\n%s",resAtbsh);
    printf("Anagram Sequences : ");
    funcC(txt,Word);
}



