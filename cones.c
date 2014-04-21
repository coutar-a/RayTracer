/*
** cones.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:05:48 2014 grelli_t
** Last update Mon Apr 21 10:05:49 2014 grelli_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

/*
** All functions here are used to fill up objs as cones.
*/

t_obj	*define_cone1(t_obj *cone)
{
  cone = malloc(sizeof(t_obj));
  cone->type = 'k';
  cone->x = -150.0;
  cone->y = -60.0;
  cone->z = 60.0;
  cone->r_a = 20.0;
  cone->color = 0xE32B68;
  cone->brill = 0.6;
  return (cone);
}
