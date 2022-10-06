#include <iostream>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <sstream>
#include <string>
#include <arpa/inet.h>
#include <chrono>
#include <thread>

//First task create glfw window


// Second task Get arrow key input from window 

// Third task print arrow key being press 




class Client {
    public:
    int main() {

        glfw_parameters();

        Socket_param();
        
        while(!glfwWindowShouldClose(window)){
            std::this_thread::sleep_for(std::chrono::milliseconds(125)); 
            
            Keyboard_Input();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }


        glfwTerminate();
        return EXIT_SUCCESS;
    }




    private:
        struct MSG{
            int msg;
        };
        MSG DATA;
        //socket client parameters 
        int S,n; 
        struct sockaddr_in serverAddr;
        socklen_t addrLen = sizeof(struct sockaddr_in);

        //Declaring the server IP ADDRESS & PORT
        char Ip[15] = "192.168.0.5";
        int port = 100;


        //GLFW parameters
        GLFWwindow* window;

        // GLFW window inital parameters 
        void glfw_parameters(){
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            //Generate the glfw window 
            window = glfwCreateWindow(800, 600, "GLFW",NULL,NULL);
            if (window == NULL){
                std::cout << "Failed to open GLFW Window" << std::endl;
                glfwTerminate();
                exit(EXIT_FAILURE);
            }

            glfwMakeContextCurrent(window);
        }   


    void Keyboard_Input(){
       
        // If Esc press by user close window and socket
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            std::cout << " Exting window " << std::endl;

            //Send closing socke message 
            DATA.msg = 5;

            Send_msg();
            
            //Close glfw window
            glfwSetWindowShouldClose(window, true);
            

        }

        //DETECTING ARROW KEYS
        if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
            std::cout << " Forward " << std::endl;
            //Write value to the struct 
            DATA.msg = 1;
            //Send struct  data to the server 
            Send_msg();
        }

        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
            std::cout << " Backward " << std::endl;
            //Write value to the struct 
            DATA.msg = 2;
            //Send struct data to the server 
            Send_msg();
        }

        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
            std::cout << " Right " << std::endl;

            //Write value to the struct
            DATA.msg = 3;

            //Send Struct  data to the server

            Send_msg();
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
            std::cout << " Left " << std::endl;

            //Write value to the struct 
            DATA.msg = 4;
            //Send Struct data to the server
            Send_msg();

        }



    }

    //Declaring the socket parameters
    void Socket_param(){
        if ((S = socket(PF_INET, SOCK_STREAM, 0)) < 0){
            std::cerr << "Error atdeclaring socket"<<std::endl;
            exit(1);
        }
        std::cout << "Socket has being declare "<<std::endl;


        //Declaring the ip, port & packega 

        serverAddr.sin_family = PF_INET;
        serverAddr.sin_addr.s_addr = inet_addr(Ip);
        serverAddr.sin_port = htons(port);


        if (connect(S, (sockaddr*) &serverAddr, addrLen)< 0 ){
            std::cerr <<"Error at declaring socket " << std::endl;
            exit(1);
        }
        std::cout << "Connection between the client & server has been establish "<< std::endl;

    }
    
    //Send data to the server 
    void Send_msg()
    {
        send(S, &DATA, sizeof(DATA), 0);
    }


};


int main(int argc, char** argv) {
    Client client;

    client.main();


    return 0;
}
