#include <kipr/botball.h>
#include <definitions.h>



void extend_extension(int speed);
void extend_extension_steps(int steps, int speed);
void rise_extension(int position, int speed);
void fold_extension(int position, int speed);
void gripper_rotate(int position, int *gripped);
void retract_extension(int position, int speed);
int abs(int number);

void turn_forward(int distance);
void turn_forward_gripping();
void turn_backwards(int distance);
void turn_left(int angle);
void turn_right(int angle);
void move_to_black_line();
int  find_fire();
int  find_fire2();
void follow_black_line(int distance);
void follow_black_line_backwards(int distance);
void grippen(int position);



struct fire
{
    int red1;
    int yellow1;
};


int main()
{

    //-------------------INIT------------------------

    int i = 0;
    int j = 0;
    int burning_house = 0;
    int burning_hospital = 0;
    int burning = 0;
    int burningh = 0;

    //--------------------------preparing-the-robot-for-hands-off-------------------
    enable_servos();
    printf("enabled servos\n");   
    create_connect();
    //create_full();
    printf("create connected\n"); 
    camera_open_black();
    camera_open();
    printf("camera connected\n");


    grippen(open);
    msleep(10);
    //wait_for_light(1);
    shut_down_in(119);


    //-------------------------------------------------------------------------------------------------------------------------    
    //-------------------------------------------------------------------------------------------------------------------------    
    //------------------------------------------------------start-of-main------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------  
/*

	extend_extension_steps(400,fast);											//preparing the robot for the driving part
    rise_extension(2400,fast);
    msleep(10);
    extend_extension_steps(half_height,fast); 									
    msleep(10);


    //drive to the middle
    turn_forward(distance_first_turn);											//drive over the "disater relief" zone line
    move_to_black_line();														//reference at "utility" zone line
    turn_forward(200);															//distance until first turn in the "utility" zone
    turn_left(turning_left_angle);												//turn the robot left inside the "utility" zone and add a value to compensate the robots drift if needed
    turn_forward(100);
    move_to_black_line();	
    msleep(10);																	//move to the "black and grey" line
    turn_forward(125);
    while(analog(sensor_line) <= white) create_drive_direct(-250,150);			//while color is white 
    while(analog(sensor_line) >= white) create_drive_direct(-150,150);			//turn, that the robot is facing in direction of the black-grey-line
    create_stop();

    																			//preparing for push the suplies to the first house
    rise_extension(1100,fast);       
    retract_extension(4350, fast);	
    turn_backwards(170);

    																			//following the black line till first house    
    msleep(10);
    follow_black_line(700+backup_distance);										//standard value is 700 till first house pushing the supplies a bit forward
    msleep(10);
    turn_backwards(backup_distance);											//get back in front of the first house
    msleep(10);

    																			//detect fire at first house
    burning = 0;
    i = 0;
    while(i<=2)
    {
        burning = find_fire2();
        if(burning == 1) j++;
        i++;
    }

    j = 0;																			//if first house is not burning
    if(j == 0)
    {
        																		// burning house is zero, so house 2 or 3 is on fire
        burning_house = 0;
        printf("first house is not burning \n");

        																		//get the botguy or the major of botopia from house 1
        msleep(10);
        turn_right(turning_right_angle+20);
        msleep(10);
        extend_extension(fast);
        retract_extension(skyscrapper0,avg);

        // turn forward to the first house and grip the object
        turn_forward_gripping();
        grippen(close);
        msleep(200);
        //deliver object into "disaster relief" zone
        extend_extension(fast);
        turn_backwards(300);
        turn_right(turning_right_angle*3);
        msleep(10);
        retract_extension(half_height,fast);
        turn_forward(150);
        msleep(10);
        retract_extension(release_height, fast);
        msleep(10);
        //drop the object in the disaster relief zone (can either be master of bottopia or botguy)
        grippen(open);

        //move back to the grey and black line
        msleep(10);
        turn_backwards(300);
        msleep(10);
        turn_right(turning_right_angle-20);
        msleep(10);

    }

    //else first house is burning (remember value for delivery of the water cube)
    else
    {
        burning_house = 1;
        printf("first house is burning \n");
    }


    //---------------------------------------------------------------------------------------------       
    //---------------------following-the-black-line-till-second-house------------------------------
    //-----------------------------create-stays-at-first-house-------------------------------------
    //---------------------------------------------------------------------------------------------  


    follow_black_line(360+backup_distance);
    msleep(10);
    turn_backwards(backup_distance);

    //detect fire at second house
    burning = 0;
    i = 0;
    j = 0;
    while(i<=2)
    {
        burning = find_fire2();
        if(burning == 1) j++;
        i++;
    }

    //if second house is not burning
    if(j == 0)
    {
        printf("second house is not burning \n");
        turn_right(turning_right_angle+20);
        msleep(10);

        extend_extension(fast);
        retract_extension(skyscrapper1,fast);

        //turn forward until the object is in range
        turn_forward_gripping();
        grippen(close);															//get object
        msleep(200);

        //deliver object into "disaster relief" zone
        extend_extension(fast);  
        msleep(10);
        turn_backwards(300);
        retract_extension(2000, fast);
        msleep(10);
        turn_right(turning_right_angle*2+30);
        msleep(10);
        retract_extension(release_height,fast);
        turn_forward(10);
        msleep(10);

        //deliver second object in disater relief zone
        grippen(open);

        //move back to the grey and black line
        msleep(100);
        turn_backwards(100);
        msleep(10);
        turn_right(turning_right_angle);
        msleep(10);

    }

    //else second house is burning
    else 
    {
        printf("second house is burning \n");
        burning_house = 2;  													//remember value for delivery of the water cube
    }




    //---------------------------------------------------------------------------------------------       
    //---------------------following-the-black-line-till-third-house-------------------------------
    //----------------------------create-stays-at-second-house-------------------------------------
    //--------------------------------------------------------------------------------------------- 




    follow_black_line(350+backup_distance);
    msleep(10);
    turn_backwards(backup_distance);


    //detect fire at third house
    burning = 0;
    i = 0;
    while(i <= 2)
    {
        burning = find_fire2();
        if(burning == 1) j++;
        i++;
    }

*/
    //if third house is not burning
    if (j == 0)
    {
        printf("third house is not burning\n");
        turn_right(turning_right_angle+20);
        msleep(10);

        extend_extension(fast);
        retract_extension(skyscrapper0,avg);									//get on top of the third skyscrapper

        turn_forward_gripping();
        grippen(close);															//get the object of the third skyscrapper
        msleep(200);
        //deliver object into "disaster relief" zone
        extend_extension(fast);
        turn_backwards(250);
        turn_right(turning_right_angle*2+30);
        msleep(10);
        
        i=0;
        j=0;
        while(i<=2)																//check which hospital is burning
    	{
        	burningh = find_fire2();
            if(burningh == 1) j++;
        	i++;
    	}
        if(j >= 1)
        {
            burning_hospital = 1;
            printf("hospital 1 is burning");
        }
        else
        {
            burning_hospital = 2;
            printf("hospital 2 is burning");
        }
        
        retract_extension(half_height,avg);
        turn_forward(50);
        msleep(10);
        retract_extension(bottom_extension-half_height-release_height, avg);
        msleep(10);
        grippen(open);															//drop the second object in the disaster relief zone
        //move back to the grey and black line
        msleep(10);
        turn_backwards(100);
        msleep(10);
    }
    //else house 3 is burning
    else
    {
        printf("third house is burning\n");
        burning_house = 3;														//remember the value for delivery of the water cube
        turn_left(turning_left_angle);
        i=0;
        j=0;
        while(i<=2)																//check which hospital is burning
    	{
        	burningh = find_fire2();
            if(burningh == 1)	j++;
        	i++;
    	}
        if(j >= 1)
        {
            burning_hospital = 1;
            printf("hospital 1 is burning");
        }
        else
        {
            burning_hospital = 2;
            printf("hospital 2 is burning");
        }
        turn_right(turning_right_angle);
    }

    //--------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------deliver-the-suplies------------------------------------------------------------    
    //--------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------  

    
    
    
    

    //--------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------deliver-the-fire-truck----------------------------------------------------------    
    //--------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------  

    //get the fire truck
    turn_right(turning_right_angle+40);
    follow_black_line(200);
    turn_left(turning_left_angle);
    move_to_black_line();
    turn_forward(100);

    //gippen

    turn_backwards(200);


    //controll hospital 1 for fire

    

    if(burningh == 0)
    {
        turn_backwards(200);
        turn_right(turning_right_angle);
        turn_forward(100);
        grippen(open);
    }
    else
    {
        turn_right(turning_right_angle);
        turn_forward(100);
        grippen(open);
    }















    //--------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------deliver-the-water-cube----------------------------------------------------------    
    //--------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------  





    //get the water cube after the delivering the fire truck
    switch(burning_hospital)
    {
            //the hospital 1 burns
        case 1:
            turn_backwards(200);
            turn_left(turning_left_angle);
            turn_forward(200);
            grippen(close);

            break;
            //the hospital near the water cube burns    
        case 2:
            turn_backwards(200);
            turn_left(turning_left_angle);
            turn_forward(400);
            grippen(close);
            break;

    }





    //deliver the water cube
    switch(burning_house)
    {
            //deliver the water cube to the first house
        case 1:
            turn_backwards(300);
            turn_left(turning_left_angle);
            follow_black_line(800);
            turn_left(turning_left_angle);
            extend_extension(fast);
            turn_forward(200);
            retract_extension(skyscrapper0,avg);
            grippen(open);

            break;
            //deliver the water cube to the second house    
        case 2:
            turn_backwards(300);
            turn_left(turning_left_angle);
            follow_black_line(600);
            turn_left(turning_left_angle);
            extend_extension(fast);
            turn_forward(200);
            retract_extension(skyscrapper1,avg);
            grippen(open);

            break;
            //deliver the water cube to the third house    
        case 3:
            turn_backwards(300);
            turn_left(turning_left_angle);
            follow_black_line(600);
            turn_left(turning_left_angle);
            extend_extension(fast);
            turn_forward(200);
            retract_extension(skyscrapper0,avg);
            grippen(open);

            break;
    }






















	camera_close();
    disable_servos();
    create_disconnect();
    return 0;
}



