import socket 
import sys


class Client:
    def __init__(self):
        try:
            self.address = ("192.168.0.6",100)
            self.s = ""
            self.S_call();

            #Get arrow key's data
            
            self.Send_msg();

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
        self.s.close()

# Send message to server
    def Send_msg(self):
        while True:
            # Get keyboard arrow key input
            msg = "TEST"
            self.s.send(msg.encode('utf-8'));


if __name__ == "__main__":
    Client();