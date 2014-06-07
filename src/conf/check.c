/*
** check.c for raytracer in /home/grelli_t/ABUZAY/conf_file/srcs
**
** Made by grelli_t
** Login   <grelli_t@epitech.net>
**
** Started on  Wed May 28 12:14:34 2014 grelli_t
** Last update Sat Jun  7 10:21:17 2014 grelli_t
** Last update Fri Jun  6 17:27:09 2014 cheval_2
*/

#include <stdlib.h>
#include <unistd.h>
#include "raytracer.h"

int	init_struct(t_params *params)
{
  if ((params->objs = malloc(sizeof(t_objs *))) == NULL)
    return (ERROR);
  if ((params->spots = malloc(sizeof(t_spots))) == NULL)
    return (ERROR);
  if ((params->mlx_conf = malloc(sizeof(t_dump))) == NULL)
    return (ERROR);
  return (0);
}

int		check_file(char **file, t_params *params)
{
  int		i;
  int		is_objs;

  if (init_struct(params) == ERROR)
    return (ERROR);
  is_objs = 0;
  i = -1;
  while (file[++i] != NULL)
    {
      if (file[i][0] == '#')
	continue ;
      if (is_objs == 0)
	if (my_strcmp(file[i], "WINDOW") == 0)
	  {
	    if ((is_objs = fill_window(params, file, &i)) == ERROR)
	      return (ERROR);
	  }
	else if (my_strcmp(file[i], "OBJECTS") == 0)
	  {
	    if ((is_objs = fill_objects(params, file, &i)) == ERROR)
	      return (ERROR);
	    --i;
	  }
	else if (my_strcmp(file[i], "SPOTS") == 0)
	  if ((is_objs = fill_spot(params, file, &i)) == ERROR)
	    return (ERROR);
    }
  return (0);
}
