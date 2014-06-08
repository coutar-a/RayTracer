/*
** obj_rank.c for raytracer in /home/coutar_a/rendu/raytracer
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Wed Jun  4 16:49:16 2014 coutar_a
** Last update Sun Jun  8 10:17:50 2014 grelli_t
*/

#include <raytracer.h>

void	rank_objects(t_params *params)
{
  int	*value;
  int	count;
  int	i;

  i = -1;
  count = -1;
  if (!(value = malloc(sizeof) * (params->nb_objs)))
    return ;
  while (++i != params->nb_objs)
    {
      value[i] = sqrt(pow(params->objs[i]->pos[0] - params->pos_eye[0]) +
		      pow(params->objs[i]->pos[1] - params->pos_eye[1]) +
		      pow(params->objs[i]->pos[2] - params->pos_eye[2]));
    }
  i = -1;
  while (++count != params->nb_objs)
    {
      if (value[count] == ++i)
	{
	  params->objs[count]->rank = count;
	  ++count;
	  i = -1;
	}
    }
}
