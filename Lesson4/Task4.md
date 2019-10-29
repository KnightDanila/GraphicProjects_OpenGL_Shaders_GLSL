#### [ENG](#Eng) --- [UKR](#Ukr)
<a name="Eng"></a>

# Lab work 4!
# First Shader - Bright and Dim :D

## Download libs for lab
GLM - https://github.com/g-truc/glm/releases


## Task
1. Learn the base opportunities of "GLShader.h". Understand the features of the "GLShader.h" class.
2. Using the application template(pattern) Task04Src download "GLShader.h" [https://github.com/KnightDanila/GraphicProjects_OpenGL_Shaders_GLSL/tree/master/Lesson4/Task04Src] - write and run the code with your namespace.
3. Download "BrightAndDim_VertexShader.vs", "BrightAndDim_FragmentShader.fs" to working folder;
4. Add output to the console:
```
Task 4
Author: Vasya Pupkin
```
5. Create Shader by ...::GraphCore::GLShader* shaderBrightDim = new ...::GraphCore::GLShader("BrightAndDim_VertexShader.vs", "BrightAndDim_FragmentShader.fs");
6. Draw VBO object (from previous lab) - and add a shader to it.
7. Add key action to change the color in shader - add to main glfwSetKeyCallback(window, keyCallback); and write :
```
void keyCallback(GLFWwindow * window, int key, int scancode, int action, int mode) {
	println((string) "key:" + key + "-scancode:" + scancode + "-action:" + action + "-mode:" + mode);

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        println("SPACE");
        //TO DO
    }
}

```

