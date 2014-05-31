
#include <stdlib.h>
#include "raytracer.h"

static const t_fill	g_objet[] = {
  {"pos", &fill_sphere_pos},
  {"ray", &fill_sphere_ray},
  {"angle", &fill_sphere_angle},
  {"color", &fill_sphere_color},
  {"transparency", &fill_sphere_transparency},
  {"negative", &fill_sphere_negative},
  {"texture", &fill_sphere_texture},
   {NULL, NULL},
};

int	fill_sphere(t_params *obj, char **file, int *i)
{
  char	**tab;
  int	j;
  int   c;

  obj->objs->type = SPHERE;
  j = -1;
  tab = NULL;
  if ((tab = my_str_to_wordtab(file[*i], '=')) == NULL)
    return (ERROR);
  while (file[*i] != NULL && file[*i][0] != '}')
    {
      if ((tab = my_str_to_wordtab(file[*i], '=')) == NULL)
	return (ERROR);
      /* my_putstr("================================"); */
      /* my_putstr(tab[0]); */
      /* my_putstr("================================"); */
      while (g_objet[++j].line != NULL)
	{
	  //printf("J = %d, LINE = %s\n", j, g_objet[j].line);
	  if (my_strcmp(g_objet[j].line, tab[0]) == 0)
	    {
	      //my_putstr("LOL>LOL>LOL>LOL>LOL>LOL>");
	      g_objet[j].ptr(obj, tab[1]);
	    }
	}
      j = -1;
      ++(*i);
      free_tab(tab);
    }
  return (0);
}
