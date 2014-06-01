/*
** my_str.c for minishell2 in /home/grelli_t/ABUZAY/minishell1
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Sun Mar  9 09:38:19 2014 grelli_t
** Last update Sun Jun  1 15:33:57 2014 coutar_a
*/

#include <unistd.h>
#include "raytracer.h"

int	my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    return (-1);
  return (0);
}

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (-1);
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i]);
  return (i);
}

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      write(1, "-", 1);
    }
  if (nb > 9)
    my_put_nbr(nb  / 10);
  my_putchar((nb % 10) + '0');
}

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      write(1, "\n", 1);
      ++i;
    }
}
