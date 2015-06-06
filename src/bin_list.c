/*
** bin_list.c for huffman in /home/kinoo_m/rendu/huffman/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Dec  2 02:54:03 2014 Martin Kinoo
** Last update Wed Dec  3 09:20:37 2014 Martin Kinoo
*/

#include	<unistd.h>
#include	<stdlib.h>
#include        "huff.h"

t_bin		*new_bin(void (*f)(t_print *))
{
  t_bin		*ret;

  if (!(ret = xmalloc(sizeof(t_bin))))
    return (NULL);
  ret->f = f;
  return (ret);
}

char		add_bin(t_bin **head, void (*f)(t_print *))
{
  t_bin		*tmp;

  if (!head || !(*head))
    {
      if (!(*head = new_bin(f)))
	return (1);
      return (0);
    }
  tmp = *head;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new_bin(f);
  return (0);
}

void		print_one(t_print *huffman)
{
  char		mask;

  mask = 1 << huffman->len;
  huffman->print |= mask;
  if (!(huffman->len))
    {
      write(huffman->fd, &(huffman->print), 1);
      huffman->print = 0;
      huffman->len = 7;
    }
  else
    (huffman->len)--;
}

void		print_zero(t_print *huffman)
{
  char		mask;

  mask = ~(1 << huffman->len);
  huffman->print &= mask;
  if (!(huffman->len))
    {
      write(huffman->fd, &(huffman->print), 1);
      huffman->print = 0;
      huffman->len = 7;
    }
  else
    (huffman->len)--;
}
