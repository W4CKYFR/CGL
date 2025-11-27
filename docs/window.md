## Creating a window object and opening it.

Now we will create a **window** object. 
```c
cgl::Window window(width, height, "Window Name");
```  
Replace the **"width"** and **"height"** by an **integer** like for example 800, 600 if you want an 800 by 600 window.  
You can also replace the "Window Name" with whatever you'd like the window to be called.

Now we will keep it **open** by using window.ShouldClose() which is a **boolean** that checks if the window should close or not  
```c
while (!window.ShouldClose()) {
  // Everything that happens in the window goes in here
}
```

Here's what the window should look like once the code is run:  

<img width="790" height="623" alt="Näyttökuva 2025-11-27 203831" src="https://github.com/user-attachments/assets/e70127ee-eed6-45b5-9ecb-59a4e990bd8f" />


## Other Basic Things

in the while statement you should put

```c
window.ClearColorBufferBit(); // Clears the current frame’s color buffer to whatever color you set
window.PollEvents(); // Checks for any pending window or input events and processes them.

window.SwapBuffers(); // This displays the finished frame onto the screen. 
```

Here's what the window should look like once the code is run now:  

<img width="797" height="619" alt="Näyttökuva 2025-11-27 203734" src="https://github.com/user-attachments/assets/63600795-45cf-462d-a77a-0decccc0c2de" />  

This is because the real default color is black, before the SwapBuffers(); just didn't exist so it couldn't swap them to show the true color  

---

Then another small basic thing is **changing** the background **color**.  

Here's how that's done:

```c
window.SetColor(Red, Green, Blue, Alpha); // these are all Floats (0.0-1.0)
if (!window.ShouldClose()){
  window.ClearColorBufferBit();
  window.PollEvents();

  window.SwapBuffers();
}
```

SetColor takes in Red, Green, Blue and Alpha in floats, so that means if you put 

```c
window.SetColor(1.0f, 0.0f, 0.0f, 1.0f);
```

it will be red  

This is how it should look like:

<img width="796" height="638" alt="Näyttökuva 2025-11-27 204817" src="https://github.com/user-attachments/assets/9e16bd5b-2095-47ba-a1fd-8420653009d9" />  
