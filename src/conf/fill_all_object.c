
#include <stdlib.h>
#include "raytracer.h"

static const t_fill	g_object[] = {
  {"pos", &fill_pos},
  {"rot", &fill_rot},
  {"ray", &fill_ray},
  {"angle", &fill_angle},
  {"color", &fill_color},
  {"transparency", &fill_transparency},
  {"negative", &fill_negative},
  {"texture", &fill_texture},
  {"height", &fill_height},
  {"checkerboard", &fill_checkerboard},
  {"color_checkerboard", &fill_color_checkerboard},
  {"size_checkerboard", &fill_size_checkerboard},
  {NULL, NULL},
};

int	fill_object(t_params *obj, char **file, int *i, int k)
{
  char	**tab;
  int	j;
  int   c;

  j = -1;
  tab = NULL;
  while (file[*i] != NULL && file[*i][0] != '}')
    {
      if ((tab = my_str_to_wordtab(file[*i], '=')) == NULL)
	return (ERROR);
      while (g_object[++j].line != NULL)
	if (my_strcmp(g_object[j].line, tab[0]) == 0)
	  if (g_object[j].ptr(obj, tab[1], k) == ERROR)
	    return (ERROR);
      j = -1;
      ++(*i);
      free_tab(tab);
    }
  return (0);
}
