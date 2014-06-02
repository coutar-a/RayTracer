/*
** lumos.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:06:33 2014 grelli_t
** Last update Mon Jun  2 14:29:02 2014 grelli_t
*/

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "raytracer.h"

/*
** Determines light coefficient for each pixel.
** Also calls in shadow_checking for shadows.
*/

int		lumos(t_params *params, t_objs *obj)
{
  t_3d		l;
  double	norm_l;
  double	norm_n;
  double	scal;
  double	cos_a[params->nb_spots]; // à vérifier ????
  int		i;

  i = 0;
  printf("NB_SPOTS === \n", params->nb_spots);
  while (i != params->nb_spots)
    {
      l.x = params->spots[i].pos[0] - obj->intersection.p_x;
      l.y = params->spots[i].pos[1] - obj->intersection.p_y;
      l.z = params->spots[i].pos[2] - obj->intersection.p_z;
      scal = l.x * obj->intersection.x_n + l.y * obj->intersection.y_n + l.z *
	obj->intersection.z_n;
      norm_l = sqrt(pow(l.x, 2.0) + pow(l.y, 2.0) + pow(l.z, 2.0));
      norm_n = sqrt(pow(obj->intersection.x_n, 2.0) +
		    pow(obj->intersection.y_n, 2.0) + pow(obj->intersection.z_n,
							  2.0));
      cos_a[i] = DRK_CHK((scal / (norm_l * norm_n)));
      if ((shadow_checking(&l, obj->intersection, params->objs,
			   params->nb_objs)) == 1)
      	cos_a[i] /= 2;
      i++;
    }
  return (apply_light(params, obj, cos_a));
}

/*int	lumos(t_3d *spot, t_sec *k, t_obj **scene)
  {
    t_3d	l;
    double	norm_l;
    double	norm_n;
    double	scal;
    double	cos_a;

    l.x = spot->x - k->p_x;
    l.y = spot->y - k->p_y;
    l.z = spot->z - k->p_z;
    scal = l.x * k->x_n + l.y * k->y_n + l.z * k->z_n;
    norm_l = sqrtf(powf(l.x, 2.0) + powf(l.y, 2.0) + powf(l.z, 2.0));
    norm_n = sqrtf(powf(k->x_n, 2.0) + powf(k->y_n, 2.0) + powf(k->z_n, 2.0));
    cos_a = scal / (norm_l * norm_n);
    if (cos_a < 0.0)
      cos_a = 0.0;
    if ((shadow_checking(&l, k, scene)) == 1)
      cos_a = cos_a / 2;
    return (apply_light(cos_a, k, spot));
  }*/
