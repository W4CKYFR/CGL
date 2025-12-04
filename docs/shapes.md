## How to create a shape object in CGL:

To create and draw a shape, you have to make the object, just like with anything else in CGL.  
  
Here, I'll create a simple red triangle, using the default triangle that CGL proides  

```c
cgl::Shape::Triangle myTriangle = cgl::Shape::DefaultTriangle(window.GetVGContext(), cgl::Color::Red);
```

The Default Triangle takes in the NanoVG context which you can get using ``window.GetVGContext()``  
And it also takes in a ``cgl::Color.`` Here, I'm using one of the pre-made colors ``cgl::Color::Red``  
  
You can also create a custom Triangle by setting your own points like this:

```c
cgl::Shape::Triangle myTriangle(window.GetVGContext(), { 100, 100 }, { 200, 100 }, { 150, 200 }, cgl::Color::White;
```
  
The numbers are a ``cgl::Vector2`` variable which takes in x and y. You can change them to whatever you'd like.
  
Here's how you can create a square using the default square that CGL provides:  
```c
cgl::Shape::Rectangle mySquare = cgl::shape::DefaultSquare(window.GetVGContext(), cgl::Color::White);
```

The Default Square also takes in the NanoVG context which you can get by using ``window.GetVGContext()``  
The color also works the exact same way as with the triangle.  

Like with the triangle, you can create a custom rectangle like this:
```c
cgl::Shape::Rectangle myRectangle(window.GetVGContext(), { 100, 100 }, { 200, 100 }, { 200, 200 }, { 100, 200 }, cgl::Color::White);
```

## Shape functions

**Drawing**

To draw your shape to the window, you'll need to use
```c
myShape.Draw();
```
Without this, the shape won't be shown. 

---

**SetColor:**

To Change the color of your shape you can use
```c
myShape.SetColor(cgl::Color::Red);
```
This changes the color of the specified shape in to the ``cgl::Color`` you chose.

---

**SetPoints:**

To change the specific points of a triangle you can use  
```c
myTriangle.SetPoints({ 100, 200 }, { 200, 100 }, { 150, 200 });
```
Similarly to when you created the triangle, it takes in three ``cgl::Vector2``'s which you can modify to whatever you'd like.  

To change the specific points of a rectangle you can use
```c
myRectangle.SetPoints({ 100, 100 }, { 200, 100 }, { 200, 200 }, { 100, 200 });
```

---

**Show And Hide:**

To change wether you want the triangle to be drawn or not at runtime or with a command you can use
```c
myShape.Show();
```
This sets the ``visible`` variable of the shape to ``true`` so that the shape gets drawn
```c
myShape.Hide();
```
Which sets the ``visible`` variable of the shape to ``false``
By default the  ``visible`` variable which these two change in the background is equal to ``true``  
This means that you do not need to use the ``show`` function unless you have already used the ``Hide`` function.  
(These only work if the `Draw()` function has been called on the shape)

---

**Moving Shapes:**  

All shapes have these four functions that make it easy to move them around:  
```c
myShape.MoveUp(1);
myShape.MoveDown(1);
myShape.MoveLeft(1);
myShape.MoveRight(1);
```
The ``1`` in all of these is an integer that represents amount it moves in to the specified direction.  
If you want it to go faster you can set the integer higher.
