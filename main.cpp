#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>


/*/////////////////////////////////////////////////
// INSTRUCCIONES //
    Q => Giro eje X izquierda
    E => Giro eje X derecha
    W => Giro eje Y izquierda
    S => Giro eje Y derecha
    A => Giro eje Z izquierda
    D => Giro eje Z derecha
/////////////////////////////////////////////////*/

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

///////////////////////////////////////////////////
// CONFIGURACION DE VALORES //

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

//////////////////////////////////////////////////
// CLASE PLANO

class Plano {
public:
    Plano() {
        shader();
    }
    Plano(float new_vertices[20], unsigned int new_indices[6]) {
        shader();
        setVertices(new_vertices, new_indices);
    }
    Plano(float new_vertices[20], unsigned int new_indices[6], glm::vec4 new_color) {
        shader();
        setVertices(new_vertices, new_indices);
        setColor(new_color);
    }
    void setColor(glm::vec4 new_color) {
        color = new_color;
    }
    void render(glm::mat4 transform) {
        glUseProgram(shaderProgram);

        unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, color[0], color[1], color[2], color[3]);
        // render container
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void setVertices(float new_vertices[20], unsigned int new_indices[6]) {
        for (int i = 0; i < 20; i++)
            vertices[i] = new_vertices[i];
        for (int i = 0; i < 6; i++)
            indices[i] = new_indices[i];

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // texture coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) <35P10/>;
    }
    ~Plano() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteProgram(shaderProgram);
    }
private:
    glm::vec4       color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    unsigned int    VBO, VAO, EBO;
    unsigned int    shaderProgram = glCreateProgram();
    float           vertices[20];
    unsigned int    indices[6];

    bool shader() {
        const char* vertexShaderSource = "#version 330 core\n"
            "layout(location = 0) in vec3 aPos; \n"
            "uniform mat4 transform; \n"
            "void main()\n"
            "{\n"
            "    gl_Position = transform * vec4(aPos, 1.0);\n"
            "}\n";
        const char* fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "uniform vec4 ourColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = ourColor;\n"
            "}\n\0";

        //===============  vertex shader
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        //===============   fragment Shader
        // create  fragmentShader;
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // link shaders
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return true;
    }
};

//////////////////////////
// CLASE CUBO

class Cubo {
public:
    glm::mat4 model_;

    glm::vec3 pos_inicial;
    //trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    /*
    color estructura
    0. front
    1. behind
    2. left
    3. right
    4. down
    5. up
    */
    Cubo(std::vector<glm::vec4> newColor, glm::vec3 translacion, glm::vec3 escalar, glm::mat4 model) {

        colores.clear();
        for (int i = 0; i < 6; i++) {
            colores.push_back(newColor[i]);
        }

        transform = glm::scale(transform, escalar);
        transform = glm::translate(transform, translacion);

        //transform = model * transform;
        model_ = model;
        float vertices1[] = {
            // positions          // texture coords
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
             0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
        };
        float vertices2[] = {
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        };
        float vertices3[] = {
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f
        };
        float vertices4[] = {
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f,  0.5f,  0.0f, 0.0f
        };
        float vertices5[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f
        };
        float vertices6[] = {
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f
        };
        unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };

        lados[0].setColor(colores[0]); lados[0].setVertices(vertices1, indices);
        lados[1].setColor(colores[1]); lados[1].setVertices(vertices2, indices);
        lados[2].setColor(colores[2]); lados[2].setVertices(vertices3, indices);
        lados[3].setColor(colores[3]); lados[3].setVertices(vertices4, indices);
        lados[4].setColor(colores[4]); lados[4].setVertices(vertices5, indices);
        lados[5].setColor(colores[5]); lados[5].setVertices(vertices6, indices);

    }

    glm::mat4 get_model() {
        return transform;
    }

    void render() {
        for (int i = 0; i < 6; i++)
            lados[i].render(transform);
    }

     
    void set_rotation(float rot_grades, glm::vec3 rot_vect, glm::mat4 _transform) {

        //model_ = glm::rotate(model_, glm::radians(0.05f), glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 model_2 = glm::rotate(model_, glm::radians(rot_grades), rot_vect);
        //gl_Position = projection * view * model * vec4(aPos, 1.0);
        transform = model_2 * transform;
    }



    void input(GLFWwindow* window) {
        //eje x

        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            
            //model_ = glm::rotate(model_, glm::radians(0.05f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::mat4 model_2 = glm::rotate(model_, glm::radians(-0.8f), glm::vec3(1.0f, 0.0f, 0.0f));
            //gl_Position = projection * view * model * vec4(aPos, 1.0);
            transform = model_2 * transform;

        }

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            //model_ = glm::rotate(model_, glm::radians(0.05f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::mat4 model_2 = glm::rotate(model_, glm::radians(0.8f), glm::vec3(1.0f, 0.0f, 0.0f));
            //gl_Position = projection * view * model * vec4(aPos, 1.0);
            transform = model_2 * transform;
        }
        /*
        //eje y
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            //model_ = glm::rotate(model_, glm::radians(-0.05f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::mat4 model_2 = glm::rotate(model_, glm::radians(-0.8f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = model_2 * transform;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            //model_ = glm::rotate(model_, glm::radians(0.05f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::mat4 model_2 = glm::rotate(model_, glm::radians(0.8f), glm::vec3(0.0f, 1.0f, 0.0f));
            transform = model_2 * transform;
        }
        */
        //eje z
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
            //model_ = glm::rotate(model_, glm::radians(0.05f), glm::vec3(0.0f, 0.0f, 1.0f));
            glm::mat4 model_2 = glm::rotate(model_, glm::radians(0.8f), glm::vec3(0.0f, 0.0f, 1.0f));
            transform = model_2 * transform;
        }
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
            //model_ = glm::rotate(model_, glm::radians(-0.05f), glm::vec3(0.0f, 0.0f, 1.0f));
            glm::mat4 model_2 = glm::rotate(model_, glm::radians(-0.8f), glm::vec3(0.0f, 0.0f, 1.0f));
            transform = model_2 * transform;
        }
    }

    void setColor(std::vector<glm::vec4> newColor){
        colores.clear();
        for(int i=0;i<6;i++){
            colores.push_back(newColor[i]);
        }
    }
