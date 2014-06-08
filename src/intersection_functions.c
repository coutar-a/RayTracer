/*
** some_more_intersection_functions.c for raytracer in /home/coutar_a/rendu/raytracer
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri May 30 17:10:10 2014 coutar_a
** Last update Sun Jun  8 15:41:20 2014 coutar_a
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
** Updated to use the cfg file structs
*/

void		sub_int_k(t_sec *k, double b, double delta, double a)
{
  double	k1;
  double	k2;

  k1 = ((-b) - (sqrt(delta))) / (2.0 * a);
  k2 = ((-b) + (sqrt(delta))) / (2.0 * a);
  k->k = CPR_MIN(k1, k2);
}

void		inter_sph(t_params *params, t_3d *vc, t_objs *sph)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  translation_obj(sph, sph->trans[0], sph->trans[1], sph->trans[2]);
  vc = rotate_ray(vc, sph);
  a = (pow(vc->x, 2.0) + pow(vc->y, 2.0) + pow(vc->z, 2.0));
  b = 2.0 * (vc->x * (params->pos_eye[0] - sph->pos[0]) + vc->y *
	     (params->pos_eye[1] - sph->pos[1]) + vc->z * (params->pos_eye[2] -
							   sph->pos[2]));
  c = SUPERCALC;
  delta = pow(b, 2.0) - (4.0 * a * c);
  vc = unrotate_ray(vc, sph);
  translation_obj(sph, -sph->trans[0], -sph->trans[1], -sph->trans[2]);
  if (delta < 0.0)
    sph->intersection.k = 0.0;
  else if (delta == 0.0)
    sph->intersection.k = (-b) / (2.0 * a);
  else
    sub_int_k(&(sph->intersection), b, delta, a);
}

void		inter_plan(t_params *params, t_3d *vc, t_objs *pl)
{
  double	test;

  translation_obj(pl, pl->trans[0], pl->trans[1], pl->trans[2]);
  vc = rotate_ray(vc, pl);
  if (vc->x == 0.0 && vc->y == 0.0 && vc->z == 0.0)
    pl->intersection.k = 0.0;
  test = -(params->pos_eye[0] * pl->pos[0] + params->pos_eye[1]
	   * pl->pos[1] + params->pos_eye[2] *
	   pl->pos[2] + pl->ray) / (pl->pos[0] * vc->x +
				    pl->pos[1] * vc->y + pl->pos[2] * vc->z);
  vc = unrotate_ray(vc, pl);
  translation_obj(pl, -pl->trans[0], -pl->trans[1], -pl->trans[2]);
  if (test < 0.0)
    pl->intersection.k = 0.0;
  else
    pl->intersection.k = test;
}

void		inter_cyl(t_params *params, t_3d *vc, t_objs *cyl)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  translation_obj(cyl, cyl->trans[0], cyl->trans[1], cyl->trans[2]);
  vc = rotate_ray(vc, cyl);
  a = (pow(vc->x, 2.0) + pow(vc->y, 2.0));
  b = 2.0 * (vc->x * (params->pos_eye[0] - cyl->pos[0]) + vc->y *
	     (params->pos_eye[1] - cyl->pos[1]));
  c = (pow(params->pos_eye[0], 2.0) + pow(params->pos_eye[1], 2.0) +
       (pow(cyl->pos[0], 2.0) + pow(cyl->pos[1], 2.0) - 2.0 *
	(cyl->pos[0] * params->pos_eye[0] + cyl->pos[1] * params->pos_eye[1]) -
	pow(cyl->ray, 2.0)));
  delta = pow(b, 2.0) - (4.0 * a * c);
  vc = unrotate_ray(vc, cyl);
  translation_obj(cyl, -cyl->trans[0], -cyl->trans[1], -cyl->trans[2]);
  if (delta < 0.0)
    cyl->intersection.k = 0.0;
  else if (delta == 0.0)
    cyl->intersection.k = (-b) / (2.0 * a);
  else
    sub_int_k(&(cyl->intersection), b, delta, a);
}

void		inter_cone(t_params *params, t_3d *vc, t_objs *cone)
{
  double	q;
  double	a;
  double	b;
  double	c;
  double	delta;

  translation_obj(cone, cone->trans[0], cone->trans[1], cone->trans[2]);
  vc = rotate_ray(vc, cone);
  q = tan(cone->ray * (M_PI / 180.0));
  a = pow(vc->x, 2.0) + pow(vc->y, 2.0) - (q * pow(vc->z, 2.0));
  b = SC_B;
  c  = SC_C;
  delta = pow(b, 2.0) - (4.0 * a * c);
   vc = unrotate_ray(vc, cone);
  translation_obj(cone, -cone->trans[0], -cone->trans[1], -cone->trans[2]);
  if (delta < 0.0)
    cone->intersection.k = 0.0;
  else if (delta == 0.0)
    cone->intersection.k = (-b) / (2.0 * a);
  else
    sub_int_k(&(cone->intersection), b, delta, a);
}
