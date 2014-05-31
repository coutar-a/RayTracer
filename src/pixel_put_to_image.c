/*
** pixel_put_to_image.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:07:06 2014 grelli_t
** Last update Mon Apr 21 15:05:38 2014 grelli_t
*/

#include <mlx.h>
#include "raytracer.h"

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
