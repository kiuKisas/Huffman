/*
** dico.c for huffman in /home/kinoo_m/rendu/huffman/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Dec  2 14:15:35 2014 Martin Kinoo
** Last update Thu Dec  4 19:15:14 2014 Martin Kinoo
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"huff.h"

static void	dico_hub(t_bin *prev, t_node *node, t_huff *huff)
{
  t_bin		*cpy;

  if (node->val)
    {
      print_one(huff->print);
      print_bin_char(huff->print, node->val);
      if (!prev)
	prev = new_bin(&print_zero);
      huff->dico[(int)node->val] = prev;
      return ;
    }
  print_zero(huff->print);
  cpy = cpy_bin_list(prev);
  add_bin(&cpy, &print_one);
  add_bin(&prev, &print_zero);
  dico_hub(prev, node->left, huff);
  dico_hub(cpy, node->right, huff);
}

static void	write_t_bin(t_print *print, t_bin *bin)
{
  if (!bin)
    return ;
  while (bin)
    {
      (*(bin->f))(print);
      bin = bin->next;
    }
}

static void	write_bin_file(t_huff *huffman)
{
  t_list	*ptr;
  unsigned char	*cast;
  t_bin		**dico;

  if (!(huffman->file))
    return ;
  ptr = huffman->file->next;
  dico = huffman->dico;
  while (ptr->data)
    {
      cast = ptr->data;
      while (*cast)
	{
	  write_t_bin(huffman->print, dico[(int)(*cast)]);
	  cast++;
	}
      ptr = ptr->next;
    }
}

int		write_my_bin(t_node *tree, t_huff *huffman)
{
  char		*start;

  if (!tree || !(huffman->print))
    return (print_error("empty tree"));
  if (!(huffman->dico = xmalloc(sizeof(t_bin *) * 255)))
    return (1);
  huffman->print->len = 4;
  dico_hub(NULL, tree, huffman);
  write_bin_file(huffman);
  if (huffman->print->len == 7)
    {
      if (!(start = my_bin_converter(0, 3)))
	return (1);
    }
  else if (!(start = my_bin_converter((huffman->print->len + 1), 3)))
    return (1);
  while (huffman->print->len < 7)
    print_zero(huffman->print);
  lseek(huffman->print->fd, 0, SEEK_SET);
  read(huffman->print->fd, &(huffman->print->print), 1);
  print_bin_string(huffman->print, start);
  lseek(huffman->print->fd, 0, SEEK_SET);
  write(huffman->print->fd, &(huffman->print->print), 1);
  return (0);
}
