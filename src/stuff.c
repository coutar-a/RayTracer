/*
** stuff.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:09:19 2014 grelli_t
** Last update Sun Jun  1 15:29:20 2014 coutar_a
*/

#include <mlx.h>
#include "raytracer.h"

/*
** Sub-function of calc, calculates point 3d coords.
*/

void		sub_calc_pt(t_params *params, t_3d *pt, int x, int y)
{
  pt->x = params->mlx_conf->win_x;
  pt->y = (params->mlx_conf->win_x / 2) - (x);
  pt->z = (params->mlx_conf->win_y / 2) - (y);
}

/*
** Inits MLX image, stuffs it into dump struct (yay MLX).
*/

void		init_img(t_dump *ptr)
{
  int		sizeline;
  int		bpp;
  int		endian;

  ptr->img = mlx_get_data_addr(ptr->img_ptr, &bpp, &sizeline, &endian);
  ptr->sizeline = sizeline;
  ptr->bpp = bpp;
  ptr->endian = endian;
}
