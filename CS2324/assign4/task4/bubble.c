
#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

void swap(char s[NUM][LEN], int p1, int p2){
    char temp[strlen(s[p1])];
    strcpy(temp,s[p1]);
    strcpy(s[p1],s[p2]);
    strcpy(s[p2],temp);   
}
void print(char s[NUM][LEN]){
    for(int x = 0; x < 10;x++){
        printf("%s\n",s[x]);
    }
}
int main()
{
    char s[NUM][LEN];
    int swapped = 1;
    printf("Please enter %d strings, one per line:\n", NUM);
    int sc = 0;
    while(sc < NUM){
      char * st;
      scanf("%s",&*st);
      strcpy(s[sc],st);
      sc++;
    }
    puts("\nHere are the strings in the order you entered:");
    print(s);
    while(swapped != 0){
        swapped = 0;
        for(int x = 0; x < 9;x++){
            int max;
            if(strlen(s[x]) > strlen(s[x+1])){
                max = strlen(s[x]);
            }else{
                max = strlen(s[x+1]);
            }
            for(int y = 0; y < max;y++){
                int c = s[x][y];
                int d = s[x+1][y];
                if(c > d){ 
                    swapped++;
                    swap(s,x,x+1);
                    break;
                }else if(d > c){
                    break;
                }
            }
        }
    }
    puts("\nIn alphabetical order, the strings are:");  
    print(s);
    return 0;
}