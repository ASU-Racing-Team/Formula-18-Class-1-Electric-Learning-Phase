# Keil uVision IDE and Simulator
## Creating a new project

1 - From the project menu create a new uVision Project and create a new folder for it and give it a name.  

![](./keil2.PNG)

2 - You have to select a target device for the project, we will be working with stm32f103c8 most of the time.  

![](./keil3.PNG)

3 - Third you have to select what libraries to include.  
![](./keil4.PNG)

3.1 - Under CMSIS check the box next to CORE and DSP.  
![](./keil5.PNG)
3.2 - Under Device check the box next to startup.    
![](./keil6.PNG)
3.3 - Under Device and under StdPeriph Drivers check everything (not everything is shown in the picture but you have to select everything).  
![](./keil7.PNG)
4 - Now you project is created.  
![](./keil8.PNG)
5 - Create a main file.
![](./keil9.PNG)
![](./keil10.PNG)

## Configuring the simulator

1 - double click on Target.  
![](./keil11.PNG)
2 - In Project menu select options for target1.  
![](./keil14.PNG)
3 - In the Target tab change Xtal to 8.  
![](./keil12.PNG)  
4 - In the Debug tab select simulator and check Limit Speed to Real-Time and Load Application at Startup.  
5 - and change Dialog DLL to DARMSTM.DLL.  
6 - and change paramter to -pSTM32F103C8.  
![](./keil13.PNG)

