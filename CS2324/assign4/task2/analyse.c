#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    // int digit = -65536;
    // char *out = dTB(digit);
    // printf("The Binary Notation of %d is 0b",digit);
    // int spacecount = 0;
    // for(int x = 0; x < strlen(out);x++){
    //     char *ch = malloc(1);
    //     *ch = out[x];
    //     printf("%s",ch);
    //     spacecount++;
    // }
    char inp[] = "";
    printf("Enter a word \n");
    scanf("%s",&inp);
    char low[] = "abcdefghijklmnopqrstuvwxyz";
    char up[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char nums[] = "1234567890";
    int nl = 0;
    int nu = 0;
    int nn = 0;
    int nc = 0;
    int not = 0;
    for(int x = 0; x <strlen(inp); x++){
        bool is = false;
        char a = inp[x];
        for(int y = 0; y <strlen(low)-1; y++){
            char b = low[y];
            if(a==b){
                nl++;
                is = true;
            }
        }
        for(int y = 0; y <strlen(up)-1; y++){
            char b = up[y];
            if(a==b){
                nu++;
                is = true;
            }
        }
        for(int y = 0; y <strlen(nums)-1; y++){
            char b = nums[y];
            if(a==b){
                nn++;
                is = true;
            }
        }
        if(is == false){
            not++;
        }
    }
    printf("\t \tWord Stats \n");
    printf("Word: %s \n",inp);
    printf("Total Length: %d \n",strlen(inp));
    printf("Total Lowercases: %d \n",nl);
    printf("Total Uppercases: %d \n",nu);
    printf("Total Numbers: %d \n",nn);
    printf("Total Other Characters: %d \n",not);
    return 0;
}

