#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int right = 0;

int ft_strlen(char *s)
{
  int i = 0;
  while(s[i])
    i++;
  return (i);
}

char *combiner(char *tab, char *src)
{
  int i = 0;
  printf("%s %s\n", tab, src);
  int tab_size = ft_strlen(tab) - 1;
  int src_size = ft_strlen(src) - 1;

  if (src_size > tab_size)
    return (src);
  else
  {
    printf("%c\n", tab[src_size]);
    while(tab[src_size])
    {
      tab[src_size] = src[i];
      i++;
      src_size++;
    }
  }
  return (tab);
}

int main(void) {
  char *tab = "01234";

  printf("%s\n", combiner(tab, "lol"));
  return 0;
}
