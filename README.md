# Epaper temperature display

This is a README for the project

Im going to assume that you are smarter than me(me when I started the project I mean),  
if you need more detailed info for the intalation process, read the Detailed_Guide.md

### Features 
Shows CPU temp in both numbers and a graph.

Shows GPU temp in both numbers and a graph.

Shows time.

### How it was created

I saw a review of Valve's steam machine, and noticed that they have a  
special cover, that displayed the systems temperature and other stuff.  
I thought: "damn, thats a cool thing, lemme make it!"(exact wording of my thought btw).  
I got the display, started coding the basic layout function, just to get a raw demo, of how  
it will look like when finished.

After that, I used my 9th grade math(I am now about to start highschool(as of 19th of July 2026))  
to make a formula to draw the graph. After explaining the logic behind my thinking, I put the  
.txt file into Claude (dont tell them about my age please:), and it created some syntax, which I then  
polished(I can assure you 99% of the logic you see in the code is made by me, I used AI only for  
syntax, since Im a newbie).

After several attpempts, I have gotten a clean (well, not proffesianally clean, but working and  
somewhat understandable) code. 

After that came the 3d modeling, and thats where I am somewhat skilled. I designed a case for  
the display I had, and after some resting for rethinking the choices I made in the design 3d printed it.

After assembly came some finishing code touches, then came the setup on Task Scheduler, which was quite easy.


### Parts used

Raspberry Pi Pico

WeAct Studio 4.2 inch display ("WeAct 4.2'' 4.2 Inch Epaper Module E-paper E-Ink EInk Display Screen SPI Black-White" on aliexpress)

USB A to microUSB cable

Some TheFillament PLA HS

### How to set up

If using the same parts as me:  

Install all the needed libraries(they are mentioned in the python script).

Connect the pins to the ones marked in teh code(not neccesarry for most of them, some can be changed in code ofc)

3d print out the case with the .step file linked

Glue the parts to one another in the spots they should go (it is assembled in the file, so you can use it as guidance).

Install Libre Hardware Monitor and run the server

Schedule the launch of LHM in the Task Scheduler on boot.

Test if the script is working for you(I mean the update.pyw).

If it does, schedule it in the Task Scheduler on boot, but with some delay(mine is set to 30 seconds, just for sure).

If not, you might need to search for the right ID in the json file and change it in the script.

Then plug in the cable, and upload the code to raspberry pi.

After that, to test it all(without restearting your system) justrun the update file in cmd and watch the magic happen.