//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------sub-programms----------------------------------------------------------    
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------



void rise_extension(int steps, int speed)	//function to deploy the extension by steps and speed
{
    cmpc(motor_rise);   
    while(gmpc(motor_rise) <= steps)	//operate in this while loop, until the number of steps is smaller than var1
    {
        motor_power(motor_rise, speed);
    } 
    motor_power(motor_rise, 2);
    msleep(10);

}
void fold_extension(int steps, int speed)	//function to deploy the extension by steps and speed
{
    cmpc(motor_rise);   
    steps = steps * (-1);
    speed = speed * (-1);

    while(gmpc(motor_rise) >= steps)	//operate in this while loop, until the number of steps is smaller than var1
    {
        motor_power(motor_rise, speed);
    }   
    motor_power(motor_rise, 0);
    msleep(10);
}


void extend_extension(int speed)	//function to deploy the extension by steps and speed
{

    while(digital(sensor_height) == 0)	
    {
        motor_power(motor_extension, speed);
    }
    cmpc(motor_extension);
    motor_power(motor_extension, 0);
    msleep(100);


}
void retract_extension(int steps, int speed)	//function to deploy the extension by steps and speed
{
    cmpc(motor_extension);
    steps = steps * (-1);
    speed = speed * (-1);

    while(gmpc(motor_extension) >= steps)	//operate in this while loop, until the number of steps is smaller than steps
    {
        motor_power(motor_extension, speed);
    }   
    motor_power(motor_extension, 0);
    msleep(100);
}
void extend_extension_steps(int steps, int speed)	//function to deploy the extension by steps and speed
{
    cmpc(motor_extension);   

    while(gmpc(motor_extension) <= steps)	//operate in this while loop, until the number of steps is smaller than steps
    {
        motor_power(motor_extension, speed);
    }   
    motor_power(motor_extension, 0);
    msleep(100);
}


