/*
** some_more_intersection_functions.c for raytracer in /home/coutar_a/rendu/raytracer
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri May 30 17:10:10 2014 coutar_a
** Last update Mon Jun  2 16:03:49 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

/*
** Intersection functions for plans, spheres, cones and cylinders.
** All take an object struct as parameter, fill out an intersection struct.
*/

void		sub_int_k(t_sec *k, double b, double delta, double a)
{
  double		k1;
  double		k2;

  k1 = ((-b) - (sqrtf(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrtf(delta))) / (2.0 * a);
  //printf("K returned = %lf\n", CPR_MIN(k1, k2));
  k->k = CPR_MIN(k1, k2);
}

void		inter_sph(t_params *params, t_3d *vc, t_objs *sph)
{
  double		a;
  double		b;
  double		c;
  double		delta;

  //printf("Sphere\n");
  a = (pow(vc->x, 2.0) + pow(vc->y, 2.0) + pow(vc->z, 2.0));
  b = 2.0 * (vc->x * (params->pos_eye[0] - sph->pos[0]) + vc->y *
	   (params->pos_eye[1] - sph->pos[1]) + vc->z * (params->pos_eye[2] - sph->pos[2]));
  c = (pow(params->pos_eye[0], 2.0) + pow(params->pos_eye[1], 2.0) + pow(params->pos_eye[2], 2.0) +
       (pow(sph->pos[0], 2.0) + pow(sph->pos[1], 2.0) + pow(sph->pos[2], 2.0) -
	2.0 * (sph->pos[0] * params->pos_eye[0] + sph->pos[1] * params->pos_eye[1] +
	     sph->pos[2] * params->pos_eye[2]) - pow(sph->ray, 2.0)));
  delta = pow(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    {
      sph->intersection.k = 0.0;
      //printf("no k\n");
    }
  else if (delta == 0.0)
    {
      sph->intersection.k = (-b) / (2.0 * a);
      //printf("K = %lf\n", (-b) / (2.0 * a));
    }
  else
    sub_int_k(&(sph->intersection), b, delta, a);
}

void	inter_plan(t_params *params, t_3d *vc, t_objs *pl)
{
  double	test;

  //printf("Plan\n");
  if (vc->x == 0.0 && vc->y == 0.0 && vc->z == 0.0)
    pl->intersection.k = 0.0;
  test = -(params->pos_eye[0] * pl->pos[0] + params->pos_eye[1]
	   * pl->pos[1] + params->pos_eye[2] *
	   pl->pos[2] + pl->ray) / (pl->pos[0] * vc->x +
				    pl->pos[1] * vc->y + pl->pos[2] * vc->z);
  if (test < 0.0)
    {
      //printf("No K\n");
      pl->intersection.k = 0.0;
    }
  else
    {
      //printf ("K = %lf\n", test);
      pl->intersection.k = test;
    }
}

void		inter_cyl(t_params *params, t_3d *vc, t_objs *cyl)
{
  double		a;
  double		b;
  double		c;
  double		delta;

  //printf("Cylinder\n");
  a = (pow(vc->x, 2.0) + pow(vc->y, 2.0));
  b = 2.0 * (vc->x * (params->pos_eye[0] - cyl->pos[0]) + vc->y * (params->pos_eye[1] - cyl->pos[1]));
  c = (pow(params->pos_eye[0], 2.0) + pow(params->pos_eye[1], 2.0) +
       (pow(cyl->pos[0], 2.0) + pow(cyl->pos[1], 2.0) - 2.0 *
	(cyl->pos[0] * params->pos_eye[0] + cyl->pos[1] * params->pos_eye[1]) - pow(cyl->ray, 2.0)));
  delta = pow(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    {
      //printf("No K\n");
      cyl->intersection.k = 0.0;
    }
  else if (delta == 0.0)
    {
      //printf("K = %lf\n", (-b) / (2.0 * a));
      cyl->intersection.k = (-b) / (2.0 * a);
    }
  else
    sub_int_k(&(cyl->intersection), b, delta, a);
}

void		inter_cone(t_params *params, t_3d *vc, t_objs *cone)
{
  double		q;
  double		a;
  double		b;
  double		c;
  double		delta;

  //printf("Cone\n");
  q = tan(cone->ray * (M_PI / 180.0));
  a = pow(vc->x, 2.0) + pow(vc->y, 2.0) - (q * pow(vc->z, 2.0));
  b = 2.0 * (vc->x * (params->pos_eye[0] - cone->pos[0]) + vc->y *
	      (params->pos_eye[1] - cone->pos[1]) - q * vc->z * (params->pos_eye[2] - cone->pos[2]));
  c = pow(params->pos_eye[0], 2.0) + pow(cone->pos[0], 2.0) + pow(params->pos_eye[1], 2.0)
    + pow(cone->pos[1], 2.0) - q * pow(params->pos_eye[2], 2.0) - q *
    pow(cone->pos[2], 2.0) - 2 * (cone->pos[0] * params->pos_eye[0] + cone->pos[1] *
			      params->pos_eye[1] - (q * cone->pos[2] * params->pos_eye[2]));
  delta = pow(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    {
      //printf("No K\n");
      cone->intersection.k = 0.0;
    }
  else if (delta == 0.0)
    {
      //printf("K = %lf\n", (-b) / (2.0 * a));
      cone->intersection.k = (-b) / (2.0 * a);
    }
  else
    sub_int_k(&(cone->intersection), b, delta, a);
}
