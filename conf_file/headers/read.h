#ifndef READ_H_
# define READ_H_
# define ERROR (-1)
# define SUCCESS (1)

# include "raytracer.h"

int	fill_window_in_params_height(t_params *params, char *tab);
int	fill_window_in_params_lenght(t_params *params, char *tab);
int	fill_window_in_params_pos_eye(t_params *params, char *tab);
char	**my_str_to_wordtab(char *str, char sep);
int	fill_window_in_params(t_params *params, char **file, int *i);
int	fill_objects(t_params *params, char **file, int *i);
int	fill_spots(t_params *params, char **file, int *i);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int size);
int	fill_keywords(t_params *params, char **file, int *i);
int	fill_window(t_params *params, char **file, int *i);
int	pars_file(char *line, char **file);
int	show_tab(char **tab);
char	**str_to_word_tab(char *str, char token);
int	count_word(char *str, char token);
char	*copy_word(char *s, char token);
int	my_strlen_V2(char *str, char token);
int	check_file(char **file);
int	check_error_read_file_part(int *fd, int *ret, char *file_name);
char	*check_error_read_file(int *fd, int *ret, char *file_name);
char	*read_file(char *file_name);
int	my_error(char *str);
int	sizestr(char *str);
char	*my_epur(char *str);
void	char_space(char *final);
int	my_putstr(char *str);
int	my_strlen(char *str);
void	my_put_nbr(int nb);
void	aff_tab(char **tab);

#endif /* !READ_H_ */
