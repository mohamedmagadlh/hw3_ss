#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define WORD 30
# define TXT 1024
int GematriaChar( char  ch){

        if (ch<='z'&& ch>='a'){
            return ch-96;;

        }
        if (ch<='Z'&&ch>='A'){
            return ch-64;
        }
        
    return 0;
}

 
int GematriaWord( char  Word[WORD]){
int g=0;
int i=0;
while(Word[i]!='\0')
{
        if (Word[i]<='z'&& Word[i]>='a'){
            g+=Word[i]-96;

        }
        if (Word[i]<='Z'&&Word[i]>='A'){
            g+=Word[i]-64;
        }
i++;
}
    
        
    return g;
}
void func (char txt[TXT],char res[TXT],int t,int i,int j)
{
    if(j!=0)
        res[j++]='~';
    for(int k=t;txt[k]!='\0'&&k<=i;k++)
    {
        
        res[j++]=txt[k];

    }
    
    res[++j]='\0';

}
void  funcA(char txt[TXT],char Word[WORD],char res[TXT])

{
    int i=0,t=0;
    int count=0,countInputWord=0;
    countInputWord=GematriaWord(Word);
    for(i=0;i<strlen(txt);i++)
    {
    if((txt[i]>='a' && txt[i]<='z') || (txt[i]>='A' && txt[i]<='Z')){
       if(count==0)t=i;
   
        count+=GematriaChar(txt[i]);
        if(count==countInputWord)
        {
            func(txt,res,t,i,strlen(res));
            count=0;
             i=t;

        }
        if(count>countInputWord)
        {
            count=0;
            i=t;
        }
    }
    }
    
}
char *AtbshWord(char str[TXT]){

for (int i = 0; i < strlen(str); i++) 
{
        if('a'<=str[i] && str[i]<='z'){
            str[i] = ('z'- str[i] + 'a');
        }
        
        if('A'<=str[i] && str[i]<='Z'){
            str[i] = ('Z'- str[i] + 'A');
        }
}
return str;
}
char *reverse(char Word[WORD])
{   int i;
    char *res=(char*)malloc(sizeof(char) * WORD);
    int finish=0;
    while (Word[finish] != '\0') finish++;
     for (i=0;i<finish;i++)res[i]=Word[finish-i-1];
    res[finish]='\0';
    return res;
}
void funcB(char txt[TXT],char Word[WORD]){
char *atbash=AtbshWord(Word);
char *reversed=reverse(atbash);
int j,k,i;
int res=0;
  for(i=0;i<strlen(txt)-1&&txt[i]!='\0';i++)
    {
        if(txt[i]==atbash[0]){
            char ab='a';
                k=0;
            for(j=i; txt[j]!='\0'&&atbash[k]!='\0'&&k>=0; j++)
                if((txt[j]>='a'&&txt[j]<='z')||(txt[j]>='A'&&txt[j]<='Z')){
                    if(txt[j]==atbash[k]){
                        ++k;
                        if(atbash[k]=='\0'){
                            ab='b';
                            k=-1;} 
                    }
                    else k=-1;}
            j--;
            if(ab!='a')
            {
                if(res)printf("~");
                  for(k=i;k<=j;k++)printf("%c",txt[k]);                
                res++;}
                          }
        else if(txt[i]==reversed[0])
        {   k=0;
            char ab='a';
            for (j=i;txt[j]!='\0'&&reversed[k]!='\0'&&k>=0;j++)
                if((txt[j]>='a'&&txt[j]<='z')||(txt[j]>='A'&&txt[j]<='Z'))
                {
                    if(txt[j]==reversed[k])
                    {k++;
                        if(reversed[k]=='\0')
                        {
                            ab='b';
                            k=-1;
                        }
                    }
                    else k=-1;
                }
            j--;
            if(ab!='a')
            {
                if(res) printf("~");
                for(k=i;k<=j;k++) printf("%c",txt[k]);
                res++;
            }
        }
    }
}
void funcC(char txt[TXT],char word[WORD])
{
    int res = 0;
    char abc ;
    int j , k , i;
    for(i = 0;i < strlen(txt)-1 && txt[i]!='\0' ; i++)
    {
        if (txt[i] != 32 && txt[i] !='\t' && txt[i] !='\n')
        {
            char newword[WORD];
             abc = 'b';
             j = i;
            strcpy(newword, word);
            while (txt[j] !='\0' && abc =='b')
            {
                if (txt[j] != 32 && txt[j] != '\t' && txt[j] != '\n')
                {
                    abc ='a';
                    k = 0;
                    while (newword[k] != '\0' && abc <='a'){
                        if (txt[j] == newword[k])
                        {
                            newword[k] *= -1;
                            abc ='b';
                        }k++;
                    }
                    if (abc =='b')
                    {
                        abc ='c';
                        for (k =0; newword[k] !='\0' && abc =='c'; k++)
                            if (newword[k] >0)
                                 abc ='b'; }
                                } j++;
                            }j--;
            if (abc =='c'){
                if (res) printf("~");
                        for ( k = i; k <= j; k++)
                        printf("%c", txt[k]);
                    res++;
            }
        }
    }
}
