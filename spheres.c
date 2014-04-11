/*
** spheres.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Mar  7 16:45:11 2014 coutar_a
** Last update Sat Mar 15 17:58:18 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

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
