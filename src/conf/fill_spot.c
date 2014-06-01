
#include <stdlib.h>
#include "raytracer.h"

static const t_fill	g_spot[] = {
  {"pos", &fill_spot_pos},
  {"color", &fill_spot_color},
  {NULL, NULL},
};

int		fill_spot(t_params *scene, char **file, int *i)
{
  char		**tab;
  int		p;
  int		j;

  p = -1;
  j = 0;
  while (file[*i] != NULL && file[*i][0] != '}')
    {
      while (file[*i][0] != '}')
	{
	  if ((tab = my_str_to_wordtab(file[*i], '=')) == NULL)
	    return (ERROR);
	  while (g_spot[++p].line != NULL)
	    if (my_strcmp(g_spot[p].line, tab[0]) == 0)
	      g_spot[p].ptr(scene, tab[1], j);
	  p = -1;
	  ++(*i);
	  free_tab(tab);
	}
      ++j;
      ++(*i);
    }
  return (0);
}

int	init_spots(t_params *scene, char **file, int *i)
{
  if ((scene->spots = malloc((scene->nb_spots * sizeof(t_spots)) +
			     1)) == NULL)
    return (ERROR);
  fill_spot(scene, file, i);
  return (0);
}
