/*
 * File:   main.c
 * Author: Manu H P
 *
 * Created on April 21, 2026, 11:28 AM
 */

#include <xc.h>
#include "black_box.h"
#include "clcd.h"
#include "adc.h"
#include "matrix_keypad.h"
#include "i2c.h"
#include "rtc.h"
#include "uart.h"

#define _XTAL_FREQ 20000000

unsigned char key;

State_t state;// = e_dashboard;

void init_config(void)
{
    init_clcd();
    init_adc();
    init_matrix_keypad();

    init_i2c();
    init_ds1307();

    init_uart();

    state = e_dashboard;
}

void main(void)
{
    init_config();

    while(1)
    {
        key = read_matrix_keypad(EDGE);

        /* SW10 -> enter main menu */
        if(key == SW10)
        {
            state = e_main_menu;
            clear_screen();
            key = 0xFF;
        }

        /* SW12 -> exit to main menu */
        if(key == SW12)
        {
            state = e_main_menu;
            clear_screen();
            key = 0;
        }

        switch(state)
        {
            case e_dashboard:
                
                view_dashboard();
                break;

            case e_main_menu:
                
                display_main_menu();
                break;

            case e_view_log:
                
                view_log();
                break;

            case e_download_log:
                
                download_log();
                break;

            case e_clear_log:
                clcd_print("LOG IS CLEATRED",LINE2(0));
                clear_log();     
                state = e_main_menu; // Optional return to menu after clear
                break;

            case e_set_time:
                
                clear_screen();
                set_time();
                break;
        }
    }
}
