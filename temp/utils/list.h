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

#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

/* Defined a link node structure for link list */
typedef struct ListElmt_ {
  void *data;
  struct ListElmt_ *next;
} ListElmt;

/* Define a structure for the link list */
typedef  struct List_ {
  int size;
  /*由从链表数据结构中派生的新类型使用*/
  int (*match)(const void *key1, const void *key2);
  /*传递给list_init的destroy函数*/
  void (*destroy)(void *data);
  ListElmt *head; /*指向链表中头结点*/
  ListElmt *tail; /*指向链表中尾结点*/
} List;

/* Public Interface */
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
/*在链表指定的元素后面插入一个元素，返回0表示成功，-1表示失败*/
int list_ins_next(List *list, ListElmt *element, const void *data);
/*移除链表中element对应的元素，当element为空时，移除表头元素，data指向已移除元素存储的数据*/
int list_rem_next(List *list, ListElmt *element, void **data);

/* Public Macro */
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(list, element) ((element) == (list)->tail ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif
