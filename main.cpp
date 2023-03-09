#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* abs */
#include <string.h>
#include <sstream> 

#include "plano.h"
#include "cubo.h"
#include "defineRubik.h"
#include "cubo_rubik.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void process_input(GLFWwindow* window);

///////////////////////////////////////////////////
// CONFIGURACION DE VALORES //

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

// camera
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float camRotRadius = 5.0f;
float camRotCont = 0.0f;
float camRotContYaxis = 0.0f;
float camRotSpeed = 0.01f;
float camRotSpeedY = 0.03f;
float camX = 0.0f;
float camZ = 0.0f;
float camY = 0.0f;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main(){
    std::cout <<"Movements\n:----------------\n";
    std::cout <<"U  = U key\n";
    std::cout <<"U' = I key\n";
    std::cout <<"L  = P key\n";
    std::cout <<"L' = L key\n";
    std::cout <<"F  = U key\n";
    std::cout <<"F' = I key\n";
    std::cout <<"R  = R key\n";
    std::cout <<"R' = T key\n";
    std::cout <<"F  = G key\n";
    std::cout <<"F' = F key\n";
    std::cout <<"R  = R key\n";
    std::cout <<"R' = T key\n";
    std::cout <<"W  = B key\n";
    std::cout <<"W' = V key\n";
    std::cout <<"D  = Q key\n";
    std::cout <<"D' = F key\n";
    std::cout <<"Solver = Z key\n";
    std::cout <<"List of movements' = X key\n";
    std::cout <<"Cube mapping' = M key\n";

    // glfw: initialize and configure 
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glm::mat4 model = glm::mat4(1.0f);
    float angle = 20.0f * 2;

    cubo_rubik* Holaaa = new cubo_rubik();
    

    while (!glfwWindowShouldClose(window)){
        // input
        // -----
        process_input(window);

        // render
        // ------                                                                                       
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // camera/view transformation
        glm::mat4 view = lookAt(glm::vec3( sin(camRotCont) * camRotRadius, sin(camRotContYaxis) * camRotRadius, cos(camRotCont) * camRotRadius ), cameraTarget, cameraUp);
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

        Holaaa->render(window, view, projection);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void process_input(GLFWwindow* window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camRotContYaxis += camRotSpeedY;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camRotContYaxis -= camRotSpeedY;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camRotCont += camRotSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camRotCont -= camRotSpeed;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    if(camRotRadius > 2 && yoffset == -1)
        camRotRadius += (float)yoffset;
    else if(11  > camRotRadius && yoffset == 1)
        camRotRadius += (float)yoffset;
}