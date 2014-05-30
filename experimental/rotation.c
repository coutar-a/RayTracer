/*
** rotation.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:07:41 2014 grelli_t
** Last update Mon Apr 21 15:06:08 2014 grelli_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

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

