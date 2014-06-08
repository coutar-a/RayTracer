
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "raytracer.h"

int	my_error(char *str)
{
  if (write(2, str, my_strlen(str)) == -1)
    return (-1);
  return (0);
}

char	*read_file(char *file_name, t_params *params)
{
  int	fd;
  int	ret;
  char	*buff;
  char	**tab;

  if ((buff = check_error_read_file(&fd, &ret, file_name)) == NULL)
    return (NULL);
  if ((buff = epur(buff)) == NULL)
    {
      my_error("Epur_str fail\n");
      if (close(fd) == ERROR)
	return (NULL);
      return (NULL);
    }
  if (close(fd) == ERROR)
    return (NULL);
  tab = my_str_to_wordtab(buff, '\n');
  if (check_file(tab, params) == ERROR)
    {
      if (close(fd) == ERROR)
	return (NULL);
      return (NULL);
    }
  return (buff);
}

int	conf_file(int ac, char **av, t_params *params)
{
  char	*file;
  int	option;

  if (ac < 2 || ac > 3)
    {
      my_putstr("[Usage] : ./a.out <name of the conf file>\n");
      return (ERROR);
    }
  if ((option = microparser(av)) == 1)
    {
      if ((file = read_file(av[2], params)) == NULL)
	return (ERROR);
      return (1);
    }
  if ((file = read_file(av[1], params)) == NULL)
    return (ERROR);
  return (0);
}
