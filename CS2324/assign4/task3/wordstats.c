#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#define MAX_BUF 1024


int main () {
  int letter_frequency[26] = {0};
  int len, i;
  char buf[MAX_BUF] = "aaaaaaa";
  len = strlen(buf);
  int c = 0;
  do {
    if(buf[c] > 90){
        buf[c] = buf[c] - 32;
    }
    int d = buf[c] - 65;
    letter_frequency[d] = letter_frequency[d] + 1;
    c++;
  } while (c < len);

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}



