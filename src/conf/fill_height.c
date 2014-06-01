
#include <stdlib.h>
#include "raytracer.h"

int	fill_height(t_params *params, char *line, int j)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((params->objs[j].height = atof(line)) <= 0)
    params->objs[j].height = 75;
  return (0);
}
