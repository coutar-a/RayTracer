/*
** init_list.c for rt in /home/cheval_2/git/raytracer/src/conf
**
** Made by cheval_2
** Login   <cheval_2@epitech.net>
**
** Started on  Fri Jun  6 18:37:31 2014 cheval_2
<<<<<<< HEAD
** Last update Sun Jun  8 15:17:46 2014 grelli_t
=======
** Last update Sun Jun  8 13:26:15 2014 cheval_2
>>>>>>> 8bc9c2bc5a72758d16c280cf2738223c75a50220
*/

#include "raytracer.h"

void		init_all_spots(t_params *params)
{
  int		c;

  c = -1;
  while (++c < params->nb_spots)
    {
      params->spots[c].pos[0] = 200;
      params->spots[c].pos[1] = 0;
      params->spots[c].pos[2] = 100;
      params->spots[c].rot[0] = 0;
      params->spots[c].rot[1] = 0;
      params->spots[c].rot[2] = 0;
      params->spots[c].angle = 0;
      params->spots[c].intensity = 1;
      params->spots[c].pos[0] = 200.0;
      params->spots[c].pos[1] = 0.0;
      params->spots[c].pos[2] = 100.0;
      params->spots[c].rot[0] = 0.0;
      params->spots[c].rot[1] = 0.0;
      params->spots[c].rot[2] = 0.0;
      params->spots[c].angle = 0.0;
      params->spots[c].intensity = 1.0;
      params->spots[c].color = 0xFFFFFF;
    }
}

void		init_objs(t_params *params)
{
  int		c;

  c = -1;
  while (++c < params->nb_objs)
    {
      params->objs[c].pos[0] = 500;
      params->objs[c].pos[1] = 0;
      params->objs[c].pos[2] = 200;
      params->objs[c].rot[0] = 0;
      params->objs[c].rot[1] = 0;
      params->objs[c].rot[2] = 0;
      params->objs[c].trans[0] = 0;
      params->objs[c].trans[1] = 0;
      params->objs[c].trans[2] = 0;
      params->objs[c].ray = 50.0;
      params->objs[c].angle = 0.0;
      params->objs[c].shine = 0.3;
      params->objs[c].color = 0x0000FF;
      params->objs[c].checkerboard = NO;
      params->objs[c].color_checkerboard = 0x0000FF;
      params->objs[c].size_checkerboard = 0;
      params->objs[c].negative = NO;
      params->objs[c].type = SPHERE;
    }
}
