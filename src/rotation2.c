/*
** rotation2.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:07:31 2014 grelli_t
** Last update Wed Jun  4 14:30:10 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

/*
** Matrix for z-axis rotation. Angle in degrees.
*/

void	matrix_rot_z(double matrix[][3], double angle)
{
  double	reg;

  reg = angle * (M_PI/180);
  matrix[0][0] = cos(reg);
  matrix[0][1] = -sin(reg);
  matrix[0][2] = 0;
  matrix[1][0] = sin(reg);
  matrix[1][1] = cos(reg);
  matrix[1][2] = 0;
  matrix[2][0] = 0;
  matrix[2][1] = 0;
  matrix[2][2] = 1;
}

/*
** Matrix for x-axis rotation. Angle in degrees.
*/

void	matrix_rot_x(double matrix[][3], double angle)
{
  double	reg;

  reg = angle * (M_PI/180);
  matrix[0][0] = 1;
  matrix[0][1] = 0;
  matrix[0][2] = 0;
  matrix[1][0] = 0;
  matrix[1][1] = cos(reg);
  matrix[1][2] = -sin(reg);
  matrix[2][0] = 0;
  matrix[2][1] = sin(reg);
  matrix[2][2] = cos(reg);
}

/*
** Matrix for y-axis rotation. Angle in degrees.
*/

void	matrix_rot_y(double matrix[][3], double angle)
{
  double	reg;

  reg = angle * (M_PI/180);
  matrix[0][0] = cos(reg);
  matrix[0][1] = 0;
  matrix[0][2] = sin(reg);
  matrix[1][0] = 0;
  matrix[1][1] = 1;
  matrix[1][2] = 0;
  matrix[2][0] = sin(reg);
  matrix[2][1] = 0;
  matrix[2][2] = cos(reg);
}

/*
** Multiplies 3d point struct with trans matrix.
*/

void	trans_pt(t_3d *pt, double m[][3])
{
  double	x_swap;
  double	y_swap;
  double	z_swap;

  x_swap = pt->x;
  y_swap = pt->y;
  z_swap = pt->z;
  pt->x = x_swap * m[0][0] + y_swap * m[0][1] + z_swap * m[0][2];
  pt->y = x_swap * m[1][0] + y_swap * m[1][1] + z_swap * m[1][2];
  pt->z = x_swap * m[2][0] + y_swap * m[2][1] + z_swap * m[2][2];
}

/*
** Multiplies 2 trans matrices, results in first one.
*/

void	mult_matrix(double m1[][3], double m2[][3])
{
  m1[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0] + m1[0][2] * m2[2][0];
  m1[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1] + m1[0][2] * m2[2][1];
  m1[0][2] = m1[0][0] * m2[0][2] + m1[0][1] * m2[1][2] + m1[0][2] * m2[2][2];
  m1[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0] + m1[1][2] * m2[2][0];
  m1[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1] + m1[1][2] * m2[2][1];
  m1[1][2] = m1[1][0] * m2[0][2] + m1[1][1] * m2[1][2] + m1[1][2] * m2[2][2];
  m1[2][0] = m1[2][0] * m2[0][0] + m1[2][1] * m2[1][0] + m1[2][2] * m2[2][0];
  m1[2][1] = m1[2][0] * m2[0][1] + m1[2][1] * m2[1][1] + m1[2][2] * m2[2][1];
  m1[2][2] = m1[2][0] * m2[0][2] + m1[2][1] * m2[1][2] + m1[2][2] * m2[2][2];
}
