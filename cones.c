/*
** cones.c for rtv1.h in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Mar  7 16:57:33 2014 coutar_a
** Last update Mon Mar 17 13:09:45 2014 coutar_a
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
