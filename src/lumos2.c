/*
** lumos2.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:06:23 2014 grelli_t
** Last update Sat May 31 17:08:19 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

/*
** Decomposes MLX color integer into RR GG BB, applies light coeff, then
** puts those back into an MLX-usable int. Powered by dark magics most foul.
*/

void	incre_unsigned(t_apply *apply)
{
  apply->r = 0;
  apply->g = 0;
  apply->b = 0;
  apply->t_spot = 0;
  apply->i = -1;
  apply->ret = 0;
  apply->g_spot = 0;
  apply->b_spot = 0;
}

int		apply_light(t_params *params, t_objs *obj, double cos_a[])
{
  t_apply	apply;

  incre_unsigned(&apply);
  while (++apply.i != params->nb_spots)
    {
      apply.r += (unsigned char)(((obj->intersection.color >> 16) & 0xFF)
				 * cos_a[apply.i]) / params->nb_spots;
      apply.g += (unsigned char)(((obj->intersection.color >> 8) & 0xFF)
				 * cos_a[apply.i]) / params->nb_spots;
      apply.b += (unsigned char)((obj->intersection.color & 0xFF)
				 * cos_a[apply.i]) / params->nb_spots;
      apply.r_params->spots += (unsigned char)((params->spots[apply.i]->color >>
						16 & 0xFF) * cos_a[apply.i])
	/ params->nb_spots;
      apply.g_params->spots += (unsigned char)((params->spots[apply.i]->color
						>> 8 & 0xFF) * cos_a[apply.i]) /
        params->nb_spots;
      apply.b_params->spots += (unsigned char)((params->spots[apply.i]->color &
						0xFF) * cos_a[apply.i]) /
        params->nb_spots;
    }
  apply.r = (apply.r) * (1 - obj->shine) + (apply.r_params->spots) * obj->shine;
  apply.g = (apply.g) * (1 - obj->shine) + (apply.g_params->spots) * obj->shine;
  apply.b = (apply.b) * (1 - obj->shine) + (apply.b_params->spots) * obj->shine;
  apply.ret = apply.b | apply.g << 8 | apply.r << 16;
  return (apply.ret);
}
