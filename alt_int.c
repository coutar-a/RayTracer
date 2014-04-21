/*
** alt_int.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:05:19 2014 grelli_t
** Last update Mon Apr 21 15:04:03 2014 grelli_t
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

void		sub_int_k(t_sec *k, float b, float delta, float a)
{
  float		k1;
  float		k2;

  k1 = ((-b) - (sqrtf(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrtf(delta))) / (2.0 * a);
  k->k = CPR_MIN(k1, k2);
}

void		alt_sphere_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *sph)
{
  float		a;
  float		b;
  float		c;
  float		delta;

  a = (powf(vc->x, 2.0) + powf(vc->y, 2.0) + powf(vc->z, 2.0));
  b = 2.0 * (vc->x * (eye->x - sph->x) + vc->y *
	   (eye->y - sph->y) + vc->z * (eye->z - sph->z));
  c = (powf(eye->x, 2.0) + powf(eye->y, 2.0) + powf(eye->z, 2.0) +
       (powf(sph->x, 2.0) + powf(sph->y, 2.0) + powf(sph->z, 2.0) -
	2.0 * (sph->x * eye->x + sph->y * eye->y +
	     sph->z * eye->z) - powf(sph->r_a, 2.0)));
  delta = powf(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    k->k = 0.0;
  else if (delta == 0.0)
    k->k = (-b) / (2.0 * a);
  else
    sub_int_k(k, b, delta, a);
}

void	alt_plan_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *pl)
{
  float	test;

  if (vc->x == 0.0 && vc->y == 0.0 && vc->z == 0.0)
    k->k = 0.0;
  test = -(eye->x * pl->x + eye->y * pl->y + eye->z *
	   pl->z + pl->r_a) / (pl->x * vc->x + pl->y * vc->y + pl->z * vc->z);
  if (test < 0.0)
    {
      k->k = 0.0;
    }
  else
    k->k = test;
}

void		alt_cyl_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *cyl)
{
  float		a;
  float		b;
  float		c;
  float		delta;

  a = (powf(vc->x, 2.0) + powf(vc->y, 2.0));
  b = 2.0 * (vc->x * (eye->x - cyl->x) + vc->y * (eye->y - cyl->y));
  c = (powf(eye->x, 2.0) + powf(eye->y, 2.0) +
       (powf(cyl->x, 2.0) + powf(cyl->y, 2.0) - 2.0 *
	(cyl->x * eye->x + cyl->y * eye->y) - powf(cyl->r_a, 2.0)));
  delta = powf(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    k->k = 0.0;
  else if (delta == 0.0)
    k->k = (-b) / (2.0 * a);
  else
    sub_int_k(k, b, delta, a);
}

void		alt_cone_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *cone)
{
  float		q;
  float		a;
  float		b;
  float		c;
  float		delta;

  q = tanf(cone->r_a * (M_PI / 180.0));
  a = powf(vc->x, 2.0) + powf(vc->y, 2.0) - (q * powf(vc->z, 2.0));
  b = 2.0 * (vc->x * (eye->x - cone->x) + vc->y *
	      (eye->y - cone->y) - q * vc->z * (eye->z - cone->z));
  c = powf(eye->x, 2.0) + powf(cone->x, 2.0) + powf(eye->y, 2.0)
    + powf(cone->y, 2.0) - q * powf(eye->z, 2.0) - q *
    powf(cone->z, 2.0) - 2 * (cone->x * eye->x + cone->y *
			      eye->y - (q * cone->z * eye->z));
  delta = powf(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    k->k = 0.0;
  else if (delta == 0.0)
    k->k = (-b) / (2.0 * a);
  else
    sub_int_k(k, b, delta, a);
}
