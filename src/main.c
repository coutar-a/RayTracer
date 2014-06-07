/*
** main.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
**
** Made by coutar_a
** Login   <coutar_a@epitech.net>
**
** Started on  Sat Feb 15 13:33:14 2014 coutar_a
** Last update Sat Jun  7 10:10:43 2014 grelli_t
*/

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "raytracer.h"

/*
** Fills up image pixel per pixel with calls to calc and pixel_put_to_image.
*/

int	fill_image(t_params *params)
{
  int	pixel;
  int	x;
  int	y;

  init_img(params->mlx_conf);
  x = 0;
  y = 0;
  my_putstr(THANGS);
  while (y != params->mlx_conf->win_y)
    {
      while (x != params->mlx_conf->win_x)
	{
	  pixel = calc(params, x, y);
	  params->mlx_conf->color =
	    mlx_get_color_value(params->mlx_conf->mlx_ptr, pixel);
	  my_pixel_put_to_image(params->mlx_conf->img, x, y, params->mlx_conf);
	  x++;
	}
      mlx_put_image_to_window(params->mlx_conf->mlx_ptr,
			      params->mlx_conf->win_ptr,
			      params->mlx_conf->img_ptr, 0, 0);
      x = 0;
      y++;
    }
  return (SUCCESS);
}

/*
** Sub-function of calc, determines LOS vector, applies eye rotations.
*/

void		sub_calc_vc(t_3d *pt, t_params *params, t_3d *vector)
{
  double	trans[3][3];

  vector->x = pt->x - params->pos_eye[0];
  vector->y = pt->y - params->pos_eye[1];
  vector->z = pt->z - params->pos_eye[2];
  matrix_rot_x(trans, params->rot_eye[0]);
  trans_pt(vector, trans);
  matrix_rot_y(trans, params->rot_eye[1]);
  trans_pt(vector, trans);
  matrix_rot_z(trans, params->rot_eye[2]);
  trans_pt(vector, trans);
}

/*
** Determines closest object on a give LOS vector, returns appropriate
** adjusted-for-light-values color of said pixel through
** lumos or default color.
*/

int		color_picker(t_params *params)
{
  double	swap_k;
  int		j;
  int		i;
  int		color;

  swap_k = params->objs[0].intersection.k;
  j = 0;
  i = 0;
  while (i != params->nb_objs)
    {
      if ((params->objs[i].intersection.k < swap_k &&
	   params->objs[i].intersection.k != 0.0) ||
	  (swap_k == 0.0 && params->objs[i].intersection.k > 0.0))
	{
	  swap_k = params->objs[i].intersection.k;
	  j = i;
	}
      i++;
    }
  if (swap_k != 0.0)
    return (lumos(params, &(params->objs[j])));
  return (COLOR_DEFAULT);
}

/*
** Inits object and intersection arrays,
** calculates both 3D coords and LOS vector for each FOV point.
** Then sends those to the intersection functions.
** Finally returns return value of color picker.
*/

int		calc(t_params *params, int x, int y)
{
  t_3d		point;
  t_3d		vector;
  int		color;

  sub_calc_pt(params, &point, x, y);
  sub_calc_vc(&point, params, &vector);
  calc_inter(params, &vector);
  process_k(params, &vector);
  color = color_picker(params);
  return (color);
}

/*
** Main function. Inits eye pos and orientation,
** as well as required components for MLX use.
** Also calls in expose and key functions + MLX loop.
*/

int		main(int argc, char **argv)
{
  t_params	params;

  if ((conf_file(argc, argv, &params) == ERROR))
    return (ERROR);
  if ((params.mlx_conf->mlx_ptr = mlx_init()) == NULL)
    return (ERROR);
  printf("roation objet 0 : angle x = %lf angle = %lf angle z = %lf\n", params.objs[0].rot[0], params.objs[0].rot[1], params.objs[0].rot[2]);
  params.mlx_conf->win_ptr = mlx_new_window(params.mlx_conf->mlx_ptr,
					    params.mlx_conf->win_x,
					    params.mlx_conf->win_y, TITLE);
  params.mlx_conf->img_ptr = mlx_new_image(params.mlx_conf->mlx_ptr,
					   params.mlx_conf->win_x,
					   params.mlx_conf->win_y);
  fill_image(&params);
  my_putstr(DISP_MSG);
  mlx_key_hook(params.mlx_conf->win_ptr, key_event, 0);
  mlx_expose_hook(params.mlx_conf->win_ptr, expose_redraw, params.mlx_conf);
  mlx_loop(params.mlx_conf->mlx_ptr);
  return (SUCCESS);
}
