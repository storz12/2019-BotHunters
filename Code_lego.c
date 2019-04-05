#include <kipr/botball.h>
#include <defines.h>

void reference(void);
void gripper_startpoint(void);
void lowposition(void);
void lowpositiondots(void);
void lowpositioncont(void);
void highposition(void);
void gripper_bridge(void);
void gripper_download(void);
void forward1(void);
void forward_grey(void);
void take_citiziens(int distance_ticks);

void gripper_turn_straight(void);
void gripper_arm_close(void);
void gripper_bakc_position(void);
void turn_robot_right(int turn_ticks);
void turn_robot_left(int turn_ticks);
void turn_robot_right1w(int turn_ticks);
void turn_robot_right1w_backward();
void turn_robot_left1w(int turn_ticks);
void move_robot_forward(int distance_ticks);
void move_robot_backward(int distance_ticks);
void move_robot_forward_longway(void);
void move_robot_forward_longway_andi(void);

void follow_black_line(int distance_ticks);
void follow_black_line_left(int distance_ticks);
void follow_black_line_medical(void);
void follow_black_lineh(void);
void follow_black_lineh2(void);
void follow_grey_line(void);
void find_medical_center(void);
void twerk(int distance_ticks);

void sort_right(void);
void sort_left(void);

void sort_skybridge(void);
void sort_underbridge(void);
void open_green_door(void);
void open_red_door(void);	



int main()
{

  //---------------------move to the first postition infront of the houses, collect the blue poms and load them down in the container
    turn_robot_right1w(1000);
    forward_house();
    turn_robot_right1w(1300);
    move_robot_backward(-2000);
    highposition();
    enable_servos();
    gripper_startpoint();
    lowpositiondots();
    move_robot_forward_longway_andi();
    move_robot_forward(2500);
    msleep(tw);
    gripper_arm_close();
    msleep(tw);
    highposition();
    turn_robot_left(380);
    move_robot_forward(360);
    lowpositioncont();
    msleep(500);
    highposition();
    move_robot_backward(-380);
    turn_robot_right(300);
    lowpositiondots();
    gripper_arm_close();
    msleep(tw);
    highposition();
    turn_robot_left(300);
    move_robot_forward(380);
    lowpositioncont();
    highposition();
    gripper_back_position();
    //msleep(tw);
    move_robot_backward(-700);
    turn_robot_right(380);
    turn_robot_right(turn_ticks_1);
    
    //the robot drives along the black line in the middle and collects the citiziens in each gap
	
    forward1();
    move_robot_forward(1000);
    turn_robot_right(turn_ticks_1);*/
    enable_servos();
    set_servo_position(sort_serv,1095);
    follow_black_line(2400);
    //-------------take citiziens bridge1 and sort them-----------
    follow_black_lineh();                       
    move_robot_backward(-990); // anpassen!!
    turn_robot_right(turn_ticks_1);
    highposition();
    gripper_startpoint();
    lowposition();
    //set_servo_position(gripper_serv,900);
    // ... take citzienes on /under skybridge
    take_citiziens(1320);
    msleep(100);
    move_robot_backward(-1600);
    highposition();
    gripper_download();
    set_servo_position(sort_serv, sortright);
    msleep(500);
    sort_left();
    msleep(500); 
    turn_robot_left(turn_ticks_1);
    sort_right();
    msleep(500);
    follow_black_line(2000);
    sort_left();
    msleep(500);
    set_servo_position(sort_serv,1295);
    
    //-------------take citiziens bridge2 and sort them-----------    
    follow_black_line(4900);
    //follow_black_line(100);
    //move_robot_backward(300);
    turn_robot_right(turn_ticks_1);
    //move_robot_forward(500);
    highposition();
    gripper_startpoint();
    lowposition();
    set_servo_position(gripper_serv,1000);
    // ... take citzienes on /under skybridge
    take_citiziens(1300);
    msleep(100);
    gripper_arm_close();
    
    move_robot_backward(-1600);
    highposition();
    gripper_download();
    highposition();
    set_servo_position(sort_serv,1450);
    msleep(1000);
    sort_left();
    msleep(500);
    turn_robot_left(turn_ticks_1);
    sort_right();
    msleep(1000);
    follow_black_line(2500);
    sort_left();
    msleep(500);
    set_servo_position(sort_serv,1295);
    
    //-------------take citiziens bridge3 and sort them-----------    
    follow_black_line(5000);
    //move_robot_backward(-800);
    turn_robot_right(turn_ticks_1);
    //move_robot_forward(500);
    highposition();
    gripper_startpoint();
    lowposition();
    set_servo_position(gripper_serv,1000);
    // ... take citzienes on /under skybridge
    take_citiziens(1300);
    msleep(100);
    gripper_arm_close();
    move_robot_backward(-1600);
    highposition();
    gripper_download();
    highposition();
    set_servo_position(sort_serv,1450);
    msleep(1000);
    sort_left();
    msleep(500);
    turn_robot_left(turn_ticks_3);
    sort_right();
    msleep(500);
    follow_black_line(2500);
  	sort_left();
    msleep(500);
    set_servo_position(sort_serv,1295);
    
    //-------------take citiziens bridge4 and sort them-----------    
    follow_black_line(5000);
    //move_robot_backward(-800);
    turn_robot_right(turn_ticks_3);
    //move_robot_forward(500);
    highposition();
    gripper_startpoint();
    lowposition();
    set_servo_position(gripper_serv,1000);
    // ... take citzienes on /under skybridge
    take_citiziens(1300);
    msleep(100);
    gripper_arm_close();
    move_robot_backward(-1600);
    highposition();
    gripper_download();
    highposition();
    set_servo_position(sort_serv,1450);
    msleep(500);
    sort_left();
    msleep(500);
    turn_robot_left(turn_ticks_3);
    sort_right();
    msleep(1000);
    follow_black_line(2500);
    sort_left();
    msleep(500);
    disable_servos();

    return 0;
}


