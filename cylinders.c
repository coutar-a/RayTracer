/*
** cylinders.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:06:00 2014 grelli_t
** Last update Mon Apr 21 10:06:00 2014 grelli_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

/*
** All functions here define cylinders.
*/

t_obj	*define_cyl(t_obj *cyl)
{
  cyl = malloc(sizeof(t_obj));
  cyl->type = 'c';
  cyl->x = -150.0;
  cyl->y = 50.0;
  cyl->z = 5.0;
  cyl->r_a = 10.0;
  cyl->color = 0xAAAAAA;
  cyl->brill = 0.82;
  return (cyl);
}
