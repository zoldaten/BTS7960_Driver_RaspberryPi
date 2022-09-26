# Simple example to test the bts7960 driver

### To run test.py 

```
sudo python3 test.py
```



# To run remote_PI_server.py & remote_PI_clinet.py

### The remote_PI_server.py run on the raspberry pi 


First you need to seet the socket server ip 

You can ether set socket server ip by running the function get_ip();
and saving the return value to variable (ip)
<p align="center">
  <img src="https://raw.githubusercontent.com/The-GUY-2024/BTS7960_Driver/main/src/Screenshot%20from%202022-09-17%2013-42-57.png" width="350" />
</p>

another way to set server socket ip is 
to write ip address to the variable call(SELF.IP = "10.0.0.7")

<p align="center">

  <img src="https://raw.githubusercontent.com/The-GUY-2024/BTS7960_Driver/main/src/Screenshot%20from%202022-09-17%2013-44-19.png" width="350" />

</p>


### The remote_PI_client.py run on the client or desktop

First you need to seet the socket the client is goint to connect to

<p align="center">
  <img src="https://raw.githubusercontent.com/The-GUY-2024/BTS7960_Driver/main/src/Screenshot%20from%202022-09-17%2014-02-28.png" width="350" />

</p>
  In the (Line 21) write the ip address as (self.address = "IP",100) Enter the raspberry pi address.
  
 ### Before running remote_PI_client.py
 install pygame before you run the remote_PI_client.py
 ```
   sudo pip3 install pygame
 ```

Start the server in the raspberry pi by running 

```
sudo python3 remote_PI_server.py
```

now run the client side 

```
sudo python3 remote_PI_client.py
```



### DEMO GIF Record screen & power chair movement

<p align="center">

  <img src="" width="350" />

</p>
