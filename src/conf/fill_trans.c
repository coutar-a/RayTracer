
#include <stdlib.h>
#include "raytracer.h"

int	fill_trans(t_params *obj, char *line, int j)
{
  int	c;
  char	**tab;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((tab = my_str_to_wordtab(line, ',')) == NULL)
    return (ERROR);
  obj->objs[j].trans[0] = atof(tab[0]);
  obj->objs[j].trans[1] = atof(tab[1]);
  obj->objs[j].trans[2] = atof(tab[2]);
  free_tab(tab);
  return (0);
}
