/*************************************************************************
	> File Name: 04.c
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年09月21日 星期一 23时21分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
replaceSpace (char *s)
{
  int n = strlen (s);
  int i, j = 0;
    printf("%d\n", n);
  for (i = 0; i < n; i++)
    {
      if (s[i] == ' ')
	{
	  j++;

	}

    }
printf("%d %d\n", n, j);
    printf("%s %p\n", s, s);
    char *t;
    t = malloc(sizeof(char) * (n + j * 2));
    for (i = 0, j = 0; i < n; i++, j++) {
        if (s[i] == ' ') {
            t[j] = '%';
            t[++j] = '2';
            t[++j] = '0';
            i++;
            j++;
        }
        t[j] = s[i];
    }
    printf("%s\n", t);
}

int main ()
{
  char *s = malloc(20);
  s = "we are happy";
  replaceSpace (s);
}
