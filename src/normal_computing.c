/*
** normal_computing.c for raytracer in /home/coutar_a/rendu/raytracer
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat May 31 14:20:53 2014 coutar_a
** Last update Sat May 31 15:35:26 2014 coutar_a
*/

#include <math.h>
#include "raytracer.h"

void	process_k_plan(t_params *params, t_3d *vc, t_objs *plan)
{
  plan->intersection.p_x = params->pos_eye[0] + plan->intersection.k * vc->x;
  plan->intersection.p_y = params->pos_eye[1] + plan->intersection.k * vc->y;
  plan->intersection.p_z = params->pos_eye[2] + plan->intersection.k * vc->z;
  plan->intersection.x_n = plan->pos[0];
  plan->intersection.y_n = plan->pos[1];
  plan->intersection.z_n = plan->pos[2];
}

void	process_k_sphere(t_params *params, t_3d *vc, t_objs *sph)
{
  sph->intersection.p_x = params->pos_eye[0] + sph->intersection.k * vc->x;
  sph->intersection.p_y = params->pos_eye[1] + sph->intersection.k * vc->y;
  sph->intersection.p_z = params->pos_eye[2] + sph->intersection.k * vc->z;
  sph->intersection.x_n = sph->intersection.p_x - sphere->pos[0];
  sph->intersection.y_n = sph->intersection.p_y - sphere->pos[1];
  sph->intersection.z_n = sph->intersection.p_z - sphere->pos[2];
}

void	process_k_cyl(t_params *params, t_3d *vc, t_objs *cyl)
{
  cyl->intersection.p_x = params->pos_eye[0] + cyl->intersection.k * vc->x;
  cyl->intersection.p_y = params->pos_eye[1] + cyl->intersection.k * vc->y;
  cyl->intersection.p_z = params->pos_eye[2] + cyl->intersection.k * vc->z;
  cyl->intersection.x_n = cyl->intersection.p_x - cyl->pos[0];
  cyl->intersection.y_n = cyl->intersection.p_y - cyl->pos[1];
  cyl->intersection.z_n = 0;
}

void	process_k_cone( t_params *params, t_3d *vc, t_objs *cone)
{
  cone->intersection.p_x = params->pos_eye[0] + cone->intersection.k * vc->x;
  cone->intersection.p_y = params->pos_eye[1] + cone->intersection.k * vc->y;
  cone->intersection.p_z = params->pos_eye[2] + cone->intersection.k * vc->z;
  cone->intersection.x_n = cone->intersection.p_x - cone->pos[0];
  cone->intersection.y_n = cone->intersection.p_y - cone->pos[1];
  cone->intersection.z_n = -(tan(cone->r_a * (M_PI / 180.0))) *
    cone->intersection.p_z - cone->pos[2];
}
