/*
** init_list.c for rt in /home/cheval_2/git/raytracer/src/conf
**
** Made by cheval_2
** Login   <cheval_2@epitech.net>
**
** Started on  Fri Jun  6 18:37:31 2014 cheval_2
** Last update Fri Jun  6 18:51:21 2014 cheval_2
*/

#include "raytracer.h"

void		init_spot(t_params *params)
{
  int		c;

  c = 0;
  while (c < params->nb_spots)
    {
      params->spots[c]->pos[0] = 0;
      params->spots[c]->pos[1] = 0;
      params->spots[c]->pos[2] = 0;
      params->spots[c]->rot[0] = 0;
      params->spots[c]->rot[1] = 0;
      params->spots[c]->rot[2] = 0;
      params->spots[c]->angle = 0;
      params->spots[c]->color = 0xFFFFFF;
      ++c;
    }
}

void		init_objs(t_params *params)
{
  int		c;

  c = 0;
  while (c < params->nb_objs)
    {
      params->objs[c]->pos[0] = 0;
      params->objs[c]->pos[1] = 0;
      params->objs[c]->pos[2] = 0;
      params->objs[c]->rot[0] = 0;
      params->objs[c]->rot[1] = 0;
      params->objs[c]->rot[2] = 0;
      params->objs[c]->ray = 0;
      params->objs[c]->angle = 0;
      params->objs[c]->height = 0;
      params->objs[c]->shine = 0;
      params->objs[c]->color = 0xFF0000;
      params->objs[c]->checkerboard = NO;
      params->objs[c]->color_checkerboard = 0xFFFFFF;
      params->objs[c]->size_checkerboard = 0;
      params->objs[c]->negative = NO;
      params->objs[c]->type = SPHERE;
      ++c;
    }
}