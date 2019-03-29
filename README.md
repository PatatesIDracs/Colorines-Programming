# Colorines-Programming
Repository for Advanced Graphics Programming Class
Authors: Joan Pareja, Pere Rifà

# Features
## General
![FileMenu](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/FileMenu.PNG)      
**New scene:** Create a new blank scene, discarding the current one.      
![New_scene_toolbar](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/NewScene_Toolbar.PNG)      
**Open scene:** Load any .jope scene into the editor (it will discard the current scene).      
![Load_scene_toolbar](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/LoadScene_Toolbar.PNG)    
**Save scene:** Save the current scene into a .jope file.       
![Save_scene_toolbar](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/SaveScene_Toolbar.PNG)      
   

## Hierarchy
![Hierarchy_window](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/Hierarchy%20window.PNG)      
**Add Entity:** Add a new game object to the scene       
**Remove Entity:** Remove the selected object from the scene      
**Click GO name:** Select the clicked game object      

## Inspector 
![Inspector_window](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/Inspector_window.PNG)      
**Name:** Change the name of the Game object      

### Transform
![Transform_window](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/Transform_window.PNG)      
**Translation:** Change the 2D position of the game object (X,Y)      
**Scale:** Change 2D scale of the game object (X,Y)      

### Renderer
![Renderer_window](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/Renderer_window.PNG)      
**Shape:** Select the Game object shape (point, line, rect, circle, ellipse)      
 - Point: Simple point, no more properites     
 - Line: Draw a line from object position to the Point 2 coordinates     
 - Rect: Rectangle with specified width and height      
 - Circle: Perfect circle with specified radius, can't be deformed      
 - Ellipse: Circle with specified radius, can be deformed with scale changes     

**Point 2 X and Y (Line shape only):** Change the position of the second point of the line    
**Width and Height (Rect shape only):** Change the width and height of the rectangle      
**Radius (Circle and ellipse only):** Change the radius of the circle or ellipse.    
 
**Fill color:** Color of the object shape     
**Stroke color:** Color of object shape outer line      
**Stroke thick:** How thick the outer line will be     
**Stroke Style:** Drawn style of the outer line     


# Qt features    
**Slots & signals:**    
The default signals from the Qt widgets were connected to diferent slots in order to affect objects in the scene when
their values change. We have also created custom signals to easly manage the scene update.      

**QDialogs: Color & File**    
QFileDialog is used to save and load different scenes.       
QColorDialog is used in order to select the colors in the renderer options.      

**QDataStream:**     
Is used to read and write data to/from a stream in order to save and load scenes.      

**QPainter:**   
Used to render an paint the diferent objects in the scene window.     

**Stylesheet:**      
Small stylesheet changes are used in order to display the selected color for the object in the color selection button.

