# CGL Input system

**Setting up Input in the window:**  

To set up your window for Input, all you have to do is use the SetWindow command
```c
cgl::Input::SetWindow(window);
```
This makes it so that your window can receive input.

---

## Checking for input

**Keys**

To check for input you'll use one of the IsKey functions or IsMouseButton functions.  
Here's an example on the IsKeyPressed function.  
```c
if (cgl::Input::IsKeyPressed(cgl::Key::Space)){
    std::cout << "The space key was pressed";
}
```
This will print "The space key was pressed" once on the frame that space was pressed on.  
  
Here is an example on how to use the IsKeyDown function
```C
if (cgl::Input::IsKeyDown(cgl::Key::Space)) {
    std::cout << "The space key is down";
}
```
The IsKeyDown function checks if a key is down and it triggers every frame that the specified key is down.  
So every frame that the space key is down, it will print "The space key is down"

Here is an example on how to use the IsKeyReleased function
```c
if (cgl::Input::IsKeyReleased(cgl::Key::Space)) {
    std::cout << "The space key was released";
}
```
Triggers once on the frame the key was released on

**Mouse Buttons**

It works the exact same way for the mouse buttons, but here are all the functions
```c
if (cgl::Input:IsMouseButtonPressed(cgl::Mouse::LeftMouseButton)) {
    std::cout << "The left mouse butoon was pressed";
}
```

Triggers once on the frame the mouse button was pressed
```C
if (cgl::Input:IsMouseButtonDown(cgl::Mouse::LeftMouseButton)) {
    std::cout << "The left mouse button is down"
}
```
Triggers every frame the mouse button is down
```c
if (cgl::Input::IsMouseButtonReleased(cgl::Mouse::LeftMouseButton)) {
    std::cout << "The left mouse button was released"
}
```
Triggers once on the frame the mouse button was released
