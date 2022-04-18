## Cyclic Animation (Sunrise/Sunset)

For this cyclic animation, I wanted to do something different that isn't related to specific shapes and playing around with them, so I thought of different cycles that we encounter in our everyday life and so the idea I decided to implement was a sunrise/sunset. I made it to give the impression that the sun is rising from the west, and setting at the east, and it repeats, changing the background color for an effect as well as the color of the sun itself, which I believe could still be improved. 

A video example could be seen below:

https://user-images.githubusercontent.com/57350259/163744843-08d07324-5512-4499-be29-8f0bba1a1bae.mov

As well as some images across different points in time:

<img width="330" alt="1" src="https://user-images.githubusercontent.com/57350259/163745039-2fac193c-6bb3-49ad-a382-197295b3b1f4.png"> <img width="330" alt="2" src="https://user-images.githubusercontent.com/57350259/163745048-394ed99f-b97d-41b6-8519-6d3b2ccb4939.png"> <img width="330" alt="3" src="https://user-images.githubusercontent.com/57350259/163745052-3724da5f-fe7d-4b94-abbd-75b5a46c7104.png">

At first I didn't have the grass at the bottom but decided later to add it to make it clearer that this is actually a sunset as I asked my friends and they couldn't really recognize it at first. Regarding the code, I first initialized the times that I would want the color changes to occur and used the getLerped() function to transition smoothly between the colors. I set the initial color and the second color as 2 separate variables to make sure that the color transition is smooth and starts from the correct shade. 

```
drawBgColor = firstBgColor.getLerped(secondBgColor, percentageToSecond);
```

I then worked on moving the sun in a curve from left to right using some trial and error until I was comfortable with it and every time the sun sets on the right side of the screen, before it rises again, I resetted all of the values and colors to their initial positions and shades to restart the cycle, adding the "ofGetElapsedTimef()" to each of the transition times so that it does the same thing again and again. 

The below code segmed is it move the sun down and change it's color, as this was the most I was satisfied with, although I still believe that there is room for improvement in terms of color as well as figuring out whether or not the transition would be the same on a larger screen. 

```
// if the sun reaches the center, move it downwards
    if (posX >= (ofGetWidth()/2)) {
        posY += 0.7;
        // sun color
        ofSetColor(r, g -= 0.1, b -=0.1);
    }
    else{
        posY -= 0.7;
        // sun color
        ofSetColor(r, g -= 0.2, b -=0.2);
    }
    posX += 1.5;
    ofDrawCircle(posX, posY, radius);
```

Lastly, I added the green rectangle at the bottom. At first, I was going to change its color gradually as well, however, when I watched it, it gave the impression that the color is actually changing so I decided to keep it as it is. 
