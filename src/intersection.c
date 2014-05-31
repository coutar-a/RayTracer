/*
** intersection.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:06:11 2014 grelli_t
** Last update Mon Apr 21 15:04:59 2014 grelli_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

/*
** Deprecated intersection functions.
*/

float		sphere_intersection(t_eye *eye, t_3d *vc, float ray)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k1;
  float		k2;

  a = (powf(vc->x, 2.0) + powf(vc->y, 2.0) + powf(vc->z, 2.0));
  b = 2.0 * (eye->x * vc->x) + 2 * (eye->y * vc->y) + 2 * (eye->z * vc->z);
  c = (powf(eye->x, 2.0) + powf(eye->y, 2.0) + powf(eye->z, 2.0) - powf(ray, 2.0));
  delta = powf(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    return (0.0);
  else if (delta == 0.0)
    return ((-b) / (2.0 * a));
  else
    {
      k1 = ((-b) - (sqrtf(delta))) / (2.0 * a);
      k2 = ((-b) + (sqrtf(delta))) / (2.0 * a);
      if (k1 < k2 && k1 > 0.0)
	return (k1);
      return (k2);
    }
}

float	cyl_intersection(t_eye *eye, t_3d *vc, float ray)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k1;
  float		k2;

  a = (powf(vc->x, 2.0) + powf(vc->y, 2.0));
  b = 2.0 * ((eye->x * vc->x) + (eye->y * vc->y));
  c = (powf(eye->x, 2.0) + powf(eye->y, 2.0) - powf(ray, 2.0));
  delta = powf(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    return (0);
  else if (delta == 0.0)
    return ((-b) / (2.0 * a));
  else
    {
      k1 = ((-b) - (sqrtf(delta))) / (2.0 * a);
      k2 = ((-b) + (sqrtf(delta))) / (2.0 * a);
      if (k1 < k2 && k1 > 0.0)
	return (k1);
      return (k2);
    }
}

/*
** Angle in degrees.
** Square constant q for funky results.
*/

float	cone_intersection(t_eye *eye, t_3d *vc, float angle)
{
  float		q;
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k1;
  float		k2;

  q = tanf((angle * (M_PI/180.0)));
  a = powf(vc->x, 2.0) + powf(vc->y, 2.0) - (q * powf(vc->z, 2.0));
  b = 2.0 * (eye->x * vc->x + eye->y * vc->y - (q * eye->z * vc->z));
  c = (powf(eye->x, 2.0) + powf(eye->y, 2.0) - (q * powf(eye->z, 2.0)));
  delta = powf(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    return (0.0);
  else if (delta == 0.0)
    return ((-b) / (2.0 * a));
  else
    {
      k1 = ((-b) - (sqrt(delta))) / (2.0 * a);
      k2 = ((-b) + (sqrt(delta))) / (2.0 * a);
      if (k1 < k2 && k1 > 0.0)
	return (k1);
      return (k2);
    }
}

float	plan_intersection(t_eye *eye, t_3d *vc)
{
  float	k;

  if (vc->z == 0)
    return (0.0);
  k = (((- eye->z)) / (vc->z));
  if (k < 0)
    return (0.0);
  return (k);
}
