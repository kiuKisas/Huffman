/*
** get_char_from_octet.c for huffman in /home/kinoo_m/rendu/huffman/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Thu Dec  4 09:42:56 2014 Martin Kinoo
** Last update Thu Dec  4 17:53:43 2014 Martin Kinoo
*/

#include	"huff.h"

static char	*next_cast(t_list **octet, char *cur)
{
  char		*cast;

  (*octet) = (*octet)->next;
  cast = (*octet)->data;
  *cur = 0;
  return (cast);
}

static void	char_zero(unsigned char *ret, char len)
{
  char		mask;

  mask = ~(1 << len);
  *ret &= mask;
}

static void	char_one(unsigned char *ret, char len)
{
  char		mask;

  mask = 1 << len;
  *ret |= mask;
}

char		get_char_from_octet(t_list **octet, char *cur, char *err)
{
  unsigned char	ret;
  char		len;
  char		*cast;

  ret = 0;
  len = 7;
  cast = (*octet)->data;
  while (len >= 0)
    {
      (*cur)++;
      if (!cast[(int)(*cur)] && !(cast = next_cast(octet, cur)))
	{
	  *err = 1;
	  return (0);
	}
      if (cast[(int)(*cur)] == '1')
	char_one(&ret, len);
      else
	char_zero(&ret, len);
      len--;
    }
  return (ret);
}
