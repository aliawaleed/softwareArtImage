# Assignment 1: Motion

## Description
For this assignment, I wanted to elaborate on the sunset effect that I created in the previous sketch and so I wanted to complete the picture by having a story that expresses time. When run, the user sees a living room setup with a window in the background that imitates a sunrise and sunset. Once it starts setting, this is when more effects take place. As the sun sets, I put down the blinds, dim the lighting in the room, and turn on the lamp on the side, setting the overall atmosphere. This is one complete cycle, and it keeps repeating; sun rising -> sun setting -> blinds closing, lights dimming, lamp turning on -> dark sleepy room and repeat. 

Below is an image of the initial screen:
![initial](/images/initial.jpg)

## Algorithm
The first thing I did was setup the sunset using the previous code that I made, referenced [here](https://github.com/aliawaleed/softwareArtImage/tree/main/sketch2). In setup, I initially set the starting position and color of the sun which are later incremented in the draw function as it runs. I also initialized the background colors for the 3 different phases of the cycle so that the color would gradually change to them creating a smooth effect representing the sunrise/sunset in an accurate way. I also set the color changing times to be at seconds 1, 10, and 18 as when I ran it multiple times and changed using trial and error, these values made the most sense to me. The color of the background is updating in the draw() function using ```ofGetElapsedTimef()``` and making the changes to the time and the color accordingly. An example from the second change time is as follows

```
} else if (animationTime < secondChangeTime) {
        float timeSinceFirst = animationTime - firstChangeTime;
        float percentageToSecond = timeSinceFirst / (secondChangeTime - firstChangeTime);
        
        // transition into color
        drawBgColor = firstBgColor.getLerped(secondBgColor, percentageToSecond);   
```
This function gets the time, updates it, and smoothly transitions to the next color that I have set in the setup() function. After the background and the sun were done, I started working on the foreground. The first thing I did was put up the walls, which took me so much time as I used trial and error to try and find the best combination that would allow me to use the rest of the empty space to set the scene. Next, I worked on setting up the blinds, have them go down with the sunset, up with the sunrise, and ensure that they stop at the very top when being pulled up and limiting to just after the window. 

The code snippet for this could be seen below:
```
if (posX >= (w/2)) {
        center = true;
        posY += 0.7;
        dim += 0.3;
        if(curtainY < (h/8)*4 + 20){
            curtainY += 1;
        }
        // sun color
        ofSetColor(r, g -= 0.1, b -=0.1);
    }
    else{
        posY -= 0.7;
        if (started == true){
            dim -= 0.3;
            if(curtainY > 20){
                curtainY -= 1;
            }
        }
        // sun color
        ofSetColor(r, g -= 0.2, b -=0.2);
}
```
Several changes occur together when the sun reaches the center of the screen and starts to send. The ```started``` boolean variable is set to true when the ................... 

After that, I made a lamp using some shapes and an image that I got online for the lamp cover, and wrote the code to control turning the light for the lamp on and off, playing around with different colors for the lamp as well as the walls as it wasn't very clear at the beginning. I then added a couch at the center and changed the color to match the rest of the room. 

At this point, I felt that it was still incomplete as there was still a lot of empty space, so I added a plant on the left side, which also had some negative space, which made me decide on adding a wall frame with an image above it. The colors, however, were so far off and didn't go together, which made me also change the color of the images by basically adding an effect on them. 

Below is an example of the code for drawing the tree and the couch:
```
    ofSetColor(112, 76, 47); //filter
    couch.draw(w/6, (h/8)*4 + 20, w/3*2, h/3*2 + 20);
    tree.draw(0, h/2 - 80, w/4, h/1.5);
```
The w and h variables are the ```ofGetWidth()``` and ```ofGetHeight()``` functions, respectively, as I noticed that I repeated them over 30 times each throughout the code, so I changed it for convenience. Positioning items on the screen and putting them together, like the lamp, for example, were also very time consuming as, from start to end, it was all trial and error. 

## Sample Output


## Evaluation

