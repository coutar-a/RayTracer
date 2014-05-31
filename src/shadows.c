/*
** shadows.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:08:34 2014 grelli_t
** Last update Sat May 31 16:45:20 2014 coutar_a
*/

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "raytracer.h"

/*
** The following are intersection functions modified to calculate shadows.
*/

double		sphere_int_shadow(t_3d *eye, t_3d *vc, t_objs *sph)
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		k1;
  double		k2;

  a = (pow(vc->x, 2.0) + pow(vc->y, 2.0) + pow(vc->z, 2.0));
  b = 2.0 * (vc->x * (eye->x - sph->x) + vc->y *
	   (eye->y - sph->y) + vc->z * (eye->z - sph->z));
  c = (pow(eye->x, 2.0) + pow(eye->y, 2.0) + pow(sph->z, 2.0) +
       (pow(sph->x, 2.0) + pow(sph->y, 2.0) + pow(sph->z, 2.0) -
	2.0 * (sph->x * eye->x + sph->y * eye->y + sph->z * eye->z) -
	pow(sph->r_a, 2.0)));
  delta = pow(b, 2.0) - (4.0 * a * c);
 if (delta < 0.0)
    return(-1.0);
  else if (delta == 0.0)
    return((-b) / (2.0 * a));
  k1 = ((-b) - (sqrtf(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrtf(delta))) / (2.0 * a);
  return(CPR_MIN(k1, k2));
}

double	plan_int_shadow(t_3d *eye, t_3d *vc, t_objs *pl)
{
  double	test;

  if (vc->x == 0.0 && vc->y == 0.0 && vc->z == 0.0)
    return (-1.0);
  test = -(eye->x * pl->x + eye->y * pl->y + eye->z *
	   pl->z + pl->r_a) / (pl->x * vc->x + pl->y * vc->y + pl->z * vc->z);
  if (test < 0.0)
    return (-1.0);
  return (test);
}

double		cyl_int_shadow(t_3d *eye, t_3d *vc, t_objs *cyl)
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		k1;
  double		k2;

  a = (pow(vc->x, 2.0) + pow(vc->y, 2.0));
  b = 2.0 * (vc->x * (eye->x - cyl->x) + vc->y * (eye->y - cyl->y));
  c = pow(eye->x, 2.0) + pow(eye->y, 2.0) +
    pow(cyl->x, 2.0) + pow(cyl->y, 2.0) - 2.0 *
    (cyl->x * eye->x + cyl->y * eye->y) - pow(cyl->r_a, 2.0);
  delta = pow(b, 2.0) - (4.0 * a * c);
  if (delta < 0.0)
    return(-1.0);
  else if (delta == 0.0)
    return((-b) / (2.0 * a));
  k1 = ((-b) - (sqrtf(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrtf(delta))) / (2.0 * a);
  return(CPR_MIN(k1, k2));
}

double		cone_int_shadow(t_3d *eye, t_3d *vc, t_objs *cone)
{
  double		q;
  double		a;
  double		b;
  double		c;
  double		delta;
  double		k1;
  double		k2;

  q = tan(cone->r_a * (M_PI / 180.0));
  a = pow(vc->x, 2.0) + pow(vc->y, 2.0) - (q * pow(vc->z, 2.0));
  b = 2.0 * (vc->x * (eye->x - cone->x) + vc->y *
	      (eye->y - cone->y) - q * vc->z * (eye->z - cone->z));
  c = pow(eye->x, 2.0) + pow(cone->x, 2.0) + pow(eye->y, 2.0)
    + pow(cone->y, 2.0) - q * pow(eye->z, 2.0) - q *
    pow(cone->z, 2.0) - 2 * (cone->x * eye->x + cone->y *
			      eye->y - (q * cone->z * eye->z));
  delta = pow(b, 2.0) - (4.0 * a * c);
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

int			shadow_checking(t_3d *l, t_sec *k, t_objs *objs)
{
  int			i;
  double		ret;
  double		(*shadow_array[4])(t_3d*, t_3d*, t_objs*);
  t_3d			fake_eye;

  fake_eye.x = obj->intersection.p_x;
  fake_eye.y = obj->intersection.p_y;
  fake_eye.z = obj->intersection.p_z;
  shadow_array[0] = &cone_int_shadow;
  shadow_array[1] = &plan_int_shadow;
  shadow_array[2] = &sphere_int_shadow;
  shadow_array[3] = &cyl_int_shadow;
  i = 0;
  while (i != params->nb_objs)
    {
      ret = shadow_array[objs[i]->type - 1](&fake_eye, l, objs[i]);
      if (ret > 0.00001 && ret < 1.0)
	return (1);
      i++;
    }
  return (0);
}
