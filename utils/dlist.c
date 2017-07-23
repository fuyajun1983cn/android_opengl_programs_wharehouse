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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

/* dlist_init */
void dlist_init(DList *list, void (*destroy)(void *data))
{
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;
}

/* dlist_destory */
void dlist_destory(DList *list)
{
  void *data;

  /* Remove each element */
  while (dlist_size(list) > 0) {
    if (dlist_remove(list, dlist_tail(list), (void **)&data) == 0 &&
        list->destroy != NULL) {
      list->destroy(data);
    }
  }

  memset(list, 0, sizeof(DList));
}

/* dlist_next */
int dlist_ins_next(DList *list, DListElmt *element, const void *data)
{
  DListElmt *new_element;
  /* Do not allow NULL element unless the list is empty */
  if (element == NULL && dlist_size(list) != 0) {
    return -1;
  }

  /* allocate new element */
  new_element = (DListElmt*)malloc(sizeof(DListElmt));
  if (new_element == NULL)
    return -1;

  new_element->data = data;

  if (dlist_size(list) == 0) {
    /* insertion when list is empty */
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  } else {
    new_element->next = element->next;
    new_element->prev = element;

    if (element->next == NULL) {
      list->tail = new_element;
    } else {
      element->next->prev = new_element;
    }
    element->next = new_element;
  }
  list->size++;
  return 0;
}

/* dlist_ins_prev */
int dlist_ins_prev(DList *list, DListElmt *element, const void *data)
{
  DListElmt *new_element;

  /* don't allow a NULL element unless the list is empty */
  if (element == NULL && dlist_size(list) != 0)
    return -1;

  new_element = (DListElmt*)malloc(sizeof(DListElmt));
  if (new_element == NULL)
    return -1;

  new_element->data = data;

  if (dlist_size(list) == 0) {
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  } else {
    new_element->prev = element->prev;
    new_element->next = element;
    if (element->prev == NULL)
      list->head = new_element;
    else
      element->prev->next = new_element;
    element->prev = new_element;
  }
  
  list->size++;
  return 0;
}

/* dlist_delete */
int dlist_remove(DList *list, DListElmt *element, void **data)
{
  if (element == NULL || dlist_size(list) == 0)
    return -1;

  *data = element->data;

  if (element == list->head) {
    list->head = element->next;
    if (list->head == NULL)
      list->tail = NULL;
    else
      element->next->prev = NULL;
  } else {
    element->prev->next = element->next;
    if (element->next == NULL)
      list->tail = element->prev;
    else
      element->next->prev = element->prev;
  }
  
  free(element);
  list->size--;
  
  return 0;
}
