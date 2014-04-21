/*
** translation.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:09:29 2014 grelli_t
** Last update Mon Apr 21 15:07:09 2014 grelli_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

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
