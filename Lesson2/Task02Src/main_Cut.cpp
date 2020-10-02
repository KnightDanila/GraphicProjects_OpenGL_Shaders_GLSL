#include "GLWindow.h"
#include "GLRenderSystem.h"

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

    unsigned int VBO;

    void init() {
        {
        }
    }


};

namespace Squares {
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
        255, 0, 0,
        255, 0, 0,
        255, 0, 0,

        0, 0, 255,
        0, 0, 255,
        0, 0, 255,
        0, 0, 255
    };



}

using namespace std;

void resize(GLFWwindow * window, int width, int height) {
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

int main(int argc, char** argv) {

    Knight3D::GraphCore::GLRenderSystem* renderer;


    renderer->init();


    Knight3D::GLWindow* Win1 = new Knight3D::GLWindow("Lesson 021", 320, 240);
    Knight3D::GLWindow* Win2 = new Knight3D::GLWindow("Lesson 022", 640, 480);

    Cube::init();

    // Проверяем нажатие клавиши Escape или закрытие окна
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0) {
        

        glfwMakeContextCurrent(Win1->getGLFWHandle());
        renderer->render(Win1->getGLFWHandle());
        ...
        glfwSwapBuffers(Win1->getGLFWHandle());


        glfwMakeContextCurrent(Win2->getGLFWHandle());
        renderer->render(Win2->getGLFWHandle());
        ...
        glfwSwapBuffers(Win2->getGLFWHandle());


        glfwPollEvents();
        glfwMakeContextCurrent(window);
    }


    glDeleteBuffers(1, &Cube::VBO);

    glfwDestroyWindow(...);
    glfwTerminate();
    
    return 0;
}