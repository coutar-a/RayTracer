/*
** raytracer.h for rt in /home/cheval_2/git/raytracer/include
**
** Made by
** Login   <cheval_2@epitech.net>
**
** Started on  Sat May 31 15:43:54 2014
** Last update Thu Jun  5 14:41:42 2014 grelli_t
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
# define CYLINDER	(4)

# define YES		(1)
# define NO		(0)

typedef struct		s_sec
{
  double		k;
  double		p_x;
  double		p_y;
  double		p_z;
  double		x_n;
  double		y_n;
  double		z_n;
}			t_sec;

typedef struct		s_objs
{
  t_sec			intersection;
  double		pos[3];
  double		rot[3];
  double		ray;
  double		angle;
  double		height;
  double		shine;
  double		transparency;
  int			color;
  int			color_checkerboard;
  int			checkerboard;
  int			negative;
  int			texture;
  int			type;
  int			size_checkerboard;
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
  double		x;
  double	      	y;
  double	       	z;
  int		       	color;
}			t_3d;

/*
** CONF
*/

void		disp_params(t_params *);
int		init_spots(t_params *, char *, int);
int		fill_spot_pos(t_params *, char *, int);
int		fill_spot_color(t_params *, char *, int);
int		fill_rot(t_params *, char *, int);
int		fill_pos(t_params *, char *, int);
int		fill_size_checkerboard(t_params *, char *, int);
int		fill_checkerboard(t_params *, char *, int);
int		fill_color_checkerboard(t_params *, char *, int);
int		fill_color(t_params *, char *, int);
int		fill_ray(t_params *, char *, int);
int		fill_texture(t_params *, char *, int);
int		fill_negative(t_params *, char *, int);
int		fill_transparency(t_params *, char *, int);
int		fill_angle(t_params *, char *, int);
int		fill_height(t_params *, char *, int);
int		fill_window_in_params_height(t_params *, char *);
int		fill_window_in_params_lenght(t_params *, char *);
int		fill_window_in_params_pos_eye(t_params *, char *);
int		fill_window_in_params(t_params *, char **, int *);
int		fill_objects(t_params *, char **, int *);
int		fill_spots(t_params *, char **, int *);
int		fill_keywords(t_params *, char **, int *);
int		fill_window(t_params *, char **, int *);
int		check_file(char **, t_params *);
int		check_error_read_file_part(int *, int *, char *);
char		*check_error_read_file(int *, int *, char *);
char		*read_file(char *, t_params *);

/*
** LIB
*/

int		my_strlen(char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_pixel_put_to_image(char *, int, int, t_dump *);
int		show_tab(char **);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_error(char *);
char		**my_str_to_wordtab(char *, char);
char		*my_epur(char *);
char		*epur(char *);
void		char_space(char *);
void		aff_tab(char **);
int		my_putchar(char);
int		my_putstr(char *);
void		my_put_nbr(int);
void		free_tab(char **);

/*
** SRC
*/

int		key_event(int keycode);
int		expose_redraw(t_dump *ptr);
void		process_k(t_params *params, t_3d *vc);
void		process_k_plan(t_params *params, t_3d *vc, t_objs *plan);
void		process_k_sphere(t_params *params, t_3d *vc, t_objs *sph);
void		process_k_cyl(t_params *params, t_3d *vc, t_objs *cyl);
void		process_k_cone( t_params *params, t_3d *vc, t_objs *cone);
void		calc_inter(t_params *params, t_3d *vc);
void		sub_int_k(t_sec *k, double b, double delta, double a);
void		inter_sph(t_params *params, t_3d *vc, t_objs *sph);
void		inter_plan(t_params *params, t_3d *vc, t_objs *pl);
void		inter_cyl(t_params *params, t_3d *vc, t_objs *cyl);
void		inter_cone(t_params *params, t_3d *vc, t_objs *cone);
void		incre_unsigned(t_apply *apply);
int		apply_light(t_params *params, t_objs *obj, double cos_a[]);
int		lumos(t_params *params, t_objs *obj);
void		matrix_rot_z(float matrix[][3], float angle);
void		matrix_rot_x(float matrix[][3], float angle);
void		matrix_rot_y(float matrix[][3], float angle);
void		trans_pt(t_3d *pt, float m[][3]);
void		mult_matrix(float m1[][3], float m2[][3]);

#endif /* !RAYTRACER_H_ */

