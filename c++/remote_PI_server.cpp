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
#include "motor_driver.hpp"

class Server {
    public:
        int main(){
            std::cout << "Testing motor drivers" << std::endl;

            Md.Test();



            std::cout << "Calling sockets parameters" << std::endl;


            Call_socket();

            while (true){

                rcv_msg();


                std::cout << DATA.msg <<std::endl;
           
                if(DATA.msg == 1 ){
                    std::cout << "Forward" << std::endl;

                    Md.Forward();
                }


                if (DATA.msg == 2 ){
                    std::cout << "Backward" << std::endl;
                    Md.Backward();

                }

                if (DATA.msg == 3 ){
                    std::cout << "Right " << std::endl;

                    Md.Rigth();

                }

                if (DATA.msg == 4){
                    std::cout << "Left " << std::endl;

                    Md.Left();
                }
                if(DATA.msg == 5){
                    std::cout << "Closing system" << std::endl;
                    Close_socket();

                }

            }


            return EXIT_SUCCESS;
        }

    private: 


        //ip address
        char ip[20] = "192.168.0.5";
        //Port number 
        int port = 100;


        // New socket 
        int NewSock;
        //Calling socket 
        int S;

        socklen_t client_len;

        //Server & client socket parameters
        struct sockaddr_in serv_addr, cli_addr;
        int n;

        //Message memory declaration
        struct MSG {
            int msg;
        };
        MSG DATA;

        //Declaring motor driver 
        bts7960::Driver Md;


        //Recive Message from client 
        void rcv_msg(){
           // bzero(buffer, 1024);
            n = recv(NewSock, (void*)&DATA, sizeof(DATA), 0);

            if (n < 0){
                error("Error at reading message from socket");
                Close_socket();
            }
            
        }

        // function to Close socket 
        void Close_socket(){
            std::cout << "Closing client socket " << std::endl;
            close(NewSock);

            std::cout << "Closing server socket " << std::endl;

            close(S);

        }
        //Error message function (Good Practice i guess) 
        void error(const char *msg){
            perror(msg);
            exit(1);
        }
        
        //Socket declaration function
        void Call_socket(){
            S = socket(AF_INET, SOCK_STREAM, 0);
            if (S < 0)
            {
                error("error at socket declaration");
            
            }

            //Declare serve addr
            bzero((char *) &serv_addr, sizeof(serv_addr));


            //Declaring the  network packet family
            serv_addr.sin_family = AF_INET;
            //Declaring the socket IP addres
            serv_addr.sin_addr.s_addr = inet_addr(ip);
            //Declaring the socket PORT
            serv_addr.sin_port = htons(port);

            //Here we bind socket to the information provided above
            int bind_inf = bind(S, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
            if (bind_inf < 0)
            {
                error("Error at binding socket please check Lines (55 to 60).");
            }
            std::cout << "Server is open at address: 127.0.0.1" << ":" << port << std::endl;
            

            //Listen for incoming connection from client 
            listen(S,5);
            
            //storing client address
            client_len = sizeof(cli_addr);

            std::cout << "Accepting clinet socket \n" << std::endl;
            //Accept Incomming connection from client
            NewSock = accept(S, (struct sockaddr *) &cli_addr, &client_len);

            if (NewSock < 0){
                error("Error occure Accepting new client to server");
            
                Close_socket();
            }
            
            std::cout << "Client connected to server \n " << std::endl;
        

        }


};


int main(int argc, char *argv[]){
    Server server;

    server.main();

    return 0;
}
