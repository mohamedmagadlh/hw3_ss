#include <stdio.h>
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
    int i=0,j=0,t=0;
    int count=0,countInputWord=0;
    countInputWord=GematriaWord(Word);
    for(i=0;i<strlen(txt);i++)
    {
    if(txt[i]>='a' && txt[i]<='z' || txt[i]>='A' && txt[i]<='Z'){
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
void *AtbshWord(char str[TXT]){

for (int i = 0; i < strlen(str); i++) 
{
        if('a'<=str[i] && str[i]<='z'){
            str[i] = ('z'- str[i] + 'a');
        }
        
        if('A'<=str[i] && str[i]<='Z'){
            str[i] = ('Z'- str[i] + 'A');
        }
}


}

void reverce(char word[WORD],char rev[WORD])
{

    int i,j=0;
    for(i=strlen(word)-1;i>=0;i--)
    {
        rev[j++]=word[i];
    }
    rev[j]='\0';
}
void funcB(char txt[TXT],char atbshWord[WORD],char res[TXT])
{
    int i,j=0,k;
    char rev[WORD]="";

     reverce(atbshWord,rev);
    
       for(i=0;i<strlen(txt);i++)
       {
           if(txt[i]==atbshWord[0])
           {    k=i;
                j=1;
               while ((txt[k]==atbshWord[j]&& j<strlen(atbshWord)-1)||txt[k]==32)
               {
                   if(txt[k]==32)
                   {
                       k++;
                       continue;
                   }
                   res[j]=txt[k];
                  j++;
                  k++;
               }
               res[j]='~';
           }
            if(txt[i]==rev[0])
           {
                k=i;
                j=1;
               while ((txt[k]==rev[j]&& j<strlen(rev)-1)||txt[k]==32)
               {
                   if(txt[k]==32)
                   {
                       k++;
                       continue;
                   }
                   res[j]=txt[k];
                  j++;
                  k++;
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
                                } ++j;
                            }--j;
            if (abc =='c'){
                if (res) printf("~");
                        for ( k = i; k <= j; k++)
                        printf("%c", txt[k]);
                    ++res;
            }
        }
    }
}