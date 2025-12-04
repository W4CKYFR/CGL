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
