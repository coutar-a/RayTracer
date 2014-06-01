/*
** intersection_computing.c for raytracer in /home/coutar_a/rendu/raytracer
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat May 31 14:03:08 2014 coutar_a
** Last update Sun Jun  1 16:13:59 2014 coutar_a
*/

#include "raytracer.h"

void		process_k(t_params *params, t_3d *vc)
{
  int		obj;
  int		i;
  void		(*process_array[4])(t_params*, t_3d*, t_objs*);

  process_array[0] = &process_k_cone;
  process_array[1] = &process_k_plan;
  process_array[2] = &process_k_sphere;
  process_array[3] = &process_k_cyl;
  i = 0;
  printf("number of objects = %d\n", params->nb_objs);
  while (i < params->nb_objs)
    {
      obj = params->objs[i].type - 1;
      process_array[obj](params, vc, &(params->objs[i]));
      i++;
    }
}

void		calc_inter(t_params *params, t_3d *vc)
{
  int		obj;
  int		i;
  void		(*inter_array[4])(t_params*, t_3d*, t_objs*);

  inter_array[0] = &inter_cone;
  inter_array[1] = &inter_plan;
  inter_array[2] = &inter_sph;
  inter_array[3] = &inter_cyl;
  i = 0;
  printf("number of objects = %d\n", params->nb_objs);
  while (i < params->nb_objs)
    {
      obj = params->objs[i].type - 1;
      inter_array[obj](params, vc, &(params->objs[i]));
      i++;
    }
}
