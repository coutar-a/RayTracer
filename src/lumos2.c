/*
** lumos2.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:06:23 2014 grelli_t
** Last update Tue Jun  3 13:33:28 2014 coutar_a
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
  apply->r_spot = 0;
  apply->i = -1;
  apply->ret = 0;
  apply->g_spot = 0;
  apply->b_spot = 0;
}

int	checkering(t_objs *obj)
{
  int	p1;
  int	p2;
  int	p3;

  /* if (obj->checkering == NO) */
  /*   return (obj->color); */
  p1 = obj->intersection.p_x / 50;
  p2 = obj->intersection.p_y / 50;
  p3 = obj->intersection.p_z / 50;
  if (p3 % 2 == 0)
    {
      if ((p1 % 2 == 0 && p2 % 2 == 0) || (p1 % 2 != 0 && p2 % 2 != 0))
	return (0xFFFFFF);
      else
	return (obj->color);
    }
  else
    {
      if ((p1 % 2 == 0 && p2 % 2 == 0) || (p1 % 2 != 0 && p2 % 2 != 0))
	return (obj->color);
      else
	  return (0xFFFFFF);
    }
}

/*
** Assembles RGB components in an int. does the whole negative thing. Figure it out.
*/

int	light_assembler(t_apply *apply, t_objs *obj)
{
  //printf("negative = %d\n", obj->negative);
  if (obj->negative == YES)
    {
      apply->r = NEG((apply->r)) * (1 - obj->shine) + NEG((apply->r_spot)) * obj->shine;
      apply->g = NEG((apply->g)) * (1 - obj->shine) + NEG((apply->g_spot)) * obj->shine;
      apply->b = NEG((apply->b)) * (1 - obj->shine) + NEG((apply->b_spot)) * obj->shine;
    }
  else
    {
      apply->r = (apply->r) * (1 - obj->shine) + (apply->r_spot) * obj->shine;
      apply->g = (apply->g) * (1 - obj->shine) + (apply->g_spot) * obj->shine;
      apply->b = (apply->b) * (1 - obj->shine) + (apply->b_spot) * obj->shine;
    }
  apply->ret = apply->b | apply->g << 8 | apply->r << 16;
  return (apply->ret);
}

/*
** Divide this one into two functions : second one will take the struct and make an usable int, depending on the object's properties
*/

int		apply_light(t_params *params, t_objs *obj, double cos_a[])
{
  t_apply	apply;
  int		j;
  int		color;

  j = -1;
  incre_unsigned(&apply);
  while (++apply.i != params->nb_spots)
    {
      color = checkering(&obj[++j]);
      apply.r += (unsigned char)(((/* obj[++j].color */color >> 16) & 0xFF)
				 * cos_a[apply.i]) / params->nb_spots;
      apply.g += (unsigned char)(((/* obj[j].color */color >> 8) & 0xFF)
				 * cos_a[apply.i]) / params->nb_spots;
      apply.b += (unsigned char)((/* obj[j].color */color & 0xFF)
				 * cos_a[apply.i]) / params->nb_spots;
      apply.r_spot += (unsigned char)((params->spots[apply.i].color >>
						16 & 0xFF) * cos_a[apply.i])
	/ params->nb_spots;
      apply.g_spot += (unsigned char)((params->spots[apply.i].color
						>> 8 & 0xFF) * cos_a[apply.i]) /
        params->nb_spots;
      apply.b_spot += (unsigned char)((params->spots[apply.i].color &
						0xFF) * cos_a[apply.i]) /
        params->nb_spots;
    }
  return (light_assembler(&apply, obj));
}
