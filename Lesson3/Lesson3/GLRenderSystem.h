/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GLRenderSystem.h
 * Author: KnightDanila
 *
 * Created on 17 сентября 2019 г., 7:11
 */

#ifndef GLRENDERSYSTEM_H
#define GLRENDERSYSTEM_H

namespace Knight3D {
    namespace GraphCore {

        class GLRenderSystem {
        public:

            virtual void init() {
            }

            virtual void render(GLFWwindow * window) {
            }

            virtual void renderTriangleArray(GLfloat vertices[], GLfloat colors[]) {
            }

            virtual void renderVBO() {
            }
        };

        class GLRender : public GLRenderSystem {

            void init() {
                if (!glfwInit()) {
                    fprintf(stderr, "Ошибка при инициализации GLFW\n");
                }
                /*
                glfwWindowHint(GLFW_SAMPLES, 4); // 4x Сглаживание
                glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Мы хотим использовать OpenGL 3.3
                glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
                 */
                //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
                //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Мы не хотим старый OpenGL
            }

            void render(GLFWwindow * window) {
                // Пока что ничего не выводим. Это будет в уроке 2.
                glClearColor(sin(colorRGB * PI / 180), abs(cos(colorRGB * PI / 180)), abs(sin(colorRGB * PI / 180) + cos(colorRGB * PI / 180)), 1.0f);
                //glClear(GL_COLOR_BUFFER_BIT);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

                {
                    colorRGB <= 180 ? colorRGB += 0.1 : colorRGB = 0;
                }


                glEnable(GL_DEPTH_TEST);



                /*
                провести сечкение 4х мерного куба
                х>0 
                трехмерной гиперплоскостью
                 */

                glMatrixMode(GL_MODELVIEW); //set the matrix to model view mode

                glPushMatrix(); // push the matrix
                angle = glfwGetTime() * 50.0f;
                //glRotatef(angle, 1.0, 1.0, 0.0); //apply transformation



                //glColor3f(1.f, 1.f, 0.f);


                //Указание отобразить нарисованное немедленно
                //glFlush();

                // calculate the model matrix for each object and pass it to shader before drawing
                //glm::mat4 model = glm::mat4(1.0f);
                //model = glm::translate(model, Cube::cubePositions[0]);
                //println(glfwGetTime()%100);
                //if(rotation){
                //angle = glfwGetTime() * 50.0f;
                //}
                //model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
                //Cube::ourShader.setMat4("model", model);
                //Cube::ourShader.setFloat("time", glfwGetTime());

                //Рисование треугольника, указывая количества вершин
                //glDrawArrays(GL_TRIANGLES, 0, sizeof (Cube::vertices) / sizeof (float) / 3);

                //Создание нового VBO и сохранение идентификатора VBO
                glGenBuffers(1, &Cube::VBO);

                //Установка активности VBO
                glBindBuffer(GL_ARRAY_BUFFER, Cube::VBO);

                //Выгрузка данных вершин в видеоустройство
                glBufferData(GL_ARRAY_BUFFER, sizeof (Cube::vertices), Cube::vertices, GL_STATIC_DRAW);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof (float), (void*) 0);
                glEnableVertexAttribArray(0);
                //Рисование треугольника из VBO - происходит каждый раз, когда окно, точка обзора или данные изменяются
                //Устанавливаем 3 координаты каждой вершины с 0 шагом в этом массиве; тут необходимо
                glVertexPointer(3, GL_FLOAT, 0, NULL);

                //Сделать новую VBO активным. Повторите это, в случае изменения с инициализации
                glBindBuffer(GL_ARRAY_BUFFER, Cube::VBO);

                //Данный массив содержит вершины(не нормалей, цвета, текстуры и т.д.)
                glEnableClientState(GL_VERTEX_ARRAY);


                glDrawArrays(GL_TRIANGLES, 0, 36);


                glPopMatrix(); //pop the matrix

                glMatrixMode(GL_PROJECTION); // Apply projection matrix again

                glDisableVertexAttribArray(0);
            }

            void renderTriangleArray(GLfloat vertices[], GLfloat colors[]) {
                //glClear(GL_COLOR_BUFFER_BIT);


                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_COLOR_ARRAY);

                glVertexPointer(3, GL_FLOAT, 0, vertices);
                glColorPointer(3, GL_FLOAT, 0, colors);

                glDrawArrays(GL_QUADS, 0, 8);


                glDisableClientState(GL_COLOR_ARRAY);
                glDisableClientState(GL_VERTEX_ARRAY);
            }
        };

        class GLRendererOld2_1 : public GLRenderSystem {

            void init() {
                if (!glfwInit()) {
                    fprintf(stderr, "Ошибка при инициализации GLFW\n");
                }
                glfwWindowHint(GLFW_SAMPLES, 4); // 4x Сглаживание
                glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); // Мы хотим использовать OpenGL 3.3
                glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

                //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
                //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Мы не хотим старый OpenGL
            }

            void render(GLFWwindow * window) {
                // Пока что ничего не выводим. Это будет в уроке 2.
                glClearColor(sin(colorRGB * PI / 180), abs(cos(colorRGB * PI / 180)), abs(sin(colorRGB * PI / 180) + cos(colorRGB * PI / 180)), 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);


                {
                    colorRGB <= 180 ? colorRGB += 0.1 : colorRGB = 0;
                }


                glLoadIdentity();
                glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
                glBegin(GL_TRIANGLES);
                glColor3f(1.f, 0.f, 0.f);
                glVertex3f(-0.6f, -0.4f, 0.f);
                glColor3f(0.f, 1.f, 0.f);
                glVertex3f(0.6f, -0.4f, 0.f);
                glColor3f(0.f, 0.f, 1.f);
                glVertex3f(0.f, 0.6f, 0.f);
                glEnd();
            }

            void renderTriangleArray(GLfloat vertices[], GLfloat colors[]) {

                glClear(GL_COLOR_BUFFER_BIT);


                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_COLOR_ARRAY);

                glVertexPointer(3, GL_FLOAT, 0, vertices);
                glColorPointer(3, GL_FLOAT, 0, colors);

                glDrawArrays(GL_QUADS, 0, 8);


                glDisableClientState(GL_COLOR_ARRAY);
                glDisableClientState(GL_VERTEX_ARRAY);
            }
        };
    }
}


#endif /* GLRENDERSYSTEM_H */

