/*
** fill_object.c for raytracer in /home/grelli_t/ABUZAY/conf_file/srcs
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Tue May 27 11:50:51 2014 grelli_t
** Last update Sat May 31 16:44:51 2014 grelli_t
*/

#include <stdlib.h>
#include "read.h"

int     fill_objects_in_params(t_params *params, char **file, int *i)
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

int		fill_diffrent_object(t_params *params, char **file, int *i)
{
  t_params	*obj;

  /* if ((obj = malloc(sizeof(t_params))) == NULL) */
  /*   return (ERROR); */
  /* if ((obj->objs = malloc((params->nb_objs * sizeof(t_objs)) + 1)) == NULL) */
  /*   return (ERROR); */
  printf("%d\n", (params->nb_objs + 1));
  fill_sphere(params, file, i);
  return (0);
}

t_params	*fill_nb_objs(t_params *params, char *file, int flag)
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
    params->nb_objs = 1;
  if ((params->objs = malloc((params->nb_objs * sizeof(t_objs)) + 1)) == NULL)
    return (NULL);
  free_tab(tab);
  return (params);
}

int	kind_of_objects(t_params *params, char **file, int *i)
{
  char	**tab;

  tab = NULL;
  while (file[*i] != NULL)
    {
      if ((tab = my_str_to_wordtab(file[*i], '=')) == NULL)
	return (ERROR);
      printf("i = %d, LINE = %s\n", *i, file[*i]);
      //printf("TAB[0] = %s\n", tab[0]);
      if (my_strcmp(tab[0], "nb_objs") == 0)
	{
	  my_putstr("NB_OBJS\n");
	  if ((params = fill_nb_objs(params, file[*i])) == NULL)
	    return (ERROR);
	}
      else if (my_strcmp(file[*i], "sphere") == 0)
	{
	  my_putstr("SPHERE\n");
	  fill_sphere(params, file, i);
	}
      else if (my_strcmp(file[*i], "cone") == 0)
	{
	  my_putstr("CONE\n");
	  fill_diffrent_object(params, file, i);
	}
      else if (my_strcmp(file[*i], "cylinder") == 0)
	{
	  my_putstr("CYLINDER\n");
	  fill_diffrent_object(params, file, i);
	}
      if (file[*i][0] == '}')
        {
          //++(*i);
	  //++(*i);
	  free_tab(tab);
          return (SUCCESS);
        }
      ++(*i);
    }
  return (SUCCESS);
}

int     fill_objects(t_params *params, char **file, int *i)
{
  while (file[*i] != NULL)//trier et c'est fini !!!
    {
      printf("i = %d, LINE = %s\n", *i, file[*i]);
      if (file[*i][0] == '}')
	{
	  ++(*i);
	  return (0);
	}
      kind_of_objects(params, file, i);
      ++(*i);
    }
  return (0);
}
