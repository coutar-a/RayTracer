/*
** raytracer.h for rt in /home/cheval_2/git/raytracer/include
**
** Made by
** Login   <cheval_2@epitech.net>
**
** Started on  Sat May 31 15:43:54 2014
** Last update Sun Jun  1 09:40:52 2014 
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# define CPR_MIN(x, y)	(x < y ? x : y)
# define DRK_CHK(x)	(x < 0.0 ? 0.0 : x)
# define NTS_CHK(x, y)	(x * y > 1.0 ? 1.0 : x * y)
# define NEG(x)		(255 - x)
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
  int		(*ptr)(t_params *params, char *tab, int j);
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

int		fill_spot_pos(t_params *, char *, int);
int		fill_spot_color(t_params *, char *, int);
void		fill_sphere_pos(t_params *, char *);
void		fill_sphere_color(t_params *, char *);
void		fill_sphere_ray(t_params *, char *);
void		fill_sphere_texture(t_params *, char *);
void		fill_sphere_negative(t_params *, char *);
void		fill_sphere_transparency(t_params *, char *);
void		fill_sphere_angle(t_params *, char *);

#endif /* !RAYTRACER_H_ */
