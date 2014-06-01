/*
** translation.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:09:29 2014 grelli_t
** Last update Sun Jun  1 15:32:42 2014 coutar_a
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

void	translation_eye(t_params *params, double x_plus, double y_plus, double z_plus)
{
  params->pos_eye[0] += x_plus;
  params->pos_eye[1] += y_plus;
  params->pos_eye[2] += z_plus;
}

void	translation_point(t_3d *pt, double x_plus, double y_plus, double z_plus)
{
  pt->x += x_plus;
  pt->y += y_plus;
  pt->z += z_plus;
}
