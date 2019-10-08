/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GLWindow.h
 * Author: KnightDanila
 *
 * Created on 17 сентября 2019 г., 0:04
 */

#ifndef GLWINDOW_H
#define GLWINDOW_H

namespace Knight3D {

    class GLWindow {
    public:
        GLWindow(const std::string& title, uint32_t width, uint32_t height);
        GLWindow(const std::string& title, uint32_t width, uint32_t height, GLFWwindow* share);

        ~GLWindow() {
            glfwDestroyWindow(handle);
        };
        uint32_t getWidth() const;
        uint32_t getHeight() const;


        GLFWwindow* getGLFWHandle() const;
    private:
        // TODO
        GLFWwindow* handle;

    };

    GLWindow::GLWindow(const std::string& title, uint32_t width, uint32_t height) {
        handle = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
        //glfwMakeContextCurrent(handle);
        // Инициализируем GLEW
        //glewExperimental = true; // Флаг необходим в Core-режиме OpenGL
        //if (glewInit() != GLEW_OK) {
        //    fprintf(stderr, "Невозможно инициализировать GLEW\n");
        //}
    };

    GLWindow::GLWindow(const std::string& title, uint32_t width, uint32_t height, GLFWwindow* share) {
        handle = glfwCreateWindow(width, height, title.data(), nullptr, share);
        //glfwMakeContextCurrent(handle);
        // Инициализируем GLEW
        //glewExperimental = true; // Флаг необходим в Core-режиме OpenGL
        //if (glewInit() != GLEW_OK) {
        //    fprintf(stderr, "Невозможно инициализировать GLEW\n");
        //}
    };

    GLFWwindow* GLWindow::getGLFWHandle() const {
        return handle;
    };

}
#endif /* GLWINDOW_H */