void gripper_startpoint(void)  //gripper is moved into the start position
{
    int position_servo=5;

    while(position_servo <= 2035)
    {
        position_servo=position_servo+15;
        msleep(5);
        set_servo_position(arm_serv, position_servo);
    }
    msleep(10);

    set_servo_position(turn_serv, left_serv_pos);
    msleep(10);
    set_servo_position(gripper_serv, close_serv_pos);
    msleep(tw);

}
void lowposition(void)  //gripper is moved in the bottom-position
{
    int l=0;
    int downticks2 = -4610;
    cmpc (updown);
    msleep(10);
    set_servo_position(turn_serv, 1100);
    msleep(10);
    set_servo_position(gripper_serv, 1100);

    msleep(tw);

    while(downticks2 <= gmpc(updown) )
    {
        motor(updown,-100);     
    }
    msleep(10);
    motor(updown,0);
    /*
    while (l<250){
        l++;
        motor(updown,50);
    }
    */
    msleep(100);
    set_servo_position(gripper_serv, 950);
    msleep(tw);

}

void lowpositiondots(void)   //gripper is moved in the bottom position to get the dots
{
    int l=0;
    int downticks3 = -4400;

    cmpc(updown);
    set_servo_position(turn_serv, 790);
    set_servo_position(gripper_serv, 400);

    while(downticks3 <= gmpc(updown))
    {
        motor(updown,-100);     
    }

    motor(updown,0);  
    msleep(10);
}

void lowpositioncont(void)   //moves the gripper in the  right position to put the dots into the container
{
    int l=0;
    int downticks3 = -1700;

    cmpc(updown);

    while(downticks3 <= gmpc(updown))
    {
        motor(updown,-100);     
    }
    set_servo_position(gripper_serv, 400);
    motor(updown,0);  

}


void highposition(void)  //moves the gripper in the highest position
{
    int t=0;
    while(digital(0)==0)
    {
        motor(updown,100);     
    }
    motor(updown,0);  
    while (t<190){
        t++;
        motor(updown,-70);
    }
    motor(updown,0);  
    set_servo_position(turn_serv, 350);
    set_servo_position(gripper_serv, 1700);
    msleep(tw);

}

