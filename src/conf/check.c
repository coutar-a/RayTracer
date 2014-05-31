/*
** check.c for raytracer in /home/grelli_t/ABUZAY/conf_file/srcs
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Wed May 28 12:14:34 2014 grelli_t
** Last update Sat May 31 16:19:53 2014 grelli_t
*/

#include <stdlib.h>
#include <unistd.h>
#include "read.h"
#include "raytracer.h"

int	init_struct(t_params *params)
{
  if ((params->objs = malloc(sizeof(t_objs))) == NULL)
    return (ERROR);
  if ((params->spots = malloc(sizeof(t_spots))) == NULL)
    return (ERROR);
  if ((params->mlx_conf = malloc(sizeof(t_dump))) == NULL)
    return (ERROR);
  return (0);
}

int		check_file(char **file)//global tableau pointeur sur fonction.
{
  int		i;
  t_params	params;
  int		is_objs;

  if (init_struct(&params) == ERROR)
    return (ERROR);;
  is_objs = 0;
  i = -1;
  while (file[++i] != NULL)
    {
      if (file[i][0] == '#')
	continue ;
      if (is_objs == 0)
	{
	  my_putstr("\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
	  //my_putstr(file[i]);
	  //printf("\ni = %d\n", i);
	  if (my_strcmp(file[i], "WINDOW") == 0)
	    is_objs = fill_window(&params, file, &i);
	  else if (my_strcmp(file[i], "OBJECTS") == 0)
	    is_objs = fill_objects(&params, file, &i);
	  else if (my_strcmp(file[i], "SPOTS") == 0)
	    is_objs = fill_spots(&params, file, &i);
	}
    }
  return (0);
}
