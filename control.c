#include "ev3api.h"
#include "app.h"



/*void GoAheadCheckPoint() //次の目的地に向かう
{
     
}
*/
/*bool PutObjectToCup(bool start_put_object) //カップにオブジェクトを置く
{
    ev3_motor_config(EV3_PORT_C, MEDIUM_MOTOR);
    ev3_motor_config(EV3_PORT_D, MEDIUM_MOTOR);

    if(start_put_object == true)
    {
        
    }
}
*/
/*void GoToAheadGoal() //ゴールに向かう
{

}
*/

int TouchStartByButtom(int state_buf_size)
{
    ev3_sensor_config(EV3_PORT_4, TOUCH_SENSOR);
    bool touch_sensor_on = ev3_touch_seosor_is_pressed(EV3_PORT_4);

    if(touch_sensor_on == true)
    {
        state_buf_size = 1;
        return state_buf_size;
    }
    
}

bool LineTracer(bool start_move)
{
    if(start_move == true)
    {
        
    }
    ev3_motor_config(EV3_PORT_A, LARGE_MOTOR);
    ev3_motor_config(EV3_PORT_B, LARGE_MOTOR);
    ev3_sensor_config(EV3_PORT_1, COLOR_SENSOR);
    ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);
    ev3_sensor_config(EV3_PORT_3, ULTRASONIC_SENSOR);

    start_put_object = false;

    int sonic_sensor_dist = ev3_ultrasonic_sensor_get_distance(EV3_PORT_3);
    int r_current_color_val = ev3_color_sensor_get_reflect(EV3_PORT_1);
    int l_current_color_val = ev3_color_sensor_get_reflect(EV3_PORT_2);
    int gain_const = 0.001; //This is Gain constant of controll amount
    int r_target_color_val = 50; //This is average, between white and black 
    int l_target_color_val = 50;
    int r_control_amount, l_control_amount;

    while(1)
    {
        if(40 < r_current_color_val && r_target_color_val < 60 && 40 < l_current_color_val && l_current_color_val< 60) //LINE COLOR IS BLACK
        {
            r_target_color_val = 50; //any value 
            l_target_color_val = 50;

            r_control_amount = (r_target_color_val - r_current_color_val) * gain_const;
            l_control_amount = (l_target_color_val - l_current_color_val) * gain_const;
        
            int r_motor_power = 100 * -r_control_amount;
            int l_motor_power = 100 * l_control_amount;
        
            ev3_motor_set_power(EV3_PORT_A, r_motor_power); //motor power get it in here
            ev3_motor_set_power(EV3_PORT_B, l_motor_power);

            if(sonic_sensor_dist < 10)
            {
                ev3_motor_set_power(EV3_PORT_A, 0); //Motor Power is 0 
                ev3_motor_set_power(EV3_PORT_B, 0);
                start_put_object = true;
                return start_put_object; //if start_put_object is true, start put object
            }

            else
            {
              return start_put_object;
            }
            

        }   
        
        else if((10 < r_current_color_val && r_current_color_val < 40) && 10 < (l_current_color_val && l_current_color_val < 40)) //LINE COLOR IS YELLO
        {
            r_target_color_val = 30; //any value 
            l_target_color_val = 30;

            r_control_amount = (r_target_color_val - r_current_color_val) * gain_const;
            l_control_amount = (l_target_color_val - l_current_color_val) * gain_const);
        
            int r_motor_power = 100 * -r_control_amount;
            int l_motor_power = 100 * l_control_amount;
        
            ev3_motor_set_power(EV3_PORT_A, r_motor_power); //motor power get it in here
            ev3_motor_set_power(EV3_PORT_B, l_motor_power);
        }

        else if((20 < r_current_color_val && r_current_color_val < 35) && (20 < l_current_color_val && l_current_color_val < 35)) //LINE COLOR IS BULE
        {
            r_target_color_val = 25; //any value 
            l_target_color_val = 25;

            r_control_amount = (r_target_color_val - r_current_color_val) * gain_const);
            l_control_amount = (l_target_color_val - l_current_color_val) * gain_const);
        
            int r_motor_power = 100 * -r_control_amount;
            int l_motor_power = 100 * l_control_amount;
        
            ev3_motor_set_power(EV3_PORT_A, r_motor_power); //motor power get it in here
            ev3_motor_set_power(EV3_PORT_B, l_motor_power);
        }

        else if((30 < r_current_color_val && r_current_color_val < 40) && 30 < (l_current_color_val && l_current_color_val < 40)) //LINE COLOR IS RED
        {
            r_target_color_val = 30; //any value 
            l_target_color_val = 30;

            r_control_amount = (r_target_color_val - r_current_color_val) * gain_const);
            l_control_amount = (l_target_color_val - l_current_color_val) * gain_const);
        
            int r_motor_power = 100 * -r_control_amount;
            int l_motor_power = 100 * l_control_amount;
        
            ev3_motor_set_power(EV3_PORT_A, r_motor_power); //motor power get it in here
            ev3_motor_set_power(EV3_PORT_B, l_motor_power);
        }

        else if((45 < r_current_color_val && r_current_color_val < 60) && (45 < l_current_color_val && l_current_color_val < 60)) //LINE COLOR IS GREEN
        {
            r_target_color_val = 30; //any value 
            l_target_color_val = 30;

            r_control_amount = (r_target_color_val - r_current_color_val) * gain_const);
            l_control_amount = (l_target_color_val - l_current_color_val) * gain_const);
        
            int r_motor_power = 100 * -r_control_amount;
            int l_motor_power = 100 * l_control_amount;
        
            ev3_motor_set_power(EV3_PORT_A, r_motor_power); //motor power get it in here
            ev3_motor_set_power(EV3_PORT_B, l_motor_power);
        }
    }
}

void main_task(intptr_t exinf)
{
    ext_tsk();
}
bool StateMachine(void)
{
    int state_buf_size[5] = {0, 0, 0, 0, 0};
    bool start_move

    state_buf_size[0] = TouchStartByButtom(state_buf_size[0]);
    if(state_buf_size[0] = 1)
    {
       start_move = true;
       LineTracer(start_move);
    }
    
}
