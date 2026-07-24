# Epaper temperature display

This is a README for the project

Im going to assume that you are smarter than me(me when I started the project I mean),  
if you need more detailed info for the intalation process, read the [Detailed guide](GUIDE/Detailed_guide.md)
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

Before we start, by script I mean update.pyw file, and by program I mean the .ide file.

#### Things to do regardless if you are using the same parts as me

Install all the needed libraries(they are mentioned in the script).

Test if the script is working for you.

If it does, schedule it in the Task Scheduler on boot, but with some delay(mine is set to 30 seconds, just for sure).

If not, you might need to search for the right ID in the json file and change it in the script.

Install Libre Hardware Monitor and run the server.


**Only do next steps, once evetything works**

Schedule the launch of LHM in the Task Scheduler on boot.

Schedule the run of the script 30 seconds after boot(on boot, with some delay).
##### If using the same parts as me:  


Connect the pins to the ones marked in the code(not neccesarry for most of them, some can be changed in code ofc)

After that, to test it all(without restearting your system) just run the update file in cmd and watch the magic happen.

3d print out the case with the .step file linked

obviously test fit it.

Glue the parts to one another in the spots they should go (it is assembled in the file, so you can use it as guidance).


### If you dont use the same parts as me

Get the display working using the pre made libraries.

Paste the lines needed for the display to work into the code.

If the resolution(Im using the 400 by 300 one) is not the same,  
than adjust the basic layout function and the partial refresh window coordinates.

You might also need to adjust the formula to the graph coordinates you use(both formulas are published in the thoughts.txt file).

Design a specific case for your screen mounting style  
(for example Ive heard that on Waveshares displays holes are a different size).

Testfit it and if fits glue it together.

**Congrats, you have completed the project!**
