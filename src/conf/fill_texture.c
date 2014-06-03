
#include <stdlib.h>
#include "raytracer.h"

int	fill_texture(t_params *obj, char *line, int j)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if (my_strcmp(line, "YES") == 0)
    obj->objs[j].texture = YES;
  else
    obj->objs[j].texture = NO;
  return (0);
}
