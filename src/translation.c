/*
** translation.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:09:29 2014 grelli_t
** Last update Sat Jun  7 14:27:17 2014 coutar_a
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

void	translation_eye(t_params *params, double x_p, double y_p, double z_p)
{
  params->pos_eye[0] += x_p;
  params->pos_eye[1] += y_p;
  params->pos_eye[2] += z_p;
}

void	translation_point(t_3d *pt, double x_p, double y_p, double z_p)
{
  pt->x += x_p;
  pt->y += y_p;
  pt->z += z_p;
}

void	translation_obj(t_objs *objs, double x_p, double y_p, double z_p)
{
  objs->pos[0] += x_p;
  objs->pos[1] += y_p;
  objs->pos[2] += z_p;
}
