/**
 * Copyright (c)  2016     Yajun Fu (fuyajun1983cn@163.com)
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

/* list.c */

#include <stdlib.h>
#include <string.h>

#include "list.h"

/* list_init */
void list_init(List *list, void (*destroy)(void *data))
{
  list->size = 0;
  list->match = NULL;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;
}

/* list destroy */
void list_destroy(List *list)
{
  void *data;
  /* Remove each element */
  while (list_size(list) > 0) {
    if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL)
      list->destroy(data);/* call user defined destroy function */
  }
  memset(list, 0, sizeof(List));
}

/* list ins next */
int list_ins_next(List *list, ListElmt *element, const void *data)
{
  ListElmt *new_element;
  if ((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL)
    return -1;

  new_element->data = (void*)data;
  if (element == NULL) {/* first element */
    if (list_size(list) == 0) {
      list->tail = new_element;
    }
    new_element->next = list->head;
    list->head = new_element;
  } else {
    if (element->next == NULL)
      list->tail = new_element;
    new_element->next = element->next;
    element->next = new_element;
  }
  list->size++;
  return 0;
}

/* list remove element, remove element next to the specified element */
int list_rem_next(List *list, ListElmt *element, void **data)
{
  ListElmt *old_element;

  if (list_size(list) == 0)
    return -1;

  if (element == NULL) {/* remove element from head */
    *data = list->head->data;
    old_element = list->head;
    list->head = list->head->next;

    if (list_size(list) == 1)
      list->tail = NULL;
  } else {
    if (element->next == NULL)
      return -1;
    *data = element->data;
    old_element = element->next;
    element->next = element->next->next;

    if (element->next == NULL)
      list->tail = element;
  }
  free(old_element);
  list->size--;
  return 0;
}
