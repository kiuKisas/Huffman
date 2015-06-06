/*
** list.c for huffman in /home/kinoo_m/rendu/huffman
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Oct 28 21:31:00 2014 Martin Kinoo
** Last update Thu Dec  4 18:35:49 2014 Martin Kinoo
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"huff.h"

void		new_list(t_list **list)
{
  if (((*list) = xmalloc(sizeof(t_list))) == NULL)
    {
      write(2, "[ERROR]: malloc impossible.\n", 28);
      *list = NULL;
      return ;
    }
  (*list)->data = NULL;
  (*list)->prev = (*list);
  (*list)->next = (*list);
}

void		delete_list(t_list **list)
{
  t_list	*it;

  if (!list || !(*list))
    return ;
  it = (*list)->next;
  while (it->data)
    {
      it = it->next;
      if (it->prev->data)
	free(it->prev->data);
      free(it->prev);
    }
  if (it)
    free(it);
  it = NULL;
}

void		delete_elem(t_list *elem)
{
  if (!elem && !(elem->data))
    return ;
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}

void		add_elem(t_list **list, void *data)
{
  t_list	*new_elem;

  if (!data)
    return ;
  if (!list || !(*list))
    new_list(list);
  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    {
      write(2, "[ERROR]: malloc impossible.\n", 28);
      return ;
    }
  new_elem->data = data;
  (*list)->prev->next = new_elem;
  new_elem->next = *list;
  new_elem->prev = (*list)->prev;
  (*list)->prev = new_elem;
}
