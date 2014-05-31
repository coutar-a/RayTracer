/*
** epur_str.c for mysh in /home/lancel_e/rendu/PSU_2013_minishell2
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sat Mar  8 17:59:43 2014 lancel_e
** Last update Wed May 28 15:56:40 2014 grelli_t
*/

#include <stdlib.h>
#include <unistd.h>
#include "read.h"

void	ini_var(int *i, int *k)
{
  *i = 0;
  *k = 0;
}

void	first_space(char *str, int *i)
{
  while (str[*i] == ' ' && str[*i])
    *i = *i + 1;
}

char	*epur(char *str)
{
  char  *ret;
  int   i;
  int   k;

  ini_var(&i, &k);
  ret = malloc(my_strlen(str) + 1);
  first_space(str, &i);
  while (str[i])
    {
      if (str[i] != ' ')
        {
          ret[k] = str[i];
          k = k + 1;
        }
      else if (str[i + 1] != '\0' && str[i] == ' ' && str[i + 1] != ' ')
        {
          ret[k] = ' ';
          k = k + 1;
        }
      i = i + 1;
    }
  ret[k] = '\0';
  return (ret);
}
