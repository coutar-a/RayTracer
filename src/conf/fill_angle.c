
#include <stdlib.h>
#include "raytracer.h"

int	fill_angle(t_params *obj, char *line, int j)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\ANGLE   >");
  my_putstr(line);
  my_putstr("<   ANGLE\n");
  if ((obj->objs[j].angle = atof(line)) <= 0)
    obj->objs[j].angle = 0.0;
  printf("ANGLE = %f\n", obj->objs[j].angle);
}
