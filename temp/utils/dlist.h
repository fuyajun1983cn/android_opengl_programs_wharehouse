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

#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

/* doubly-linked list element data structure definition */
typedef struct _DListElmt_ {
  void *data;
  struct _DListElmt_ *prev;
  struct _DListElmt_ *next;
} DListElmt;

/* doubly-linked list data structure definition */
typedef struct _DList {
  int size;
  int (*match) (const void *key1, const void *key2);
  void (*destroy) (void *data);
  DListElmt *head;
  DListElmt *tail;
} DList;

/* public interfaces */
void dlist_init(DList *list, void (*destroy)(void *data));
void dlist_destroy(DList *list);
int dlist_ins_next(DList *list, DListElmt *element, const void *data);
int dlist_ins_prev(DList *list, DListElmt *element, const void *data);
int dlist_remove(DList *list, DListElmt *element, void **data);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_is_head(element) ((element)->prev == NULLL ? 1:0)
#define dlist_is_tail(element) ((element)->next == NULL ? 1:0)
#define dlist_data(element) ((element)->data)
#define dlist_prev(element) ((element)->prev)
#define dlist_next(element) ((element)->next)

#endif
