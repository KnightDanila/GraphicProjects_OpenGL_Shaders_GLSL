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
1. Створіть своє унікальне ім'я двигуна OpenGL - як абревіатуру вашого імені.
Наприклад GSC - Григорович Сергій Константинович [(GSC Game World)](https://en.wikipedia.org/wiki/GSC_Game_World)
```
namespace GSC{
}
```
2. Використовуючи шаблон програми Task02Src [https://github.com/KnightDanila/GraphicProjects_OpenGL_Shaders_GLSL/tree/master/Lesson2/Task02Src] - запишіть та запустіть код з вашим простором імен.
3. Використовуйте діаграму UML для довідки:
! [UML] (data / UML_Main1.jpg)
4. Додайте вихід до консолі:
```
Завдання 2
Автор: Вася Пупкін
```
5. Створіть 3 вікна за допомогою класу GLWindow
6. Намалюйте об'єкт VBO (без текстури)
7. Намалюйте простий масив точок glDrawArrays()
8. Покажіть, що ви можете використовувати дві рендерні машини GLRender () та GLRendererOld2_1 ().
