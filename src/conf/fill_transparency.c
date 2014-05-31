
#include <stdlib.h>
#include "raytracer.h"

void    fill_sphere_transparency(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nTRANSPARENCY    ");
  my_putstr(line);
  my_putstr("    TRANSPARENCY\n");
  if (obj->objs->transparency = atoi(line) <= 0)
    obj->objs->transparency = NO;
  printf("TRANSPARENCY = %f\n", obj->objs->transparency);
}