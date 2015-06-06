/*
** bin_writer.c for huffman in /home/kinoo_m/rendu/huffman/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Thu Dec  4 11:16:33 2014 Martin Kinoo
** Last update Thu Dec  4 19:12:17 2014 Martin Kinoo
*/

#include	<unistd.h>
#include	"huff.h"

static int	switch_end(t_list **octet, char *cur, char **cast)
{
  char		*tmp;

  tmp = *cast;
  (*cur)++;
  if (!(tmp[(int)(*cur)]))
    {
      *octet = (*octet)->next;
      *cast = (*octet)->data;
      if (!(*cast))
	return (1);
      *cur = 0;
    }
  return (0);
}

void		my_write_bin(t_node *tree)
{
  if (!tree)
    return ;
  write(1, &(tree->val), 1);
  write(1, "\n", 1);
  write(1, "left\n", 5);
  my_write_bin(tree->left);
  write(1, "rigt\n", 5);
  my_write_bin(tree->right);
}

static void	bin_printer(int fd, t_node **node, t_node *tree)
{
  if (!(*node)->left)
    {
      write(fd, &((*node)->val), 1);
      (*node) = tree;
    }

}

int		bin_writer(int fd, t_list *octet, char curs, t_node *tree)
{
  char		*cast;
  t_node	*node;

  cast = octet->data;
  node = tree;
  while (!switch_end(&octet, &curs, &cast))
    {
      bin_printer(fd, &node, tree);
      if (!(node->val) && cast[(int)(curs)] == '0')
	node = node->left;
      else if (!(node->val))
	node = node->right;
    }
  if (node != tree)
    bin_printer(fd, &node, tree);
  if (node != tree)
    return (print_error("missing part in bin file"));
  return (0);
}
