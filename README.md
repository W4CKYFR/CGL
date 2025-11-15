# CGL
Core Graphics Library is a library that I made to make OpenGL simple to code in.<br>I'd like to credit GLFW for their library which powers mine.

> [!Warning]
> Before using CGL you will need to have [GLFW](https://www.glfw.org) installed and ready to go.<br>
> We recommend using vcpkg for simplicity if you are using [Visual Studio](https://visualstudio.microsoft.com). <br>
> Thank you!

## Windows and Visual Studio Installation Guide

1. For windows you can download the CGL-Installer.exe from one of the [releases](https://github.com/W4CKYFR/CGL/releases).
2. Or optionally you can also download the .zip file.
3. After CGL has been downloaded you will make a C++ project in [Visual Studio](https://visualstudio.microsoft.com).
4. In the project you will need to include the lib folder as an additional library directory (In the Linker, Input)
5. Do the same for the include folder, but as an additional include directory (In VC++ Directories and C/C++)
6. Also make sure you have installed [GLFW](https://www.glfw.org) for this project (unless you used vcpkg, it does that automatically)
7. Now you should have CGL installed and ready to use.
8. If you need any help join the official [CGL Discord](discord.gg/JrsCsKBDtM)

## Linux and MacOS Installation Guide
> [!NOTE]
> This will be very similiar to the guide above if:<br>
> You're using [CLion](https://www.jetbrains.com/clion), [QT Creator](https://www.qt.io/product/development-tools) or [Code::Blocks](https://www.codeblocks.org)<br>
> Otherwise you might want to watch a tutorial on how to include additional include directories and libraries.<br>
> Remember to have GLFW installed and ready to use for the project.<br>
> Again we recommend you to use vcpkg for maximum simplicity if you are using [Visual Studio](https://visualstudio.microsoft.com)<br>
> If you are using [Visual Studio](https://visualstudio.microsoft.com) you can use the Windows Installing guide above.<br>

> [!TIP]
> The following guide includes a tutorial for [CLion](https://www.jetbrains.com/clion), [QT Creator](https://www.qt.io/product/development-tools) and [Code::Blocks](https://www.codeblocks.org)<br>
> If you are using [CLion](https://www.jetbrains.com/clion) proceed to the guide that is after this text (guide still in development)<br>
> If you are using [QT Creator](https://www.qt.io/product/development-tools) proceed to the guide that is after the CLion guide.<br>
> If you are using [Code::Blocks](https://www.codeblocks.org) proceed to the last guide.<br>
> If you are using [Visual Studio](https://visualstudio.microsoft.com) then back up and follow the Windows installation. (Just download the .zip instead of the installer)<br>

## QT Creator Installation

1. Download the latest .zip file from [releases](https://github.com/W4CKYFR/CGL/releases).<br>
2. After CGL has downloaded you will make a project in [QT Creator](https://www.qt.io/product/development-tools).<br>
3. Right click your project and then click "Add Library" <br>
4. It will ask for a path to the .lib file in which you will put your path to the CGL folder and then in there the "lib" folder<br>
5. It will also ask for a path to the "include" directory in which you will put your path to the CGL folder and then in there the "include" folder<br>
6. Remember to make sure you have [GLFW](https://www.glfw.org) installed for this project<br>
7. Now you should have CGL installed and ready to use.<br>
8. If you need any help join the official [CGL Discord](discord.gg/JrsCsKBDtM)<br>
