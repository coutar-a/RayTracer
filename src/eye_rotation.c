/*
** rotation4.c for raytracer in /home/coutar_a/Projets/Bukkit/MUL_2013_rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Mon Apr 28 13:58:32 2014 coutar_a
** Last update Sat Jun  7 10:22:51 2014 coutar_a
*/

#include "raytracer.h"

void		*rotate_eye(t_params *params, t_objs *obj)
{
  double	trans[3][3];

  if (obj->rot[0])
    {
      matrix_rot_x(trans, obj->rot[0]);
      trans_eye(params, trans);
    }
  if (obj->rot[1])
    {
      matrix_rot_y(trans, obj->rot[1]);
      trans_eye(params, trans);
    }
  if (obj->rot[2])
    {
      matrix_rot_z(trans, obj->rot[2]);
      trans_eye(params, trans);
    }
}

void		*unrotate_eye(t_params *params, t_objs *obj)
{
  double	trans[3][3];

  if (obj->rot[0])
    {
      matrix_rot_x(trans, -obj->rot[0]);
      trans_eye(params, trans);
    }
  if (obj->rot[1])
    {
      matrix_rot_y(trans, -obj->rot[1]);
      trans_eye(params, trans);
    }
  if (obj->rot[2])
    {
      matrix_rot_z(trans, -obj->rot[2]);
      trans_eye(params, trans);
    }
}

void		trans_eye(t_params *params, double m[3][3])
{
  double	x_swap;
  double	y_swap;
  double	z_swap;

  x_swap = params->pos_eye[0];
  y_swap = params->pos_eye[1];
  z_swap = params->pos_eye[2];
  params->pos_eye[0] = x_swap * m[0][0] + y_swap * m[0][1] + z_swap * m[0][2];
  params->pos_eye[1] = x_swap * m[1][0] + y_swap * m[1][1] + z_swap * m[1][2];
  params->pos_eye[2] = x_swap * m[2][0] + y_swap * m[2][1] + z_swap * m[2][2];
}
