/*
** rtv1.h for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
**
** Made by grelli_t
** Login   <grelli_t@epitech.net>
**
** Started on  Mon Apr 21 10:08:06 2014 grelli_t
** Last update Sat May 31 14:30:06 2014 grelli_t
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# define CPR_MIN(x, y)	(x < y ? x : y)
# define COLOR_DEFAULT	(0x2FD1D4)
# define ESCAPE		(65307)
# define ERROR		(-1)
# define SUCCESS	(1)

# define CONE		(1)
# define PLAN		(2)
# define SPHERE		(3)
# define CYLINDRE	(4)

typedef struct		s_sec
{
  float			k;
  float			p_x;
  float			p_y;
  float			p_z;
  float			x_n;
  float			y_n;
  float			z_n;
}			t_sec;

typedef struct		s_objs
{
  t_sec			intersection;
  double		pos[3];
  double		rot[3];
  double		ray;
  double		angle;
  double		shine;
  double		transparency;
  int			color;
  int			negative;
  int			texture;
  int			type;
}			t_objs;

typedef struct		s_spots
{
  double		pos[3];
  double		rot[3];
  double		ray;
  double		angle;
  double		shine;
  double		transparency;
  int			color;
  int			negative;
  int			texture;
}			t_spots;


typedef struct		s_dump
{
  unsigned long		color;
  void			*mlx_ptr;
  void			*win_ptr;
  void			*img_ptr;
  char			*img;
  int			sizeline;
  int			bpp;
  int			endian;
  int			win_x;
  int			win_y;
}			t_dump;

typedef struct		s_params
{
  double		pos_eye[3];
  double		rot_eye[3];
  int			nb_objs;
  int			nb_spots;
  t_spots		*spots;
  t_objs		*objs;
  t_dump		*mlx_conf;
}			t_params;

typedef struct	s_fill
{
  char		*line;
  void		(*ptr)(t_params *params, char *tab);
}		t_fill;


typedef struct		s_apply
{
  unsigned char		r;
  unsigned char		g;
  unsigned char		b;
  unsigned char		r_spot;
  unsigned char		g_spot;
  unsigned char		b_spot;
  int			ret;
  int			i;
}			t_apply;

typedef struct		s_3d
{
  float			x;
  float			y;
  float			z;
  int			color;
}			t_3d;

void	fill_sphere_pos(t_params *params, char *line);
void	fill_sphere_color(t_params *params, char *line);
void	fill_sphere_ray(t_params *params, char *line);
void	fill_sphere_texture(t_params *params, char *line);
void	fill_sphere_negative(t_params *params, char *line);
void	fill_sphere_transparency(t_params *params, char *line);
void	fill_sphere_angle(t_params *params, char *line);

#endif /* !RAYTRACER_H_ */
