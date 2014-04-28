/*
** rtv1.h for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:08:06 2014 grelli_t
** Last update Mon Apr 21 14:33:29 2014 grelli_t
*/

#ifndef RAYTRACEUR_H_
# define RAYTRACEUR_H_
# define CPR_MIN(x, y) (x < y ? x : y)
# define COLOR_DEFAULT (0x2FD1D4)
# define NUMBER_OBJ (4)
# define NBR_LIGHTS (4)
# define ESCAPE (65307)

typedef struct	s_dump
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*img;
  int		sizeline;
  int		bpp;
  int		endian;
  unsigned long	color;
  int		win_x;
  int		win_y;
}		t_dump;

typedef struct	s_apply
{
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
  unsigned char	r_spot;
  unsigned char	g_spot;
  unsigned char	b_spot;
  int		ret;
  int		i;
}		t_apply;

typedef struct	s_3d
{
  float		x;
  float		y;
  float		z;
  int		color;
}		t_3d;

typedef struct	s_sec
{
  float		k;
  float		p_x;
  float		p_y;
  float		p_z;
  float		x_n;
  float		y_n;
  float		z_n;
  int		color;
  float		brill;
}		t_sec;

typedef struct	s_eye
{
  float		x;
  float		y;
  float		z;
  float		angle_x;
  float		angle_y;
  float		angle_z;
}		t_eye;

typedef struct	s_obj
{
  char		type;
  float		x;
  float		y;
  float		z;
  float		r_a;
  int		color;
  float		brill;
}		t_obj;

void	free_scene(t_obj **scene, t_sec **inter, t_3d **spots);

void    incre_unsigned(unsigned char *r, unsigned char *g, unsigned char *b,
                       unsigned char *t_spot);
void	incre_unsi_int(unsigned char *g_spot, unsigned char *b_spot, int *i,
		       int *ret);
int	key_event(int keycode);
int	expose_redraw(t_dump *ptr);
float	sphere_intersection(t_eye *eye, t_3d *vc, float ray);
float	plan_intersection(t_eye *eye, t_3d *vc);
float	cyl_intersection(t_eye *eye, t_3d *vc, float ray);
float	cone_intersection(t_eye *eye, t_3d *vc, float angle);
int	fill_image(t_dump *ptr, t_eye *eye);
int	calc(t_dump *ptr, int x, int y, t_eye *eye);
int	my_pixel_put_to_image(char *img, int x, int y, t_dump *ptr);
int	do_a_thing(t_dump *ptr);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int nb);
t_obj	*define_sphere1(t_obj *sphere);
t_obj	*define_sphere2(t_obj *sphere);
t_obj	*define_sphere3(t_obj *sphere);
t_obj	*define_plan1(t_obj *plan);
t_obj	*define_plan2(t_obj *plan);
t_obj	*define_cyl(t_obj *cyl);
t_obj	*define_cone1(t_obj *cone);
void	define_spot1(t_3d *spot);
void	define_lights(t_3d **spots);
void	alt_sphere_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *sph);
void	alt_plan_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *pl);
void	alt_cyl_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *cyl);
void	alt_cone_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *cone);
void	rotate_z(t_3d *pt, float angle);
void	rotate_x(t_3d *pt, float angle);
void	rotate_y(t_3d *pt, float angle);
void	matrix_rot_z(float matrix[3][3], float angle);
void	matrix_rot_x(float matrix[3][3], float angle);
void	matrix_rot_y(float matrix[3][3], float angle);
void	trans_pt(t_3d *pt, float m[3][3]);
void	translation_point(t_3d *pt, float x_plus, float y_plus, float z_plus);
void	translation_eye(t_eye *eye, float x_plus, float y_plus, float z_plus);
void	process_k_plan(t_sec *k, t_eye *eye, t_3d *vector, t_obj *plan);
void	process_k_sphere(t_sec *k, t_eye *eye, t_3d *vector, t_obj *sphere);
void	process_k_cyl(t_sec *k, t_eye *eye, t_3d *vector, t_obj *cyl);
void	process_k_cone(t_sec *k, t_eye *eye, t_3d *vector, t_obj *cone);
int	lumos(t_3d **spot, t_sec *k, t_obj **scene);
int	apply_light(float *cos_a, t_sec *k, t_3d **spot);
int 	color_picker(t_obj **scene, t_sec **inter_array, t_3d **spot);
void	calc_inter(t_obj **scene, t_sec **inter, t_eye *eye, t_3d *vc);
void	process_k(t_obj **scene, t_sec **inter, t_eye *eye, t_3d *vc);
void	define_scene(t_obj **scene, t_sec **inter_array);
void	display_sec_array(t_sec inter_array[2]);
void	disp_scene_spec(t_obj scene[2]);
void	disp_obj_spec(t_obj *obj);
int	shadow_checking(t_3d *l, t_sec *k, t_obj **scene);
float	cone_int_shadow(t_eye *eye, t_3d *vc, t_obj *cone);
float	cyl_int_shadow(t_eye *eye, t_3d *vc, t_obj *cyl);
float	plan_int_shadow(t_eye *eye, t_3d *vc, t_obj *pl);
float	sphere_int_shadow(t_eye *eye, t_3d *vc, t_obj *sph);
int	find_object_type(t_obj *obj);

#endif /* !RAYTRACEUR_H_ */
