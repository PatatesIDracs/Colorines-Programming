# Colorines-Programming
Repository for Advanced Graphics Programming Class
Authors: Joan Pareja, Pere Rifà

# Features
## General
**Create new scene:** Create a new blank scene, discarding the current one.      
![New_scene_filemenu](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/NewScene_FileMenu.PNG)
![New_scene_toolbar](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/NewScene_Toolbar.PNG)      
**Load scene:** Load any .jope scene into the editor (it will discard the current scene).      
![Load_scene_filemenu](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/LoadScene_FileMenu.PNG)
![Load_scene_toolbar](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/LoadScene_Toolbar.PNG)    
**Save scene:** Save the current scene into a .jope file.       
![Save_scene_filemenu](https://github.com/PatatesIDracs/Colorines-Programming/blob/master/Images/SaveScene_FileMenu.PNG)
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


