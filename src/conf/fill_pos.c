
#include <stdlib.h>
#include "raytracer.h"

int	fill_sphere_pos(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nPOSPOSPOSPOSPOSPOSPOSPOSPOS     ");
  my_putstr(line);
  my_putstr("     POSPOSPOSPOSPOSPOSPOSPOSPOS\n");
  if (obj->objs->pos[0] = atof(line) <= 0)
    obj->objs->pos[0] = 50;
  printf("POS = %f\n", obj->objs->pos[0]);
}

int	fill_cylinder_pos(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nPOSPOSPOSPOSPOSPOSPOSPOSPOS     ");
  my_putstr(line);
  my_putstr("     POSPOSPOSPOSPOSPOSPOSPOSPOS\n");
  if (obj->objs->pos[0] = atof(line) <= 0)
    obj->objs->pos[0] = 50;
  printf("POS = %f\n", obj->objs->pos[0]);
}

int	fill_plan_pos(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nPOSPOSPOSPOSPOSPOSPOSPOSPOS     ");
  my_putstr(line);
  my_putstr("     POSPOSPOSPOSPOSPOSPOSPOSPOS\n");
  if (obj->objs->pos[0] = atof(line) <= 0)
    obj->objs->pos[0] = 50;
  printf("POS = %f\n", obj->objs->pos[0]);
}

int	fill_cone_pos(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\nPOSPOSPOSPOSPOSPOSPOSPOSPOS     ");
  my_putstr(line);
  my_putstr("     POSPOSPOSPOSPOSPOSPOSPOSPOS\n");
  if (obj->objs->pos[0] = atof(line) <= 0)
    obj->objs->pos[0] = 50;
  printf("POS = %f\n", obj->objs->pos[0]);
}
