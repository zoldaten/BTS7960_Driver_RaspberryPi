#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

namespace bts7960{
    
    class Driver{
        public:
            void Test(){
                Initiate_Drivers();
                delay(1000);
                Forward();
                delay(5000);
                Backward();
            }

            void Forward(){
                softPwmWrite(D1_RPWM, 40);
                softPwmWrite(D2_RPWM, 40);
                delay(250);
                softPwmStop(D1_RPWM);
                softPwmStop(D2_RPWM);

            }
            void Left(){
                softPwmWrite(D1_RPWM,40);
                delay(250);
                softPwmStop(D1_RPWM);
            }

            void Rigth(){
                softPwmWrite( D2_RPWM, 40);
                delay(250);
                softPwmStop(D2_RPWM);
            }


            void Backward(){
                softPwmWrite(D1_LPWM, 40);
                softPwmWrite(D2_LPWM, 40);
                delay(250);
                softPwmStop(D1_LPWM);
                softPwmStop(D2_LPWM);

            }

        private:
        //Driver Gpio Declaration
//################################################
        //#### DRIVER 1 MOVEMENT ENABLE PIN #####
            int D1_R_EN = 23;// BCM 13;
            int D1_L_EN = 22;// BCM 6;

            //DRIVER 1 Forward & Backward 
            
            //Driver 1 Forward Movement
            int D1_RPWM = 25;// BCM 26;

            //Driver 1 Backward Movement
            int D1_LPWM = 24; // BCM 19;

            //Driver 1 PWM Pin
            int rpwm_d1;
            int lpwm_d1;

//##########################################################

///#########################################################
        //#### DRIVER 2 MOVEMENT ENABLE PIN #####
            int D2_R_EN = 27; // BCM 16;
            int D2_L_EN = 26; // BCM 12;

            //DRIVER 2 Forward & Backward

            //Driver 2 Forward Movement
            int D2_RPWM = 29; //BCM 21;
            //Driver 2 Backward Movement
            int D2_LPWM = 28;  //BCM 20;

            //Driver 2 PWM PIN
            int rpwm_d2;
            int lpwm_d2;

        //Gpio initiation and setup declaration
            void Initiate_Drivers(){
                wiringPiSetup();
                
                //Enable all pins of driver 1
                pinMode(D1_R_EN, OUTPUT);
                pinMode(D1_L_EN, OUTPUT);
                pinMode(D1_RPWM, OUTPUT);
                pinMode(D1_LPWM, OUTPUT); 


                //Enable alls pins of driver 2
                pinMode(D2_R_EN, OUTPUT);
                pinMode(D2_L_EN, OUTPUT);
                pinMode(D2_RPWM, OUTPUT);
                pinMode(D2_LPWM, OUTPUT);

                //Enable Driver-1 Forward & Backward
                digitalWrite(D1_R_EN ,HIGH);
                digitalWrite(D1_L_EN ,HIGH); 

                //Enable Driver-2 Forward & Backward
                digitalWrite(D2_R_EN, HIGH);
                digitalWrite(D2_L_EN, HIGH);
                

                //create the pwm for the driver's
                //DRIVER 1
                rpwm_d1 = softPwmCreate(D1_RPWM, 0,100);
                
                //check for error at the creation of the rpwm_d1 
                error_gpio(rpwm_d1, D1_RPWM);
                
                lpwm_d1 = softPwmCreate(D1_LPWM, 0, 100);

                //Check for the error at the creation of the lpwm_d1
                error_gpio(lpwm_d1, D1_LPWM);

                //DRIVER 2
                rpwm_d2 = softPwmCreate(D2_RPWM, 0, 100);

                //Check for the error at the creation of the rpwm_d2
                error_gpio(rpwm_d2, D2_RPWM);

                lpwm_d2 = softPwmCreate(D2_LPWM, 0, 100);

                //Check for the error at the creation of the lpwm_d2
                error_gpio(lpwm_d2, D2_LPWM);

            }

            

            //Check for error at the pwm pin declaration
            void error_gpio(int pwm_value, int Pin){
                if (pwm_value != 0)
                {
                    std::cout << "The pwm pin was not succesfully creatd for the " << Pin << "return value was: " << pwm_value << std::endl;

                    exit(EXIT_FAILURE);
                }

                if (pwm_value == 0 ){
                    std::cout << "pwm pin was succesfully created for: " << Pin << " return value was: " << pwm_value << std::endl;  
                }

            }

            void CleanUp(){

            }

    };
}
