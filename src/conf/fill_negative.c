
#include "raytracer.h"

int	fill_sphere_negative(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n\\\\\\\\\\\\\\\\\\");
  my_putstr(line);
  my_putstr("\\\\\\\\\\\\\\\\\\\n");
  if (my_strcmp(line, "YES") == 0)
    obj->objs->negative = YES;
  else
    obj->objs->negative = NO;
  printf("NEGATIVE = %d\n", obj->objs->negative);
}

int	fill_cone_negative(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n\\\\\\\\\\\\\\\\\\");
  my_putstr(line);
  my_putstr("\\\\\\\\\\\\\\\\\\\n");
  if (my_strcmp(line, "YES") == 0)
    obj->objs->negative = YES;
  else
    obj->objs->negative = NO;
  printf("NEGATIVE = %d\n", obj->objs->negative);
}

int	fill_cylinder_negative(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n\\\\\\\\\\\\\\\\\\");
  my_putstr(line);
  my_putstr("\\\\\\\\\\\\\\\\\\\n");
  if (my_strcmp(line, "YES") == 0)
    obj->objs->negative = YES;
  else
    obj->objs->negative = NO;
  printf("NEGATIVE = %d\n", obj->objs->negative);
}

int	fill_cone_negative(t_params *obj, char *line)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n\\\\\\\\\\\\\\\\\\");
  my_putstr(line);
  my_putstr("\\\\\\\\\\\\\\\\\\\n");
  if (my_strcmp(line, "YES") == 0)
    obj->objs->negative = YES;
  else
    obj->objs->negative = NO;
  printf("NEGATIVE = %d\n", obj->objs->negative);
}
