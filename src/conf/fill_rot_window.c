/*
** fill_window.c for raytracer in /home/grelli_t/ABUZAY/conf_file/srcs
**
** Made by grelli_t
** Login   <grelli_t@epitech.net>
**
** Started on  Tue May 27 12:01:13 2014 grelli_t
** Last update Fri Jun  6 22:26:33 2014 grelli_t
*/

#include <stdlib.h>
#include "raytracer.h"

int	fill_window_in_params_rot_eye(t_params *params, char *value)
{
  char	**rot_eye;
  int	c;

  rot_eye = NULL;
  if ((rot_eye = my_str_to_wordtab(value, ',')) == NULL)
    return (ERROR);
  c = my_strlen(rot_eye[2]) - 1;
  if (rot_eye[2][c] == ';')
    rot_eye[2][c] = '\0';
  params->rot_eye[0] = atof(rot_eye[0]);
  params->rot_eye[1] = atof(rot_eye[1]);
  params->rot_eye[2] = atof(rot_eye[2]);
  free_tab(rot_eye);
  return (0);
}