void gripper_bridge(void)   //moves the gripper in the right position to take the citiziens from the bridge
{
    cmpc(updown);
    int downticks=-1300; 
    while(downticks <= gmpc(updown))
    {
        motor(updown,-60);     
    }
    motor(updown,0);  

    motor(updown,0);  
    set_servo_position(turn_serv, 350);
    set_servo_position(gripper_serv, 400);
    msleep(tw);
}

void gripper_download()   //moves the catched citiziens to the sorting mechanism
{

    cmpc(updown);
    int downticks = -940;
    int t=0;
    int position_servo2;
    position_servo2=2030; 
    
    set_servo_position(gripper_serv,1750);

    while(position_servo2>=10)
    {
        position_servo2=position_servo2-15;
        set_servo_position(gripper_serv,1750);
        msleep(7);
        set_servo_position(arm_serv, position_servo2);
        
    }

    printf("I am cool");
    msleep(tw);
    if(position_servo2<=10){
        set_servo_position(turn_serv, 600);
        while(downticks <= gmpc(updown))
        {
            motor(updown,-100);
        }   
        motor(updown,0);  
        msleep(50);
        set_servo_position(1, 1200);
        msleep(tw);
         while(digital(0)==0)
        {
            motor(updown,100);
        }   
    }
}

void gripper_back_position()   // moves the gripper on the position over the load area
{

    int position_servo2;
    position_servo2=2030; 

    while(position_servo2>=10)
    {
        position_servo2=position_servo2-15;
        msleep(5);
        set_servo_position(arm_serv, position_servo2);
    }

    msleep(tw);
}


void gripper_turn_straight(void)   //moves the gripper into horizontal position
{
    set_servo_position(turn_serv, 1230);
}

void gripper_arm_close(void)    //gripper is closed
{
    set_servo_position(gripper_serv, 1700);
    msleep(tw);
}  

void sort_right(void)   //sorts the green citiziens on the right side of the load area
{

    int position_servo;
    position_servo=sortleft; 

    while(position_servo<sortright)
    {
        position_servo=position_servo+5;
        msleep(10);
        set_servo_position(3, position_servo);
    }    
    msleep(tw);
}

void sort_left(void)  ////sorts the red citiziens on the left side of the load area
{

    int position_servo;
    position_servo=sortright; 

    while(position_servo>sortleft)
    {
        position_servo=position_servo-5;
        msleep(10);
        set_servo_position(3, position_servo);
    }    
    msleep(tw);


}


void open_green_door()   //opens the door of the green citiziens
{

    set_servo_position(sort_serv,2000);
}

void open_red_door()   ////opens the door of the red citiziens
{

    set_servo_position(sort_serv,100);
}


//---------------------------robot moving-----------------------

void forward1(void){ //moves the robot forward until a black line is detected


    while(analog(0) < blackngrey){
        motor(motor_left,100);
        motor(motor_right,94); 
    }
    motor(motor_left,0);
    motor(motor_right,0); 
    msleep(tw);

}

void forward_grey(void){   ////moves the robot forward until a grey line is detected


    while(analog(0) <=grey){
        motor(motor_left,100);
        motor(motor_right,94); 
    }
    motor(motor_left,0);
    motor(motor_right,0); 
    msleep(tw);

}

void take_citiziens(int distance_ticks){  //robot moves to take the citiziens
    
    cmpc(motor_left);
    cmpc(motor_right);

    while(distance_ticks >= gmpc(motor_left) && distance_ticks >= gmpc(motor_right))
    {
        motor(motor_left,50);
        motor(motor_right,50);																													
    } 
    motor(motor_left,0);
    motor(motor_right,0); 
    msleep(tw);

/*

    while(digital(1) == 0){
        motor(motor_left,51);
        motor(motor_right,51); 
    }
    motor(motor_left,0);
    motor(motor_right,0); 
    msleep(500);*/
    set_servo_position(gripper_serv,1750);
    msleep(tw);

}
void forward_house(void){   //moves the robot to the first house


    while(digital(1) == 0){
        motor(motor_left,motor_left_forward);
        motor(motor_right,motor_right_forward); 
    }
    motor(motor_left,0);
    motor(motor_right,0); 
    msleep(500);
    gripper_arm_close();
    msleep(tw);

}

