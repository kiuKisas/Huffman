/*
** bin_extra.c for huffman in /home/kinoo_m/rendu/huffman/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Wed Dec  3 08:34:45 2014 Martin Kinoo
** Last update Thu Dec  4 19:55:45 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	"huff.h"

char		*my_bin_converter(int nbr, int len)
{
  int		tmp;
  char		*ret;

  if (len < 0)
    return (NULL);
  tmp = nbr;
  if (!len)
    {
      while (nbr >= 1)
	{
	  nbr = nbr / 2;
	  len++;
	}
    }
  nbr = tmp;
  if ((ret = xmalloc(sizeof(char) * (len + 1))) == NULL)
      return (NULL);
  while (len)
    {
      len--;
      tmp = nbr % 2;
      ret[len] = tmp + 48;
      nbr = nbr / 2;
    }
  return (ret);
}

void		print_bin_string(t_print *print, char *str)
{
  if (!str)
    return ;
  while (*str)
    {
      if (*str == '1')
	print_one(print);
      else
	print_zero(print);
      str++;
    }
}

void		print_bin_char(t_print *print, unsigned char c)
{
  char		*cara;

  cara = my_bin_converter((int)c, 8);
  print_bin_string(print, cara);
  free(cara);
}

t_bin		*cpy_bin_list(t_bin *from)
{
  t_bin		*ret;

  if (!from || !(from->f))
    return (NULL);
  ret = NULL;
  while (from)
    {
      add_bin(&ret, from->f);
      from = from->next;
    }
  return (ret);
}
