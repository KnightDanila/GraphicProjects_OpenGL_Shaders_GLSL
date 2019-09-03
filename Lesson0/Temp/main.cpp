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
#include <iostream>
#include <cstdlib>

// OpenGL
#define GLUT_DISABLE_ATEXIT_HACK
#define GLFW_DLL
#define GLEW_STATIC

#pragma comment(lib, "libs\\GL_AL\\glfw3.lib")
#pragma comment(lib, "libs\\GL_AL\\glut32.lib")
#pragma comment(lib, "libs\\GL_AL\\alut.lib")
#pragma comment(lib, "libs\\GL_AL\\glew32.lib")
#pragma comment(lib, "libs\\GL_AL\\glew32s.lib")


#include "libs\GL_AL\glew.h"
//#include "libs\GL_AL\glew.c"
//#include <glad/glad.h>

#include "libs\GL_AL\glfw3.h"
#include "libs\GL_AL\glut.h"


using namespace std;

template < typename T>
void println(T i) {
    cout << i << endl;
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
int main(int argc, char** argv) {
    argsEcho(argc, argv);
    println("Hello World");
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    
    
    system("pause");        
    return 0;
}

