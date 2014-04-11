/*
** plans.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Mar  7 16:45:58 2014 coutar_a
** Last update Sat Mar 15 14:01:04 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

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
