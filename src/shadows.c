/*
** shadows.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:08:34 2014 grelli_t
** Last update Sat Jun  7 11:41:36 2014 coutar_a
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

  //eye = rotate_fake_eye(eye, sph);
  vc = rotate_ray(vc, sph);
  a = (pow(vc->x, 2.0) + pow(vc->y, 2.0) + pow(vc->z, 2.0));
  b = 2.0 * (vc->x * (eye->x - sph->pos[0]) + vc->y *
	     (eye->y - sph->pos[1]) + vc->z * (eye->z - sph->pos[2]));
  c = (pow(eye->x, 2.0) + pow(eye->y, 2.0) + pow(eye->z, 2.0) +
       (pow(sph->pos[0], 2.0) + pow(sph->pos[1], 2.0) + pow(sph->pos[2], 2.0) -
	2.0 * (sph->pos[0] * eye->x + sph->pos[1] * eye->y + sph->pos[2] * eye->z) -
	pow(sph->ray, 2.0)));
  delta = pow(b, 2.0) - (4.0 * a * c);
  vc = unrotate_ray(vc, sph);
  //eye = unrotate_fake_eye(eye, sph);
 if (delta < 0.0)
    return (-1.0);
  else if (delta == 0.0)
    return ((-b) / (2.0 * a));
  k1 = ((-b) - (sqrt(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrt(delta))) / (2.0 * a);
  return (CPR_MIN(k1, k2));
}

double	plan_int_shadow(t_3d *eye, t_3d *vc, t_objs *pl)
{
  double	test;

  //eye = rotate_fake_eye(eye, pl);
  vc = rotate_ray(vc, pl);
  if (vc->x == 0.0 && vc->y == 0.0 && vc->z == 0.0)
    return (-1.0);
  test = -(eye->x * pl->pos[0] + eye->y * pl->pos[1] + eye->z *
	   pl->pos[2] + pl->ray) / (pl->pos[0] * vc->x + pl->pos[1] * vc->y + pl->pos[2] * vc->z);
  vc = unrotate_ray(vc, pl);
  //eye = unrotate_fake_eye(eye, pl);
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

  //eye = unrotate_fake_eye(eye, cyl);
  vc = unrotate_ray(vc, cyl);
  a = (pow(vc->x, 2.0) + pow(vc->y, 2.0));
  b = 2.0 * (vc->x * (eye->x - cyl->pos[0]) + vc->y * (eye->y - cyl->pos[1]));
  c = pow(eye->x, 2.0) + pow(eye->y, 2.0) +
    pow(cyl->pos[0], 2.0) + pow(cyl->pos[1], 2.0) - 2.0 *
    (cyl->pos[0] * eye->x + cyl->pos[1] * eye->y) - pow(cyl->ray, 2.0);
  delta = pow(b, 2.0) - (4.0 * a * c);
  vc = rotate_ray(vc, cyl);
  //eye = rotate_fake_eye(eye, cyl);
  if (delta < 0.0)
    return (-1.0);
  else if (delta == 0.0)
    return ((-b) / (2.0 * a));
  k1 = ((-b) - (sqrt(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrt(delta))) / (2.0 * a);
  return (CPR_MIN(k1, k2));
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

  eye = rotate_fake_eye(eye, cone);
  vc = rotate_ray(vc, cone);
  q = tan(cone->ray * (M_PI / 180.0));
  a = pow(vc->x, 2.0) + pow(vc->y, 2.0) - (q * pow(vc->z, 2.0));
  b = 2.0 * (vc->x * (eye->x - cone->pos[0]) + vc->y *
	      (eye->y - cone->pos[1]) - q * vc->z * (eye->z - cone->pos[2]));
  c = pow(eye->x, 2.0) + pow(cone->pos[0], 2.0) + pow(eye->y, 2.0)
    + pow(cone->pos[1], 2.0) - q * pow(eye->z, 2.0) - q *
    pow(cone->pos[2], 2.0) - 2 * (cone->pos[0] * eye->x + cone->pos[1] *
			      eye->y - (q * cone->pos[2] * eye->z));
  delta = pow(b, 2.0) - (4.0 * a * c);
  vc = unrotate_ray(vc, cone);
  eye = unrotate_fake_eye(eye, cone);
  if (delta < 0.0)
    return (-1.0);
  else if (delta == 0.0)
    return((-b) / (2.0 * a));
  k1 = ((-b) - (sqrt(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrt(delta))) / (2.0 * a);
  return (CPR_MIN(k1, k2));
}

/*
** Checks wether there is an object between the intersection point
** and the light spot.
*/

int			shadow_checking(t_3d *l, t_params *params, t_objs *one_object)
{
  int			i;
  int			index;
  double		ret;
  double		(*shadow_array[4])(t_3d*, t_3d*, t_objs*);
  t_3d			fake_eye;

  fake_eye.x = one_object->intersection.p_x;
  fake_eye.y = one_object->intersection.p_y;
  fake_eye.z = one_object->intersection.p_z;
  shadow_array[0] = &cone_int_shadow;
  shadow_array[1] = &plan_int_shadow;
  shadow_array[2] = &sphere_int_shadow;
  shadow_array[3] = &cyl_int_shadow;
  i = 0;
  while (i != params->nb_objs)
    {
      index = params->objs[i].type - 1;
      ret = shadow_array[index](&fake_eye, l, &(params->objs[i]));
      if (ret > 0.00001 && ret < 1.0)
	return (1);
      i++;
    }
  return (0);
}
