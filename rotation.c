/*
** rotation.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Feb 28 15:07:59 2014 coutar_a
** Last update Fri Mar  7 13:03:58 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

/*
** Rotates point around z-axis. Counterclockwise.
** Angle in degrees ! Deprecated.
*/

void	rotate_z(t_3d *pt, float angle)
{
  float	reg;
  float	x_swap;
  float	y_swap;
  float	z_swap;
  float	test;
  float	test2;

  reg = angle * (M_PI/180);
  x_swap = pt->x;
  y_swap = pt->y;
  z_swap = pt->z;
  pt->x = x_swap * cosf(reg) + y_swap * (-sinf(reg)) + z_swap;
  pt->y = x_swap * sinf(reg) + x_swap * cosf(reg);
}

/*
** Rotates point around x-axis. Counterclockwise.
** Angle in degrees ! Deprecated.
*/

void	rotate_x(t_3d *pt, float angle)
{
  float	reg;
  float	x_swap;
  float	y_swap;
  float	z_swap;
  float	test;
  float	test2;

  reg = angle * (M_PI/180);
  x_swap = pt->x;
  y_swap = pt->y;
  z_swap = pt->z;
  pt->y = y_swap * cosf(reg) + z_swap * (-sin(reg));
  pt->z = y_swap * sinf(reg) + z_swap * cosf(reg);
}

/*
** Rotates point around y-axis. Counterclockwise (I think ?)
** Angle in degrees ! Deprecated.
*/

void	rotate_y(t_3d *pt, float angle)
{
  float	reg;
  float	x_swap;
  float	y_swap;
  float	z_swap;
  float	test;
  float	test2;

  reg = angle * (M_PI/180);
  x_swap = pt->x;
  y_swap = pt->y;
  z_swap = pt->z;
  pt->x = x_swap * cosf(reg) + z_swap * sinf(reg);
  pt->z = x_swap * (-sinf(reg)) + z_swap * cosf(reg);
}

