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
    void render(GLFWwindow* window, glm::mat4 view, glm::mat4 projection) {

        //U horario
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
        //U antihorario
        if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS && U_action == 0)
            U_action = 7;
        //L antihorario
        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && U_action == 0)
            U_action = 8;
        //F antihorario
        if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS && U_action == 0)
            U_action = 9;
        //R antihorario
        if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && U_action == 0)
            U_action = 10;
        //B antihorario
        if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS && U_action == 0)
            U_action = 11;
        //D antihorario
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && U_action == 0)
            U_action = 12;

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

                char tempcolor1 = ptr2[0][0].second;
                char tempcolor2 = ptr2[0][1].second;
                ptr2[0][0].second = ptr2[0][2].second;
                ptr2[0][1].second = ptr2[0][5].second;
                ptr2[0][2].second = ptr2[0][8].second;
                ptr2[0][5].second = ptr2[0][7].second;
                ptr2[0][8].second = ptr2[0][6].second;
                ptr2[0][7].second = ptr2[0][3].second;
                ptr2[0][6].second = tempcolor1;
                ptr2[0][3].second = tempcolor2;
            }
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[0][i].first->set_rotation(-radians, glm::vec3(0.0f, 1.0f, 0.0f), model);
        }
        if (U_action == 7) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

                //actualizando valores
                Cubo temp1 = cubo_01;
                Cubo temp4 = cubo_04;
                cubo_01 = cubo_07;
                cubo_04 = cubo_08;
                cubo_07 = cubo_09;
                cubo_08 = cubo_06;
                cubo_09 = cubo_03;
                cubo_06 = cubo_02;
                cubo_03 = temp1;
                cubo_02 = temp4;

                char tempcolor1 = ptr2[0][0].second;
                char tempcolor2 = ptr2[0][1].second;
                ptr2[0][0].second = ptr2[0][2].second;
                ptr2[0][1].second = ptr2[0][5].second;
                ptr2[0][2].second = ptr2[0][8].second;
                ptr2[0][5].second = ptr2[0][7].second;
                ptr2[0][8].second = ptr2[0][6].second;
                ptr2[0][7].second = ptr2[0][3].second;
                ptr2[0][6].second = tempcolor1;
                ptr2[0][3].second = tempcolor2;
            }
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[0][i].first->set_rotation(radians, glm::vec3(0.0f, 1.0f, 0.0f), model_X);
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
                ptr2[1][i].first->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);

        }
        else if (U_action == 8) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

                //actualizando valores
                Cubo temp1 = cubo_01;
                Cubo temp4 = cubo_04;
                cubo_01 = cubo_07;
                cubo_04 = cubo_17;
                cubo_07 = cubo_27;
                cubo_17 = cubo_24;
                cubo_27 = cubo_21;
                cubo_24 = cubo_11;
                cubo_21 = temp1;
                cubo_11 = temp4;

            }
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[1][i].first->set_rotation(radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);
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
                ptr2[3][i].first->set_rotation(radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);
        }
        else if (U_action == 9) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

                //actualizando valores
                Cubo temp7 = cubo_07;
                Cubo temp17 = cubo_17;
                cubo_07 = cubo_27;
                cubo_17 = cubo_28;
                cubo_27 = cubo_29;
                cubo_28 = cubo_19;
                cubo_29 = cubo_09;
                cubo_19 = cubo_08;
                cubo_09 = temp7;
                cubo_08 = temp17;
            }
            glm::mat4 model_X = glm::mat4(1.0f);

            for (int i = 0; i < 9; i++)
                ptr2[3][i].first->set_rotation(-radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);
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
                ptr2[2][i].first->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);

        }
        else if (U_action == 10) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

                //actualizando valores
                Cubo temp9 = cubo_09;
                Cubo temp19 = cubo_19;
                cubo_09 = cubo_29;
                cubo_19 = cubo_26;
                cubo_29 = cubo_23;
                cubo_26 = cubo_13;
                cubo_23 = cubo_03;
                cubo_13 = cubo_06;
                cubo_03 = temp9;
                cubo_06 = temp19;
            }
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[2][i].first->set_rotation(radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);

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
                ptr2[4][i].first->set_rotation(radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);
   
        }
        else if (U_action == 11) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

                //actualizando valores
                Cubo temp1 = cubo_01;
                Cubo temp11 = cubo_11;
                cubo_01 = cubo_21;
                cubo_11 = cubo_22;
                cubo_21 = cubo_23;
                cubo_22 = cubo_13;
                cubo_23 = cubo_03;
                cubo_13 = cubo_02;
                cubo_03 = temp1;
                cubo_02 = temp11;
            }
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[4][i].first->set_rotation(-radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);

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
                ptr2[5][i].first->set_rotation(-radians, glm::vec3(0.0f, 0.1f, 0.0f), model_X);
        }
        else if (U_action == 12) {
            contador_interacion++;
            if (contador_interacion >= velocidad) {
                contador_interacion = 0;
                U_action = 0;
                std::cout << "\nRotacion finalizada\n";

                //actualizando valores
                Cubo temp21 = cubo_21;
                Cubo temp24 = cubo_24;
                cubo_21 = cubo_27;
                cubo_24 = cubo_28;
                cubo_27 = cubo_29;
                cubo_28 = cubo_26;
                cubo_29 = cubo_23;
                cubo_26 = cubo_22;
                cubo_23 = temp21;
                cubo_22 = temp24;
            }
            glm::mat4 model_X = glm::mat4(1.0f);
            for (int i = 0; i < 9; i++)
                ptr2[5][i].first->set_rotation(radians, glm::vec3(0.0f, 0.1f, 0.0f), model_X);
            }

        cubo_01.render(view, projection);
        cubo_01.input(window);

        cubo_02.render(view, projection);
        cubo_02.input(window);

        cubo_03.render(view, projection);
        cubo_03.input(window);

        cubo_04.render(view, projection);
        cubo_04.input(window);

        cubo_05.render(view, projection);
        cubo_05.input(window);

        cubo_06.render(view, projection);
        cubo_06.input(window);

        cubo_07.render(view, projection);
        cubo_07.input(window);

        cubo_08.render(view, projection);
        cubo_08.input(window);

        cubo_09.render(view, projection);
        cubo_09.input(window);

        cubo_11.render(view, projection);
        cubo_11.input(window);

        cubo_12.render(view, projection);
        cubo_12.input(window);

        cubo_13.render(view, projection);
        cubo_13.input(window);

        cubo_14.render(view, projection);
        cubo_14.input(window);

        cubo_15.render(view, projection);
        cubo_15.input(window);

        cubo_16.render(view, projection);
        cubo_16.input(window);

        cubo_17.render(view, projection);
        cubo_17.input(window);

        cubo_18.render(view, projection);
        cubo_18.input(window);

        cubo_19.render(view, projection);
        cubo_19.input(window);

        cubo_21.render(view, projection);
        cubo_21.input(window);

        cubo_22.render(view, projection);
        cubo_22.input(window);

        cubo_23.render(view, projection);
        cubo_23.input(window);

        cubo_24.render(view, projection);
        cubo_24.input(window);

        cubo_25.render(view, projection);
        cubo_25.input(window);

        cubo_26.render(view, projection);
        cubo_26.input(window);

        cubo_27.render(view, projection);
        cubo_27.input(window);

        cubo_28.render(view, projection);
        cubo_28.input(window);

        cubo_29.render(view, projection);
        cubo_29.input(window);

    }

    glm::vec4 g = glm::vec4(0.0f, 0.607f, 0.282f, 1.0f);
    glm::vec4 w = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec4 r = glm::vec4(0.717f, 0.070f, 0.203f, 1.0f);
    glm::vec4 y = glm::vec4(1.0f, 0.835f, 0.0f, 1.0f);
    glm::vec4 b = glm::vec4(0.0f, 0.274f, 0.678f, 1.0f);
    glm::vec4 o = glm::vec4(1.0f, 0.345f, 0.0f, 1.0f);
    glm::vec4 bk = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);



    bool resolver() {
        std::string cubeString = mapeo();
        std::istringstream file(cubeString);
        file >> rubik_solver;
        rubik_solver.solve(solution);

        for (unsigned int i = 0; i < solution.size(); ++i)
            std::cout << solution[i];
        std::cout << endl;

        return true;
    }

    std::string mapeo() {
        std::string rubik_colors;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                rubik_colors += ptr2[i][j].second;
                rubik_colors += " ";
            }
            rubik_colors += "\n";
        }
        for (int j = 0; j < 9; j++) {
            rubik_colors += ptr2[5][j].second;
            rubik_colors += " ";
        }
        return rubik_colors;
    }

