#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
    char str[] = "";
    printf("Enter a string: \n");
    scanf("%s",str);
    char low[] = "abcdefghijklmnopqrstuvwxyz";
    char up[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char out[] = "";
    str[0] = *"T";
    printf("Before: %s \n",str);
    for(int x = 0; x <strlen(str); x++){
        char a = str[x];
        for(int y = 0; y <strlen(low)-1; y++){
            char b = low[y];
            if(a==b){
                str[x] = up[y];
            }
        }
    }
    printf("Now: %s \n",str);
    return 0;
}

