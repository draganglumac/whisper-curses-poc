/*
 * =====================================================================================
 *
 *       Filename:  ui.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/02/15 12:52:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __UI_H__
#define __UI_H__

#include <ncurses.h>

typedef struct {
	WINDOW *prompt;
	WINDOW *screen;	
	int next_line;
} ui_t;

ui_t *create_ui();
void destroy_ui(ui_t *ui);
char *get_message(ui_t *ui);
void display_local_message(ui_t *ui, char *msg);
void display_remote_message(ui_t *ui, char *msg);

#endif // __UI_H__
