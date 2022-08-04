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
    char mov='_';
    bool _resolver = false;
    vector<char> lista_mov;
    cubo_rubick() {
        //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    }
    void handle_solution_animations(GLFWwindow* window){
        //cout << "\naction::" << U_action << "\n";
        //cout << "\nmov::" << mov << "\n";
        if(_resolver && U_action == 0){
            if (solution.size() == 0) {
                mov = '_';
                _resolver = false;
            }
            else {
                mov = solution[0];
                solution.erase(solution.begin());
            }
            switch (mov) {
                case 'U':
                    U_action = 1;
                    break;
                case 'u':
                    U_action = 7;
                    break;
                case 'F':
                    U_action = 11;
                    break;
                case 'f':
                    U_action = 5;
                    break;
                case 'W':
                    U_action = 9;
                    break;
                case 'w':
                    U_action = 3;
                    break;
                case 'R':
                    U_action = 4;
                    break;
                case 'r':
                    U_action = 10;
                    break;
                case 'L':
                    U_action = 8;
                    break;
                case 'l':
                    U_action = 2;
                    break;
                case 'D':
                    U_action = 6;
                    break;
                case 'd':
                    U_action = 12;
                    break;
                default:
                    std::cout << "Accion no reconocida: " << mov <<"\n";
                    break;
            }
            
        }
    }
    void input(GLFWwindow* window){
        if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && !_resolver)
            this->resolver();
        if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS && !_resolver)
            this->printHistoriaMov();
        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && U_action == 0)
            U_action = 1;
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && U_action == 0)
            U_action = 2;
        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && U_action == 0)
            U_action = 3;
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && U_action == 0)
            U_action = 4;
        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && U_action == 0)
            U_action = 5;
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && U_action == 0)
            U_action = 6;
        if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS && U_action == 0)
            U_action = 7;
        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && U_action == 0)
            U_action = 8;
        if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS && U_action == 0)
            U_action = 9;
        if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && U_action == 0)
            U_action = 10;
        if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS && U_action == 0)
            U_action = 11;
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && U_action == 0)
            U_action = 12;
    }

    void printHistoriaMov() {
        std::cout << "Numero: " <<lista_mov.size() << "\n";
        for (char i : lista_mov)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    void animations() {
            if (U_action == 1) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: U\n";
                    lista_mov.push_back('U');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[0][i]->rot_z();
                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[0][i]->set_rotation(-radians, glm::vec3(0.0f, 1.0f, 0.0f), model);
            }
            if (U_action == 7) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: u\n";
                    lista_mov.push_back('u');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[0][i]->rot_z();
                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[0][i]->set_rotation(radians, glm::vec3(0.0f, 1.0f, 0.0f), model_X);
            }
            else if (U_action == 2) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: l\n";
                    lista_mov.push_back('l');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[1][i]->rot_y();

                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[1][i]->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);

            }
            else if (U_action == 8) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: L\n";
                    lista_mov.push_back('L');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[1][i]->rot_y();

                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[1][i]->set_rotation(radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);
            }
            else if (U_action == 3) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: b\n";
                    lista_mov.push_back('b');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[3][i]->rot_x();
                }
                glm::mat4 model_X = glm::mat4(1.0f);

                for (int i = 0; i < 9; i++)
                    ptr2[3][i]->set_rotation(radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);
            }
            else if (U_action == 9) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: B\n";
                    lista_mov.push_back('B');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[3][i]->rot_x();
                }
                glm::mat4 model_X = glm::mat4(1.0f);

                for (int i = 0; i < 9; i++)
                    ptr2[3][i]->set_rotation(-radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);
            }
            else if (U_action == 4) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: R\n";
                    lista_mov.push_back('R');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[2][i]->rot_y();
                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[2][i]->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);

            }
            else if (U_action == 10) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: r\n";
                    lista_mov.push_back('r');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[2][i]->rot_y();
                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[2][i]->set_rotation(radians, glm::vec3(1.0f, 0.0f, 0.0f), model_X);

            }
            else if (U_action == 5) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: f\n";
                    lista_mov.push_back('f');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[4][i]->rot_x();
                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[4][i]->set_rotation(radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);

            }
            else if (U_action == 11) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: F\n";
                    lista_mov.push_back('F');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[4][i]->rot_x();
                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[4][i]->set_rotation(-radians, glm::vec3(0.0f, 0.0f, 1.0f), model_X);

            }
            else if (U_action == 6) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: D\n";
                    lista_mov.push_back('D');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[5][i]->rot_z();
                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[5][i]->set_rotation(-radians, glm::vec3(0.0f, 0.1f, 0.0f), model_X);
            }
            else if (U_action == 12) {
                contador_interacion++;
                if (contador_interacion >= velocidad) {
                    contador_interacion = 0;
                    U_action = 0;
                    std::cout << "\nRotacion finalizada: d\n";
                    lista_mov.push_back('d');
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

                    //actualizado colores
                    for (int i = 0; i < 9; i++)
                        ptr2[5][i]->rot_z();
                }
                glm::mat4 model_X = glm::mat4(1.0f);
                for (int i = 0; i < 9; i++)
                    ptr2[5][i]->set_rotation(radians, glm::vec3(0.0f, 0.1f, 0.0f), model_X);
            }
    }
    void render(GLFWwindow* window, glm::mat4 view, glm::mat4 projection) {
        this->input(window);
        this->handle_solution_animations(window);
        this->animations();
        cubo_01.render(view, projection);
        cubo_02.render(view, projection);
        cubo_03.render(view, projection);
        cubo_04.render(view, projection);
        cubo_05.render(view, projection);
        cubo_06.render(view, projection);
        cubo_07.render(view, projection);
        cubo_08.render(view, projection);
        cubo_09.render(view, projection);
        cubo_11.render(view, projection);
        cubo_12.render(view, projection);
        cubo_13.render(view, projection);
        cubo_14.render(view, projection);
        cubo_15.render(view, projection);
        cubo_16.render(view, projection);
        cubo_17.render(view, projection);
        cubo_18.render(view, projection);
        cubo_19.render(view, projection);
        cubo_21.render(view, projection);
        cubo_22.render(view, projection);
        cubo_23.render(view, projection);
        cubo_24.render(view, projection);
        cubo_25.render(view, projection);
        cubo_26.render(view, projection);
        cubo_27.render(view, projection);
        cubo_28.render(view, projection);
        cubo_29.render(view, projection);
    }

    glm::vec4 g = glm::vec4(0.0f, 0.607f, 0.282f, 1.0f);
    glm::vec4 w = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec4 r = glm::vec4(0.717f, 0.070f, 0.203f, 1.0f);
    glm::vec4 y = glm::vec4(1.0f, 0.835f, 0.0f, 1.0f);
    glm::vec4 b = glm::vec4(0.0f, 0.274f, 0.678f, 1.0f);
    glm::vec4 o = glm::vec4(1.0f, 0.345f, 0.0f, 1.0f);
    glm::vec4 bk = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);

    bool resolver() {
        solution.clear();
        std::string cubeString = mapping();
        std::istringstream file(cubeString);
        file >> rubik_solver;
        rubik_solver.solve(solution);

        for (unsigned int i = 0; i < solution.size(); ++i)
            std::cout << solution[i];
        std::cout << endl;
        _resolver = true;
        return true;
    }

    /*
    UP,LEFT,FRONT,RIGHT,BEHING,DOWN
    */
    std::string mapping() {
        std::string rubik_colors;
        //UP
        for (int i = 0; i < 9; i++) {
                rubik_colors += ptr2[0][i]->getColor(0);
                rubik_colors += " ";
        }
        rubik_colors += "\n";
        //LEFT
        for (int i = 0; i < 9; i++) {
            rubik_colors += ptr2[1][i]->getColor(2);
            rubik_colors += " ";
        }
        rubik_colors += "\n";
        //FRONT
        for (int i = 0; i < 9; i++) {
            rubik_colors += ptr2[4][i]->getColor(1);
            rubik_colors += " ";
        }
        rubik_colors += "\n";
        //RIGHT
        for (int i = 0; i < 9; i++) {
            rubik_colors += ptr2[2][i]->getColor(2);
            rubik_colors += " ";
        }
        rubik_colors += "\n";
        //BEHING
        for (int i = 0; i < 9; i++) {
            rubik_colors += ptr2[3][i]->getColor(1);
            rubik_colors += " ";
        }
        rubik_colors += "\n";
        //DOWN
        for (int i = 0; i < 9; i++) {
            rubik_colors += ptr2[5][i]->getColor(0);
            rubik_colors += " ";
        }

        std::cout << rubik_colors << "\n"<<"===========================================\n";
     
        return rubik_colors;
    }

    /*
    UP,LEFT,FRONT,RIGHT,BEHING,DOWN
    */
    /*
    std::string mapping_2() {
        rubik_solver_2.red[0] = ;
        rubik_solver_2.red[1] = ;
        rubik_solver_2.red[2] = ;
        rubik_solver_2.red[3] = ;
        rubik_solver_2.red[4] = ;
        rubik_solver_2.red[5] = ;
        rubik_solver_2.red[6] = ;
        rubik_solver_2.red[7] = ;
        rubik_solver_2.red[8] = ;
    }
    */



