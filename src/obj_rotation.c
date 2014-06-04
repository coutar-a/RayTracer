/*
** rotation3.c for raytracer in /home/coutar_a/Projets/Bukkit/MUL_2013_rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Mon Apr 21 14:58:41 2014 coutar_a
** Last update Wed Jun  4 14:31:27 2014 coutar_a
*/

#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

void	trans_k(double *x, double *y, double *z, double m[3][3])
{
  double	x_swap;
  double	y_swap;
  double	z_swap;

  x_swap = (*x);
  y_swap = (*y);
  z_swap = (*z);
  (*x) = x_swap * m[0][0] + y_swap * m[0][1] + z_swap * m[0][2];
  (*y) = x_swap * m[1][0] + y_swap * m[1][1] + z_swap * m[1][2];
  (*z) = x_swap * m[2][0] + y_swap * m[2][1] + z_swap * m[2][2];
}

void	apply_rotations(t_obj *obj)
{
  double	trans[3][3];

  matrix_rot_x(trans, obj->angle_x);
  trans_k(&(obj->pos[0]), &(obj->pos[1]), &(obj->pos[2]), trans);
  matrix_rot_y(trans, obj->angle_y);
  trans_k(&(obj->pos[0]), &(obj->pos[1]), &(obj->pos[2]), trans);
  matrix_rot_z(trans, obj->angle_z);
  trans_k(&(obj->pos[0]), &(obj->pos[1]), &(obj->pos[2]), trans);
}

t_3d	*rotate_ray(t_3d *vector, t_obj *obj)
{
  double	trans[3][3];

  matrix_rot_x(trans, obj->angle_x);
  trans_pt(vector, trans);
  matrix_rot_y(trans, obj->angle_y);
  trans_pt(vector, trans);
  matrix_rot_z(trans, obj->angle_z);
  trans_pt(vector, trans);
  return (vector);
}

t_3d	*unrotate_ray(t_3d *vector, t_obj *obj)
{
  double	trans[3][3];

  matrix_rot_x(trans, -obj->angle_x);
  trans_pt(vector, trans);
  matrix_rot_y(trans, -obj->angle_y);
  trans_pt(vector, trans);
  matrix_rot_z(trans, -obj->angle_z);
  trans_pt(vector, trans);
  return (vector);
}
