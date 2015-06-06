/*
** huff_tree.c for huffman in /home/kinoo_m/rendu/huffman
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Sat Nov 29 09:22:27 2014 Martin Kinoo
** Last update Wed Dec  3 12:44:55 2014 Martin Kinoo
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"huff.h"

static void	switch_list(t_list *prev, t_list *node, t_node *pc, t_node *nc)
{
  while (pc)
    {
      if (pc->size < nc->size)
	{
	  prev->prev->next = node;
	  node->prev = prev->prev;
	  prev->prev = node;
	  prev->next = node->next;
	  node->next->prev = prev;
	  node->next = prev;
	  prev = node->prev;
	  pc = prev->data;
	}
      else
	return ;
    }
}

void		huff_elem(t_list *list, unsigned char elem, unsigned char *nbr)
{
  t_node	*node;

  while (list->data)
    {
      node = list->data;
      if (node->val == elem)
	{
	  ++(node->size);
	  switch_list(list->prev, list, list->prev->data, list->data);
	  return ;
	}
      list = list->next;
    }
  if (!(node = xmalloc(sizeof(t_node))))
    return ;
  node->val = elem;
  node->size = 1;
  add_elem(&list, node);
  (*nbr)++;
}

static t_list	*move_node(t_list *curs, unsigned char tmp)
{
  while (tmp--)
    curs = curs->next;
  return (curs);
}

static void	dicho_huff_node(t_list *elem, t_node *node, unsigned char len)
{
  unsigned char	mini_len;
  t_list	*curs;
  t_node	*cast;
  t_node	*next;
  t_node	*prev;

  mini_len = len / 2 + (len % 2);
  curs = move_node(elem, mini_len);
  cast = curs->data;
  next = curs->next->data;
  prev = curs->prev->data;
  if ((!cast || (cast->size >= node->size))
      && (!next || node->size >= next->size))
    add_elem(&(curs), node);
  else if ((!cast || (cast->size <= node->size))
	   && (!prev || node->size <= prev->size))
    add_elem(&(curs), node);
  else if (cast->size > node->size)
    dicho_huff_node(curs->prev, node, mini_len + !(len % 2));
  else
    dicho_huff_node(elem, node, mini_len);
}

t_node		*huff_tree(t_list *elem, unsigned char len)
{
  t_node	*new_node;
  t_node	*one;
  t_node	*two;

  if (!elem || !(elem->next->data))
    return (NULL);
  if (len == 1)
    return (elem->next->data);
  if (!(new_node = xmalloc(sizeof(t_node))))
    return (NULL);
  one = elem->prev->data;
  two = elem->prev->prev->data;
  new_node->right = two;
  new_node->left = one;
  new_node->size = one->size + two->size;
  elem->prev->prev->prev->next = elem;
  elem->prev = elem->prev->prev->prev;
  if (len == 2)
    dicho_huff_node(elem, new_node, len);
  else
    dicho_huff_node(elem, new_node, len - 2);
  return (huff_tree(elem, len - 1));
}
