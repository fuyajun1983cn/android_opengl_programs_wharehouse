/**
 * Copyright (c)  2017     Yajun Fu (fuyajun1983cn@163.com)
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>

#include "clist.h"

/* clist_init */
void clist_init(CList *list, void (*destroy)(void *data))
{
  list->head = NULL;
  list->destroy = destroy;
  list->size = 0;
}

/* clist_destroy */
void clist_destroy(CList *list)
{
  void *data;

  while (clist_size(list) != 0) {
    if (clist_rem_next(list, list->head, (void**)&data) == 0 &&
        list->destroy != NULL) {
      list->destroy(data);
    }
  }

  memset(list, 0, sizeof(CList));
}

int clist_ins_next(CList *list, CListElmt *element, void *data)
{
  CListElmt *new_element;

  if ((new_element = (CListElmt*)malloc(sizeof(CListElmt))) == NULL)
    return -1;

  new_element->data = data;
  if (clist_size(list) == 0) {
    list->head = new_element;
    new_element->next = list->head;
  } else {
    new_element->next = element->next;
    element->next = new_element;
  }

  list->size++;
  return 0;
}

int clist_rem_next(CList *list, CListElmt *element, void **data)
{
  CListElmt *old_element;

  /* don't allow remove element from an empty list */
  if (clist_size(list) == 0)
    return -1;

  *data = element->next->data;
  if (element->next == element) {
    old_element = element->next;
    list->head = NULL;
  } else {
    old_element = element->next;
    element->next = element->next->next;
    /* the head is the removed element */
    if (clist_head(list) == old_element)
      list->head = old_element->next;
  }

  free(old_element);
  list->size--;
  return 0;

}

