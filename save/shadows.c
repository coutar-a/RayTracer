/*
** shadows.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:08:34 2014 grelli_t
** Last update Mon Apr 21 15:06:26 2014 grelli_t
*/

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "raytracer.h"

/*
** The following are intersection functions modified to calculate shadows.
*/

float		sphere_int_shadow(t_eye *eye, t_3d *vc, t_obj *sph)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k1;
  float		k2;

  a = (powf(vc->x, 2.0) + powf(vc->y, 2.0) + powf(vc->z, 2.0));
  b = 2.0 * (vc->x * (eye->x - sph->x) + vc->y *
	   (eye->y - sph->y) + vc->z * (eye->z - sph->z));
  c = (powf(eye->x, 2.0) + powf(eye->y, 2.0) + powf(sph->z, 2.0) +
       (powf(sph->x, 2.0) + pow(sph->y, 2.0) + powf(sph->z, 2.0) -
	2.0 * (sph->x * eye->x + sph->y * eye->y + sph->z * eye->z) -
	powf(sph->r_a, 2.0)));
  delta = pow(b, 2.0) - (4.0 * a * c);
 if (delta < 0.0)
    return(-1.0);
  else if (delta == 0.0)
    return((-b) / (2.0 * a));
  k1 = ((-b) - (sqrtf(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrtf(delta))) / (2.0 * a);
  return(CPR_MIN(k1, k2));
}

float	plan_int_shadow(t_eye *eye, t_3d *vc, t_obj *pl)
{
  float	test;

  if (vc->x == 0.0 && vc->y == 0.0 && vc->z == 0.0)
    return (-1.0);
  test = -(eye->x * pl->x + eye->y * pl->y + eye->z *
	   pl->z + pl->r_a) / (pl->x * vc->x + pl->y * vc->y + pl->z * vc->z);
  if (test < 0.0)
    return (-1.0);
  return (test);
}

float		cyl_int_shadow(t_eye *eye, t_3d *vc, t_obj *cyl)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k1;
  float		k2;

  a = (powf(vc->x, 2.0) + powf(vc->y, 2.0));
  b = 2.0 * (vc->x * (eye->x - cyl->x) + vc->y * (eye->y - cyl->y));
  c = powf(eye->x, 2.0) + powf(eye->y, 2.0) +
    powf(cyl->x, 2.0) + powf(cyl->y, 2.0) - 2.0 *
    (cyl->x * eye->x + cyl->y * eye->y) - powf(cyl->r_a, 2.0);
  delta = powf(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    return(-1.0);
  else if (delta == 0.0)
    return((-b) / (2.0 * a));
  k1 = ((-b) - (sqrtf(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrtf(delta))) / (2.0 * a);
  return(CPR_MIN(k1, k2));
}

float		cone_int_shadow(t_eye *eye, t_3d *vc, t_obj *cone)
{
  float		q;
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k1;
  float		k2;

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
    return(-1.0);
  else if (delta == 0.0)
    return((-b) / (2.0 * a));
  k1 = ((-b) - (sqrtf(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrtf(delta))) / (2.0 * a);
  return(CPR_MIN(k1, k2));
}

/*
** Checks wether there is an object between the intersection point
** and the light spot.
*/

int		shadow_checking(t_3d *l, t_sec *k, t_obj **scene)
{
  int		i;
  int		test;
  float		ret;
  float		(*shadow_array[4])( t_eye*, t_3d*, t_obj*);
  t_eye		fake_eye;

  fake_eye.x = k->p_x;
  fake_eye.y = k->p_y;
  fake_eye.z = k->p_z;
  shadow_array[0] = &sphere_int_shadow;
  shadow_array[1] = &cyl_int_shadow;
  shadow_array[2] = &cone_int_shadow;
  shadow_array[3] = &plan_int_shadow;
  i = 0;
  while (i != NUMBER_OBJ)
    {
      test = find_object_type(scene[i]);
      ret = shadow_array[test](&fake_eye, l, scene[i]);
      if (ret > 0.00001 && ret < 1.0)
	return (1);
      i++;
    }
  return (0);
}
