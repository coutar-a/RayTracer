/*
** anti_aliasing.h for raytracer in /home/jamme-_c/rendu/raytracer_func/anti_aliasing/src/
** 
** Made by jamme-_c
** Login   <jamme-_c@epitech.net>
** 
** Started on  Thu Jun  5 16:21:18 2014 jamme-_c
** Last update Sun Jun  8 11:18:34 2014 jamme-_c
*/

#ifndef ANTI_ALIASING_H_
# define ANTI_ALIASING_H_
# define CURRENT 4

typedef struct	s_color
{
  int		r;
  int		g;
  int		b;
}		t_color;

int	microparser(char **av);
void	check_pixel(int x, int y, char *data, int sizeline);
void	init_color(t_color (*color)[], char *data, int pos[]);
int	anti_aliasing_datapars(int win_x, int win_y, char *data, int sizeline);
void	init_pos(int x, int y, int sizeline, int (*pos)[]);
int	process_color_blue(t_color (*color)[]);
int	process_color_red(t_color (*color)[]);
int	process_color_green(t_color (*color)[]);


#endif  /* !ANTI_ALIASING */
