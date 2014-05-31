
#include "raytracer.h"

void	fill_sphere_ray(t_params *obj, char *line)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n------------------");
  my_putstr(line);
  my_putstr("------------------\n");
  obj->objs->ray;//FINIR remplir sphere;
}
