/*
** my_str.c for minishell2 in /home/grelli_t/ABUZAY/minishell1
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Sun Mar  9 09:38:19 2014 grelli_t
** Last update Sat Apr 12 10:14:13 2014 grelli_t
*/

#include <unistd.h>
#include "read.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  if (str == NULL)
    return (-1);
  i = 0;
  while(str[i] != '\0')
    {
      my_putchar(str[i]);
      ++i;
    }
  return (1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    ++i;
  return (i);
}

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb < 9)
    nb = nb  / 10;
  my_putchar((nb % 10) + '0');
  return (nb);
}

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      ++i;
    }
}
