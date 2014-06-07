/*
** normal_computing.c for raytracer in /home/coutar_a/rendu/raytracer
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat May 31 14:20:53 2014 coutar_a
** Last update Fri Jun  6 16:48:09 2014 coutar_a
*/

#include <math.h>
#include "raytracer.h"

void	process_k_plan(t_params *params, t_3d *vc, t_objs *plan)
{
  if (plan->intersection.k == 0.0)
    {
      plan->intersection.p_x = 0.0;
      plan->intersection.p_y = 0.0;
      plan->intersection.p_z = 0.0;
    }
  else
    {
      plan->intersection.p_x = params->pos_eye[0] + plan->intersection.k * vc->x;
      plan->intersection.p_y = params->pos_eye[1] + plan->intersection.k * vc->y;
      plan->intersection.p_z = params->pos_eye[2] + plan->intersection.k * vc->z;
    }
  //printf("intersection p x = %f, p y = %f, p z = %f\n", plan->intersection.p_x, plan->intersection.p_y, plan->intersection.p_z);
  plan->intersection.x_n = plan->pos[0];
  plan->intersection.y_n = plan->pos[1];
  plan->intersection.z_n = plan->pos[2];
}

void	process_k_sphere(t_params *params, t_3d *vc, t_objs *sph)
{
  if (sph->intersection.k == 0.0)
    {
      sph->intersection.p_x = 0.0;
      sph->intersection.p_y = 0.0;
      sph->intersection.p_z = 0.0;
    }
  else
    {
      sph->intersection.p_x = params->pos_eye[0] + sph->intersection.k * vc->x;
      sph->intersection.p_y = params->pos_eye[1] + sph->intersection.k * vc->y;
      sph->intersection.p_z = params->pos_eye[2] + sph->intersection.k * vc->z;
    }
  //printf("intersection p x = %f, p y = %f, p z = %f\n", sph->intersection.p_x, sph->intersection.p_y, sph->intersection.p_z);
  sph->intersection.x_n = sph->intersection.p_x - sph->pos[0];
  sph->intersection.y_n = sph->intersection.p_y - sph->pos[1];
  sph->intersection.z_n = sph->intersection.p_z - sph->pos[2];
}

void	process_k_cyl(t_params *params, t_3d *vc, t_objs *cyl)
{
  if (cyl->intersection.k == 0.0)
    {
      cyl->intersection.p_x = 0.0;
      cyl->intersection.p_y = 0.0;
      cyl->intersection.p_z = 0.0;
    }
  else
    {
      cyl->intersection.p_x = params->pos_eye[0] + cyl->intersection.k * vc->x;
      cyl->intersection.p_y = params->pos_eye[1] + cyl->intersection.k * vc->y;
      cyl->intersection.p_z = params->pos_eye[2] + cyl->intersection.k * vc->z;
    }
  //printf("intersection p x = %f, p y = %f, p z = %f\n", cyl->intersection.p_x, cyl->intersection.p_y, cyl->intersection.p_z);
  cyl->intersection.x_n = cyl->intersection.p_x - cyl->pos[0];
  cyl->intersection.y_n = cyl->intersection.p_y - cyl->pos[1];
  cyl->intersection.z_n = 0;
}

void	process_k_cone( t_params *params, t_3d *vc, t_objs *cone)
{
  if (cone->intersection.k == 0.0)
    {
      cone->intersection.p_x = 0.0;
      cone->intersection.p_y = 0.0;
      cone->intersection.p_z = 0.0;
    }
  else
    {
      cone->intersection.p_x = params->pos_eye[0] + cone->intersection.k * vc->x;
      cone->intersection.p_y = params->pos_eye[1] + cone->intersection.k * vc->y;
      cone->intersection.p_z = params->pos_eye[2] + cone->intersection.k * vc->z;
    }
  //printf("intersection p x = %f, p y = %f, p z = %f\n", cone->intersection.p_x, cone->intersection.p_y, cone->intersection.p_z);
  cone->intersection.x_n = cone->intersection.p_x - cone->pos[0];
  cone->intersection.y_n = cone->intersection.p_y - cone->pos[1];
  cone->intersection.z_n = -(tan(cone->ray * (M_PI / 180.0))) *
    cone->intersection.p_z - cone->pos[2];
}
