# Colorines-Programming
Repository for Advanced Graphics Programming Class
Authors: Joan Pareja, Pere Rifà

# Features
## General
**Create new scene:** Create a new blank scene, discarding the current one.      
**Save scene:** Save the current scene into a .jope file.       
**Load scene:** Load any .jope scene into the editor (it will discard the current scene).        

## Hierarchy
**Add Entity:** Add a new game object to the scene       
**Remove Entity:** Remove the selected object from the scene      
**Click GO name:** Select the clicked game object      

## Inspector 
**Name:** Change the name of the Game object      

### Transform
**Translation:** Change the 2D position of the game object (X,Y)      
**Scale:** Change 2D scale of the game object (X,Y)      

### Renderer

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


