/*
** main.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
**
** Made by coutar_a
** Login   <coutar_a@epitech.net>
**
** Started on  Sat Feb 15 13:33:14 2014 coutar_a
** Last update Mon Apr 21 15:32:16 2014 grelli_t
*/

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "raytracer.h"

/*
** Fills up image pixel per pixel with calls to calc and pixel_put_to_image.
*/

int	fill_image(t_dump *ptr, t_eye *eye)
{
  int	pixel;
  int	x;
  int	y;

  do_a_thing(ptr);
  x = 0;
  y = 0;
  my_putstr("Doin thangs...\n");
  while (y != ptr->win_y)
    {
      while (x != ptr->win_x)
	{
	  if (y == 0 && x == 1)
	    translation_eye(eye, -1000.0, 0.0, 90.0);
	  pixel = calc(ptr, x, y, eye);
	  ptr->color = mlx_get_color_value(ptr->mlx_ptr, pixel);
	  my_pixel_put_to_image(ptr->img, x, y, ptr);
	  x++;
	}
      x = 0;
      y++;
    }
  return (0);
}

/*
** Sub-function of calc, determines LOS vector, applies eye rotations.
*/

void	sub_calc_vc(t_3d *pt, t_eye *eye, t_3d *vector)
{
  float	trans[3][3];

  vector->x = pt->x - eye->x;
  vector->y = pt->y - eye->y;
  vector->z = pt->z - eye->z;
  matrix_rot_x(trans, eye->angle_x);
  trans_pt(vector, trans);
  matrix_rot_y(trans, eye->angle_y);
  trans_pt(vector, trans);
  matrix_rot_z(trans, eye->angle_z);
  trans_pt(vector, trans);
}

/*
** Determines closest object on a give LOS vector, returns appropriate
** adjusted-for-light-values color of said pixel through
** lumos or default color.
*/

int	color_picker(t_obj **scene, t_sec **inter_array, t_3d **spot)
{
  float	swap_k;
  int	obj;
  int	i;

  swap_k = inter_array[0]->k;
  obj = 0;
  i = 0;
  while (i != NUMBER_OBJ)
    {
      if ((inter_array[i]->k < swap_k && inter_array[i]->k != 0.0) ||
	  (swap_k == 0.0 && inter_array[i]->k > 0.0))
	{
	  swap_k = inter_array[i]->k;
	  obj = i;
	}
      i++;
    }
  if (swap_k != 0.0)
    return (lumos(spot, inter_array[obj], scene));
  return (COLOR_DEFAULT);
}

/*
** Inits object and intersection arrays,
** calculates both 3D coords and LOS vector for each FOV point.
** Then sends those to the intersection functions.
** Finally returns return value of color picker.
*/

int		calc(t_dump *ptr,int x, int y, t_eye *eye)
{
  t_3d		point;
  t_3d		vector;
  static t_obj	**scene;
  static t_sec	**inter_array;
  static t_3d	**spots;
  int		color;

  sub_calc_pt(ptr, &point, x, y);
  sub_calc_vc(&point, eye, &vector);
  if (x == 0 &&  y == 0)
    {
      scene = malloc((sizeof(t_obj*)) * NUMBER_OBJ);
      inter_array = malloc((sizeof(t_sec*)) * NUMBER_OBJ);
      spots = malloc((sizeof(t_3d*) * NBR_LIGHTS));
      define_scene(scene, inter_array);
      define_lights(spots);
    }
  calc_inter(scene, inter_array, eye, &vector);
  process_k(scene, inter_array, eye, &vector);
  color = color_picker(scene, inter_array, spots);
  if (x == ptr->win_x - 1 && y == ptr->win_y - 1)
    free_scene(scene, inter_array, spots);
  return (color);
}

/*
** Main function. Inits eye pos and orientation,
** as well as required components for MLX use.
** Also calls in expose and key functions + MLX loop.
*/

int		main(void)
{
  t_dump	ptr;
  t_eye		eye;

  eye.x = 0.0;
  eye.y = 0.0;
  eye.z = 0.0;
  eye.angle_x = 0.0;
  eye.angle_y = 0.0;
  eye.angle_z = 0.0;
  ptr.win_x = 1400;
  ptr.win_y = 768;
  if ((ptr.mlx_ptr = mlx_init()) == NULL)
    return (0);
  ptr.win_ptr = mlx_new_window(ptr.mlx_ptr,
			       ptr.win_x, ptr.win_y, "trace them rays boy");
  ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, ptr.win_x, ptr.win_y);
  fill_image(&ptr, &eye);
  mlx_key_hook(ptr.win_ptr, key_event, 0);
  mlx_expose_hook(ptr.win_ptr, expose_redraw, &ptr);
  mlx_loop(ptr.mlx_ptr);
  return (0);
}
