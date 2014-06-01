
#include <stdlib.h>
#include "raytracer.h"

int    fill_transparency(t_params *obj, char *line, int j)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nTRANSPARENCY    ");
  my_putstr(line);
  my_putstr("    TRANSPARENCY\n");
  if (obj->objs[j].transparency = atoi(line) <= 0)
    obj->objs[j].transparency = NO;
  printf("TRANSPARENCY = %f\n", obj->objs[j].transparency);
}
