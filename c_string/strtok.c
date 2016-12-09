
#include <stdio.h>
#include <string.h>

int main(void)
{
  int toknum = 0;
  char src[] = "Hello,, world!";
  const char delimiters[] = ", !";
  char *token = strtok(src, delimiters);
  printf("%d: [%s]\n", ++toknum, token);

  while((token = strtok(NULL, delimiters)) != NULL) {
    printf("%d: [%s]\n", ++toknum, token);
  }

  return 0;
}
