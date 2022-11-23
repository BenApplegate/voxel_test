#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

void framebufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

int main() {

    int windowWidth = 800;
    int windowHeight = 600;

    //Start by initializing GLFW
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW, exiting\n";
        exit(1);
    }

    //Now we need to create our window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowWidth, "Voxel Test", nullptr, nullptr);
    if(window == nullptr){
        std::cerr << "Failed to create window object\n";
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window);

    //Next we need to intiialize our OpenGL Loader
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Failed to initialize GLAD\n";
        glfwTerminate();
        exit(1);
    }

    //The last step is to set up our GL Viewport
    glViewport(0, 0, windowWidth, windowHeight);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    //Finally we can enter our update loop
    while(!glfwWindowShouldClose(window)){


        //Swap our buffers
        glfwSwapBuffers(window);

        //Update any system events and callbacks
        glfwPollEvents();
    }

    glfwTerminate();
}
