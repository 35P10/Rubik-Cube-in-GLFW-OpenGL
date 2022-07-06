#pragma once


class cubo_rubick {
public:
    /*
    0 -> Disponible para realizar una accion
    1 -> UP
    2 -> LEFT
    3 -> FRONT
    4 -> RIGHT
    5 -> BEHIND
    6 -> DOWN/BOTTOM
    */
    int U_action = 0;
    int velocidad = 40;
    float radians = 90.0 / velocidad;
    int contador_interacion = 0;

    cubo_rubick() {
        //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    }


    void render(GLFWwindow* window, glm::mat4 view) {

        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && U_action == 0)
            U_action = 1;
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && U_action == 0)
            U_action = 2;
        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && U_action == 0)
            U_action = 3;
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && U_action == 0)
            U_action = 4;
        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && U_action == 0)
            U_action = 5;
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && U_action == 0)
            U_action = 6;

        if (U_action == 1){
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

                //actualizando valores
                Cubo temp1 = cubo_01;
                Cubo temp2 = cubo_02;
                cubo_01 = cubo_03;
                cubo_02 = cubo_06;
                cubo_03 = cubo_09;
                cubo_06 = cubo_08;
                cubo_09 = cubo_07;
                cubo_08 = cubo_04;
                cubo_07 = temp1;
                cubo_04 = temp2;
            }
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[0][i]->set_rotation(-radians, glm::vec3(0.0f, 1.0f, 0.0f), model);
        }
        else if (U_action == 2) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

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
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[1][i]->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);

        }
        else if (U_action == 3) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

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
            glm::mat4 model_X = glm::mat4(1.0f);

            for (int i = 0; i < 9; i++)
                ptr2[3][i]->set_rotation(radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);
        }
        else if (U_action == 4) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

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
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[2][i]->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);

        }
        else if (U_action == 5) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

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
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[4][i]->set_rotation(radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);
   
        }
        else if (U_action == 6) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

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
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[5][i]->set_rotation(-radians, glm::vec3(0.0f, 0.1f, 0.0f), model_X);
        }

        cubo_01.render(view);
        cubo_01.input(window);

        cubo_02.render(view);
        cubo_02.input(window);

        cubo_03.render(view);
        cubo_03.input(window);

        cubo_04.render(view);
        cubo_04.input(window);

        cubo_05.render(view);
        cubo_05.input(window);

        cubo_06.render(view);
        cubo_06.input(window);

        cubo_07.render(view);
        cubo_07.input(window);

        cubo_08.render(view);
        cubo_08.input(window);

        cubo_09.render(view);
        cubo_09.input(window);

        cubo_11.render(view);
        cubo_11.input(window);

        cubo_12.render(view);
        cubo_12.input(window);

        cubo_13.render(view);
        cubo_13.input(window);

        cubo_14.render(view);
        cubo_14.input(window);

        cubo_15.render(view);
        cubo_15.input(window);

        cubo_16.render(view);
        cubo_16.input(window);

        cubo_17.render(view);
        cubo_17.input(window);

        cubo_18.render(view);
        cubo_18.input(window);

        cubo_19.render(view);
        cubo_19.input(window);

        cubo_21.render(view);
        cubo_21.input(window);

        cubo_22.render(view);
        cubo_22.input(window);

        cubo_23.render(view);
        cubo_23.input(window);

        cubo_24.render(view);
        cubo_24.input(window);

        cubo_25.render(view);
        cubo_25.input(window);

        cubo_26.render(view);
        cubo_26.input(window);

        cubo_27.render(view);
        cubo_27.input(window);

        cubo_28.render(view);
        cubo_28.input(window);

        cubo_29.render(view);
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
    //glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(-55.0f), glm::vec3(0.0f, 1.0f, 0.0f));

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
    Cubo cubo_01{ std::vector<glm::vec4>{bk,b,o,bk,bk,w},  glm::vec3(-1.1f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_02{ std::vector<glm::vec4>{bk,b,bk,bk,bk,w}, glm::vec3(0.0f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_03{ std::vector<glm::vec4>{bk,b,bk,r,bk,w},  glm::vec3(1.1f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_04{ std::vector<glm::vec4>{bk,bk,o,bk,bk,w}, glm::vec3(-1.1f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_05{ std::vector<glm::vec4>{bk,bk,bk,bk,bk,w},  glm::vec3(0.0f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_06{ std::vector<glm::vec4>{bk,bk,bk,r,bk,w},  glm::vec3(1.1f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_07{ std::vector<glm::vec4>{g,bk,o,bk,bk,w},  glm::vec3(-1.1f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_08{ std::vector<glm::vec4>{g,bk,bk,bk,bk,w},  glm::vec3(0.0f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_09{ std::vector<glm::vec4>{g,bk,bk,r,bk,w},  glm::vec3(1.1f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };

    //fila 2
    Cubo cubo_11{ std::vector<glm::vec4>{bk, b, o, bk, bk, bk}, glm::vec3(-1.1f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_12{ std::vector<glm::vec4>{bk,b,bk,bk,bk,bk}, glm::vec3(0.0f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_13{ std::vector<glm::vec4>{bk, b, bk, r, bk, bk}, glm::vec3(1.1f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_14{ std::vector<glm::vec4>{bk,bk,o,bk,bk,bk}, glm::vec3(-1.1f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
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