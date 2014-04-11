/*
** spot.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Mon Mar 10 14:53:47 2014 coutar_a
** Last update Sat Mar 15 17:38:24 2014 coutar_a
*/

#include <stdio.h>
#include <mlx.h>
#include "rtv1.h"

/*
** Light spot coords, etc...
*/

void	define_spot1(t_3d *spot)
{
  spot->x = -220.0;
  spot->y = 75.0;
  spot->z = 25.0;
  spot->color = 0xA9EEAE;
}

void	define_spot2(t_3d *spot)
{
  spot->x = -220.0;
  spot->y = -75.0;
  spot->z = 25.0;
  spot->color = 0xA9EEAE;
}

void	define_spot3(t_3d *spot)
{
  spot->x = 220.0;
  spot->y = -75.0;
  spot->z = 25.0;
  spot->color = 0xA9EEAE;
}

void	define_spot4(t_3d *spot)
{
  spot->x = 220.0;
  spot->y = 120.0;
  spot->z = 25.0;
  spot->color = 0xA9EEAE;
}

void	define_spot5(t_3d *spot)
{
  spot->x = -220.0;
  spot->y = 0.0;
  spot->z = 25.0;
  spot->color = 0xA9EEAE;
}