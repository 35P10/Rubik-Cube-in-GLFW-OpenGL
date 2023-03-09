#pragma once

class cubo_rubik {
public:
    cubo_rubik();
    cubo_rubik(float, glm::vec3);
    void render(GLFWwindow*, glm::mat4 view, glm::mat4 projection);
    bool resolver();
    std::string mapping();
private:
    void handle_solution_animations(GLFWwindow* window);
    void input(GLFWwindow* window);
    void printHistoriaMov();
    void animations();

    std::vector<char>   solution;
    Rubik               rubik_solver;
    glm::mat4           model       = glm::mat4(1.0f);
    int                 U_action    = 0;
    int                 velocidad   = 40;
    float               radians     = 90.0 / velocidad;
    int                 contador_interacion = 0;
    char                mov         = '_';
    bool                _resolver   = false;
    vector<char>        lista_mov;

    glm::vec4 g = glm::vec4(0.0f, 0.607f, 0.282f, 1.0f);
    glm::vec4 w = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec4 red = glm::vec4(0.717f, 0.070f, 0.203f, 1.0f);
    glm::vec4 y = glm::vec4(1.0f, 0.835f, 0.0f, 1.0f);
    glm::vec4 blue = glm::vec4(0.0f, 0.274f, 0.678f, 1.0f);
    glm::vec4 o = glm::vec4(1.0f, 0.345f, 0.0f, 1.0f);
    glm::vec4 bk = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);

    //definiendo cubos
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
    Cubo cubo_03{ std::vector<glm::vec4>{bk,g,bk,red,bk,w}, "grw", glm::vec3(1.1f, 1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_04{ std::vector<glm::vec4>{bk,bk,o,bk,bk,w}, "xow", glm::vec3(-1.1f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_05{ std::vector<glm::vec4>{bk,bk,bk,bk,bk,w}, "xyw", glm::vec3(0.0f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_06{ std::vector<glm::vec4>{bk,bk,bk,red,bk,w},  "xrw", glm::vec3(1.1f, 1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_07{ std::vector<glm::vec4>{blue,bk,o,bk,bk,w}, "low", glm::vec3(-1.1f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_08{ std::vector<glm::vec4>{blue,bk,bk,bk,bk,w}, "lyw",  glm::vec3(0.0f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_09{ std::vector<glm::vec4>{blue,bk,bk,red,bk,w}, "lrw",  glm::vec3(1.1f, 1.1f,-1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };

    //fila 2
    Cubo cubo_11{ std::vector<glm::vec4>{bk, g, o, bk, bk, bk}, "go-", glm::vec3(-1.1f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_12{ std::vector<glm::vec4>{bk, g,bk,bk,bk,bk}, "gy-", glm::vec3(0.0f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_13{ std::vector<glm::vec4>{bk, g, bk, red, bk, bk}, "gr-", glm::vec3(1.1f, 0.0f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_14{ std::vector<glm::vec4>{bk,bk,o,bk,bk,bk}, "xo-", glm::vec3(-1.1f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_15{ std::vector<glm::vec4>{bk,bk,bk,bk,bk,bk}, "xy-", glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_16{ std::vector<glm::vec4>{bk,bk,bk,red,bk,bk}, "xr-", glm::vec3(1.1f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_17{ std::vector<glm::vec4>{blue,bk,o,bk,bk,bk}, "lo-", glm::vec3(-1.1f, 0.0f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_18{ std::vector<glm::vec4>{blue,bk,bk,bk,bk,bk}, "ly-", glm::vec3(0.0f, 0.0f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };
    Cubo cubo_19{ std::vector<glm::vec4>{blue,bk,bk,red,bk,bk}, "lr-", glm::vec3(1.1f, 0.0f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model };

    //fila 3
    Cubo cubo_21 = Cubo(std::vector<glm::vec4>{bk, g, o, bk, y, bk}, "goy", glm::vec3(-1.1f, -1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_22 = Cubo(std::vector<glm::vec4>{bk, g, bk, bk, y, bk}, "g-y", glm::vec3(0.0f, -1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_23 = Cubo(std::vector<glm::vec4>{bk, g, bk, red, y, bk}, "gry", glm::vec3(1.1f, -1.1f, 1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_24 = Cubo(std::vector<glm::vec4>{bk, bk, o, bk, y, bk}, "-oy", glm::vec3(-1.1f, -1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_25 = Cubo(std::vector<glm::vec4>{bk, bk, bk, bk, y, bk}, "--y", glm::vec3(0.0f, -1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_26 = Cubo(std::vector<glm::vec4>{bk, bk, bk, red, y, bk}, "-ry", glm::vec3(1.1f, -1.1f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_27 = Cubo(std::vector<glm::vec4>{blue, bk, o, bk, y, bk}, "loy", glm::vec3(-1.1f, -1.1f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_28 = Cubo(std::vector<glm::vec4>{blue, bk, bk, bk, y, bk}, "l-y", glm::vec3(0.0f, -1.1f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);
    Cubo cubo_29 = Cubo(std::vector<glm::vec4>{blue, bk, bk, red, y, bk}, "lry", glm::vec3(1.1f, -1.1f, -1.1f), glm::vec3(0.2f, 0.2f, 0.2f), model);

    //movimientos
    void U();
    void u();
    void L();
    void l();
    void F();
    void f();
    void R();
    void r();
    void B();
    void b();
    void D();
    void d();

    //grupo de cubos por caras
    Cubo* ptr2[6][9] =
    {
        //UP
        {&cubo_07,&cubo_08,&cubo_09,&cubo_04,&cubo_05,&cubo_06,&cubo_01,&cubo_02,&cubo_03},
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

cubo_rubik::cubo_rubik() {
    model = glm::mat4(1.0f);
}

cubo_rubik::cubo_rubik(float rotacion, glm::vec3 ejes) {
    model = glm::rotate(model, glm::radians(rotacion), ejes);
}

bool cubo_rubik::resolver() {
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

std::string cubo_rubik::mapping() {
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

    std::cout << rubik_colors << "\n" << "===========================================\n";

    return rubik_colors;
}

void cubo_rubik::U() {
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
    for (int i = 0; i < 9; i++)
        ptr2[0][i]->set_rotation(-radians, glm::vec3(0.0f, 1.0f, 0.0f));
}

void cubo_rubik::u() {
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
    for (int i = 0; i < 9; i++)
        ptr2[0][i]->set_rotation(radians, glm::vec3(0.0f, 1.0f, 0.0f));
}

void cubo_rubik::l() {
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
    for (int i = 0; i < 9; i++)
        ptr2[1][i]->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f));
}

void cubo_rubik::L() {
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
    for (int i = 0; i < 9; i++)
        ptr2[1][i]->set_rotation(radians, glm::vec3(1.0f, 0.0f, 0.0f));
}

void cubo_rubik::D() {
    contador_interacion++;
    if (contador_interacion >= velocidad) {
        contador_interacion = 0;
        U_action = 0;
        std::cout << "\nRotacion finalizada: D\n";
        lista_mov.push_back('D');
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
    for (int i = 0; i < 9; i++)
        ptr2[5][i]->set_rotation(radians, glm::vec3(0.0f, 0.1f, 0.0f));
}
void cubo_rubik::B() {
    contador_interacion++;
    if (contador_interacion >= velocidad) {
        contador_interacion = 0;
        U_action = 0;
        std::cout << "\nRotacion finalizada: B\n";
        lista_mov.push_back('B');
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
    for (int i = 0; i < 9; i++)
        ptr2[3][i]->set_rotation(radians, glm::vec3(0.0f, 0.0f, 1.0f));
}
void cubo_rubik::b() {
    contador_interacion++;
    if (contador_interacion >= velocidad) {
        contador_interacion = 0;
        U_action = 0;
        std::cout << "\nRotacion finalizada: b\n";
        lista_mov.push_back('b');
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
    for (int i = 0; i < 9; i++)
        ptr2[3][i]->set_rotation(-radians, glm::vec3(0.0f, 0.0f, 1.0f));
}
void cubo_rubik::R() {
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
    for (int i = 0; i < 9; i++)
        ptr2[2][i]->set_rotation(-radians, glm::vec3(1.0f, 0.0f, 0.0f));
}
void cubo_rubik::r() {
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
    for (int i = 0; i < 9; i++)
        ptr2[2][i]->set_rotation(radians, glm::vec3(1.0f, 0.0f, 0.0f));
}
void cubo_rubik::f() {
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
    for (int i = 0; i < 9; i++)
        ptr2[4][i]->set_rotation(radians, glm::vec3(0.0f, 0.0f, 1.0f));
}
void cubo_rubik::F() {
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
    for (int i = 0; i < 9; i++)
        ptr2[4][i]->set_rotation(-radians, glm::vec3(0.0f, 0.0f, 1.0f));
}
void cubo_rubik::d() {
    contador_interacion++;
    if (contador_interacion >= velocidad) {
        contador_interacion = 0;
        U_action = 0;
        std::cout << "\nRotacion finalizada: d\n";
        lista_mov.push_back('d');
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
    for (int i = 0; i < 9; i++)
        ptr2[5][i]->set_rotation(-radians, glm::vec3(0.0f, 0.1f, 0.0f));
}
void cubo_rubik::handle_solution_animations(GLFWwindow* window) {
    if (_resolver && U_action == 0) {
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
        case 'w':
            U_action = 9;
            break;
        case 'W':
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
            U_action = 12;
            break;
        case 'd':
            U_action = 6;
            break;
        default:
            std::cout << "Accion no reconocida: " << mov << "\n";
            break;
        }

    }
}

void cubo_rubik::input(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && !_resolver)
        this->resolver();
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS && !_resolver)
        this->printHistoriaMov();
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS && !_resolver)
        this->mapping();
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

void cubo_rubik::printHistoriaMov() {
    std::cout << "Numero: " << lista_mov.size() << "\n";
    for (char i : lista_mov)
        std::cout << i << " ";
    std::cout << std::endl;
}

void cubo_rubik::render(GLFWwindow* window, glm::mat4 view, glm::mat4 projection) {
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

void  cubo_rubik::animations() {
    switch (U_action){
        case 1:
            U();
            break;
        case 2:
            l();
            break;
        case 3:
            B();
            break;
        case 4:
            R();
            break;
        case 5:
            f();
            break;
        case 6:
            d();
            break;
        case 7:
            u();
            break;
        case 8:
            L();
            break;
        case 9:
            b();
            break;
        case 10:
            r();
            break;
        case 11:
            F();
            break;
        case 12:
            D();
            break;
        default:
            break;
    }
}