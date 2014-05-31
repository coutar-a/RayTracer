/*
** spot.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:09:04 2014 grelli_t
** Last update Mon Apr 21 15:06:50 2014 grelli_t
*/

#include <stdio.h>
#include <mlx.h>
#include "raytracer.h"

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
