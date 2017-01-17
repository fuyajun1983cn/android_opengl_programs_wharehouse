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

#include <glib.h>
#include <glib/gprintf.h>

#include "sm.h"

/**
   Core Engine for the state machine
   can only change the sm's state in this function
*/
static void smSteps(P_SM_DATA_T prStateData, SM_STATE_T nextState)
{
  gboolean flgIsTransition;
  SM_STATE_T ePrevState;

  do {
    ePrevState = prStateData->state;
    prStateData->state = nextState;
    flgIsTransition = FALSE;

    switch (prStateData->state) {
    case STATE_IDLE: {
      g_printf("Going to STATE IDLE\n");
      break;
    }
    case STATE_A: {
      g_printf("Going In State A \n");
      nextState = STATE_IDLE;
      flgIsTransition = TRUE;
      break;
    }
    case STATE_B: {
      g_printf("Going to STATE C\n");
      break;
    }
    default:
      g_printf("Unkown State!!\n");
      break;
    }
  } while (flgIsTransition == TRUE);
}

/* Init Function */
void smInit(P_SM_DATA_T prData)
{
  /* do something */
  smSteps(prData, STATE_IDLE);
}

/* Start */
void smStart(P_SM_DATA_T prData)
{
  /* do something */
  smSteps(prData, STATE_A);
}

/* do something */
void smStop(P_SM_DATA_T prData)
{
  /* do something */
  smSteps(prData, STATE_B);
}
