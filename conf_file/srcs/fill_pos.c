
#include "raytracer.h"

void    fill_sphere_pos(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n------------------");
  my_putstr(line);
  my_putstr("------------------\n");
  if (obj->objs->pos[0] = atof(line) <= 0)
    obj->objs->pos = 50;
  printf("LOL<>LOL>LOL>LOL> = %f\n", obj->objs->ray);
}