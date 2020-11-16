#include "ev3api.h"
#include "app.h"

int wait_task(intptr_t exinf)
{

    tslp_tsk(5000);                                            /*5s wait*/

}



void main_task(intptr_t exinf)
{


    ev3_motor_config(EV3_PORT_A, LARGE_MOTOR);
    ev3_motor_config(EV3_PORT_B, LARGE_MOTOR);
    ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);
    ev3_sensor_config(EV3_PORT_3, COLOR_SENSOR);

    ev3_lcd_set_font(EV3_FONT_SMALL);


    while(1)
    {

        int r_current_color_val = ev3_color_sensor_get_reflect(EV3_PORT_2);
        int l_current_color_val = ev3_color_sensor_get_reflect(EV3_PORT_3);
        double gain_const = 0.01; //This is Gain constant of controll amount
        double r_control_amount, l_control_amount;
        int r_target_color_val = 50; //This is average, between white and black
        int l_target_color_val = 50;
        char r_current_color_str[20];
        char l_current_color_str[20];
        char r_control_amount_str[20];
        char l_control_amount_str[20];
        char r_motor_power_str[20];
        char l_motor_power_str[20];
        char gain_str[20];

        sprintf(r_current_color_str, "r_current_color: %d", r_current_color_val);
        sprintf(l_current_color_str, "l_current_color: %d", l_current_color_val);
        ev3_lcd_draw_string(r_current_color_str, 0, 10);
        ev3_lcd_draw_string(l_current_color_str, 0, 20);

        if((35 < r_current_color_val && r_target_color_val < 55) && (35 < l_current_color_val && l_current_color_val< 45)) //LINE COLOR IS BLACK
        {
            sprintf(r_current_color_str, "r_current_color: %d", r_current_color_val);
            sprintf(l_current_color_str, "l_current_color: %d", l_current_color_val);
            ev3_lcd_draw_string(r_current_color_str, 0, 30);
            ev3_lcd_draw_string(l_current_color_str, 0, 40);
            r_target_color_val = 46; //any value
            l_target_color_val = 46;

            sprintf(gain_str, "gain: %f", gain_const);
            ev3_lcd_draw_string(gain_str, 10, 10);
            r_control_amount = (double)((r_target_color_val - r_current_color_val)) * gain_const;
            l_control_amount = (double)((l_target_color_val - l_current_color_val)) * gain_const;
            sprintf(r_control_amount_str, "r_control_amount: %f", r_control_amount);
            sprintf(l_control_amount_str, "l_control_amount: %f", l_control_amount);
            ev3_lcd_draw_string(r_control_amount_str, 0, 50);
            ev3_lcd_draw_string(l_control_amount_str, 0, 60);

            int r_motor_power = 30 * (int)(-r_control_amount);
            int l_motor_power = 30 * (int)(l_control_amount);
            sprintf(r_motor_power_str, "r_motor_power: %d", r_motor_power);
            sprintf(l_motor_power_str, "l_motor_power: %d", l_motor_power);

            ev3_lcd_draw_string(r_motor_power_str, 0, 70);
            ev3_lcd_draw_string(l_motor_power_str, 0, 80);

            ev3_motor_set_power(EV3_PORT_A, r_motor_power); //motor power get it in here
            ev3_motor_set_power(EV3_PORT_B, l_motor_power);



        }


    }
}


int buzer(intptr_t exinf)
{

    ev3_speaker_set_volume(1);                              /* 音量設定（0～100．0はミュート．100超えると+100になる．） */
	ev3_speaker_play_tone(440, 100);                        /* 音を鳴らす（440Hzで100ミリ秒鳴らす．） */
	tslp_tsk(100);                                          /* 100ms待機 */
	ev3_speaker_stop();                                     /* 音を停止する */

}
