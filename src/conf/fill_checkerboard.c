
#include <stdlib.h>
#include "raytracer.h"

int	fill_checkerboard(t_params *obj, char *line, int j)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if (my_strcmp(line, "YES") == 0)
    obj->objs[j].checkerboard = YES;
  else
    obj->objs[j].checkerboard = NO;
  return (0);
}
