/*
** stuff.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:09:19 2014 grelli_t
** Last update Mon Apr 21 10:09:20 2014 grelli_t
*/

#include <mlx.h>
#include "rtv1.h"

/*
** Sub-function of calc, calculates point 3d coords.
*/

void		sub_calc_pt(t_dump *ptr, t_3d *pt, int x, int y)
{
  pt->x = ptr->win_x;
  pt->y = (ptr->win_x / 2) - (x);
  pt->z = (ptr->win_y / 2) - (y);
}

/*
** Inits MLX image, stuffs it into dump struct (yay MLX).
*/

int		do_a_thing(t_dump *ptr)
{
  char		*data_ptr;
  int		sizeline;
  int		bpp;
  int		endian;

  data_ptr = mlx_get_data_addr(ptr->img_ptr, &bpp, &sizeline, &endian);
  ptr->img = data_ptr;
  ptr->sizeline = sizeline;
  ptr->bpp = bpp;
  ptr->endian = endian;
  return (0);
}
