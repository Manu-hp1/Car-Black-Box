/* 
 * File:   black_box.h
 * Author: Manu H P
 *
 * Created on April 21, 2026, 11:25 AM
 */

#ifndef BLACK_BOX_H
#define BLACK_BOX_H

#include <xc.h>

typedef enum
{
    e_dashboard,
    e_main_menu,
    e_view_log,
    e_set_time,
    e_download_log,
    e_clear_log

} State_t;

extern State_t state;

void view_dashboard(void);
void display_main_menu(void);
void view_log(void);
void set_time(void);
void download_log(void);
void clear_log(void);

/* functions defined in black_box.c */
void store_log(unsigned char gear_index,unsigned char *speed);
unsigned char* get_speed(void);
void get_gear(void);


#endif	/* BLACK_BOX_H */

