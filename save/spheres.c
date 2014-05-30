/*
** spheres.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:08:53 2014 grelli_t
** Last update Mon Apr 21 15:06:38 2014 grelli_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

/*
** Those functions define spheres.
*/

t_obj	*define_sphere1(t_obj *sphere)
{
  sphere = malloc(sizeof(t_obj));
  sphere->type = 's';
  sphere->x = 0.0;
  sphere->y = 0.0;
  sphere->z = 0.0;
  sphere->r_a = 100.0;
  sphere->color = 0x00FF00;
  sphere->brill = 0.3;
  return (sphere);
}

t_obj	*define_sphere2(t_obj *sphere)
{
  sphere = malloc(sizeof(t_obj));
  sphere->type = 's';
  sphere->x = 250.0;
  sphere->y = 175.0;
  sphere->z = 90.0;
  sphere->r_a = 57.0;
  sphere->color = 0xAABBCC;
  sphere->brill = 0.77;
  return (sphere);
}

t_obj	*define_sphere3(t_obj *sphere)
{
  sphere = malloc(sizeof(t_obj));
  sphere->type = 's';
  sphere->x = 500.0;
  sphere->y = -70.0;
  sphere->z = 150.0;
  sphere->r_a = 350.0;
  sphere->color = 0xED8E21;
  sphere->brill = 0.33;
  return (sphere);
}
