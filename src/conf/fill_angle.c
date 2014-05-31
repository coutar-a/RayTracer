
#include <stdlib.h>
#include "raytracer.h"

void    fill_sphere_angle(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\ANGLE   >");
  my_putstr(line);
  my_putstr("<   ANGLE\n");
  if ((obj->objs->angle = atof(line)) <= 0)
    obj->objs->angle = 0.0;
  printf("ANGLE = %f\n", obj->objs->angle);
}