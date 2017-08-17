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

#ifndef _MBOX_H
#define _MBOX_H

#include "sm.h"
#include <glib.h>

/* MSG IDs */
typedef  enum _MSG_ID_T {
  /*SM*/
  MID_SM_START,
  MID_SM_STOP,

  /* other component */

  MID_TOTAL_NUM
} MSG_ID_T, *P_MSG_ID;

/* message header of inter-components */
typedef struct _MSG_HDR_T {
  GList *rLinkEntry;
  MSG_ID_T eMsgId;
} MSG_HDR_T, *P_MSG_HDR_T;

typedef VOID(*PFN_MSG_HNDL_FUNC) (P_MSG_HDR_T);

typedef struct _MSG_HNDL_ENTRY {
  MSG_ID_T eMsgId;
  PFN_MSG_HNDL_FUNC pfMsgHndl;
} MSG_HNDL_ENTRY_T, *P_MSG_HNDL_ENTRY_T;

/* Define Mailbox structure */
typedef struct _MBOX_T {
	GList *rLinkHead;
} MBOX_T, *P_MBOX_T;

typedef struct _MSG_SM_START_T {
  MSG_HDR_T rMsgHdr; /* must be the first member */
  P_SM_DATA_T prSmData;
} MSG_SM_START_T, *P_MSG_SM_START_T;

typedef struct _MSG_SM_STOP_T {
  MSG_HDR_T rMsgHdr; /* must be the first member */
  P_SM_DATA_T prSmData;
} MSG_SM_STOP_T, *P_MSG_SM_STOP_T;

void mbox_setup();
void mbox_send_msg(P_MSG_HDR_T prMsg);
void mbox_recv_msg();
void mbox_init();
void mbox_destory();

#endif
