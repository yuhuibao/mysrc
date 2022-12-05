#include <stdio.h>
#include <ctype.h>

int atoi(char s[]){
    int n = 0;

    for(int i=0; s[i]>='0'&&s[i]<='9'; i++)
        n = 10 * n + s[i]-'0';
    return n;
}

int htoi(char s[]){
    int n = 0;
    int prefix[2];
    prefix[0] = s[0];
    prefix[1] = s[1];
    if(prefix[0]!='0'){
        printf("invalid input\n");
        return 1;
    }
    if(prefix[1] != 'x' && prefix[1] != 'X'){
        printf("invalid input\n");
        return 1;
    }
    if(prefix[1] == 'X'){
        for(int i = 0; s[i]; i++){
            s[i] = tolower(s[i]);
        }
    }
    for(int i=0;s[i];i++)
        printf("%c",s[i]);
    printf("\n");
    for(int i=2; s[i]>='0'&&s[i]<='9' || s[i]>='a'&&s[i]<='f'; i++){
        int digit;
        if(s[i]>='a'){
            digit = s[i]-'a'+10;
        }else{
            digit = s[i]-'0';
        }
        n = 16 * n + digit;
    }
    return n;
}

int main(){
    char s1[]={'1','6','\0'};
    char s2[]={'0','x','1','4','\0'};
    char s3[]={'0','X','F','F','\0'};
    printf("number calculated is %d\n", atoi(s1));
    printf("d-h number calculated is %d\n", htoi(s3));
    return 0;
}

