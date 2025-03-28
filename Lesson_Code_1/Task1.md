#### [ENG](#Eng) --- [UKR](#Ukr)
<a name="Eng"></a>

# Lab 1 FIGHT!

> "In OpenGL - the GL part means Good Luck, 
not Graphic Library, so I'm GlaD to see you ^_^"
>
> <p align="right"> — GlaDOS</p>

## Download OpenGL libs
GLFW - https://www.glfw.org/download.html  
GLEW or GLAD:  
GLEW - http://glew.sourceforge.net/  
GLAD - https://glad.dav1d.de/  

## Task
1. Learn the base opportunities of OpenGL. Understand the features of the GLFW library linking.
2. Using the application template (RAINBOW)[https://github.com/KnightDanila/GraphicProjects_OpenGL_Shaders_GLSL/tree/master/Lesson1/Task01Src] - review and run the code, and complete the following tasks.
3. Use glfwWindowHint (...) to connect OpenGL 3.3 or another version supported by your GPU.
4. Add output to the console:
```
Hello OpenGL – I am Glad to see you
Author: The student of the faculty of Applied Mathematics (Harry James Potter/Hermione Jean Granger)
```
5. Create a 640x480 glfwCreateWindow (...) window, named "Lesson 01 - RAINBOW - (Harry James Potter/Hermione Jean Granger) AC-13-03".

### Addons:
**Unix|Linux** build commands:  
> ```g++ main.cpp -o rainbow -lGLEW -lGL -lglfw```

**Windows** MinGW g++ commands:
> ```g++ --static-libgcc -static-libstdc++ -lglew32s -lglew32 -l:glfw3.a -lglut32 -lopengl32 -lgdi32```

<a name="Ukr"></a>

# Лабораторна робота №1

## Завантажити OpenGL бібліотеки:
GLFW - https://www.glfw.org/download.html  
GLEW or GLAD:  
GLEW - http://glew.sourceforge.net/  
GLAD - https://glad.dav1d.de/  

## Завдання
1. Ознайомитись з можливостями графічної бібліотеки OpenGL. Розібратися з особливостями підключення бібліотеки GLFW.
2. За допомогою шаблону програми (RAINBOW)[https://github.com/KnightDanila/GraphicProjects_OpenGL_Shaders_GLSL/tree/master/Lesson1/Task01Src] - розглянути та запустити код, та виконати наступні завдання.
3. За допомогою функції glfwWindowHint(...) підключити OpenGL 3.3 чи іншої версії, яку підтримує ваш GPU.
4. Додати у консоль вивід:
```
Hello OpenGL – I am Glad to see you
Author: The student of the faculty of Applied Mathematics (Harry James Potter/Hermione Jean Granger)
```
5. Створити вікно glfwCreateWindow(...) розміром 640х480, та назвою "Lesson 01 - RAINBOW - (Harry James Potter/Hermione Jean Granger) ПК-13-03".

### Доповнення:
**Unix|Linux** build commands:  
> ```g++ main.cpp -o rainbow -lGLEW -lGL -lglfw```

**Windows** MinGW g++ commands:
> ```g++ --static-libgcc -static-libstdc++ -lglew32s -lglew32 -l:glfw3.a -lglut32 -lopengl32 -lgdi32```

