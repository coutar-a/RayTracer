
#include <stdlib.h>
#include "raytracer.h"

int	fill_color(t_params *obj, char *line, int j)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((obj->objs[j].color = atof(line)) <= 0)
    obj->objs[j].color = 0x123451;
  return (0);
}
