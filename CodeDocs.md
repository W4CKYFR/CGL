# CGL Code Documentation:

> [!NOTE]
> This documentation includes everything AFTER installation.    
> The installation guide is in [README.md](https://github.com/W4CKYFR/CGL/blob/main/README.md)
> These docs mostly have code examples and guides/tutorials on how to use CGL.  
> All other info you will also find in the [README.md](https://github.com/W4CKYFR/CGL/blob/main/README.md)
> To learn C++ fundamentals you can go to [cppreference.com]( https://cppreference.com/)
> Learning C++ isn't necessary, but is recommended for the best experience.


## Including CGL (After Installation) and making a main loop

To **include** CGL in your C++ project you will use  
```cpp
#include <cgl.hpp>

int main() {
  // Everything else goes inside the main loop
}
```
  
This will **include** the cgl.hpp which has all the other header files in it.  
This makes it so you won't have to include multiple different .hpp files for your project.  

## Creating a window object and opening it.

Now we will create a **window** object. 
```cpp
cgl::Window window(width, height, "Window Name");
```  
Replace the **"width"** and **"height"** by an **integer** like for example 800, 600 if you want an 800 by 600 window.

Now we will keep it **open** by using window.ShouldClose() which is a **boolean** that checks if the window should close or not  
```cpp
if (!window.ShouldClose()) {
  // Everything that happens in the window goes in here
}
```  


