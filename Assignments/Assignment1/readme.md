# Lines and Points

## Description
For this assignment, I made drawing with lines and points that can be controlled by sliders. This drawing is meant to always be symmetrical with the points perfectly spaced and the number of lines and points increasing together, with the lines always starting at the center and growing out to the edges of the screen, passing through the points on the screen and connecting them together. A slider is also displayed for the user to interact with the drawing and control several aspects displayed.

The user can control all elements on the screen through the color as well as the number. The first slider is to choose the desired R,G,B values by playing around or using the color picker. Then the number of points and lines on the screen can be controlled, with a specified range, again always maintaining a constant distance. This is followed by controlling the lines through their width, and then the points through changing the radius.

## Algorithm 
The first thing I did was, in the header file, initialize the gui as well as the parameter groups and specific parameters that I want to have displaued on it. Next, I went into the app file and added the categories to their groups based on what they do and set the starting points as well as ranges for each of the controlled categories. The rest of the code was in the draw function so that it's constantly ongoing. I set the background to a dark color that's close to black as I wanted the colors on top to stand out, I set the initial color as one of my favorite colors and the width of the lines based on the starting points in the setup function. This was nested followed by a nested for loop to create the rows and columns of the circles and base the number of lines on that. Below is the segment of code that I wrote to put them in place, I had to think about it mathematically in order to implement it.

```
    for (int i = 1; i < number; i++) {
        for (int j = 1; j < number; j++) {
            ofDrawCircle((ofGetWidth()/number) * i, (ofGetHeight()/number) * j, radius);
            ofDrawLine((ofGetWidth()/number) * i, (ofGetHeight()/number) * j, ofGetWidth()/2,ofGetHeight()/2);
        }
    }
```

This was finally followed by the gui.draw() function and I added a few lines to take screenshots when the space bar is pressed and ran it. 

## Sample Output 
This is the initial screen.
![The first image](/screenshots/screenshot0.png)

Here I played around with the sliders, changed the points' radius and lines' width, and increased the number of lines and circles.
![The second image](/screenshots/screenshot4.png)

And here I added even more lines.
![The third image](/screenshots/screenshot3.png)
