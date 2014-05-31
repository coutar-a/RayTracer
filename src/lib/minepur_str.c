/*
** cleanstr.c for minishell2 in /home/grelli_t/ABUZAY/minishell1
**
** Made by grelli_t
** Login   <grelli_t@epitech.net>
**
** Started on  Sun Mar  9 09:32:48 2014 grelli_t
** Last update Sat Apr 12 10:29:58 2014 grelli_t
*/

#include <stdlib.h>
#include <unistd.h>
#include "read.h"

int	sizestr(char *str, char sep)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] != sep)
	++j;
      if (str[i] != sep && str[i + 1] == sep)
	++j;
      ++i;
    }
  return (j);
}

void	clear_space(char *final)
{
  int	i;

  i = 0;
  while (final[i])
    {
      if (final[i] == '\n')
	final[i]  ='\0';
      ++i;
    }
}

char	*minepur_str(char *str, char sep)
{
  int	i;
  int	j;
  char	*final;

  i = 0;
  j = 0;
  i = sizestr(str, sep);
  if((final = malloc(i + 2)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] == sep && str[i])
    ++i;
  while (str[i])
    {
      while (str[i] == sep && str[i + 1] == sep && str[i])
	++i;
      final[j] = str[i];
      ++j;
      ++i;
    }
  clear_space(final);
  if (final[sizestr(str, sep) - 1] == sep)
    final[sizestr(str, sep) - 1] = '\0';
  return (final);
}
