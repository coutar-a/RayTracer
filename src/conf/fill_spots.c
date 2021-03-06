#include <stdlib.h>
#include "raytracer.h"

int		fill_spot_pos(t_params *scene, char *line, int j)
{
  int		c;
  char		**tab;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((tab = my_str_to_wordtab(line, ',')) == NULL)
    return (ERROR);
  scene->spots[j].pos[0] = atof(tab[0]);
  scene->spots[j].pos[1] = atof(tab[1]);
  scene->spots[j].pos[2] = atof(tab[2]);
  return (0);
}

int		fill_spot_trans(t_params *scene, char *line, int j)
{
  int		c;
  char		**tab;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((tab = my_str_to_wordtab(line, ',')) == NULL)
    return (ERROR);
  scene->spots[j].trans[0] = atof(tab[0]);
  scene->spots[j].trans[1] = atof(tab[1]);
  scene->spots[j].trans[2] = atof(tab[2]);
  return (0);
}

int	fill_spot_color(t_params *scene, char *line, int j)
{
  int	c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  scene->spots[j].color = atof(line);
  return (0);
}

int	fill_intensity(t_params *params, char *line, int j)
{
  int   c;

  c = my_strlen(line) - 1;
  if (line[c] == ';')
    line[c] = '\0';
  if ((params->spots[j].intensity = atof(line)) > 10)
    params->spots[j].intensity= 7.0;
  return (0);
}
