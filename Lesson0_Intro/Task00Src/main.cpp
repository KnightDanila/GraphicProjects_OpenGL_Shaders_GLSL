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
	println("Hello OpenGL");

	if( !glfwInit() )
	{
		fprintf( stderr, "Ошибка при инициализации GLFW\n" );
		return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x Сглаживание
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Мы хотим использовать OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Мы не хотим старый OpenGL

	/*
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	*/
	// Открыть окно и создать в нем контекст OpenGL
	GLFWwindow* window; // (В сопроводительном исходном коде эта переменная является глобальной)
	window = glfwCreateWindow( 640, 480, "Lesson 01", NULL, NULL);
	//window = glfwCreateWindow(mode->width, mode->height, "Lesson 01", monitor, NULL);
	if( window == NULL ){
		fprintf( stderr, "Невозможно открыть окно GLFW. Если у вас Intel GPU, то он не поддерживает версию 3.3. Попробуйте версию уроков для OpenGL 2.1.\n" );
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Инициализируем GLEW
	glewExperimental=true; // Флаг необходим в Core-режиме OpenGL
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Невозможно инициализировать GLEW\n");
		return -1;
	}

	// Включим режим отслеживания нажатия клавиш, для проверки ниже
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	float colorRGB = 0.0;
	do{
		// Пока что ничего не выводим. Это будет в уроке 2.
		glClearColor(sin(colorRGB*PI/180), abs(cos(colorRGB*PI/180)), abs(sin(colorRGB*PI/180) + cos(colorRGB*PI/180)), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Сбрасываем буферы
		glfwSwapBuffers(window);
		glfwPollEvents();

		{
			colorRGB<=180?colorRGB+=0.1:colorRGB=0;
		}

	} 
	// Проверяем нажатие клавиши Escape или закрытие окна
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0 );


	glfwTerminate();
	system("pause");        
	return 0;
}

