/*
** fill_window.c for raytracer in /home/grelli_t/ABUZAY/conf_file/srcs
**
** Made by grelli_t
** Login   <grelli_t@epitech.net>
**
** Started on  Tue May 27 12:01:13 2014 grelli_t
** Last update Thu May 29 15:32:05 2014 grelli_t
*/

#include <stdlib.h>
#include "read.h"

int	fill_window_in_params_height(t_params *params, char *value)
{
  int	c;

  c = my_strlen(value) - 1;
  if (value[c] == ';')
    value[c] = '\0';
  if ((params->mlx_conf->win_y = atoi(value)) <= 0)
    params->mlx_conf->win_y = 1000;
  printf("%d\n", params->mlx_conf->win_y);
  return (0);
}

int	fill_window_in_params_lenght(t_params *params, char *value)
{
  int	c;

  c = my_strlen(value) - 1;
  if (value[c] == ';')
    value[c] = '\0';
  if ((params->mlx_conf->win_x = atoi(value)) <= 0)
    params->mlx_conf->win_x = 1000;
  printf("%d\n", params->mlx_conf->win_x);
  return (0);
}

int	fill_window_in_params_pos_eye(t_params *params, char *value)
{
  char	**pos_eye;
  int	c;

  pos_eye = NULL;
  if ((pos_eye = my_str_to_wordtab(value, ',')) == NULL)
    return (ERROR);
  c = my_strlen(pos_eye[2]) - 1;
  if (pos_eye[2][c] == ';')
    pos_eye[2][c] = '\0';
  if ((params->pos_eye[0] = atof(pos_eye[0])) <= 0)
    params->pos_eye[0] = -300.0;
  if ((params->pos_eye[1] = atof(pos_eye[1])) <= 0)
    params->pos_eye[1] = 0.0;
  if ((params->pos_eye[2] = atof(pos_eye[2])) <= 0)
    params->pos_eye[2] = 0.0;
  printf("%f, %f, %f\n", params->pos_eye[0], params->pos_eye[1], params->pos_eye[2]);
  free_tab(pos_eye);
  return (0);
}

int	fill_window_in_params(t_params *params, char **file, int *i)
{
  char	**tab;

  tab = NULL;
  tab = my_str_to_wordtab(file[*i], '=');
  if (my_strcmp(tab[0], "height") == 0)
    {
      if (fill_window_in_params_height(params, tab[1]) == ERROR)
	return (ERROR);
    }
  else if (my_strcmp(tab[0], "lenght") == 0)
    {
      if (fill_window_in_params_lenght(params, tab[1]) == ERROR)
	return (ERROR);
    }
  else if (my_strcmp(tab[0], "pos_eye") == 0)
    if (fill_window_in_params_pos_eye(params, tab[1]) == ERROR)
      return (ERROR);
  free_tab(tab);
  return (0);
}

int	fill_window(t_params *params, char **file, int *i)
{
  while (file[*i] != NULL)
    {
      if (my_strcmp(file[*i], "nb_objs") == 0)
	;
      if (file[*i][0] == '}')
	return (0);
      fill_window_in_params(params, file, i);
      ++(*i);
    }
  return (0);
}