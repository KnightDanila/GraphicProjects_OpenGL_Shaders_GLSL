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
            // glfwDestroyWindow(handle); // only for one-single window app
			glfwSetWindowShouldClose(_handle, true); // for multiple windows app
        };
        uint32_t getWidth() const;
        uint32_t getHeight() const;
		// ...

        GLFWwindow* getGLFWHandle() const;
		void makeCurrent();
		
		
    private:
        // TODO

    };
}
#endif /* GLWINDOW_H */

