/*
** lumos2.c for rtv1.h in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
**
** Made by coutar_a
** Login   <coutar_a@epitech.net>
**
** Started on  Tue Mar 11 10:02:35 2014 coutar_a
** Last update Mon Mar 31 17:34:14 2014 coutar_a
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

int			apply_light(float *cos_a, t_sec *k, t_3d **spot)
{
  unsigned char 	r;
  unsigned char 	g;
  unsigned char 	b;
  unsigned char 	r_spot;
  unsigned char 	g_spot;
  unsigned char 	b_spot;
  int			ret;
  int 			i;

  i = 0;
  r = 0;
  g = 0;
  b = 0;
  r_spot = 0;
  g_spot = 0;
  b_spot = 0;
  while (i != NBR_LIGHTS)
    {
      r += (unsigned char)(((k->color >> 16) & 0xFF) * cos_a[i]) / NBR_LIGHTS;
      g += (unsigned char)(((k->color >> 8) & 0xFF) * cos_a[i]) / NBR_LIGHTS;
      b += (unsigned char)((k->color & 0xFF) * cos_a[i]) / NBR_LIGHTS;
      r_spot += (unsigned char)((spot[i]->color >> 16 & 0xFF) * cos_a[i]) / NBR_LIGHTS;
      g_spot += (unsigned char)((spot[i]->color >> 8 & 0xFF) * cos_a[i]) / NBR_LIGHTS;
      b_spot += (unsigned char)((spot[i]->color & 0xFF) * cos_a[i]) / NBR_LIGHTS;
      i++;
    }
  //r = (r / NBR_LIGHTS) * (r_spot / NBR_LIGHTS) * k->brill;
  //g = (g / NBR_LIGHTS) * (g_spot / NBR_LIGHTS) * k->brill;
  //b = (b / NBR_LIGHTS) * (b_spot / NBR_LIGHTS) * k->brill;
  r = (r) * (1 - k->brill) + (r_spot) * k->brill;
  g = (g) * (1 - k->brill) + (g_spot) * k->brill;
  b = (b) * (1 - k->brill) + (b_spot) * k->brill;
  ret = b;
  ret = ret | g << 8;
  ret = ret | r << 16;
  return (ret);
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
  //spots[4] = malloc(sizeof(t_3d));
  //define_spot4(spots[4]);
}
