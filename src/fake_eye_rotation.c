/*
** fake_eye_rotation.c for raytracer in /home/coutar_a/rendu/raytracer
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat Jun  7 10:02:18 2014 coutar_a
** Last update Sat Jun  7 11:32:20 2014 coutar_a
*/

#include "raytracer.h"

void		*rotate_fake_eye(t_3d *eye, t_objs *obj)
{
  double	trans[3][3];

  if (obj->rot[0])
    {
      matrix_rot_x(trans, obj->rot[0]);
      trans_fake_eye(eye, trans);
    }
  if (obj->rot[1])
    {
      matrix_rot_y(trans, obj->rot[1]);
      trans_fake_eye(eye, trans);
    }
  if (obj->rot[2])
    {
      matrix_rot_z(trans, obj->rot[2]);
      trans_fake_eye(eye, trans);
    }
}

void		*unrotate_fake_eye(t_3d *eye, t_objs *obj)
{
  double	trans[3][3];

  if (obj->rot[0])
    {
      matrix_rot_x(trans, -(obj->rot[0]));
      trans_fake_eye(eye, trans);
    }
  if (obj->rot[1])
    {
      matrix_rot_y(trans, -(obj->rot[1]));
      trans_fake_eye(eye, trans);
    }
  if (obj->rot[2])
    {
      matrix_rot_z(trans, -(obj->rot[2]));
      trans_fake_eye(eye, trans);
    }
}

void		trans_fake_eye(t_3d *eye, double m[][3])
{
  double	x_swap;
  double	y_swap;
  double	z_swap;

  x_swap = eye->x;
  y_swap = eye->y;
  z_swap = eye->z;
  eye->x = x_swap * m[0][0] + y_swap * m[0][1] + z_swap * m[0][2];
  eye->y = x_swap * m[1][0] + y_swap * m[1][1] + z_swap * m[1][2];
  eye->z = x_swap * m[2][0] + y_swap * m[2][1] + z_swap * m[2][2];
}
