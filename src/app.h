/*
 * =====================================================================================
 *
 *       Filename:  app.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/02/15 16:54:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __APP_H__
#define __APP_H__

#include "ui.h"

typedef struct {
	ui_t *ui;
	char *msg;
} context_t;

pthread_mutex_t output_mutex;
pthread_cond_t output_cond;

void wait_for_message();
void signal_message();
void send_message(context_t *context);
void *read_loop(void *data);


#endif // __APP_H__
