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

#include "mbox.h"

#define DISP_STRING(_str)       _str

static guchar *apucDebugMsg[] = {
  (guchar*)DISP_STRING("MID_SM_START"),
  (guchar*)DISP_STRING("MID_SM_STOP")
};

/* msg map */
static MSG_HNDL_ENTRY_T arMsgMapTable[] = {
  { MID_SM_START, smStart },
  {MID_SM_STOP, smStop }
};

/* MACROS */
#define MBOX_HNDL_MSG(prMsg) do {\
if (arMsgMapTable[prMsg->eMsgId].pfMsgHndl) {\
  g_printf("DO MSG [%d : %s]\n", prMsg->eMsgId, apucDebugMsg[prMsg->eMsgId]);\
  arMsgMapTable[prMsg->eMsgId].pfMsgHndl(prMsg);\
 }\
  } while (0)

static MBOX_T rMbox;
static P_MBOX_T prMbox;


void mbox_setup()
{
  prMbox = &rMbox;
  prMbox->rLinkHead = NULL;
}

void mbox_send_msg(P_MSG_HDR_T prMsg)
{
  g_return_if_fail(prMsg != NULL);
  
  MBOX_HNDL_MSG(prMsg);
}
void mbox_recv_msg()
{
  GList *l = prMbox->rLinkHead;
  
  while (l != NULL) {
    GList *next = l->next;
    /*processing*/
    l = next;
  }
}
void mbox_init()
{
  mboxSetup();
}
void mbox_destory()
{
  
}
