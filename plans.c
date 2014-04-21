/*
** plans.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:07:18 2014 grelli_t
** Last update Mon Apr 21 15:05:47 2014 grelli_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

/*
** All functions here define plans.
*/

t_obj	*define_plan1(t_obj *plan)
{
  plan = malloc(sizeof(t_obj));
  plan->type = 'p';
  plan->x = 0.0;
  plan->y = 0.0;
  plan->z = 1.0;
  plan->r_a = 0.0;
  plan->color = 0xFF55FF;
  plan->brill = 0.1;
  return (plan);
}

t_obj	*define_plan2(t_obj *plan)
{
  plan = malloc(sizeof(t_obj));
  plan->type = 'p';
  plan->x = 1000.0;
  plan->y = 1.0;
  plan->z = 0.0;
  plan->r_a = 0.0;
  plan->color = 0x6ABD78;
  plan->brill = 0.1;
  return (plan);
}
