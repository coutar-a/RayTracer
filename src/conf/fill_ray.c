
#include <stdlib.h>
#include "raytracer.h"

int	fill_ray(t_params *obj, char *line, int j)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((obj->objs[j].ray = atof(line)) <= 0)
    obj->objs[j].ray = 50.0;
  return (0);
}
