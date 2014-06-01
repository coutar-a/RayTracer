#include <stdlib.h>
#include "raytracer.h"

int		fill_spot_pos(t_params *scene, char *line, int j)
{
  int		c;
  char		**tab;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((tab = str_to_word_tab(line, ',')) == NULL)
    return (ERROR);
  if (scene->spots[j].pos[0] = atof(tab[0]) <= 0)
    scene->spots[j].pos[0] = 50;
  if (scene->spots[j].pos[1] = atof(tab[1]) <= 0)
    scene->spots[j].pos[1] = 50;
  if (scene->spots[j].pos[2] = atof(tab[2]) <= 0)
    scene->spots[j].pos[2] = 50;
  return (0);
}

int    fill_spot_color(t_params *scene, char *line, int j)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if (scene->spots[j].color = atof(line) <= 0)
    scene->spots[j].color = 0xFFFFFF;
  return (0);
}
