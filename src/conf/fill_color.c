
#include <stdlib.h>
#include "raytracer.h"

int	fill_color(t_params *obj, char *line, int j)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nCOLOR  >");
  my_putstr(line);
  my_putstr("<  COLOR\n");
  if ((obj->objs[j].ray = atof(line)) <= 0)
    obj->objs[j].ray = 0xFFFFFF;
  printf("COLOR = %f\n", obj->objs[j].ray);
}
