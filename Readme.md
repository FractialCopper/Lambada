https://help.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax

The project will be based on:

opengl - for rendering purpouses

glfw - for creating windows

imgui - for sweet ui


Project config
1. Set project to x64. From build -> configuration manager.
2. Set directories for included headers and libraries. For ex. Visual studio -> Solution Explorer -> Properties-> VC++ Directories 
-> include directory and library directory
3. From the same window Linker -> Additional library directories , and Linker->Input-> and library name glfw3.lib.
4. Add cpp files from imgui folder and glad.c for opengl.
5. Remember to put glad.h include before glwf3.h. 
6. Build
