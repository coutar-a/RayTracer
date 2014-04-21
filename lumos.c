/*
** lumos.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:06:33 2014 grelli_t
** Last update Mon Apr 21 10:44:52 2014 grelli_t
*/

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "rtv1.h"

/*
** The following process_k functions calculate both normal vector and 3d coords
** for the intersection point on each type of object.
*/

void	process_k_plan(t_sec *k, t_eye *eye, t_3d *vector, t_obj *plan)
{
  k->p_x = eye->x + k->k * vector->x;
  k->p_y = eye->y + k->k * vector->y;
  k->p_z = eye->z + k->k * vector->z;
  k->x_n = plan->x;
  k->y_n = plan->y;
  k->z_n = plan->z;
  k->color = plan->color;
  k->brill = plan->brill;
}

void	process_k_sphere(t_sec *k, t_eye *eye, t_3d *vector, t_obj *sphere)
{
  k->p_x = eye->x + k->k * vector->x;
  k->p_y = eye->y + k->k * vector->y;
  k->p_z = eye->z + k->k * vector->z;
  k->x_n = k->p_x - sphere->x;
  k->y_n = k->p_y - sphere->y;
  k->z_n = k->p_z - sphere->z;
  k->color = sphere->color;
  k->brill = sphere->brill;
}

void	process_k_cyl(t_sec *k, t_eye *eye, t_3d *vector, t_obj *cyl)
{
  k->p_x = eye->x + k->k * vector->x;
  k->p_y = eye->y + k->k * vector->y;
  k->p_z = eye->z + k->k * vector->z;
  k->x_n = k->p_x - cyl->x;
  k->y_n = k->p_y - cyl->y;
  k->z_n = 0;
  k->color = cyl->color;
  k->brill = cyl->brill;
}

void	process_k_cone(t_sec *k, t_eye *eye, t_3d *vector, t_obj *cone)
{
  k->p_x = eye->x + k->k * vector->x;
  k->p_y = eye->y + k->k * vector->y;
  k->p_z = eye->z + k->k * vector->z;
  k->x_n = k->p_x - cone->x;
  k->y_n = k->p_y - cone->y;
  k->z_n = -(tanf(cone->r_a * (M_PI / 180.0))) * k->p_z - cone->z;
  k->color = cone->color;
  k->brill = cone->brill;
}

/*
** Determines light coefficient for each pixel.
** Also calls in shadow_checking for shadows.
*/

int	lumos(t_3d **spot, t_sec *k, t_obj **scene)
{
  t_3d	l;
  float	norm_l;
  float	norm_n;
  float	scal;
  float	cos_a[NBR_LIGHTS];
  int 	i;

  i = 0;
  while (i != NBR_LIGHTS)
    {
      l.x = spot[i]->x - k->p_x;
      l.y = spot[i]->y - k->p_y;
      l.z = spot[i]->z - k->p_z;
      scal = l.x * k->x_n + l.y * k->y_n + l.z * k->z_n;
      norm_l = sqrtf(powf(l.x, 2.0) + powf(l.y, 2.0) + powf(l.z, 2.0));
      norm_n = sqrtf(powf(k->x_n, 2.0) + powf(k->y_n, 2.0) + powf(k->z_n, 2.0));
      cos_a[i] = scal / (norm_l * norm_n);
      if (cos_a[i] < 0.0)
      	cos_a[i] = 0.0;
      if ((shadow_checking(&l, k, scene)) == 1)
      	cos_a[i] = cos_a[i] / 2;
      i++;
    }
  return (apply_light(cos_a, k, spot));
}