private:
    glm::mat4               transform = glm::mat4(1.0f);
    Plano* lados = new Plano[6];
    std::vector<glm::vec4>  colores = {
    glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), //azul
    glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), //rojo
    glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), //verde
    glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), //magenta
    glm::vec4(0.0f, 1.0f, 1.0f, 1.0f), //celeste
    glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)  //amarillo
    };;
};

//////////////////////////
// CLASE CUBO RUBICK

class cubo_rubick {
public:

    bool U_action = true;

    void render(GLFWwindow* window) {
        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && U_action) {
            U_action == false;
            U();
            U_action == true;
        }
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && U_action) {
            U_action == false;
            L();
            U_action == true;
        }

        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && U_action) {
            U_action == false;
            F();
            U_action == true;
        }

        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && U_action) {
            U_action == false;
            R();
            U_action == true;
        }

        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && U_action) {
            U_action == false;
            B();
            U_action == true;
        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && U_action) {
            U_action == false;
            D();
            U_action == true;
        }


        cubo_01.render();
        cubo_01.input(window);
    
        cubo_02.render();
        cubo_02.input(window);

        cubo_03.render();
        cubo_03.input(window);

        cubo_04.render();
        cubo_04.input(window);

        cubo_05.render();
        cubo_05.input(window);

        cubo_06.render();
        cubo_06.input(window);

        cubo_07.render();
        cubo_07.input(window);

        cubo_08.render();
        cubo_08.input(window);

        cubo_09.render();
        cubo_09.input(window);

        cubo_11.render();
        cubo_11.input(window);

        cubo_12.render();
        cubo_12.input(window);

        cubo_13.render();
        cubo_13.input(window);

        cubo_14.render();
        cubo_14.input(window);

        cubo_15.render();
        cubo_15.input(window);

        cubo_16.render();
        cubo_16.input(window);

        cubo_17.render();
        cubo_17.input(window);

        cubo_18.render();
        cubo_18.input(window);

        cubo_19.render();
        cubo_19.input(window);

        cubo_21.render();
        cubo_21.input(window);

        cubo_22.render();
        cubo_22.input(window);

        cubo_23.render();
        cubo_23.input(window);

        cubo_24.render();
        cubo_24.input(window);

        cubo_25.render();
        cubo_25.input(window);

        cubo_26.render();
        cubo_26.input(window);

        cubo_27.render();
        cubo_27.input(window);

        cubo_28.render();
        cubo_28.input(window);

        cubo_29.render();
        cubo_29.input(window);


    }

    glm::vec4 g = glm::vec4(0.0f, 0.607f, 0.282f, 1.0f);
    glm::vec4 w = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec4 r = glm::vec4(0.717f, 0.070f, 0.203f, 1.0f);
    glm::vec4 y = glm::vec4(1.0f, 0.835f, 0.0f, 1.0f);
    glm::vec4 b = glm::vec4(0.0f, 0.274f, 0.678f, 1.0f);
    glm::vec4 o = glm::vec4(1.0f, 0.345f, 0.0f, 1.0f);
    glm::vec4 bk = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);

