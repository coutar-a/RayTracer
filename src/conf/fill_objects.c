/*
** fill_object.c for raytracer in /home/grelli_t/ABUZAY/conf_file/srcs
**
** Made by grelli_t
** Login   <grelli_t@epitech.net>
**
** Started on  Tue May 27 11:50:51 2014 grelli_t
<<<<<<< HEAD
** Last update Sun Jun  8 11:15:25 2014 grelli_t
=======
** Last update Sun Jun  8 14:23:12 2014 jamme-_c
>>>>>>> 8bc9c2bc5a72758d16c280cf2738223c75a50220
*/

#include <stdlib.h>
#include "raytracer.h"

int	fill_objects_in_params(t_params *params, char **file, int *i)
{
  if (my_strcmp(file[0], "pos") == 0)
    {
      if (fill_window_in_params_height(params, file[1]) == ERROR)
        return (ERROR);
    }
  else if (my_strcmp(file[0], "lenght") == 0)
    {
      if (fill_window_in_params_lenght(params, file[1]) == ERROR)
        return (ERROR);
    }
  else if (my_strcmp(file[0], "pos_eye") == 0)
    if (fill_window_in_params_pos_eye(params, file[1]) == ERROR)
      return (ERROR);
  return (0);
}

int		fill_diffrent_object(t_params *params, char **file, int *i,
				     int flag)
{
  static int	j = 0;

  if (j >= params->nb_objs)
    return (ERROR);
  if (flag == 1)
    params->objs[j].type = SPHERE;
  else if (flag == 2)
    params->objs[j].type = CONE;
  else if (flag == 3)
    params->objs[j].type = 4;
  else if (flag == 4)
    params->objs[j].type = PLAN;
  if (fill_object(params, file, i, j) == ERROR)
    return (ERROR);
  ++j;
  return (0);
}

t_params	*fill_nb_objs(t_params *params, char *file)
{
  char		**tab;
  int		c;
  static int	j;

  c = 0;
  tab = NULL;
  if ((tab = my_str_to_wordtab(file, '=')) == NULL)
    return (NULL);
  c = my_strlen(tab[1]) - 1;
  if (tab[1][c] == ';')
    tab[1][c] = '\0';
  if ((params->nb_objs = atoi(tab[1])) <= 0)
    params->nb_objs = 10;
  if ((params->objs = malloc((params->nb_objs + 1) * sizeof(t_objs))) == NULL)
    return (NULL);
  free_tab(tab);
  init_all_spots(params);
  init_objs(params);
  printf("XDTYGVBUHGVYIBUHIJNBUHJN\n");
  return (params);
}

int	kind_of_objects(t_params *params, char **file, int *i)
{
  char	**tab;

  tab = NULL;
  while (file[*i] != NULL && file[*i][0] != '}')
    {
      if ((tab = my_str_to_wordtab(file[*i], '=')) == NULL)
	return (ERROR);
      if (my_strcmp(tab[0], "nb_objs") == 0)
	{
	  if ((params = fill_nb_objs(params, file[*i])) == NULL)
	    return (ERROR);
	}
      else if (my_strcmp(file[*i], "sphere") == 0)
	fill_diffrent_object(params, file, i, 1);
      else if (my_strcmp(file[*i], "cone") == 0)
	  fill_diffrent_object(params, file, i, 2);
      else if (my_strcmp(file[*i], "cylinder") == 0)
	  fill_diffrent_object(params, file, i, 3);
      else if (my_strcmp(file[*i], "plan") == 0)
	  fill_diffrent_object(params, file, i, 4);
      ++(*i);
      free_tab(tab);
    }
  return (SUCCESS);
}

int     fill_objects(t_params *params, char **file, int *i)
{
   while (file[*i] != NULL)
    {
      kind_of_objects(params, file, i);
      if (file[*i][0] == '}')
	{
	  ++(*i);
	  return (0);
	}
      ++(*i);
    }
  return (0);
}
