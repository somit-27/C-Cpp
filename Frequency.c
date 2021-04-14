#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
    char str[26],ch,a_char;
    int freq[26],counter,len;
    for(counter=0;counter<26;counter++){
        freq[counter]=0;
    }
    scanf("%[^\n]s",str);
    len=strlen(str);
    for(counter=0;counter<len;counter++){
        ch=str[counter];
        if(isalpha(ch)){
            ch=tolower(ch);
            freq[ch-'a']++;
        }
    }
    a_char='a';
    for(counter=0;counter<26;counter++){
        if(freq[counter]!=0){
            printf("%c\t%d\n",a_char+counter,freq[counter]);
        }
    }
}
