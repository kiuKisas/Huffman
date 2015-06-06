/*
** my_strdup.c for my_str_to_wordtab in /home/kinoo_m/rendu/fonctions/my_strndup
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on Thu May  8 22:53:35 2014 Martin Kinoo
** Last update Wed Nov 26 15:59:15 2014 Martin Kinoo
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"huff.h"

char			*my_strdup(char *str)
{
  char			*ret;
  int			i;

  if (str == NULL || *str == 0)
    return (NULL);
  if ((ret = xmalloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    {
      write(2, "erreur malloc.\n", 15);
      return (NULL);
    }
  i = -1;
  while (str[++i] != '\0')
      ret[i] = str[i];
  ret[i] = '\0';
  return (ret);
}
