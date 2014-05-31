
#include <stdlib.h>
#include "raytracer.h"

void    fill_sphere_color(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nCOLOR  >");
  my_putstr(line);
  my_putstr("<  COLOR\n");
  if (obj->objs->ray = atof(line) <= 0)
    obj->objs->ray = 0xFFFFFF;
  printf("COLOR = %f\n", obj->objs->ray);
}
