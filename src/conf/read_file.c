#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "read.h"

int	my_error(char *str)
{
  if (write(2, str, my_strlen(str)) == -1)
    return (-1);
  return (0);
}

char	*read_file(char *file_name)
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
  if (check_file(tab) == ERROR)
    {
      if (close(fd) == ERROR)
	return (NULL);
      return (NULL);
    }
  //show_tab(tab);
  return (buff);
}

int	main(int ac, char **av, char **envp)
{
  char	*file;

  if (ac != 2)
    {
      my_putstr("[Usage] : ./a.out <name of the conf file>\n");
      return (ERROR);
    }
  if ((file = read_file(av[1])) == NULL)
    return (ERROR);
  return (0);
}