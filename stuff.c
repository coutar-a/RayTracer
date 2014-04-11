/*
** stuff.c for wolf3d in /home/coutar_a/Documents/I_graph/wolf3d
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat Jan 11 16:16:43 2014 coutar_a
** Last update Mon Mar 17 13:26:33 2014 coutar_a
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