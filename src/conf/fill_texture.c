
#include <stdlib.h>
#include "raytracer.h"

void	fill_sphere_texture(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n------------------");
  my_putstr(line);
  my_putstr("------------------\n");
  if (obj->objs->texture = atof(line) <= 0)
    obj->objs->texture = 50;
  printf("LOL<>LOL>LOL>LOL> = %f\n", obj->objs->texture);
}

void	fill_plan_texture(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n------------------");
  my_putstr(line);
  my_putstr("------------------\n");
  if (obj->objs->texture = atof(line) <= 0)
    obj->objs->texture = 50;
  printf("LOL<>LOL>LOL>LOL> = %f\n", obj->objs->texture);
}

void	fill_cylinder_texture(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n------------------");
  my_putstr(line);
  my_putstr("------------------\n");
  if (obj->objs->texture = atof(line) <= 0)
    obj->objs->texture = 50;
  printf("LOL<>LOL>LOL>LOL> = %f\n", obj->objs->texture);
}

void	fill_cone_texture(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n------------------");
  my_putstr(line);
  my_putstr("------------------\n");
  if (obj->objs->texture = atof(line) <= 0)
    obj->objs->texture = 50;
  printf("LOL<>LOL>LOL>LOL> = %f\n", obj->objs->texture);
}
