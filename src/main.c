/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/02/15 12:41:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "ui.h"
#include "app.h"

int main(int argc, char **argv) {
	ui_t *ui = create_ui();
	
	context_t *context = malloc(sizeof(context_t));
	context->ui = ui;
	context->msg = NULL;
	pthread_t read_thread;
	pthread_create(&read_thread, 0, read_loop, (void *) context);

	while (TRUE) {
		pthread_mutex_lock(&output_mutex);	
		wait_for_message();
		ui_t *cui = context->ui;
		char *msg = context->msg;
		if (strcmp(msg, ":q") == 0) {
			break;
		}
		else if (strncmp(msg, "r/", 2) == 0) {
			display_remote_message(cui, msg);
		}
		else {
			display_local_message(cui, msg);
		}
		pthread_mutex_unlock(&output_mutex);
	}

	destroy_ui(ui);
	return 0;
}
