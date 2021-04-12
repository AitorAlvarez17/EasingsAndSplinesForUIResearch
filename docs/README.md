
## Easing and splines for UI animations
I am Aitor Alvarez, a student from the CITM grade in videogame design and development. This page is my personal research for Project 2 in Easing and splines for UI animations.

This will take you to the presentation of this subject.

##  Theme description

When creating animations for the UI in a videogame, we can follow a series of methods in order to create a decent and good looking environment. This Page is focused on the movement of objects in the screen and how to make them as smooth and clean while making them dynamic by moving them. 

We will be using a method used in animation called **Easing** . And in the implementation of this method we will be using a series of mathematical functions that are called splines.

Combining both concepts we can move parts of the UI like buttons, windows or text as well as all the visual components of our game giving them a aesthetic touch.



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

![Spline types](http://www.pixeltrollgames.com/RetroBlit/docs/doc/interpolate.gif)

And here are some spline representations with a back and forward motion thanks to @febucci

![@febucci on twitter](https://i.pinimg.com/originals/49/47/82/4947823a1ac8ddef3a55ef7042f4edcf.gif)



