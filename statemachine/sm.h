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

#ifndef _SM_H
#define _SM_H


/* 状态机状态定义 */
typedef enum _SM_STATE_T {
  STATE_IDLE,
  STATE_A,
  STATE_B,
  STATE_C,
  STATE_NUM,
} SM_STATE_T;

/*状态机数据结构 */
struct _SM_DATA_T {
  SM_STATE_T state; /* current state */
};

typedef struct _SM_DATA_T SM_DATA_T, *P_SM_DATA_T;

/* Type definition for MESSAGE HEADER structure */
typedef struct _MSG_HDR_T MSG_HDR_T, *P_MSG_HDR_T;


/* functions */
void smInit();
void smStart(P_MSG_HDR_T prMsg);
void smStop(P_MSG_HDR_T prMsg);
  
#endif
