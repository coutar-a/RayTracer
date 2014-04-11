/*
** translation.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Feb 28 18:56:59 2014 coutar_a
** Last update Wed Mar  5 12:31:03 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

/*
** Point/eye translation.
*/

void	translation_eye(t_eye *eye, float x_plus, float y_plus, float z_plus)
{
  eye->x = eye->x + x_plus;
  eye->y = eye->y + y_plus;
  eye->z = eye->z + z_plus;
}

void	translation_point(t_3d *pt, float x_plus, float y_plus, float z_plus)
{
  pt->x = pt->x + x_plus;
  pt->y = pt->y + y_plus;
  pt->z = pt->z + z_plus;
}
