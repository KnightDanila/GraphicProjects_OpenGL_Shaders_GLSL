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
float colorRGB = 0.0;
int width = 640, height = 480;
float angle = 0;
//#define GLFW_DLL
//#define GLEW_STATIC
//#define GLFW_INCLUDE_GLU

#pragma comment(lib, "libs\\GL_AL\\glfw3.lib")
#pragma comment(lib, "libs\\GL_AL\\glut32.lib")
#pragma comment(lib, "libs\\GL_AL\\glut32.dll")
#pragma comment(lib, "libs\\GL_AL\\alut.lib")
#pragma comment(lib, "libs\\GL_AL\\glew32.lib")
#pragma comment(lib, "libs\\GL_AL\\glew32s.lib")

#pragma comment(lib, "msvcrt.lib")
#pragma comment(lib, "msvcmrt.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")




#include "libs\GL_AL\glew.h"
//#include "glad\glad.h"

#include "glfw3.h"
#include "glut.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "filesystem.h"

namespace Cube {
    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
    };
    // world space positions of our cubes
    glm::vec3 cubePositions[] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f, 2.0f, -2.5f),
        glm::vec3(1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)
    };
    unsigned int VBO;
    unsigned int VAO;
    unsigned int texture1;
    unsigned int texture2;
    Shader ourShader;

    void init() {

        {
            //glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);


            //glBindVertexArray(VAO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

            // position attribute
            //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof (float), (void*) 0);
            //glEnableVertexAttribArray(0);
            // texture coord attribute
            //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof (float), (void*) (3 * sizeof (float)));
            //glEnableVertexAttribArray(1);
        }
    }


};

namespace Triangle {
    GLfloat vertices[] = {
        0, 0, 0,
        1, 0, 0,
        1, 1, 0,
        0, 1, 0,

        0, 0, 0,
        0, 1, 0,
        -1, 1, 0,
        -1, 0, 0
    };

    GLfloat colors[] = {

        255, 0, 0,
        0, 255, 0,
        255, 0, 0,
        255, 255, 0,

        255, 0, 255,
        0, 100, 70,
        0, 0, 0,
        0, 0, 255
    };



}
#include "GLWindow.h"
#include "GLRenderSystem.h"
#include "GLCamera.h"

using namespace std;

template < typename T>
void println(T i) {
    cout << i << endl;
}

string operator+(string s, int i) {
    return s + to_string(i);
}

void argsEcho(int argc, char** argv) {
    println("____ARGS____");
    if (argc == 0) {
        println("NO ARGS");
    } else {
        for (int i = 0; i < argc; i++) {
            println(argv[i]);
        }
    }
    println("____________\n");
}

/*
 * 
 */
int SCR_WIDTH, SCR_HEIGHT;

void resize(GLFWwindow * window, int width, int height) {
    SCR_WIDTH = width;
    SCR_HEIGHT = height;

    println((string) "Width:" + width + "-Height:" + height);

    float ratio = width / (float) height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    

}

bool rotation = true;

void keyCallback(GLFWwindow * window, int key, int scancode, int action, int mode) {
    println((string) "key:" + key + "-scancode:" + scancode + "-action:" + action + "-mode:" + mode);

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        println("SPACE");
        rotation ? rotation = false : rotation = true;
    }
}

int main(int argc, char** argv) {
    argsEcho(argc, argv);
    println("Hello OpenGL");
    bool FULL_SCREEN = false;
    bool OpenGL33 = true;

    Knight3D::GraphCore::GLRenderSystem* renderer;

    if (OpenGL33) {
        renderer = new Knight3D::GraphCore::GLRender();
    } else {
        renderer = new Knight3D::GraphCore::GLRendererOld2_1();
    }
    renderer->init();

    // Открыть окно и создать в нем контекст OpenGL
    GLFWwindow* window; // (В сопроводительном исходном коде эта переменная является глобальной)
    SCR_WIDTH = 640;
    SCR_HEIGHT = 480;
    if (!FULL_SCREEN) {
        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Lesson 02", NULL, NULL);
    } else {
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
        window = glfwCreateWindow(mode->width, mode->height, "Lesson 02", monitor, NULL);
    }
    if (window == NULL) {
        fprintf(stderr, "Невозможно открыть окно GLFW. Если у вас Intel GPU, то он не поддерживает версию 3.3. Попробуйте версию уроков для OpenGL 2.1.\n");
        glfwTerminate();
        return -1;
    }

    Knight3D::GLWindow* Win1 = new Knight3D::GLWindow("Lesson 021", 320, 240);
    Knight3D::GLWindow* Win2 = new Knight3D::GLWindow("Lesson 022", 640, 480, window);

    glfwMakeContextCurrent(window);
    //glfwMakeContextCurrent(Win1->getGLFWHandle());
    //glfwMakeContextCurrent(Win2->getGLFWHandle());
    glfwSwapInterval(1);
    // Инициализируем GLEW
    glewExperimental = true; // Флаг необходим в Core-режиме OpenGL
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Невозможно инициализировать GLEW\n");
        //return -1;
    }

    // Включим режим отслеживания нажатия клавиш, для проверки ниже
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetFramebufferSizeCallback(window, resize);
    //glfwSetWindowSizeCallback(window, resize);
    glfwSetKeyCallback(window, keyCallback);


    //Cube::init();
    Knight3D::GraphCore::Camera* CamFree = new Knight3D::GraphCore::GLCameraFree();
    //CamFree->setPerspective(45.0f, 640.0f / 480.0f, 0.5f, 1000.0f);
    CamFree->setPerspective(45.0f, SCR_WIDTH / (float)SCR_HEIGHT, 0.5f, 1000.0f);

    // Проверяем нажатие клавиши Escape или закрытие окна
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0) {

        glfwMakeContextCurrent(window);
        // Главный цикл отрисовки
        //renderOldStyle(window);
        CamFree->setPos(glm::vec3(-2, sin(angle * PI / 180), sin(angle * PI / 180)));
        //X^2+Y^2=R^2
        CamFree->setPos(glm::vec3(2 * cos(angle * PI / 180), 2, 2 * sin(angle * PI / 180)));
        renderer->render(window);
        //renderer->renderTriangleArray(Triangle::vertices, Triangle::colors);
        println((string) "Time: " + glfwGetTime());
        // Сбрасываем буферы
        glfwSwapBuffers(window);
        // Сообщения 

        glfwMakeContextCurrent(Win1->getGLFWHandle());
        // Главный цикл отрисовки
        //renderOldStyle(window);
        renderer->render(Win1->getGLFWHandle());
        renderer->renderTriangleArray(Triangle::vertices, Triangle::colors);
        println((string) "Time: " + glfwGetTime());
        // Сбрасываем буферы
        glfwSwapBuffers(Win1->getGLFWHandle());


        glfwMakeContextCurrent(Win2->getGLFWHandle());
        // Главный цикл отрисовки
        //renderOldStyle(window);
        renderer->render(Win2->getGLFWHandle());
        println((string) "Time: " + glfwGetTime());
        // Сбрасываем буферы
        glfwSwapBuffers(Win2->getGLFWHandle());


        glfwPollEvents();
        glfwMakeContextCurrent(window);
    }


    glDeleteVertexArrays(1, &Cube::VAO);
    glDeleteBuffers(1, &Cube::VBO);

    glfwDestroyWindow(window);
    glfwTerminate();

    /* Find */
    //kbhit


    //system("pause");
    return 0;
}