void move_robot_forward(int distance_ticks)   //moves robot straight ahead
{

    cmpc(motor_left);
    cmpc(motor_right);

    while(distance_ticks >= gmpc(motor_left) && distance_ticks >= gmpc(motor_right))
    {
        motor(motor_left,motor_left_forward);
        motor(motor_right,motor_right_forward);																													
    } 
    motor(motor_left,0);
    motor(motor_right,0); 
    msleep(tw);

}

void move_robot_backward(int distance_ticks) //moves robot backward
{

    cmpc(motor_left);
    cmpc(motor_right);

    while(distance_ticks <= gmpc(motor_left) && distance_ticks <= gmpc(motor_right))
    {
        motor(motor_left,motor_left_backward);
        motor(motor_right,motor_right_backward);
    } 
    motor(motor_left,0);
    motor(motor_right,0); 
    msleep(tw);
}

void turn_robot_right(int turn_ticks)  //moves robot right
{

    cmpc(motor_left);
    cmpc(motor_right);

    while(turn_ticks >= gmpc(motor_left) && turn_ticks >= gmpc(motor_right))
    {
        motor(motor_left,40);
        motor(motor_right,-40);
    }    
    motor(motor_left,0);
    motor(motor_right,0);  
    msleep(tw);
}

void turn_robot_left(int turn_ticks)   //moves robot left
{
    cmpc(motor_left);
    cmpc(motor_right);

    while(turn_ticks >= gmpc(motor_left*0.97) && turn_ticks >= gmpc(motor_right))
    {
        motor(motor_left,-40);
        motor(motor_right,40);
    }   
    motor(motor_left,0);
    motor(motor_right,0);
    msleep(tw);
}

void turn_robot_right1w(int turn_ticks) //turns the robot right but only one wheel is turned
{

    cmpc(motor_left);
    while(turn_ticks >= gmpc(motor_left))
    {
        motor(motor_left,100);
    }    
    motor(motor_left,0);
    msleep(tw);

}

void turn_robot_right1w_backward()  //turns the robot right but only one wheel is turned backward
{
    cmpc(motor_right);
    while(-1900 <=gmpc(motor_right))
    {
        motor(motor_right,-100);
    }    
    motor(motor_right,0);
    msleep(tw);

}    

void turn_robot_left1w(int turn_ticks)   //turns the robot left but only one wheel is turned
{

    cmpc(motor_right);

    while(turn_ticks >= gmpc(motor_right))
    {
        motor(motor_right,100);
    }   
    motor(motor_right,0);
    msleep(tw);
}

void follow_black_line(int distance_ticks){   //robot follows the black line

    cmpc(motor_left);
    cmpc(motor_right);

    while(distance_ticks >= gmpc(motor_left)){
        if(analog(0)<black){				
            motor(motor_right,100);		
            motor(motor_left,80);
        }
        else{
            if(analog(0) >black){		
                motor(motor_left,100);
                motor(motor_right,80);
            }
        }    

    }
    motor(motor_left,0);
    motor(motor_right,0);
    msleep(tw);
}


void follow_black_line_left(int distance_ticks){  //robot follows the black line on the left side

    cmpc(motor_left);
    cmpc(motor_right);

    while(distance_ticks >= gmpc(motor_left)){
        if(analog(0)>black){			
            motor(motor_right,100);		
            motor(motor_left,80);
        }
        else{
            if(analog(0)<black){		
                motor(motor_left,100);	
                motor(motor_right,80);
            }
        }    

    }
    motor(motor_left,0);
    motor(motor_right,0);
    msleep(tw);
}

