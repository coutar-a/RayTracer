
#include "raytracer.h"

int	fill_shine(t_params *obj, char *line, int j)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if (my_strcmp(line, "YES") == 0)
    {
      printf("PLS PLS PLS PLS\n");
      obj->objs[j].shine = YES;
    }
  else
    obj->objs[j].shine = NO;
  printf("NEGATIVITE NEGRO == %d\n", obj->objs[j].shine);
  return (0);
}
