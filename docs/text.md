# Displaying Text In The Window

> [!TIP]  
> You can download free fonts at [Google Font](https://fonts.google.com)  
> You'll need a font in order to use and draw Text  

---

First, you'll make a text object, like with the window

```c
cgl::Text text(window.GetVGContext(), "Font Name", "Hello World", x, y, 24);
```
The "x" and "y" will have to replaced by the cordinates you want the text to be drawn in    
The "Font Name" will have to be replaced by whatever name you give your font once you load it. Here's how to do that.  

```c
text.LoadFont("Roboto", "Path\\To\\Font.ttf") // For example Roboto
```
This will load the .ttf file and make it be referenced as "Roboto".  
  
Now you will draw the text to the window in your while loop. Like this.
```c
while (!window.ShouldClose()) {
        window.ClearColorBufferBit();
        window.PollEvents();

		    cgl::Draw::BeginDraw(window);

		    text.Draw();


		    cgl::Draw::EndDraw(window);

		    window.SwapBuffers();
    }
}
```
Here is a full simple code to do this  

```c
#include <cgl.hpp>
#include <iostream>

int main() {
	cgl::Window window(800, 600, "Window Name");

	cgl::Text text(window.GetVGContext(), "Roboto", "Hello World", 300, 300, 24);

	text.LoadFont("Roboto", "Your path");

    while (!window.ShouldClose()) {
        window.ClearColorBufferBit();
        window.PollEvents();

		    cgl::Draw::BeginDraw(window);

		    text.Draw();


		    cgl::Draw::EndDraw(window);

		    window.SwapBuffers();
    }
}
```
This is what should come out:  
<img width="790" height="624" alt="Näyttökuva 2025-11-28 205518" src="https://github.com/user-attachments/assets/ad8b955c-2eb6-4d5d-a997-d95341a10547" />  

## SetText functions

You can also change the text anywhere in the code by using SetText(); here's a small example:  

```c
text.Draw();
text.SetText("What's up");
```

this will simply change the text to "What's up"  

## Show And Hide

The following functions are pretty straight forward:

```c
text.Show();
```
and
```c
text.Hide();
```

text.Show(); sets an internal private boolean called "visible" to true which means it will draw Text normally.  
While text.Hide(); sets it to false which means that the compiler will ignore the draw function.

## SetPosition function

This is how you can change the position of the text  
```c
text.SetPosition(300, 400);
```
The `300`, `400` are the x and y coordinates that the text will be located at once you have set the position.
