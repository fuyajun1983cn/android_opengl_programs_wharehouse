#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void solution()
{
  int array[256] = {0};
  int i, n;
  printf("Please input the size of the array: ");
  scanf("%d", &n);
  printf("n = %d\n", n);
  for (i = 0; i < n; i++) {
    int ch;
    scanf("%d", &ch);
    printf("ch = %d\n", ch);
    if (array[ch] == 1) {
      printf("duplicated element: %d\n", ch);
      return;
    } else
      array[ch] = 1;
  }


  printf("not found\n");
  
}

int main(int argc, char *argv[])
{
  solution();
  /*
  char str[99];
  int n;
  scanf("%s%n", str, &n);
  printf("%s\t%d\n", str, n); */
  return 0;
}

