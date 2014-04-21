/*
** scene_stuff.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:08:15 2014 grelli_t
** Last update Mon Apr 21 10:08:16 2014 grelli_t
*/

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "rtv1.h"

/*
** Hardcoded scene definition. To be deprecated.
*/

void		define_scene(t_obj **scene, t_sec **inter_array)
{
  scene[0] = define_plan1(scene[0]);
  scene[1] = define_sphere1(scene[1]);
  scene[2] = define_cone1(scene[2]);
  scene[3] = define_cyl(scene[3]);
  inter_array[0] = malloc(sizeof(t_sec));
  inter_array[1] = malloc(sizeof(t_sec));
  inter_array[2] = malloc(sizeof(t_sec));
  inter_array[3] = malloc(sizeof(t_sec));
}

/*
** Checks obj struct for object type.
*/

int		find_object_type(t_obj *obj)
{
  if (obj->type == 's')
    return (0);
  if (obj->type == 'c')
    return (1);
  if (obj->type == 'k')
    return (2);
  if (obj->type == 'p')
    return (3);
  return (-1);
}

/*
** Intersection function array.
*/

void		calc_inter(t_obj **scene, t_sec **inter, t_eye *eye, t_3d *vc)
{
  int		i;
  int		test;
  void		(*inter_array[4])(t_sec*, t_eye*, t_3d*, t_obj*);

  inter_array[0] = &alt_sphere_int;
  inter_array[1] = &alt_cyl_int;
  inter_array[2] = &alt_cone_int;
  inter_array[3] = &alt_plan_int;
  i = 0;
  while (i != NUMBER_OBJ)
    {
      test = find_object_type(scene[i]);
      inter_array[test](inter[i], eye, vc, scene[i]);
      i++;
    }
}

/*
** intersection point coord calc array.
*/

void		process_k(t_obj **scene, t_sec **inter, t_eye *eye, t_3d *vc)
{
  int		i;
  int		test;
  void		(*process_array[4])(t_sec*, t_eye*, t_3d*, t_obj*);

  process_array[0] = &process_k_sphere;
  process_array[1] = &process_k_cyl;
  process_array[2] = &process_k_cone;
  process_array[3] = &process_k_plan;
  i = 0;
  while (i != NUMBER_OBJ)
    {
      test = find_object_type(scene[i]);
      process_array[test](inter[i], eye, vc, scene[i]);
      i++;
    }
}
