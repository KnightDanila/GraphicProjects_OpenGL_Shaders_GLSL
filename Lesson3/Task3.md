#### [ENG](#Eng) --- [UKR](#Ukr)
<a name="Eng"></a>

# Lab work 3!
# Lights, Camera and Action! But without Lights yet :D

## Download libs for lab
GLM - https://github.com/g-truc/glm/releases


## Task
1. Learn the base opportunities of GLM. Understand the features of the GLM library linking.
2. Using the application template(pattern) Task03Src [https://github.com/KnightDanila/GraphicProjects_OpenGL_Shaders_GLSL/tree/master/Lesson3/Task03Src] - write and run the code with your namespace.
3. Use UML diagram for help:
![UML](data/UML_Main_Camera.jpg)
4. Add output to the console:
```
Task 3
Author: Vasya Pupkin
```
5. Create Camera by ...::GraphCore::Camera* CamFree = new ...::GraphCore::GLCameraFree();
6. Set Perspective CamFree->setPerspective(...);
7. Draw VBO object (from lab 2)
8. And move your camera by {x = r * cos(df); y = r * sin(df);}  


<a name="Ukr"></a>



# Лабораторна робота №2


## Завдання
1. Ознайомитись з можливостями графічної бібліотеки GLM. Розібратися з особливостями підключення бібліотеки GLM.
2. Використовуючи шаблон програми Task03Src [https://github.com/KnightDanila/GraphicProjects_OpenGL_Shaders_GLSL/tree/master/Lesson3/Task03Src] - запишіть та запустіть код з вашим простором імен.
3. Використовуйте діаграму UML для довідки:
![UML](data/UML_Main_Camera.jpg)
4. Додайте вихід до консолі:
```
Task 3
Author: Vasya Pupkin
```
5. Створіть камеру за допомогою класу ...::GraphCore::Camera* CamFree = new ...::GraphCore::GLCameraFree();
6. Встановити перспективу CamFree->setPerspective(...);
7. Намалюйте об'єкт VBO (з лабораторії 2)
8. І перемістіть камеру за допомогою {x = r * cos(df); y = r * sin(df);}  
