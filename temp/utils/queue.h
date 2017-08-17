#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>

#include "list.h"

/* Implements Queue as list */
typedef List Queue;

/* public interfaces */
#define queue_list list_init
#define queue_destroy list_destroy
int queue_enqueue(Queue *queue, const void *data);
int queue_dequeue(Queue *queue, void **data);

#define queue_peek(queue) ((queue)->head == NULL? NULL : (queue)->head->data)
#define queue_size list_size

#endif
