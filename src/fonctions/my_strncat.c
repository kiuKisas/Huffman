/*
** my_strncat.c for my_strncat in /home/kinoo_m/rendu/projstarter
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Wed Oct 29 17:10:04 2014 Martin Kinoo
** Last update Wed Nov 26 15:59:58 2014 Martin Kinoo
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"huff.h"

char			*my_strncat(char *dest, char *src, int nbr)
{
  int			i;
  int			j;
  char			*ret;

  if ((ret = xmalloc(sizeof(char) * (my_strlen(dest) + nbr + 1))) == NULL)
    {
      write(2, "erreur malloc.\n", 15);
      return (NULL);
    }
  i = 0;
  if (dest != NULL)
    while (dest[i] != '\0')
      {
	ret[i] = dest[i];
	i++;
      }
  j = 0;
  if (src != NULL)
    while (j < nbr)
      ret[i++] = src[j++];
  ret[i] = '\0';
  return (ret);
}
