/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   main.cpp
* Author: KnightDanila
*
* Created on 4 июня 2019 г., 16:21
*/

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h> 
#include <locale.h>
#include <cmath>                                       // для функции sin


// OpenGL
#define GLUT_DISABLE_ATEXIT_HACK
#define PI 3.14159265                                  // число ПИ
//#define GLFW_DLL
//#define GLEW_STATIC


#pragma comment(lib, "libs\\GL_AL\\glfw3.lib")
#pragma comment(lib, "libs\\GL_AL\\glut32.lib")
#pragma comment(lib, "libs\\GL_AL\\glut32.dll")
#pragma comment(lib, "libs\\GL_AL\\alut.lib")
#pragma comment(lib, "libs\\GL_AL\\glew32.lib")
#pragma comment(lib, "libs\\GL_AL\\glew32s.lib")
#pragma comment(lib, "libs\\GL_AL\\glew32.dll")
// VS2013+ - bugfix - Thanks Bolsunov Dmitry
#pragma comment(lib, "msvcrt.lib")
#pragma comment(lib, "msvcmrt.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")


#include "libs\GL_AL\glew.h"
//#include "libs\GL_AL\glew.c"
//#include <glad/glad.h>
#include "libs\GL_AL\glfw3.h"

#include "libs\GL_AL\glut.h"

#include "libs\GL_AL\glew.h"
//#include "glad\glad.h"

#include "libs\GL_AL\glfw3.h"
#include "libs\GL_AL\glut.h"
#include "libs\GL_AL\glm\glm.hpp"
#include "libs\GL_AL\glm\gtc\matrix_transform.hpp"
#include "libs\GL_AL\shader.h"

float colorRGB = 0.0f;

#include "GLWindow.h"
#include "GLRenderSystem.h"

using namespace std;

//using namespace Cube;

template < typename T>
void println(T i) {
  cout << i << endl;
}

void argsEcho(int argc, char** argv) {
  println("____ARGS____");
  if (argc == 0) {
    println("NO ARGS");
  }
  else {
    for (int i = 0; i < argc; i++) {
      println(argv[i]);
    }
  }
  println("____________\n");
}
/*
*
*/

int main(int argc, char** argv) {
  argsEcho(argc, argv);
  println("Hello OpenGL");
  println("Author: Roman Shcherbak");

  if (!glfwInit())
  {
    fprintf(stderr, "Ошибка при инициализации GLFW\n");
    return -1;
  }

  Knight3D::GraphCore::GLRenderSystem* renderer;


  bool OpenGL33 = true;

  if (OpenGL33) {
    renderer = new Knight3D::GraphCore::GLRender();
  }
  else {
    renderer = new Knight3D::GraphCore::GLRendererOld2_1();
  }

  renderer->init();


  Knight3D::GLWindow* Win1 = new Knight3D::GLWindow("Lesson 021", 640, 480);
  Knight3D::GLWindow* Win2 = new Knight3D::GLWindow("Lesson 022", 640, 480);
  Knight3D::GLWindow* Win3 = new Knight3D::GLWindow("Lesson 023", 640, 480);

  /*GLFWmonitor* monitor = glfwGetPrimaryMonitor();
  const GLFWvidmode* mode = glfwGetVideoMode(monitor);
  glfwWindowHint(GLFW_RED_BITS, mode->redBits);
  glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
  glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
  glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);*/
  
  // Открыть окно и создать в нем контекст OpenGL

  
  GLFWwindow* window; // (В сопроводительном исходном коде эта переменная является глобальной)
  window = glfwCreateWindow(640, 480, "Lesson 02 -- Роман Щербак ПА-18-1", NULL, NULL);

  if (window == NULL) {
    fprintf(stderr, "Невозможно открыть окно GLFW. Если у вас Intel GPU, то он не поддерживает версию 3.3. Попробуйте версию уроков для OpenGL 2.1.\n");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  
  // Инициализируем GLEW
  glewExperimental = true; // Флаг необходим в Core-режиме OpenGL
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Невозможно инициализировать GLEW\n");
    return -1;
  }
  
  
  // Включим режим отслеживания нажатия клавиш, для проверки ниже
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);



  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
    glfwWindowShouldClose(window) == 0) {


    glfwMakeContextCurrent(Win1->getGLFWHandle());
    renderer->render(Win1->getGLFWHandle());

    glfwSwapBuffers(Win1->getGLFWHandle());


    glfwMakeContextCurrent(Win2->getGLFWHandle());
    renderer->render(Win2->getGLFWHandle());

    glfwSwapBuffers(Win2->getGLFWHandle());

    glfwMakeContextCurrent(Win3->getGLFWHandle());
    renderer->render(Win3->getGLFWHandle());

    glfwSwapBuffers(Win3->getGLFWHandle());


    glfwPollEvents();
    glfwMakeContextCurrent(window);
  }
  
 glDeleteBuffers(1, &Cube::VBO);

  delete renderer;
  glfwDestroyWindow(window);
  glfwTerminate();
  system("pause");
  return 0;
}