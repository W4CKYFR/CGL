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
cgl::Shape::Triangle myTriangle (vg, { 100, 100 }, { 200, 100 }, { 150, 200 }, color);)
```
  
The numbers are a ``cgl::Vector2`` variable which stores in a x and y. You can change them to whatever you'd like.
