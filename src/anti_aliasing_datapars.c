/*
** anti_aliasing_datapars.c for raytracer in /home/jamme-_c/rendu/raytracer_func/anti_aliasing/src/anti_aliasing
** 
** Made by jamme-_c
** Login   <jamme-_c@epitech.net>
** 
** Started on  Thu Jun  5 16:20:24 2014 jamme-_c
** Last update Sun Jun  8 15:55:44 2014 jamme-_c
*/

#include "anti_aliasing.h"
#include "raytracer.h"

int	microparser(char **av)
{
  if (av[1] != 0)
    if (my_strcmp(av[1], "-a") == 0)
      return (1);
  return (0);

}

void		check_pixel(int x, int y, char *data, int win)
{
  int		pos[9];
  t_color	color[9];

  init_pos(x, y, win, &pos);
  init_color(&color, data, pos);
  data[pos[CURRENT]] = process_color_red(&color);
  data[pos[CURRENT] + 1] = process_color_green(&color);
  data[pos[CURRENT] + 2] = process_color_blue(&color);
}

int	anti_aliasing_datapars(int win_x, int win_y, char *data, int sizeline)
{
  int	i;
  int	x;
  int	y;

  my_putstr ("\n\n --- Anti aliasing 0.5 alpha ---\n\n");
  x = 0;
  y = 0;
  while (++y < win_y)
    {
      while (++x < win_x)
	check_pixel(x, y, data, win_x);
      x = 0;
    }
  return (0);
}
