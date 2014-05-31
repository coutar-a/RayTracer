#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "read.h"

int	read_file(char *file_name)
{
  int	fd;
  int	ret;
  char	buff[4096];
  char	*final;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (ERROR);
  if ((ret = read(fd, buff, 4095)) <= 0)
    return (ERROR);
  buff[ret] = '\0';
  if ((final = minepur_str(buff, ' ')) == NULL)
    return (ERROR);
  my_putstr(final);
  if (check_file(file) == ERROR)
    {
      my_putstr("Read the 'Man' of the file.\n");
      return (ERROR);
    }
  close(fd);
}

int	main(int ac, char **av, char **envp)
{
  char	*file;

  if (ac != 2)
    {
      my_putstr("[Usage] : ./a.out <name of the conf file>\n");
      return (ERROR);
    }
  if ((file = read_file(av[1])) == ERROR)
    {
      my_putstr("Fail in read_me\n");
      return (ERROR);
    }
  return (0);
}
