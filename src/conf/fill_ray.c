
#include "raytracer.h"

int	fill_sphere_ray(t_params *obj, char *line)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nRAY  >");
  my_putstr(line);
  my_putstr("<  RAY\n");
  if (obj->objs->ray = atof(line) <= 0)
    obj->objs->ray = 75;
  printf("RAY = %f\n", obj->objs->ray);
}

int	fill_plan_ray(t_params *obj, char *line)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nRAY  >");
  my_putstr(line);
  my_putstr("<  RAY\n");
  if (obj->objs->ray = atof(line) <= 0)
    obj->objs->ray = 75;
  printf("RAY = %f\n", obj->objs->ray);
}

int	fill_cylinder_ray(t_params *obj, char *line)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nRAY  >");
  my_putstr(line);
  my_putstr("<  RAY\n");
  if (obj->objs->ray = atof(line) <= 0)
    obj->objs->ray = 75;
  printf("RAY = %f\n", obj->objs->ray);
}

int	fill_cone_ray(t_params *obj, char *line)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nRAY  >");
  my_putstr(line);
  my_putstr("<  RAY\n");
  if (obj->objs->ray = atof(line) <= 0)
    obj->objs->ray = 75;
  printf("RAY = %f\n", obj->objs->ray);
}
