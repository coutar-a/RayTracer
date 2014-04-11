/*
** pixel_put_to_image.c for wolf3d in /home/coutar_a/Documents/I_graph/tp_02
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Tue Jan  7 13:46:49 2014 coutar_a
** Last update Fri Apr 11 10:57:46 2014 coutar_a
*/

#include <mlx.h>
#include "rtv1.h"

/*
** Applies MLX unsigned-long color to the appropriate pixel.
*/

int		my_pixel_put_to_image(char *img, int x, int y, t_dump *ptr)
{
  int		pix;

  pix = ((x * (ptr->bpp / 8)) + (ptr->sizeline * y));
  img[pix] = ptr->color;
  img[pix + 1] = ptr->color >> 8;
  img[pix + 2] = ptr->color >> 16;
  return (0);
}
