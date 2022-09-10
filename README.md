# BTS7960_Driver
BTS7960 is a  high-power drive full H-bridge driver module with thermal over-current protection

<p align="center">
  <img src="https://raw.githubusercontent.com/The-GUY-2024/BTS7960_Driver/main/src/bts7960.jpg" width="250" />
</p>

# Description
This is simple explanation on how to use the BTS7960 with the raspberry pi is a very simple task 
(i'm doing this to simplify your life)

In my case i have 2 bts7960 connected to the raspberry pi

# Connection Schematic
VCC = 5v raspberry pi
GND = GND raspberry pi
raspberry pi pin mode is BCM 

## This are the pin for Driver 1 

* BCM pin (20) = Driver pin (R_EN) 

* BCM pin (21) = Driver pin (L_EN)
             
* This are the Movement pin 

* BCM pin (19) = Driver pin (RPWM)

* BCM pin (26) = Driver pin (LPWM)
             
## This are the pin for Driver 2

* BCM pin () = Driver pin ()

* BCM pin () = Driver pin ()

### This are movement pin
* BCM pin () = Driver pin ()

*BCM pin () = Driver pin ()
             
<p align="center">
  <img src="https://raw.githubusercontent.com/The-GUY-2024/BTS7960_Driver/main/src/rsp.png" width="400" />


</p>
