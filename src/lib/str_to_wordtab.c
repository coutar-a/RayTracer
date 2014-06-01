
#include <stdlib.h>
#include "raytracer.h"

int	my_count_word(char *str, char delim)
{
  int	i;
  int	nb_words;

  i = -1;
  nb_words = 1;
  while (str[++i] != '\0')
    {
      if (str[i] == delim)
	nb_words++;
    }
  return (nb_words);
}

int	my_count_letter(char *str, int num_word, char delim)
{
  int	i;
  int	nb_words;
  int	word_exist;
  int	nb_letter;

  i = 0;
  nb_words = 0;
  word_exist = 0;
  nb_letter = 0;
  while (str[i] != '\0')
    {
      if (str[i] != delim && word_exist == 0)
        {
          nb_words++;
          word_exist = 1;
        }
      if (str[i] == delim)
        word_exist = 0;
      i++;
      if (nb_words ==  num_word && str[i] != delim)
        nb_letter++;
    }
  return (nb_letter);
}

char	**my_mallocate_wordtab(char *str, char delim)
{
  char	**wordtab;
  int	nb_word;
  int	i;
  int	nb_letter;

  nb_word = my_count_word(str, delim);
  i = -1;
  nb_letter = 0;
  if ((wordtab = malloc((nb_word + 1) * sizeof(char *))) == NULL)
    return (NULL);
  wordtab[nb_word] = NULL;
  while (++i <  nb_word)
    {
      nb_letter = my_count_letter(str, (i + 1), delim);
      if ((wordtab[i] = malloc((nb_letter + 1) * sizeof(char))) == NULL)
	return (NULL);
      wordtab[i][nb_letter] = '\0';
    }
  return (wordtab);
}

char	**my_str_to_wordtab(char *str, char delim)
{
  char	**wordtab;
  int	i;
  int	j;
  int	i_str;

  if ((wordtab = my_mallocate_wordtab(str, delim)) == NULL)
    return (NULL);
  i = -1;
  j = -1;
  i_str = 0;
  while (++i <  my_count_word(str, delim))
    {
      while (++j < my_count_letter(str, (i + 1), delim))
        {
          wordtab[i][j] = str[i_str];
          i_str++;
        }
      i_str++;
      j = -1;
    }
  return (wordtab);
}

void	my_show_wordtab(char **tab)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (tab[++i] != '\0' || tab[i] != NULL)
    {
      while (tab[i][++j] != '\0')
	my_putchar(tab[i][j]);
      my_putchar('\n');
      j = -1;
    }
}
