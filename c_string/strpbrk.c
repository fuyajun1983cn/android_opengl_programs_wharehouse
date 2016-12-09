#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *result = strpbrk("This is a test", "a");
  if (result != NULL)
    printf("result = %s\n", result);
  return 0;
}
