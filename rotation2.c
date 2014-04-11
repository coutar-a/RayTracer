/*
** rotation2.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Feb 28 18:12:03 2014 coutar_a
** Last update Sat Mar 15 13:53:04 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

/*
** Matrix for z-axis rotation. Angle in degrees.
*/

void	matrix_rot_z(float matrix[3][3], float angle)
{
  float	reg;

  reg = angle * (M_PI/180);
  matrix[0][0] = cosf(reg);
  matrix[0][1] = -sinf(reg);
  matrix[0][2] = 0;
  matrix[1][0] = sinf(reg);
  matrix[1][1] = cos(reg);
  matrix[1][2] = 0;
  matrix[2][0] = 0;
  matrix[2][1] = 0;
  matrix[2][2] = 1;
}

/*
** Matrix for x-axis rotation. Angle in degrees.
*/

void	matrix_rot_x(float matrix[3][3], float angle)
{
  float	reg;

  reg = angle * (M_PI/180);
  matrix[0][0] = 1;
  matrix[0][1] = 0;
  matrix[0][2] = 0;
  matrix[1][0] = 0;
  matrix[1][1] = cosf(reg);
  matrix[1][2] = -sinf(reg);
  matrix[2][0] = 0;
  matrix[2][1] = sinf(reg);
  matrix[2][2] = cosf(reg);
}

/*
** Matrix for y-axis rotation. Angle in degrees.
*/

void	matrix_rot_y(float matrix[3][3], float angle)
{
  float	reg;

  reg = angle * (M_PI/180);
  matrix[0][0] = cosf(reg);
  matrix[0][1] = 0;
  matrix[0][2] = sinf(reg);
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

void	trans_pt(t_3d *pt, float m[3][3])
{
  float	x_swap;
  float	y_swap;
  float	z_swap;

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

void	mult_matrix(float m1[3][3], float m2[3][3])
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
