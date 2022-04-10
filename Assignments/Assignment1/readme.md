# Assignment 1: STILL

## Description
For this assignment, we made thematic images consisting of shapes that can be controlled by sliders. There are 3 themes that the user can choose from that are meant to be consonant; forest, ocean, and desert. 

## Algorithm 
The first thing we did was, in the header file, initialize the gui as well as the parameter groups and specific parameters that we want to have displayed. We then initialized arrays for the themes and ___shapes___ for the shapes. Next, in the app file, we added the categories to their groups based on what they control, whether it's the theme or the shapes, assigning the starting values as well as the ranges for each of the controlled categories. Next, we added 5 colors in each theme array that were purposely chosen from [Coolers](https://coolors.co/) to go with the selected themes. ____shapes_____ .The rest of the code was in the draw function so that it's constantly ongoing. We set the background to a dark color that's close to black as we wanted the colors on top to stand out, we set the initial color to white and the _____shapes____ based on the starting points in the setup function. We then created a for loop to assign the colors based on the chosen theme and ensure that the 5 colors of each theme are repeated so that no one color is shown more than the others. The segment of code that controls this is as follows, with an example of the forest theme:

```
int j = 0;
int count = 0;
    
for (int i = 0; i < nShapes; i++){
        if (count % 5 == 0) {
            j = i;
        }        
        ofSetColor(forest_array[i-j].x, forest_array[i-j].y, forest_array[i-j].z); //example for forest theme
        **** code for the rest of the themes and to draw shapes ****
        count ++;
}
```

This was made to restart the starting color from the array after 5 shapes are drawn. _____shapes____ . This was finally followed by the gui.draw() function and we added a few lines to take screenshots when the _____s button____ is pressed and ran the code. 

## Sample Output 
This is the initial screen.
![The first image](/Assignments/Assignment1/images/screenshot0.png)

Here, we ___did something__
![The second image](/Assignments/Assignment1/images/screenshot1.png)

And here ____something___
![The third image](/Assignments/Assignment1/images/screenshot2.png)

## Evaluation
Overall, we are satisfied with our output as we really liked the idea of having a consistent theme and focused on the colors and how they go together. Neither of us had really focused on that in the previous sketch so this one allowed us to be creative and deliver a thematic outcome. 

_____explain your creative process, your inspirations and your decision to stop at a certain point. are you satisfied with the work (it's ok not to be)? did you achieve what you expected? did you end up somewhere unexpected?________
