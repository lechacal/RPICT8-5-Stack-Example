# RPICT8-5-Stack-Example

Arduino and python to run a 5 stack RPICT8 to offer 40 AC current sensor reading on one Raspberrypi.

Arduino reads the CT sensor and send them by serial text message to the Raspberry pi. The python script running on the Raspberry Pi read this information and print them on terminal in a matrix format.

Simple installation. Upload the arduino sketch to the RPICT8. Then get the python script on the Raspbberypi.

![alt text](https://github.com/lechacal/RPICT8-5-Stack-Example/raw/master/Matrix_output.png)

## Installation
Follow this guide below to prepare the Raspberry Pi for arduino upload.

http://lechacal.com/wiki/index.php?title=Upload_Arduino_sketch_from_Raspberrypi_to_RPICT

Then upload the hex file with

```lcl-upload-sketch.sh RPICT8_5STACK_1.1.ino.hex```
