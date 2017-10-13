# How to simulate ATmega328p on proteus
## Required Software
1 - Protues 8.6  
2 - winAVR  
https://sourceforge.net/projects/winavr/files/WinAVR/20100110/WinAVR-20100110-install.exe/download

## Steps
After installing protues and winAVR  
1 - Run protues as admin    
![Run as admin](./p1.PNG)  
2 - Create new project  
![New Project](./p2.PNG)  
3 - Name the project and choose where you want to save it.  
![name](./p3.PNG)  
4 - choose creat schematic
![schematic](./p4.PNG)  
5 - choose don't create a PCB  
![](./p5.PNG)  
6 - choose create firmware project.  
7 - choose AVR in Family.  
8 - choose ATmega328p in controller.  
9 - choose WinAVR in compiler.  
(if WinAVR is not one of the options, please make sure you installed WinAVR, then refere to the section at the end of the document)  
10 - check create quick start files.  
![](./p6.PNG)
11 - you will be greated with 2 tabs:  
source code tab  
![](./p7.PNG)
schematics tab  
![](./p8.PNG)

## WinAVR not detected problem
1 - in the create firmware project window click on compilers
![](./p9.PNG)
2 - a window will open, you will probably find a download button instead of Yes as the photo below
![](./p10.PNG)
3 - click on check all 
![](./p11.PNG)
then a Yes should be written next to WinAVR, if not please send me a message