private:
    glm::mat4 model = glm::mat4(1.0f);

    /*

|       +  |    |
|          |    |
|       y  |   /  +
|          |  / z
|       -  | /
|----------|  -
 -  x      +
*/

    //fila 1 
    Cubo cubo_01{ std::vector<glm::vec4>{bk,b,o,bk,bk,w},  glm::vec3(-1.1f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_02{ std::vector<glm::vec4>{bk,b,bk,bk,bk,w}, glm::vec3( 0.0f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_03{ std::vector<glm::vec4>{bk,b,bk,r,bk,w},  glm::vec3( 1.1f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_04{ std::vector<glm::vec4>{bk,bk,o,bk,bk,w}, glm::vec3(-1.1f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_05{ std::vector<glm::vec4>{bk,bk,bk,bk,bk,w},  glm::vec3( 0.0f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_06{ std::vector<glm::vec4>{bk,bk,bk,r,bk,w},  glm::vec3( 1.1f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_07{ std::vector<glm::vec4>{g,bk,o,bk,bk,w},  glm::vec3(-1.1f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_08{ std::vector<glm::vec4>{g,bk,bk,bk,bk,w},  glm::vec3( 0.0f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_09{ std::vector<glm::vec4>{g,bk,bk,r,bk,w},  glm::vec3( 1.1f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model};

    //fila 2
    Cubo cubo_11{ std::vector<glm::vec4>{bk, b, o, bk, bk, bk}, glm::vec3(-1.1f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_12{ std::vector<glm::vec4>{bk,b,bk,bk,bk,bk}, glm::vec3(0.0f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_13{ std::vector<glm::vec4>{bk, b, bk, r, bk, bk}, glm::vec3(1.1f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_14{ std::vector<glm::vec4>{bk,bk,o,bk,bk,bk}, glm::vec3(-1.1f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_15{ std::vector<glm::vec4>{bk,bk,bk,bk,bk,bk}, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_16{ std::vector<glm::vec4>{bk,bk,bk,r,bk,bk}, glm::vec3(1.1f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_17{ std::vector<glm::vec4>{g,bk,o,bk,bk,bk}, glm::vec3(-1.1f, 0.0f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_18{ std::vector<glm::vec4>{g,bk,bk,bk,bk,bk}, glm::vec3(0.0f, 0.0f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_19{ std::vector<glm::vec4>{g,bk,bk,r,bk,bk}, glm::vec3(1.1f, 0.0f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };

    //fila 3
    Cubo cubo_21 = Cubo(std::vector<glm::vec4>{bk, b, o, bk, y, bk}, glm::vec3(-1.1f, -1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_22 = Cubo(std::vector<glm::vec4>{bk, b, bk, bk, y, bk}, glm::vec3(0.0f, -1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_23 = Cubo(std::vector<glm::vec4>{bk, b, bk, r, y, bk}, glm::vec3(1.1f, -1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_24 = Cubo(std::vector<glm::vec4>{bk, bk, o, bk, y, bk}, glm::vec3(-1.1f, -1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_25 = Cubo(std::vector<glm::vec4>{bk, bk, bk, bk, y, bk}, glm::vec3(0.0f, -1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_26 = Cubo(std::vector<glm::vec4>{bk, bk, bk, r, y, bk}, glm::vec3(1.1f, -1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_27 = Cubo(std::vector<glm::vec4>{g, bk, o, bk, y, bk}, glm::vec3(-1.1f, -1.1f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_28 = Cubo(std::vector<glm::vec4>{g, bk, bk, bk, y, bk}, glm::vec3(0.0f, -1.1f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_29 = Cubo(std::vector<glm::vec4>{g, bk, bk, r, y, bk}, glm::vec3(1.1f, -1.1f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);

    int velocidad = 10000;
  


    void U() {;
        float radians = 90.0 / velocidad;
        glm::mat4 model_X = ptr2[0][4]->get_model();
        for (int loop = 0; loop < velocidad; loop++) {
            for (int i = 0; i < 9; i++)
                ptr2[0][i]->set_rotation(-radians, glm::vec3(0.0f, 1.0f, 0.0f), model_X);
        }

        
            
        //actualizando valores
        Cubo temp1 = cubo_01;
        Cubo temp2 = cubo_02;
        cubo_01 = cubo_03;
        cubo_02 = cubo_06;
        cubo_03 = cubo_09;
        cubo_06 = cubo_08;
        cubo_09 = cubo_07;
        cubo_08 = cubo_04;
        cubo_04 = temp2;
        cubo_07 = temp1;
    }

    void L() {
        glm::mat4 model_X = ptr2[1][4]->get_model();
        float radians = 90.0 / velocidad;
        for (int loop = 0; loop < velocidad; loop++) {
           for (int i = 0; i < 9; i++)
               ptr2[1][i]->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);
        }

        //actualizando valores
        Cubo temp7 = cubo_07;
        Cubo temp4 = cubo_04;
        cubo_07 = cubo_01;
        cubo_04 = cubo_11;
        cubo_01 = cubo_21;
        cubo_11 = cubo_24;
        cubo_21 = cubo_27;
        cubo_24 = cubo_17;
        cubo_27 = temp7;
        cubo_17 = temp4;
    }

    void F() {
        glm::mat4 model_X = ptr2[1][8]->get_model();
        float radians = 90.0 / velocidad;
        for (int loop = 0; loop < velocidad; loop++) {
            for (int i = 0; i < 9; i++)
               ptr2[3][i]->set_rotation(-radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);
        }

        //actualizando valores
        Cubo temp7 = cubo_07;
        Cubo temp8 = cubo_08;
        cubo_07 = cubo_09;
        cubo_08 = cubo_19;
        cubo_09 = cubo_29;
        cubo_19 = cubo_28;
        cubo_29 = cubo_27;
        cubo_28 = cubo_17;
        cubo_27 = temp7;
        cubo_17 = temp8;
    }

    void R() {
        glm::mat4 model_X = ptr2[1][8]->get_model();
        float radians = 90.0 / velocidad;
        for (int loop = 0; loop < velocidad; loop++) {
            for (int i = 0; i < 9; i++)
                ptr2[2][i]->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);
        }

        //actualizando valores
        Cubo temp9 = cubo_09;
        Cubo temp6 = cubo_06;
        cubo_09 = cubo_03;
        cubo_06 = cubo_13;
        cubo_03 = cubo_23;
        cubo_13 = cubo_26;
        cubo_23 = cubo_29;
        cubo_26 = cubo_19;
        cubo_29 = temp9;
        cubo_19 = temp6;
    }


    void B() {
        glm::mat4 model_X = ptr2[1][8]->get_model();
        float radians = 90.0 / velocidad;
        for (int loop = 0; loop < velocidad; loop++) {
            for (int i = 0; i < 9; i++)
                ptr2[4][i]->set_rotation(-radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);
        }

        //actualizando valores
        Cubo temp1 = cubo_01;
        Cubo temp2 = cubo_02;
        cubo_01 = cubo_03;
        cubo_02 = cubo_13;
        cubo_03 = cubo_23;
        cubo_13 = cubo_22;
        cubo_23 = cubo_21;
        cubo_22 = cubo_11;
        cubo_21 = temp1;
        cubo_11 = temp2;
    }

    void D() {
        glm::mat4 model_X = ptr2[1][8]->get_model();
        float radians = 90.0 / velocidad;
        for (int loop = 0; loop < velocidad; loop++) {
            for (int i = 0; i < 9; i++)
                ptr2[5][i]->set_rotation(-radians, glm::vec3(0.0f, 0.1f, 0.0f), model_X);
        }

        //actualizando valores
        Cubo temp21 = cubo_21;
        Cubo temp22 = cubo_22;
        cubo_21 = cubo_23;
        cubo_22 = cubo_26;
        cubo_23 = cubo_29;
        cubo_26 = cubo_28;
        cubo_29 = cubo_27;
        cubo_28 = cubo_24;
        cubo_27 = temp21;
        cubo_24 = temp22;
    }

        
    Cubo* ptr2[6][9] =
    {
        //UP
        {&cubo_01,&cubo_02,&cubo_03,&cubo_04, &cubo_05 ,&cubo_06 ,&cubo_07 ,&cubo_08,&cubo_09},
        // left
        {&cubo_01,&cubo_04,&cubo_07,&cubo_17, &cubo_14 ,&cubo_11 ,&cubo_27 ,&cubo_24,&cubo_21},
        //Right
        {&cubo_09,&cubo_06,&cubo_03,&cubo_19, &cubo_16 ,&cubo_13 ,&cubo_29 ,&cubo_26,&cubo_23},
        //front
        {&cubo_07,&cubo_08,&cubo_09,&cubo_17, &cubo_18 ,&cubo_19 ,&cubo_27 ,&cubo_28,&cubo_29},
        //behind
        {&cubo_01,&cubo_02,&cubo_03,&cubo_11, &cubo_12 ,&cubo_13 ,&cubo_21 ,&cubo_22,&cubo_23},
        //down
        {&cubo_21,&cubo_22,&cubo_23,&cubo_24, &cubo_25 ,&cubo_26 ,&cubo_27 ,&cubo_28,&cubo_29}
    };
};

int main()
{
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

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::mat4 model = glm::mat4(1.0f);
    float angle = 20.0f * 2;


    cubo_rubick* Holaaa = new cubo_rubick();

    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------                                                                                       
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        
        Holaaa->render(window);
        //Cubo6->input(window);


        //Cubo7->render();
        //Cubo7->input(window);

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
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}