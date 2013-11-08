EasyPIC-Speedometer
===================

A "speedometer" example using mikroC and an EasyPIC v7 controller. This was a school project, first time I ever used C.

The idea is to simulate a speedometer, using the analog input range 0V to 5V. 0V = 0 km/hour, 5V = 200 km/h.
Unfortunately, since the analog-to-digital conversion only peaked at 1007 decimal (should be 1024), 
I couldn't make it very accurate, but oh well.
