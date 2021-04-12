
## Easing and splines for UI animations
I am Aitor Alvarez, a student from the CITM grade in videogame design and development. This page is my personal research for Project 2 in Easing and splines for UI animations.

This will take you to the [presentation](https://docs.google.com/presentation/d/1DchWIS5Of7QDwTispPUSkauCu0xbICoxWO3KHe7a0NE/edit?usp=sharing) of this subject.

Download the code [Here](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/releases/tag/1.3).

##  Theme description

When creating animations for the UI in a videogame, we can follow a series of methods in order to create a decent and good looking environment. This Page is focused on the movement of objects in the screen and how to make them as smooth and clean while making them dynamic by moving them. 

We will be using a method used in animation called **Easing** . And in the implementation of this method we will be using a series of mathematical functions that are called splines.

Combining both concepts we can move parts of the UI like buttons, windows or text as well as all the visual components of our game giving them a aesthetic touch.

![ease](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/1.gif?raw=true)

![ease2](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/3.gif?raw=true)

## Problem Description

When we are changing the position of an object on screen, we normally just change the variable directly using something close to this:

```markdown
app->render->camera.x = 100;

rect.x = 200;

player->position.x = 300.0f;
```



Or if we are changing its position considering a time value we may use the delta time like this:

```markdown
app->render->camera.x += 50 * dt;

rect.x -= 20 * dt;
```



But this will leave us with a basic  linear movement that we can alter changing the first value in the sequence. 

This method is really useful for plain and straight to the point movement, like when you make the camera follow the player with something in the lines of:

```markdown
update(float dt)
{
	app->render->camera.x = player.position.x - 300;
	app->render->camera.y = player.position.y - 200;
}
```



But when we want to create a smooth movement animation with defined accelerations through time we can not use this method, its to simple and we would have to invest a lot of time into creating a method, and here is where the easing enters.

## Easing

The **Easing functions** specify the rate of change of a parameter over time.

The implementation of this functions allows us to move objects in a natural way, because in real life objects don't move at a constant speed all the time. They accelerate or deaccelerate and they don't stop immediately.

This easing function in mathematics are called **Splines** and are used in programming because of their simplicity and easy to work with structure. On top of this they are very accurate.

## Splines

Here are some Spline examples with their representation:

![Some Splines](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/interpolate.gif?raw=true)

![@febucci on twitter](https://i.pinimg.com/originals/49/47/82/4947823a1ac8ddef3a55ef7042f4edcf.gif)

[Here](https://matthewlein.com/tools/ceaser) you can create your own splines, it could be helpful to you in the future.

This splines are framed by 4 values:

- **Initial Value (b):** The initial position of the object in our game.
- **Final Value (c):** Final position on the object in our game.
- **Current Time (t):** Time passed since the start of the movement.
- **Duration (d):** The total time of the movement.

For reference, in the code you can find each of this values as:

- **Initial Value (b):** origin.
- **Final Value (c):** finish.
- **Current Time (t):** timePassed or timeCounter.
- **Duration (d):** time or totalTime.

**In depth explanation** of the formulas of each of the splines [here](http://www.gizma.com/easing/#l).

Because of the shape of the function, we can have 3 main characteristics:

- **Ease in:** The spline accelerates through time, starting slow and ending fast.
- **Ease out:** The spline starts fast but it deaccelerates at the end.
- **Ease In and out:** The spline has both properties, it accelerates and then deaccelerates at the end of the movement.

A spline can have infinite shapes, but it can be defined also by the amount of Ease in and out that it has.

- Ease
  ![ease](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/1.gif?raw=true)

- Circ
  ![Circ](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/2.gif?raw=true)
- Back
  ![Back](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/3.gif?raw=true)
- Expo
  ![Expo](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/4.gif?raw=true)
- Quad
  ![Quad](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/5.gif?raw=true)
- Cubic
  ![Cubic](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/6.gif?raw=true)
- Quart
  ![Quart](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/7.gif?raw=true)
- Quint
  ![Quint](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/8.gif?raw=true)

**UI**

![UI](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/gifs/UI.gif?raw=true)


## Code

The code that I present to you is the implementation of an Easing module that allows us to move any object following a spline. Inside this class we can find a series of spline functions that can be modified as much as the user wants. I implemented some of this functions in order to create some examples of this implementation.

### Main struct

![Main Struct](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/SplineInfo.PNG?raw=true)



This is the information that every single Spline that you create in your game will have. In the constructor you will introduce the position of the object, the final position of the movement, the time that it will take to move and the type of Easing function that you want to use in the SplineType field.

Then we have a class and a struct in order to keep track of the amount of Splines that we have and their respective function calls.

![SplineType](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/SplineType.PNG?raw=true)

Then we have the main body of the class:

![Body](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/MainBody.PNG?raw=true)

### TODO's

I have separated all the main code into 5 TODO's:

#### TODO 1

Found on Easing.h

![TODO1](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo%201.PNG?raw=true)

Solution:

![TODO1Solved](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo%201%20complete.PNG?raw=true)

#### TODO 2

Found on Easing.cpp

![TODO2](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo%202%20incomplete.PNG?raw=true)

Solution:

![TODO2Solved](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo%202%20completed.PNG?raw=true)

#### TODO 3

Found on Easing.cpp

![TODO3](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo3%20incomplete.PNG?raw=true)

Solution:

![TODO3Solved](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo%203%20complete.PNG?raw=true)

#### TODO 4

Found on Easing.cpp

![TODO4](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo%204%20incomplete.PNG?raw=true)

Solution:

![TODO4Solved](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo%204%20complete.PNG?raw=true)

#### TODO 5

Found on Easing.cpp

![TODO5](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo%205%20incomplete.PNG?raw=true)

Solution:

This amount of functions is not neccesary, but I wanted to give an example of the amount that you can create

![TODO5olved](https://github.com/AitorAlvarez17/EasingsAndSplinesForUIResearch/blob/master/docs/images/Todo%205%20complete.PNG?raw=true)


### Improvements

I tried to keep the code as simple as possible, but in doing so is not that complete. I would include a second variable for a movement in another axis, because now you can only move in one direction. I would also include a Spline creator for splines like the quad or quint, that just change in the amount of times the variable timePassed has been multiplied.

### References

http://www.gizma.com/easing/#l

https://matthewlein.com/tools/ceaser

https://easings.net/

https://medium.com/motion-in-interaction/animation-principles-in-ui-design-understanding-easing-bea05243fe3

https://es.wikipedia.org/wiki/Spline#:~:text=En%20el%20subcampo%20matem%C3%A1tico%20del,definida%20en%20porciones%20mediante%20polinomios.

https://stackoverflow.com/questions/8316882/what-is-an-easing-function
