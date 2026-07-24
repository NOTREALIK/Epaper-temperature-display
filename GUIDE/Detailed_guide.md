# Detailed guide to the project set up.
**This guide might not work for a specific type of displays or microcontrollers, I have no**  
**expirience with Waveshare displays for example, also some microcontrollers might require a**  
**different approach to connecting it to the computer and the display**
## 1. install python and everything needed with it:

Go to the official python erbsite, and download  
the installer that fits your os. 
**IMPORTANT** do not get the windows store installer (the one with .msix)  
as it might not allow for you to create PATH.  
**NOTE** before opening the file, I have to say, wether the file has  
viruses or not is your risk since I cannot control the website you are downloading python from.  
If you are 100% sure that the file is downloaded from the official python website, open it  
with admin priviliges. This should open the menu, tick the boxes saying:  
"Use admin priviliges when installing py.exe" and "Add python.exe to PATH".  
Click on Customize installation, after that tick all boxes(should be ticked by default).  
Click Next, tick the Install Python (version name here) for all users box, leave everything else as is  
(if you wont need anything of it, but if you are jsut starting out, you wont need any of debugging stuff)  
Make sure that the file path to the installation folder is not in any user folder. After that click Install.  

When installed, answer the questions that you are asked and then close thee window.

Open cmd with admin rights, then use these commands:

pip install time  
pip install daytime  
pip install serial  
pip install requests  
pip install pyserial  

Don't worry if any of those are already pre installed on your device.

## 2. Install Arduino IDE:

Cmon dude, please dont make me teach you how to install arduino ide, there are enough guides on youtube.

## 3. Install everything else arduino related:

Depending on your microcontroller(which is reccomended to have at least 32kb ram(but really I'd use some modern controllers  
with basic 256kb ram)) you might need to install an additional board into you Arduino IDE.  
For Raspberry pi pico specifically:

Go to File -> Preferences -> Settings tab -> Additional boards manager URLs: 
Paste this link: https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json in there.

Click OK, then go into the Boards Manager(on the left side of your screen, it looks like a diskette)  
Search for "Raspberry Pi Pico/RP2040/RP2350" by Earle F. Philhower, III and install it.



Depending on your display, you might need a different kind of library.  
I am saying might, because I do not fully know if there are any displays that use anything  
else than Gx_EDP2.  
Open the Library Manager(it is above the Boards Manager, and looks like a folder).  
Search for the "GxEPD2" by Jean-Marc Zingg and install it.

## 4. connecting the microcontroller to the computer and setting it up:

Lets quickly test if your microcontroller is working.
See that window saying something like: "Select board" at the top part of IDE?  
(Im refferenig and will continue to refer as IDE to Arduino IDE)  
Click it, take a little mental note to remember what Com ports are there,  
then connect the controller to your computer via some kind of wire that it uses  
(make sure that the wire can transfer data), to a port in you computer.  
If theres a new COM port available, click on it, then in the board selection select the desired board.
If nothing happens, plug it into a different port(on your computer I mean), if again nothing happens, plug it into another  
up until theres a new COM port available.

Then in the File tab, click Examples and open some script that can test the microcontroller,  
I'd reccomend the one from Built in Examples: Basic: Blink. it works for all the microcontrollers that have an LED in them.

If everything works: W, if not, go troubleshoot it, not my fault gang.

Once troubleshooted(or if it was just working already), connect your display to the microcontroller  
(again, I do not know which one you are using, so its up to you, on how to wire and what code to add in the code to make it work)  
Usually the creators of the displays leave some kind of demo ontheir website/github repository, so test your screen first.

Download the Epaper_display.ino, configure the pinout and whatever other things your display requiers.
After that, download the fonts and put them into C:\Users\your_User\Documents\Arduino\libraries\Adafruit_GFX_Library\Fonts 
This location is the default.

Run the program and check if it works, the graps should appear, as well as the text CPU: GPU:. 

## 5. install Libre Hardware Monitor.

Another case of me not explaining this to you, go on youtube.

However, I will tell you that you need to host your Remote web server.  
To do so, press Options, and at the bottom theres a button: Remote web server.  
Click on it and then click on Run.


## 6. Lets start using the code provided.

Keep LHM(Libre hardware monitor) running.

Download the update.pyw, open CMD with admin rights, copy the path to the update.pyw file,  
configure the **ser = serial.Serial('COM10', 115200)** to your COM port. 
Then in CMD type: "cd file_path_here" and press Enter.  
After that type: "python update.pyw" and press Enter.  
It should now print out your temps of your systems every 3 seconds.

Also, if you kept your display active since 4th step, the display should now show the  
temteratures, draw the dots, and showing the time.


## 7. Seting up all of that to run automatically:

Make sure your LHM and script files are located in a folder every user can access, not in downloads, documents, etc.  
A good example of elegible folder is Program Files.

Then launch the pc from the Administrator account, press windows and type Task Scheduler.
Click on Create task, name it whatever you want.
Check the Run with highest priviliges box. then click on Change User, type SYSTEM and press OK.
Navigate to the Triggers tab, perss New, then in the "Begin the task:" press at startup.
After, navigate to the Actions tab, press New, click Browse, and locate the LHM .exe file(its in the LHM folder).
Then, navigate to the Conditions tab and uncheck the Start the task only if the computer is on AC power.
After which, Click OK.

First task done, now the second one.

Again open task cheduler.
Click on Create task, name it whatever you want.
Check the Run with highest priviliges box. then click on Change User, type SYSTEM and press OK.
Navigate to the Triggers tab, perss New, then in the "Begin the task:" press at startup, check teh Delay task for box, and select 30 seconds.
After, navigate to the Actions tab, press New, click Browse, and locate the update.pyw.
Then navigate to the Conditions tab and uncheck the Start the task only if the computer is on AC power.
Click OK.


**After this every time you turn on your pc, after 30 seconds your display should show you the info. If it doesnt, or you have some kind of questions, contact me.**

## 8. Case
This one is entirely up to you, you can use mine, you can create your own.
