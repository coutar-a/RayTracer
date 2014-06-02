
#include <stdlib.h>
#include "raytracer.h"

int	init_spots(t_params *params, char *file, int i)
{
  int	c;

  c = 0;
  c = my_strlen(file) - 1;
  if (file[c] == ';')
    file[c] = '\0';
  if ((params->nb_spots = atoi(file)) <= 0)
    params->nb_spots = 10;
  if ((params->spots = malloc((params->nb_spots * sizeof(t_spots)) +
			      1)) == NULL)
    return (ERROR);
  return (0);
}

static const t_fill	g_spot[] = {
  {"pos", &fill_spot_pos},
  {"color", &fill_spot_color},
  {"nb_spots", &init_spots},
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
      while (file[*i] != NULL && file[*i][0] != '}')
	{
	  if ((tab = my_str_to_wordtab(file[*i], '=')) == NULL)
	    return (ERROR);
	  show_tab(tab);
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