void follow_black_line_medical(void)   //moves the robot on the line at the medical center
{
    cmpc(motor_left);
    cmpc(motor_right);

    while(analog(2) <= 2000){
        if(analog(0)<black){				
            motor(motor_right,75);		
            motor(motor_left,100);
        }
        else{
            if(analog(0) >black){		
                motor(motor_left,75);	
                motor(motor_right,100);
            }
        }    

    }
    motor(motor_left,0);
    motor(motor_right,0);
    set_servo_position(turn_serv, 830);
    msleep(tw);
}



void follow_black_lineh(){   //follow black line until house1 is detected
    

    while (analog(1)<=1000){
       
        /*
        if(analog(0)<black){				
            motor(motor_right,100);		
            motor(motor_left,90);
        }
        else{
            if(analog(0) >black){		
                motor(motor_left,100);	
                motor(motor_right,90);
            }
        }
        */
        motor(motor_left,motor_left_forward);
    	motor(motor_right,motor_right_forward);
    }
    motor(motor_left,0);
    motor(motor_right,0);
    msleep(tw);


}
void follow_black_lineh2(){  //follow black line until house2 is detected

    while (analog(1)>=900){
        /*
        if(analog(0)<black){				
            motor(motor_right,50);		
            motor(motor_left,40);
        }
        else{
            if(analog(0) >black){		
                motor(motor_left,50);	
                motor(motor_right,40);
            }
        }
        */
         motor(motor_left,motor_left_forward);
   		 motor(motor_right,motor_right_forward);
    }
    motor(motor_left,0);
    motor(motor_right,0);
    msleep(tw);
}



void move_robot_forward_beside_houses(void)  //moves the robot beside the houses
{
    cmpc(motor_left);
    cmpc(motor_right);
    int i = 0;
    int premium_wert = 2850;
    int r = 100;
    int l = 100;
    int deviation = 0;
    int empty = 2900;
    int analog_sensor = 0;


    //move_robot_forward(1500);



    while(analog(2)>1000)
    {
        l = 100;
        r = 100;
        deviation=0;
        analog_sensor = analog(2);
        deviation = (premium_wert - analog_sensor)/2;



        if(analog_sensor >=2850 && analog_sensor <=2900)
        {
            r = 94;
            l = 100;
            i++;
            printf("i++");
        }
        else
        {        

            if((deviation * deviation) > 2500)
            {
                if(deviation < 0) deviation = -10;
                else deviation = 10;
            }


            if(analog(2) > 2840)
            {
                l = l + deviation;
                printf("rechts\n");
            }
            if(analog(2) < 2800)
            {
                r = r - deviation;
                printf("links\n");
            }
        }      	
        motor(motor_left,r);
        motor(motor_right,l);
    }
    motor(motor_left,0);
    motor(motor_right,0);
    set_servo_position(turn_serv, 900);
    msleep(tw);


}


void follow_grey_line(void)  //robot follows the grey line
{
    cmpc(motor_left);
    cmpc(motor_right);

    while(analog(0) < blackngrey){
        if(analog(0)>grey){				
            motor(motor_right,100);		
            motor(motor_left,80);
        }
        else{
            if(analog(0) <grey){		
                motor(motor_left,100);	
                motor(motor_right,80);
            }
        }    

    }
    motor(motor_left,0);
    motor(motor_right,0);
    msleep(tw);
}

void find_medical_center(void){  //robot detects where the medical center is
    while (analog(3)>=4000){
        motor(motor_left,-100);
        motor(motor_right,-94);
    }
    motor(motor_left,0);
    motor(motor_right,0);
    msleep(tw);
}

void twerk(int distance_ticks){   //robot downloads the citieziens with suitable dance moves
    cmpc(motor_left);
    cmpc(motor_right);

    int t=0;

    while(distance_ticks >= gmpc(motor_left) && distance_ticks >= gmpc(motor_right))
    {
        while (t>=1000){
            motor(motor_left,100);
            motor(motor_right,25);	
            t++;
        }
        t=0;
        while (t>=1000){
            motor(motor_left,25);
            motor(motor_right,100);	
            t++;
        }
        t=0;
    } 
    motor(motor_left,0);
    motor(motor_right,0); 
    msleep(tw);


}












