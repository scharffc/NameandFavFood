#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#define MAX_BUF 1024


int main () {
  int letter_frequency[26] = {0};
  int len, i;
  char buf[MAX_BUF];
  len = strlen(buf);
  int c = 0;
  do {
    int y = 0;
    int ind = 0;
    if(buf[c]-65 < 26){
      ind = buf[c] - 65;
      y++;
    }else if(buf[c]-97 < 26){
      ind = buf[c] - 97;
      y++;
    }
    printf("%d \n",y);
    letter_frequency[ind] = letter_frequency[ind]+y;
    c++;
  } while (c < len);

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}



