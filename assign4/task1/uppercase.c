#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char str[1024];
	printf("Enter a string: \n");
	scanf("%s", str);
	int size = (int)strlen(str);
	printf("Before: %s \n", str);
	for (int x = 0; x < size - 1; x++) {
		char a = str[x];
		int r = a;
		if (r > 96 && r < 123) {
			str[x] = str[x] - 32;
		}
		// printf("%c : %d \n",a,r);
	}
	printf("Now: %s \n", str);
	return 0;
}
