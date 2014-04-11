/*
** cylinders.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Mar  7 16:47:28 2014 coutar_a
** Last update Sat Mar 15 17:36:42 2014 coutar_a
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
