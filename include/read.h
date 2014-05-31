#ifndef READ_H_
# define READ_H_

# define ERROR -1

int	sizestr(char *str, char sep);
char	*minepur_str(char *str, char sep);
void	char_space(char *final);

int	read_file(char *finle_name);

void	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_put_nbr(int nb);
void	aff_tab(char **tab);

#endif /* !READ_H_ */