private:
    std::vector<char> solution;
    Rubik rubik_solver;
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


    pair<Cubo*, char> ptr2[6][9] =
    {
        //UP
        {make_pair(&cubo_01,'w'),make_pair(&cubo_02,'w'),make_pair(&cubo_03,'w'),make_pair(&cubo_04,'w'),make_pair(&cubo_05,'w'),make_pair(&cubo_06,'w'),make_pair(&cubo_07,'w'),make_pair(&cubo_08,'w'),make_pair(&cubo_09,'w')},
        //left
        {make_pair(&cubo_01,'o'),make_pair(&cubo_04,'o'),make_pair(&cubo_07,'o'),make_pair(&cubo_17,'o'),make_pair(&cubo_14,'o'),make_pair(&cubo_11,'o'),make_pair(&cubo_27,'o'),make_pair(&cubo_24,'o'),make_pair(&cubo_21,'o')},
        //Right
        {make_pair(&cubo_09,'g'),make_pair(&cubo_06,'g'),make_pair(&cubo_03,'g'),make_pair(&cubo_19,'g'),make_pair(&cubo_16,'g'),make_pair(&cubo_13,'g'),make_pair(&cubo_29,'g'),make_pair(&cubo_26,'g'),make_pair(&cubo_23,'g')},
        //front
        {make_pair(&cubo_07,'r'),make_pair(&cubo_08,'r'),make_pair(&cubo_09,'r'),make_pair(&cubo_17,'r'),make_pair(&cubo_18,'r'),make_pair(&cubo_19,'r'),make_pair(&cubo_27,'r'),make_pair(&cubo_28,'r'),make_pair(&cubo_29,'r')},
        //behind
        {make_pair(&cubo_01,'l'),make_pair(&cubo_02,'l'),make_pair(&cubo_03,'l'),make_pair(&cubo_11,'l'),make_pair(&cubo_12,'l'),make_pair(&cubo_13,'l'),make_pair(&cubo_21,'l'),make_pair(&cubo_22,'l'),make_pair(&cubo_23,'l')},
        //down
        {make_pair(&cubo_21,'y'),make_pair(&cubo_22,'y'),make_pair(&cubo_23,'y'),make_pair(&cubo_24,'y'),make_pair(&cubo_25,'y'),make_pair(&cubo_26,'y'),make_pair(&cubo_27,'y'),make_pair(&cubo_28,'y'),make_pair(&cubo_29,'y')}
    };
};