
#include <stdlib.h>
#include "raytracer.h"

int	fill_size_checkerboard(t_params *obj, char *line, int j)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((obj->objs[j].size_checkerboard = atof(line)) <= 0)
    obj->objs[j].size_checkerboard = 50;
  printf("SIZE_CHECKERBOARD == %d\n", obj->objs[j].size_checkerboard);
  return (0);
}
