/*
 * =====================================================================================
 *
 *       Filename:  app.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/02/15 16:57:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <pthread.h>

#include "app.h"

void signal_message() {
	pthread_cond_signal(&output_cond);
}
void wait_for_message() {
	pthread_cond_wait(&output_cond, &output_mutex);
}
void send_message(context_t *context) {
	signal_message();
}
void *read_loop(void *data) {
	context_t *context = (context_t *) data;
	while(TRUE) {
		char *msg = get_message(context->ui);
		context->msg = msg;
		send_message(context);
	}
	return NULL;
}


