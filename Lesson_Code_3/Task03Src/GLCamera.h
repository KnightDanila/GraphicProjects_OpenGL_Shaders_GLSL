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

namespace ... {
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
            /...
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

                glMatrixMode(...);
                glm::mat4 modelproj = glm::perspective(...);
                glLoadMatrixf(...); // Подсказка - Мы должны брать указатель

                
            };

            void setPos(glm::vec3 pos) {
                glm::vec3 target = ...
                glm::vec3 direction = glm::normalize(...);
                glm::mat4 modelview = glm::lookAt(...);
                glMatrixMode(...);
                glLoadMatrixf(...);
                
            }

            glm::vec3 getPos() {
                ...
            };
        };

        class GLCameraTarget : public Camera {
            ...
        };



    };
}

#endif /* GLCAMERA_H */

