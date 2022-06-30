#pragma once

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
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
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

    void setColor(std::vector<glm::vec4> newColor) {
        colores.clear();
        for (int i = 0; i < 6; i++) {
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
