
#include <stdlib.h>
#include "raytracer.h"

int    fill_transparency(t_params *obj, char *line, int j)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if (obj->objs[j].transparency = atoi(line) <= 0)
    obj->objs[j].transparency = NO;
  return (0);
}
