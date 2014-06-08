/*
** initializing_anti.c for raytracer in /home/jamme-_c/rendu/raytracer_func/anti_aliasing/src/anti_aliasing
** 
** Made by jamme-_c
** Login   <jamme-_c@epitech.net>
** 
** Started on  Sat Jun  7 17:26:04 2014 jamme-_c
** Last update Sun Jun  8 11:04:29 2014 jamme-_c
*/

#include "anti_aliasing.h"

int	process_color_red(t_color (*color)[])
{
  int	i;
  int	ret;
  int	sav;

  sav = 0;
  ret = 0;
  i = -1;
  while (++i < 9)
    {
      sav = ret;
      ret = sav + (*color)[i].r;
    }
  return (ret / 9);
}

int	process_color_green(t_color (*color)[])
{
  int	i;
  int	ret;
  int	sav;

  sav = 0;
  ret = 0;
  i = -1;
  while (++i < 9)
    {
      sav = ret;
      ret = ret + (*color)[i].g;
    }
  return (ret / 9);
}

int	process_color_blue(t_color (*color)[])
{
  int	i;
  int	ret;
  int	sav;

  sav = 0;
  ret = 0;
  i = -1;
  while (++i < 9)
    {
      sav = ret;
      ret = ret + (*color)[i].b;
    }
  return (ret / 9);
}

void	init_color(t_color (*color)[], char *data, int pos[])
{
  int	i;
  int	k;

  k = 0;
  i = -1;
  while (++i < 9)
    {
      (*color)[i].r = data[pos[k]];
      (*color)[i].g = data[pos[k] + 1];
      (*color)[i].b = data[pos[k] + 2];
      ++k;
    }
}

void	init_pos(int x, int y, int sizeline, int (*pos)[])
{
  (((*pos))[4]) = y * sizeline * 4;
  ((*pos)[4]) += (x * 4);
  ((*pos)[1]) = ((*pos)[4]) - (sizeline * 4);
  ((*pos)[0]) = ((*pos)[1]) - 4;
  ((*pos)[2]) = ((*pos)[1]) + 4;
  ((*pos)[3]) = ((*pos)[4]) - 4;
  ((*pos)[5]) = ((*pos)[4]) + 4;
  ((*pos)[7]) = ((*pos)[4]) + (sizeline * 4);
  ((*pos)[6]) = ((*pos)[7]) - 4;
  ((*pos)[8]) = ((*pos)[7]) + 4;
}