private:
    std::vector<char> solution;
    Rubik rubik_solver;

    Solver rubik_solver_2;
    //glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
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
    Cubo cubo_01{ std::vector<glm::vec4>{bk,g,o,bk,bk,w}, "gow", glm::vec3(-1.1f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model};
    Cubo cubo_02{ std::vector<glm::vec4>{bk,g,bk,bk,bk,w}, "gyw", glm::vec3(0.0f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_03{ std::vector<glm::vec4>{bk,g,bk,r,bk,w}, "grw", glm::vec3(1.1f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_04{ std::vector<glm::vec4>{bk,bk,o,bk,bk,w}, "xow", glm::vec3(-1.1f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_05{ std::vector<glm::vec4>{bk,bk,bk,bk,bk,w}, "xyw", glm::vec3(0.0f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_06{ std::vector<glm::vec4>{bk,bk,bk,r,bk,w},  "xrw", glm::vec3(1.1f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_07{ std::vector<glm::vec4>{b,bk,o,bk,bk,w}, "low", glm::vec3(-1.1f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_08{ std::vector<glm::vec4>{b,bk,bk,bk,bk,w}, "lyw",  glm::vec3(0.0f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_09{ std::vector<glm::vec4>{b,bk,bk,r,bk,w}, "lrw",  glm::vec3(1.1f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };

    //fila 2
    Cubo cubo_11{ std::vector<glm::vec4>{bk, g, o, bk, bk, bk}, "go-", glm::vec3(-1.1f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_12{ std::vector<glm::vec4>{bk, g,bk,bk,bk,bk}, "gy-", glm::vec3(0.0f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_13{ std::vector<glm::vec4>{bk, g, bk, r, bk, bk}, "gr-", glm::vec3(1.1f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_14{ std::vector<glm::vec4>{bk,bk,o,bk,bk,bk}, "xo-", glm::vec3(-1.1f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_15{ std::vector<glm::vec4>{bk,bk,bk,bk,bk,bk}, "xy-", glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_16{ std::vector<glm::vec4>{bk,bk,bk,r,bk,bk}, "xr-", glm::vec3(1.1f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_17{ std::vector<glm::vec4>{b,bk,o,bk,bk,bk}, "lo-", glm::vec3(-1.1f, 0.0f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_18{ std::vector<glm::vec4>{b,bk,bk,bk,bk,bk}, "ly-", glm::vec3(0.0f, 0.0f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_19{ std::vector<glm::vec4>{b,bk,bk,r,bk,bk}, "lr-", glm::vec3(1.1f, 0.0f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };

    //fila 3
    Cubo cubo_21 = Cubo(std::vector<glm::vec4>{bk, g, o, bk, y, bk}, "goy", glm::vec3(-1.1f, -1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_22 = Cubo(std::vector<glm::vec4>{bk, g, bk, bk, y, bk}, "g-y", glm::vec3(0.0f, -1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_23 = Cubo(std::vector<glm::vec4>{bk, g, bk, r, y, bk}, "gry", glm::vec3(1.1f, -1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_24 = Cubo(std::vector<glm::vec4>{bk, bk, o, bk, y, bk}, "-oy", glm::vec3(-1.1f, -1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_25 = Cubo(std::vector<glm::vec4>{bk, bk, bk, bk, y, bk}, "--y", glm::vec3(0.0f, -1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_26 = Cubo(std::vector<glm::vec4>{bk, bk, bk, r, y, bk}, "-ry", glm::vec3(1.1f, -1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_27 = Cubo(std::vector<glm::vec4>{b, bk, o, bk, y, bk}, "loy", glm::vec3(-1.1f, -1.1f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_28 = Cubo(std::vector<glm::vec4>{b, bk, bk, bk, y, bk}, "l-y", glm::vec3(0.0f, -1.1f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_29 = Cubo(std::vector<glm::vec4>{b, bk, bk, r, y, bk}, "lry", glm::vec3(1.1f, -1.1f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);


    Cubo* ptr2[6][9] =
    {
        //UP
        {&cubo_09,&cubo_08,&cubo_07,&cubo_06,&cubo_05,&cubo_04,&cubo_03,&cubo_02,&cubo_01},
        //left
        {&cubo_07,&cubo_04,&cubo_01,&cubo_17,&cubo_14,&cubo_11,&cubo_27,&cubo_24,&cubo_21},
        //Right
        {&cubo_03,&cubo_06,&cubo_09,&cubo_13,&cubo_16,&cubo_19,&cubo_23,&cubo_26,&cubo_29},
        //behind
        {&cubo_09,&cubo_08,&cubo_07,&cubo_19,&cubo_18,&cubo_17,&cubo_29,&cubo_28,&cubo_27},
        //front
        {&cubo_01,&cubo_02,&cubo_03,&cubo_11,&cubo_12,&cubo_13,&cubo_21,&cubo_22,&cubo_23},
        //down
        {&cubo_21,&cubo_22,&cubo_23,&cubo_24,&cubo_25,&cubo_26,&cubo_27,&cubo_28,&cubo_29}
    };
};