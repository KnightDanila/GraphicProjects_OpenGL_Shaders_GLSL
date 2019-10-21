/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GLCamera.h
 * Author: KnightDanila
 *
 * Created on 1 октября 2019 г., 9:15
 */

#ifndef GLCAMERA_H
#define GLCAMERA_H

namespace Knight3D {
    namespace GraphCore {

        class Camera {
        public:

            virtual void setPerspective(float fov, float aspect, float near, float far) {

            };

            virtual void setPos(glm::vec3 pos) {
            };

            virtual void setTarget(glm::vec3 pos) {

            };

            virtual glm::vec3 getPos() {
            };


        private:
            glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
        };

        class GLCameraFree : public Camera {
        public:

            void setPerspective(float fov, float aspect, float near1, float far1) {
                /*
                // Calculate The Aspect Ratio Of The Window
                // The parameters are:
                // (view angle, aspect ration of the width to the height, 
                //  The closest distance to the camera before it clips, 
                // FOV, Ratio,  The farthest distance before it stops drawing)
                 */
                //gluPerspective(45.0f, (GLfloat) width / (GLfloat) height, 0.5f, 3000.0f);

                glMatrixMode(GL_PROJECTION);
                glm::mat4 modelproj = glm::perspective(fov, aspect, near1, far1);
                glLoadMatrixf(glm::value_ptr(modelproj));

                
            };

            void setPos(glm::vec3 pos) {
                glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);
                glm::vec3 direction = glm::normalize(pos - target);
                glm::mat4 modelview = glm::lookAt(pos, direction, glm::vec3(0, 1, 0));
                //glMatrixMode(GL_PROJECTION);
                //GL_PROJECTION_MATRIX
                //glLoadMatrixf(&modelview);
                glMatrixMode(GL_MODELVIEW);
                glLoadMatrixf(glm::value_ptr(modelview));
                
            }

            glm::vec3 getPos() {
            };
        };

        class GLCameraTarget : public Camera {
            //glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
            //glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
        };



    };
}

#endif /* GLCAMERA_H */
