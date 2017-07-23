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

/* 链表测试程序 */

#include "list.h"
#include "dlist.h"
#include <stdio.h>

/* alloc frames */
int alloc_frame(List *frames)
{
  int frame_number, *data;

  if (list_size(frames) == 0) {
    /* no frames available */
    return -1;
  } else {
    if (list_rem_next(frames, NULL, (void**)&data) != 0) {
      return -1;
    } else {
      frame_number = *data;
      free(data);
    }
  }
  return frame_number;
}

/* free frames */
int free_frame(List *frames, int frame_number)
{
  int *data;

  if ((data = (int*)malloc(sizeof(int))) == NULL){
    return -1;
  }

  *data = frame_number;
  if (list_ins_next(frames, NULL, data) != 0)
    return -1;

  return 0;
}

/* alloc frames */
int alloc_frame_2(DList *frames)
{
  int frame_number, *data;

  if (dlist_size(frames) == 0) {
    /* no frames available */
    return -1;
  } else {
    if (dlist_remove(frames, frames->head, (void**)&data) != 0) {
      return -1;
    } else {
      frame_number = *data;
      free(data);
    }
  }
  return frame_number;
}

/* free frames */
int free_frame_2(DList *frames, int frame_number)
{
  int *data;

  if ((data = (int*)malloc(sizeof(int))) == NULL){
    return -1;
  }
  *data = frame_number;
  if (dlist_ins_next(frames, frames->head, data) != 0)
    return -1;

  return 0;
}




int main(int argc, char *argv[])
{
  List *frames = (List*)malloc(sizeof(List));
  list_init(frames, NULL);

  int ret = 0;

#define CHECK_RESULT(ret) do { \
  if ((ret) == -1) {                             \
    printf("操作失败！\n");\
    return -1;\
  }\
} while(0)
  /* 单链表测试 */
  printf("单链表测试\n");
  ret = free_frame(frames, 1);
  CHECK_RESULT(ret);
  ret = free_frame(frames, 2);
  CHECK_RESULT(ret);

  printf("链表大小：%d\n", list_size(frames));
  
  ret = alloc_frame(frames);
  CHECK_RESULT(ret);
  printf("分配到页帧: %d\n", ret);
  ret = alloc_frame(frames);
  CHECK_RESULT(ret);
  printf("分配到页帧: %d\n", ret);

  //  ret = alloc_frame(frames);
  //  CHECK_RESULT(ret);/* should fail here */
  //  printf("分配到页帧: %d\n", ret);

  /* 双向链表测试 */
  printf("双向链表测试\n");
  DList *frames2  = (DList*)malloc(sizeof(DList));
  if (frames2 == NULL) {
    printf("分配内存失败！\n");
    return -1;
  }
  dlist_init(frames2, NULL);
  printf("1\n");
  ret = free_frame_2(frames2, 1);
  CHECK_RESULT(ret);
  printf("2\n");
  ret = free_frame_2(frames2, 2);
  CHECK_RESULT(ret);

  printf("双向链表大小：%d\n", dlist_size(frames2));
  
  ret = alloc_frame_2(frames2);
  CHECK_RESULT(ret);
  printf("分配到页帧: %d\n", ret);
  ret = alloc_frame_2(frames2);
  CHECK_RESULT(ret);
  printf("分配到页帧: %d\n", ret);

  ret = alloc_frame_2(frames2);
  CHECK_RESULT(ret);/* should fail here */
  printf("分配到页帧: %d\n", ret);

#undef CHECK_RESULT
  
  return 0;
}
