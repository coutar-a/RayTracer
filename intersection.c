/*
** intersection.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
**
** Made by coutar_a
** Login   <coutar_a@epitech.net>
**
** Started on  Mon Feb 17 15:24:39 2014 coutar_a
** Last update Fri Mar  7 16:07:04 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

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
