
#include <stdlib.h>
#include <stdio.h>

static int     sizestr(char *str)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] != ' ')
        ++j;
      if (str[i] != ' ' && str[i + 1] == ' ')
        ++j;
      ++i;
    }
  return (j);
}

char	*epur(char *str)
{
  int	size = 0;
  char	*final;
  int	i;
  int	j;

  j = 0;
  i = -1;
  size = sizestr(str);
  if ((final = malloc((sizestr(str) + 1))) == NULL)
    return (NULL);
  while (str[++i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'));
  while (str[i])
    {
      while (str[i] && (str[i] == ' ') ||
	     (str[i] == '\t') || (str[i] == '\n' && str[i + 1] == '\n'))
	++i;
      final[j] = str[i];
      ++j;
      ++i;
    }
  if (final[j - 1] == ' ' || final[j - 1] == '\t')
    final[j - 1] = '\0';
  final[j] = '\0';
  return (final);
}
