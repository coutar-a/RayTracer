
#include <stdlib.h>
#include "raytracer.h"

int	fill_pos(t_params *obj, char *line, int j)
{
  int   c;
  char	**tab;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((tab = my_str_to_wordtab(line, ',')) == NULL)
    return (ERROR);
  my_putstr("\nPOSPOSPOSPOSPOSPOSPOSPOSPOS     >");
  my_putstr(line);
  my_putstr("<     POSPOSPOSPOSPOSPOSPOSPOSPOS\n");
  if ((obj->objs[j].pos[0] = atof(tab[0])) <= 0)
    obj->objs[j].pos[0] = 50;
  if ((obj->objs[j].pos[1] = atof(tab[1])) <= 0)
    obj->objs[j].pos[1] = 50;
  if ((obj->objs[j].pos[2] = atof(tab[2])) <= 0)
    obj->objs[j].pos[2] = 50;
  printf("POS1 = %f, POS2 = %f, POS3 = %f\n", obj->objs[j].pos[0], obj->objs[j].pos[1], obj->objs[j].pos[2]);
}
