# PID Motor Control Plan 
## Project Goal
  To design a method to successfully and accurately control a blender motor through an Arduino AC dimmer that will allow for the addition of PID code to minimize error. Due date: Jan 17, 2019
## Success Criteria
- The end goal for the entire project is to have a motor that maintains a constant speed no matter the level of resistance. This goal will be accomplished by combining our motor-AC dimmer complex with Justine and Ella's photoreflector sensor which will calculate the speed. 

- For our section of the project, our measures of success are: 
1. Being able to accurately control the speed of a motor using the AC dimmer and a potentiometer
2. The AC dimmer arduino complex can efficently attached to the rest of the blender 

## Project Schedule 
 ### Weekly Goals (To December 13): 
Nov 26-Dec 1:
  Georgia- Finish basic outline of the plan and schedule. Research and come back from break with several ideas for setup. Finish notebook. 
  Basir- Finish notebook
Dec 1- Dec 6: 
  Georgia- Finish plan specifics. Decide on specific methods for setup, power, etc. Make materials list. Write criteria and constraints.
  Basir- Finish fritzng by Friday, work on mock assembly?
Dec 8- Dec 13:
  Georgia- Gather and plan materials, use list from plan. Begin setup. 
  Basir- Finish and check Solidworks mock assembly 
  
  ***NOTE*** It turns out that these goals were actually due Friday, the 6th, so in addition to catching up on these we will also complete 
  Basir: Finish fritzing and work on code 
  Georgia: Work on code and gather materials/start setup 
  
  ## Materials
  - RobotDyn 1 Channel AC Arduino Dimmer (from Amazon)
  - Arduino METRO 
  - Blender (motor and power cords are a part of this)
  - Wires 
  - Potentiometer 
  - Resistor
  - 3D printer and necessary material
  - Acrylic to be laser cut
  - Breadboard (or prototyping shield, depends on structure of 
  - Metal standoffs (for inside of 3D printed assembly)
  - Tools (Wire cutters, sautering equipment, etc)
  
  All materials currently needed should be easily obtainable from the part bins, the AC dimmer was ordered from Amazon and the blender belongs to Basir. If we need anything else in the future we will most likely use Amazon as our main resource, but we shouldn't need any other special components since we already have the dimmer and the blender with its motor, power wires, etc. 
  
  ## Description
   ### SolidWorks Box
  We are going to use the AC dimmer we got from Amazon to control and decrease the 120 V current running from a wall outlet into the blender motor. We are not going to print a new body for the blender but will instead create a box in SolidWorks that will attach to the back of the blender and contain the Arduino, breadboard, wiring, and dimmer. Wires will run from this into the original body of the blender in order to attach to the motor and the blender's power cable will extend from here and connect to a wall outlet. Considerations for this part include:
  
  - The potentiometer must be easily accessible on the outside of the blender so for now we should plan to sauter wires onto it, if we simply plug it into the breadboard will we not be able to access it once the assembly is added to the blender.
  - The addition of the assembly must not throw off the balance of the blender and in order to do this it should take up as little weight and space as possible. The issue of balance is one of the reasons why we chose to add the assembly to the back of the blender and not to one of the sides.
  - Cost is also an issue but this has been resolved by designing the component to include as little 3D printed material as possible. This means creating a skeleton with the 3D printer and then sliding in acrylic sides. The four columns that serve as the structure for this part are all hollow in the center and contain metal standoffs for ease of assembly. Photos are attached below after the more in-depth description.
  - Related to both the issues of balance and cost is the consideration of size. Our goal is to minimize size, for both of these reasons, and in order to decrease the size of the box we must decrease the size of its contents. We can do this by custom cutting wires and taking care to arrange all components as efficiently as possible. We also had to decide whether we should use a breadboard or a prototyping shield. We decided on the prototyping shield as it would take up less space and facilitate wiring. 
  Keeping in mind all of these considerations and constraints, Basir created a design for the box in SolidWorks that meets all criteria. I. We figured it would easier to create the box and figure out how much space we had to work with before planning the wiring so we planned the box first. The box is a skeleton of a 3D printed floor with four hollow columns attached. The columns have slots to hold sheets of acrylic for the walls and metal standoffs inside of them to easily attach the top. There are holes on the bottom to screw in the Arduino and holes in the sides to attach the box to the blender. There is also a grid of large holes on the back so that the box will blend in with the design of the blender, which has a similar grid on the front for ventilation. 
  
   ### Wiring
   
   We will start work on wiring after we have printed and assembled the box in order to know what space we have to work with. In terms of components for the wiring part of this assignment we will need:
  
   - Arduino METRO (Similar to UNO but uses micro USB, has on/off switch for power, LED on side with USB port)
   - RobotDyn 1 Channel AC Arduino Dimmer (Pretty much THE most important part of the project, allows us to control the motor)
   - Blender (For motor and power cable)
   - Wires (All should be custom cut and color coded)
   - Prototyping sheild (Takes up less space than breadboard, easier to connect)
   - Resistor
   - Potentiometer (Will sauter on longer wires for easier access)
   
   We will have the fritzing diagrams complete by the end of the week (Dec. 13) but we know that the basic outline of the fritzing will involve 120 V of power from an outlet going into the AC dimmer, the dimmer being controlled by the Arduino according to te potentiometer, and the decreased voltage power running from the dimmer to the motor. It is possible that issues could occur when we actually put together the wiring because we have to devise a safe method for cutting the blender's power cord and attaching it to the the dimmer as input. Also, we have to find a way to connect (most likely sauter) the motor to he power wires coming from the Arduino. As previously stated, we also have to ensure that all components fit efficiently into the box and that the potentiometer is accessible. To add to the challenge we will have to exercise extra caution due to the high voltage that will be entering the dimmer from the power outlet.   
   
   ### Code
   While we work on the wiring we will also be creating a code to go with it. This code will not yet include the PID aspect of the project that Ella and Justine are working on. It will simply have our part of the code which controls the motor and does not adjust for resistance. One both our projects are complete we will combine our codes (and our wiring) to create a final product. The deadline for the code is the same as the deadline for the wiring (Dec. 13). Obviously this means that we wil have limited time to test run our code before we complete it. Friday, in class, we will test both our code and our wiring once both are complet For now, however, we should stil be able to create a mostly-accurate test code using online resources and elements of past projects (i.e. the potentiometer project).
   The code will use some variable (most likely readValue) to read the value of the potentiometer and then convert this to another variable (probably writeValue) which will be sent to the dimmer to tell it how much to decrease the voltage. This is very similar to the [Potentiometer Project Code](https://github.com/gwyatt40/Intermediate-Arduino/blob/master/Potentiometer/potentiometer1.ino) except minus the LCD and with a motor instead of an LED. Also with a much, much higher voltage.
   The most difficult aspect of the coding for this project will definitely be using the AC dimmer. Figuring out pins, functions, and potentially libraries for this new component could be challenging, but thankfully (as always) there is plenty of information online. One helpful resource is the [Customer Questions and Answers](https://www.amazon.com/RobotDyn-controller-control-Arduino-Raspberry/dp/B072K9P7KH/ref=sr_1_1_sspa?hvadid=77721769478724&hvbmt=be&hvdev=c&hvqmt=e&keywords=ac%2Bdimmer%2Barduino&qid=1576082989&sr=8-1-spons&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzQVRGVFJBSzE1UkEwJmVuY3J5cHRlZElkPUEwNTA5NDQ1MjIxRFpaNk1LTTFMNyZlbmNyeXB0ZWRBZElkPUEwNjQ0NjQ2MTFMMTEyMDdRMTQwNyZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU&th=1) on the Amazon page for the product we bought. Customers have posted their own codes, uses for the dimmer, and responses to other's questions so the page contains lots of useful information. 
# PID Motor Control Documentation 

## Overview 
As stated in the plan, our over all goal for this project was to use an AC dimmer to control the voltage going to a motor and thus be able to alter its speed. In order to do this we had to wire up a circuit containing a dimmer, a motor, and a potentiometer; create a code that could control this circuit; and build an addition to the handmixer that could efficiently contain the both dimmer and the arduino. Our original due date for this project was January 17, 2020, however, due to a few setbacks, we did not complete this project until February 21, 2020. 

## Final Images
Below are several photos of our final product.



<img src = "https://github.com/gwyatt40/PID-Motor-Control/blob/master/Media/Screenshot14.png" width="400" height="400">

<img src = "https://github.com/gwyatt40/PID-Motor-Control/blob/master/Media/Screenshot15.png" width="400" height="400">

<img src = "https://github.com/gwyatt40/PID-Motor-Control/blob/master/Media/Screenshot16.png" width="400" height="400">

## Solidworks 
We needed a box to place the Arduino, dimmer, and other wires inside it and attach it on the back of the mixer to make everything look nice and clean. The first design was not approved because it used a lot of support material, I redesigned the box this time I printed the base and top of the box to cut the cost and did not use any support materials. And I laser cut the sides from clear plastic so we could see the inside and make sure everything is where they supposed to be.  

<img src = "https://github.com/gwyatt40/PID-Motor-Control-/blob/master/Media/SWBoxAssembly.png" width="400">

 - The complete assembly (open view)

<img src = "https://github.com/gwyatt40/PID-Motor-Control-/blob/master/Media/SWBoxAssemblyClosed.png" width="400">

 - The complete assembly (closed view)

<img src = "https://github.com/gwyatt40/PID-Motor-Control-/blob/master/Media/SWBoxBase.png" width="400">

 - The base of the box attachment; where the Arduino attaches 

<img src = "https://github.com/gwyatt40/PID-Motor-Control-/blob/master/Media/SWBoxLid.png" width="400">

 - The lid for the box attachment; where the dimmer attaches

<img src = "https://github.com/gwyatt40/PID-Motor-Control-/blob/master/Media/SWBoxSide.png" width="400">

 - The side of the box attatchment, 3 out of 4 sides look like this

<img src = "https://github.com/gwyatt40/PID-Motor-Control-/blob/master/Media/SWBoxBack.png" width="400">

 - The fourth side of the box that attaches to the mixer, holes for screws and power cable

## Code
The main objective for the code with this project was to convert a value read from a potentiometer to a value that could be written by the AC dimmer. Our original thought had been to use a code from the dimmerś amazon project page, as mentioned in the plan, however, none of the several codes we tried from Amazon qworked properly, so we had to look elsewhere online. We eventually found a code that used timers already built into the arduino to control the dimmer by activating certain components, such as the zero cross detector, at certain points along the voltage wave. Once we were able to control the dimmer, we wrote a map function that converted the value of a potentiometer to avalue that was written by the dimmer. The main issue with this code was that, because it used the Arduino's timers to control the dimmer, it couldn't use the Serial Monitor, any delays, or any other timer-based functions. This meant that the only was to test it was to wire it up to something. Because we didn't want to deal with the motor yet, we first hooked the dimmer up to a lightbulb to try out the code. It's worth noting that a potential reason for the failure of the first Amazon codes we tried was due to the fact that our dimmer broke at some point during the trail process (more detail on that in the wiring section). (Insert two codes, one original commets and one with my comments.)

## Wiring 
The wiring for this project wasn't as difficult as the code because there was more information and documentation online, mostly on the [Amazon](https://www.amazon.com/RobotDyn-controller-control-Arduino-Raspberry/dp/B072K9P7KH) and [RobotDyn Company](https://robotdyn.com/ac-light-dimmer-module-1-channel-3-3v-5v-logic-ac-50-60hz-220v-110v.html) pages. We did have to exercise a certain degree of caution because we were dealing with 120V. The main issue that occured with the wiring was that the first AC dimmer we ordered was either broken when we ordered it or broke when we accidentally touched two wires from the power source together near it. We aren't sure which and we only realised it was broken after Mr. Diroff helped us run a very simple test code that failed to turn on our test lightbulb. When we ordered a new dimmer (the same RobotDyn model) the test code worked immediately. The wiring diagrams below are pretty comprehensive but one bit of extra information is that we found that the negative side of the power cable had faint writing on it and the positive side did not, which allowed us to differentiate them. 

<img src = "https://github.com/gwyatt40/PID-Motor-Control-/blob/master/Media/RobotDynFritzing.png" width="750">

- Fritzing diagram from the [RobotDyn Website](https://robotdyn.com/ac-light-dimmer-module-1-channel-3-3v-5v-logic-ac-50-60hz-220v-110v.html)

<img src = "https://github.com/gwyatt40/PID-Motor-Control/blob/master/Media/ProjectFritzing.png" width="700">

- A diagram of our final fritzing
## Schedule 
We didn't really have a comprehensive schedule for this project, but here's a link to our [weekly milestone goals from January 8th onward](https://docs.google.com/document/d/1TzHuSQZx-D-xI5e1sqXkh7DXw1wI24h5xXonfPMz6lk/edit?usp=sharing). Information about our pre-Winter Break schedule is in the plan section of this read.me, under "Weekly Goals (To December 13)". 

## Conclusions and Lessons Learned 
  Overall, despite going well over its original time limit, this project was a success. The finished product wasn't perfect, the motor turned at a very high speed at would jump a bit at lower potentiometer values, but we met our orignial goal of being able to control it with an AC dimmer. Here are some lessons we learned/things we would change if we did the project again: 
  
  - Create a concrete schedule- We didn't really have a specific, day-by-day schedule going into this project. We ended up making weekly goals as we went along. This worked out in the end, but we could have used our time more efficiently if we had planned ahead. Also, instead of being written at the very beginning of our project, our plan was created a week or two in and was very vague and  focuesd on short term goals which was not helpful. 
  - Document over the course of the project- It would have been helpful to have an ongoing record of the codes we tried, problems we ran into, etc. instead of summarizing everything at the end of the project.
  - Understand how a code works before trying it- I began to completely read over codes and try to figure out exactly what they were doing towards the end of the project, but at the beginning I immediately tested any code I found and moved on to the next if it didn't work. This wasted time and meant that I might have missed easily fixable errors in otherwise functional codes. 
 

Need:  ,comment and caption codes, put each archive code in own correct folder,
  
