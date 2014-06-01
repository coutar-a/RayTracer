
#include <stdlib.h>
#include <stdio.h>
#include "raytracer.h"

int	fill_texture(t_params *obj, char *line, int j)
{
  int   c;

  printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>%d\n", j);
  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  my_putstr("\n------------------");
  my_putstr(line);
  my_putstr("------------------\n");
  if (my_strcmp(line, "YES") == 0)
    {
      my_putstr("+++++++++++++++++++++++++\n");
      obj->objs[j].negative = YES;
    }
  else
    obj->objs[j].negative = NO;
  printf("LOL<>LOL>LOL>LOL> = %d\n", obj->objs[0].texture);
}
