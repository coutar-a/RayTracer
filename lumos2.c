/*
** lumos2.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:06:23 2014 grelli_t
** Last update Mon Apr 21 12:12:36 2014 grelli_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

/*
** Decomposes MLX color integer into RR GG BB, applies light coeff, then
** puts those back into an MLX-usable int. Powered by dark magics most foul.
*/

void	incre_unsigned(unsigned char *r, unsigned char *g, unsigned char *b,
		       unsigned char *t_spot)
{
  *r = 0;
  *g = 0;
  *b = 0;
  *t_spot = 0;
}

void	incre_unsi_int(unsigned char *g_spot, unsigned char *b_spot, int *i,
		       int *ret)
{
  *i = -1;
  *ret = 0;
  *g_spot = 0;
  *b_spot = 0;
}

int		apply_light(float *cos_a, t_sec *k, t_3d **spot)
{
  t_apply	apply;

  incre_unsigned(&apply.r, &apply.g, &apply.b, &apply.r_spot);
  incre_unsi_int(&apply.g_spot, &apply.b_spot, &apply.i, &apply.ret);
  while (++apply.i != NBR_LIGHTS)
    {
      apply.r += (unsigned char)(((k->color >> 16) & 0xFF) * cos_a[apply.i]) / NBR_LIGHTS;
      apply.g += (unsigned char)(((k->color >> 8) & 0xFF) * cos_a[apply.i]) / NBR_LIGHTS;
      apply.b += (unsigned char)((k->color & 0xFF) * cos_a[apply.i]) / NBR_LIGHTS;
      apply.r_spot += (unsigned char)((spot[apply.i]->color >> 16 & 0xFF) * cos_a[apply.i]) /
	NBR_LIGHTS;
      apply.g_spot += (unsigned char)((spot[apply.i]->color >> 8 & 0xFF) * cos_a[apply.i]) /
	NBR_LIGHTS;
      apply.b_spot += (unsigned char)((spot[apply.i]->color & 0xFF) * cos_a[apply.i]) /
	NBR_LIGHTS;
    }
  apply.r = (apply.r) * (1 - k->brill) + (apply.r_spot) * k->brill;
  apply.g = (apply.g) * (1 - k->brill) + (apply.g_spot) * k->brill;
  apply.b = (apply.b) * (1 - k->brill) + (apply.b_spot) * k->brill;
  apply.ret = apply.b | apply.g << 8 | apply.r << 16;
  return (apply.ret);
}

void    define_lights(t_3d **spots)
{
  spots[0] = malloc(sizeof(t_3d));
  define_spot1(spots[0]);
  spots[1] = malloc(sizeof(t_3d));
  define_spot2(spots[1]);
  spots[2] = malloc(sizeof(t_3d));
  define_spot3(spots[2]);
  spots[3] = malloc(sizeof(t_3d));
  define_spot3(spots[3]);
}
