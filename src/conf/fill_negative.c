
#include "raytracer.h"

int	fill_negative(t_params *obj, char *line, int j)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if (my_strcmp(line, "YES") == 0)
    {
      printf("PLS PLS PLS PLS\n");
      obj->objs[j].negative = YES;
    }
  else
    obj->objs[j].negative = NO;
  printf("NEGATIVITE NEGRO == %d\n", obj->objs[j].negative);
  return (0);
}
