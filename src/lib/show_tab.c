
#include "raytracer.h"

int     show_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    {
      if (tab[i][0] != '#')
	{
	  my_putstr(tab[i]);
	  my_putstr("\n");
	}
    }
  return (0);
}
