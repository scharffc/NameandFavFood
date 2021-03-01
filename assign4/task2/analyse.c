#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int categorize(char c){
  //0=lower,1=upper,2=number,3=other
  bool up = c > 64 && c < 91;
  bool low = c > 96 && c < 123;
  bool num = c > 47 && c < 60;
  bool other = (low == false && up == false && num == false) && c > 32 && c < 127;
  if(low){
    return 0;
  }else if(up){
    return 1;
  }else if(num){
    return 2;
  }else if(other){
    return 3;
  }else{
    return 4;
  }
}
int main() {
    char inp[1024];
    printf("Enter a word \n");
    scanf("%[^\n]",&inp);
    int nl = 0;
    int nu = 0;
    int nn = 0;
    int nc = 0;
    int not = 0;
    for(int x = 0; x <strlen(inp); x++){
      int a = categorize(inp[x]);
      if(a==0){
        nl++;
      }else if(a==1){
        nu++;
      }else if(a==2){
        nn++;
      }else if(a==3){
        nc++;
      }else if(a==4){
        not++;
      }
    }
    printf("\t \tWord Stats \n");
    printf("Word: %s \n",inp);
    printf("Total Length: %d \n",strlen(inp));
    printf("Total Lowercases: %d \n",nl);
    printf("Total Uppercases: %d \n",nu);
    printf("Total Numbers: %d \n",nn);
    printf("Total Other Characters: %d \n",not+nc);
    return 0;
}