void grippen(int position)
{
    set_servo_position(servo_gripper, position);
    msleep(200);
}

void turn_forward(int distance)
{
    set_create_distance(0);
    while(get_create_distance()<distance)
    {
        create_drive_straight(400); //----------------------------------------normaly 200
    }
    create_stop();
}

void turn_forward_gripping()
{

    while(analog(sensor_distance) > 500)
    {
        create_drive_straight(200); //----------------------------------------normaly 200
    }
    create_stop();
}

void turn_backwards(int distance)
{
    set_create_distance(0);
    while(get_create_distance()>-distance)
    {
        create_drive_straight(-300); //----------------------------------normaly -150
    }
    create_stop();
}

void turn_left(int angle)
{
    set_create_total_angle(0);
    while (get_create_total_angle() < angle)
    {
        create_drive_direct(-150, 150); //-------------------------------------normaly -150,150
    }
    create_stop();
}

void turn_right(int angle)
{
    set_create_total_angle(0);
    while (get_create_total_angle() > -angle)
    {
        create_drive_direct(150, -150); 										//normally 150,-150
    }
    create_stop();
}

void move_to_black_line()
{
    while(analog(sensor_line)<3500)
    {
        create_drive_straight(300);  
    }
    create_stop();
}


int find_fire2()
{
    

    struct fire fire;
    int yellow_is_here=0;
    int fire_found=0;
    fire.yellow1=0;
    fire.red1=0;
    int i =0;

    while(i < 5)
    {

        camera_update();
        fire.yellow1 = fire.yellow1 + get_object_count(yellow);
        i++;

    }
    if(fire.yellow1 >= 2)
    {
        yellow_is_here = 1;
        printf("yellow is here\n");
    }

    if(yellow_is_here == 1)
    {
        i = 0;
        while(i < 5)
        {
            camera_update();
            fire.red1 = fire.red1 + get_object_count(red);
            i++;

        }
        if(fire.red1 >= 2)
        {
            fire_found = 1;
            printf("house is burning\n");

        }
    }
    else fire_found = 0;

    
    return fire_found;
}


void follow_black_line(int distance)
{


    set_create_distance(0);
    while(distance >= get_create_distance())
    {

        if(analog(sensor_line) <= white)
        {										//detected white
            create_drive_direct(300,200);

        }
        else
        {
            if(analog(sensor_line) >= white)
            {									//detected grey

                if(analog(sensor_line) >= grey)
                {
                    create_drive_direct(100,300);
                }
                else  create_drive_direct(200,300);


            }



        } 


    }
    create_stop();
}


int abs(int number)
{
    if(number >= 0) return number;
    else return (number*-1);
} 