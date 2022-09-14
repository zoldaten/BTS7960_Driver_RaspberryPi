from ast import While
import socket 
import pygame
import sys

class Client:
    def __init__(self):
        try:
            #Defining pygame parameters
            pygame.init();
            self.fps = 30;
            self.fpsclock = pygame.time.Clock();
            self.sur_obj = pygame.display.set_mode((400,300));
            pygame.display.set_caption("Keyboard_Input");
            White=(255,255,255)            
            p1=10
            p2 = 10
            step = 1
            
            #Socket Parameters bein call
            self.address = ("192.168.0.9",100)
            self.s = ""
            self.S_call();

            #Get arrow key's data
            while True:
                self.sur_obj.fill(White);
                pygame.draw.rect(self.sur_obj, (255,0,0), (p1, p2, 70, 65))
                for eve in pygame.event.get():
                    
                    if eve.type==pygame.QUIT:
                        pygame.quit()
                        sys.exit()
                        
                        
                ##################################        
                #GET KEYBOARD INPUT
                key_input = pygame.key.get_pressed()
                
                ##############################
                if key_input[pygame.K_UP]:
                    p2 -= step
                    self.Send_msg(message="1")
                ###############################
                    print("Moving forward")
                
               ##################################
                    
                if key_input[pygame.K_DOWN]:
                    p2 += step
                    self.Send_msg(message="2")
                ##################################    
                    print("Moving Down")
                    
                #################################
                if key_input[pygame.K_LEFT]:
                    p1 -= step
                    self.Send_msg(message="3");
                #################################
                    print("Moving Left")
                #################################
                #this if statement get's rigth arrow key input
                ###############################################
                if key_input[pygame.K_RIGHT]:
                    p1 += step
                    self.Send_msg(message="4")
                    print ("Moving Right")
                    
                #################################
                
                pygame.display.update()
                self.fpsclock.tick(self.fps)
        
        except KeyboardInterrupt:
            print("\nKeyboardInterrupt system closing!\n");
            self.s.close();
            print("Socket connection is close!\n")            
            sys.exit()

    
    def S_call(self):
        #Declaring socket 
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # connect to server 
        self.s.connect(self.address);
        print("Connecting to server at: " + str(self.address[0]) + ":" + str(self.address[1]))


#CLOSE SOCKET AFTER INTERACTION
#        self.s.close()

# Send message to server
    def Send_msg(self,message):
        self.s.send(message.encode('utf-8'));


if __name__ == "__main__":
    Client();
