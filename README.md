
<table>
<tr>
<td width="300">

<img src="https://github.com/user-attachments/assets/cb2ebadc-e519-47d7-833d-f6771b6d5e5b" width="260"/>

</td>
<td>

CGL (Core Graphics Library) is a graphics library that makes graphics programming and video game developing simple and fun!<br>  

CGL is inspired by Raylib and it's made mostly for Video Game developing, but can be used for other types of Graphics programming.<br>  

CGL strives to be the best version of itself each and every update, your feedback is appreciated!<br>  

Join the official [CGL Discord Server](https://discord.gg/JrsCsKBDtM) to follow updates, talk to owners and give feedback.<br>

</td>
</tr>
</table>

---

> [!CAUTION]
> CGL is still in Early Development!<br>
> This means that even versions that are marked as "Stable" or aren't in the [beta branch](https://github.com/W4CKYFR/CGL/tree/beta) have bugs and other issues.
> If you have a problem with recent version(s) then please join the official [CGL Discord](discord.gg/JrsCsKBDtM) to get help.
> Same goes for bug reports and everything of the like.

> [!Warning]
> Before using CGL you will need to have all [dependencies](https://github.com/W4CKYFR/CGL/blob/main/Dependencies.md) installed and ready to go.<br>
> We recommend using vcpkg for simplicity if you are using [Visual Studio](https://visualstudio.microsoft.com). <br>
> Thank you!

## Additional information about CGL.
CGL was created by two people<br>The main developer, Owner and Founder: [Wacky](https://github.com/W4CKYFR)<br>The main graphics designer, Co-Owner and Co-Founder: [Axov](https://github.com/AXOV2YT)<br>
CGL was made so **YOU** could have an easy and fun time developing games and other graphics programs/software<br>
CGL was first created on the 11th of November 2025 which was also [Axov's](https://github.com/AXOV2YT) birthday.<br>

## Features
- Currently 5 external dependencies which all add functionality to CGL and are required. Read more at [Dependencies.md](https://github.com/W4CKYFR/CGL/blob/main/Dependencies.md)  
- Supported in atleast: Windows, Linux and MacOS  
- All source files are written in plain C++20 Standard.
- CGL Has an **Audio system** that includes sounds and will include Music in the future.
- CGL Has a **Text system** that let's you display text inside a window, also supports custom fonts.
- CGL has an **Input system** that includes "IsKeyPressed", "IsKeyReleased", "IsKeyDown", and more. And also has custom Input Binding.
- CGL has a **Window system** that let's you create and use windows very easily.
- CGL has a **Drawing System** which allows you to draw Shapes and text.
- CGL is **still in development** which means there is **Much, much, much more to come**
- CGL uses the zlib license. Learn more in [LICENSE](https://github.com/W4CKYFR/CGL/blob/main/LICENSE)
- CGL is **Free to use** and **Open Source**

  
---
  
> [!NOTE]
> **CGL Info box:**<br>
> CGL is a lightweight OpenGL library/wrapper.<br>
> CGL uses [GLFW](https://www.glfw.org) to function.<br>
> CGL is made to be fun and Easy-To-Use<br>
> CGL was made because [Wacky](https://github.com/W4CKYFR) was tired of having to code hundreds of lines for a triangle.<br>
> CGL is an Object-Oriented Library meaning it uses "objects" to structure software, each object combines data and the functions

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

## Code::Blocks Installation

1. Download the latest .zip file from [releases](https://github.com/W4CKYFR/CGL/releases).<br>
2. After CGL has downloaded you will make a project in [Code::Blocks](https://www.codeblocks.org).<br>
3. In [Code::Blocks](https://www.codeblocks.org) will go to Project, Build Options and Select your project on the left. <br>
4. Then select the compiler tab, click add and then choose the path to where CGL is downloaded and in there select the "include" folder.<br>
5. Then go to the linker tab, click add and select the path to where CGL is downloaded and in there select the "lib" folder.<br>
6. After that go to linker settings, click Add and select the .lib file inside of the "lib" folder of CGL.
7. Now you should have CGL installed and ready to use.<br>
8. If you need any help join the official [CGL Discord](discord.gg/JrsCsKBDtM)<br>
