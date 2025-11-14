# CGL
Core Graphics Library is a library that I made to make OpenGL simple to code in. /nI'd like to credit GLFW for their library which powers mine.


# How to install CGL for Visual Studio

1. First download the latest release of CGL from this Github page.
2. Also download GLFW's 3.4 source package from https://www.glfw.org/download.html 
3. After that create a C++ Visual Studio project 
4. Use the File Explorer to create a folder inside of the main directory of that project. Call that Folder "libraries" 
5. In there create two folders "include" and "lib" 
6. Now download CMake from https://cmake.org 
7. In CMake put the "source code" as the glfw-3.4 which includes the CMakeLists.txt 
8. Then create a folder called "build" inside of that glfw-3.4 folder and put that to the "Where to build the binaries" section 
9. Once that is done click configure and select your version of Visual Studio and Select "Use default native compilers" 
10. After that select: GLFW_BUILD_DOCS, GLFW_BUILD_EXAMPLES, GLFW_BUILD_TESTS, GLFW_BUILD_WIN32 and USE_MSVC_RUNTIME_LIBRARY_DLL. 
11. Then press configure again. 
12. Once it's done configuring, press Generate. 
13. Then go to the build folder and open GLFW.sln or GLFW.slnx. 
14. Build the solution of the project in visual studio (Make sure you are using the same version that you selected in CMake) 
15. And now once it's done building go to the build folder, then to the src folder and from there go to debug and cut and paste glfw3.lib to the lib folder of your project. 
16. Then go to the "include" folder inside of glfw-3.4 and copy and paste the "GLFW" folder in to the "include" folder of your project .
17. Now you can also cut and paste the insides of the CGL "include" folder in to the "include" folder of your project.
18. After that go in to the actual Visual Studio project that you created and make a folder called CGL-src and put the insides of "src" from the CGL folder to that folder. 
19. Create a "main.cpp" file in the project.
20. Right-click your project in the Solution Explorer (make sure you click the second one in the list) and then click Properties.
21. Go to C/C++ and then General and locate Additional Include Directories.
22. Add your include path click the dropdown then Edit… then add the path to your include folder.
23. Do the same in VC++ Directories. And also add the path to the lib file in the Additional Library Directories.
24. Then go to Linker, Input and Additional Dependencies add two new lines "glfw3.lib" and "opengl32.lib"
