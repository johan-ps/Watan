#include "textDisplay.h"
#include <iostream>
#include <string>

TextDisplay::TextDisplay() {

}

void pdrawBoard() {
    std::string resource = "CAFFEINE";
    std::string space[5] = {"   ", "    ", "     ", "      ", "       "};
    int diff = 11 - resource.length();
    std::string resourceSpace = "";
    for (int i = 0; i < diff; i++) {
        resourceSpace += " ";
    }
    std::string tab[3] = {"", "               ", "                              "};

    std::string temp = " 0";
    
    std::string hexagon[9] = {
        "|" + temp + "|--" + temp + "--|" + temp + "|",
        "/            \\",
        temp + space[3] + temp + space[2] + temp,
        "/" + space[2] + resource + resourceSpace + "\\",
        "|" + temp + "|" + space[4] + temp + space[4] + "|" + temp + "|",
        "\\                /",
        temp + space[4] + space[3] + temp,
        "\\            /",
        "|" + temp + "|--" + temp + "--|" + temp + "|"
    };
    std::string hex[3] = {
        space[3] + temp + space[2], //just location
        space[2] + resource + resourceSpace, //just resource
        space[4] + temp + space[4], //just value
    };

    int width[9] = {1, 2, 3, 2, 3, 2, 3, 2, 1};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < width[i]; j++) {
            std::cout << hexagon[i];
            if (j + 1 < width[i]) {
                std::cout << hex[i];
            }
        }
        std::cout << std::endl;
    }

}

void TextDisplay::drawBoard() {
    std::string resource = "CAFFEINE";

    // space = {"3 spaces", "4 spaces", "5 spaces", "6 spaces", "7 spaces"}
    std::string space[5] = {"   ", "    ", "     ", "      ", "       "};

    //calculate the remaining spaces after resources is printed
    int diff = 11 - resource.length();
    std::string resourceSpace = "";
    for (int i = 0; i < diff; i++) {
        resourceSpace += " ";
    }
    
    //tab = {"0 spaces", "15 spaces", "30 spaces"}
    std::string tab[3] = {"", "               ", "                              "};

    std::string temp = " 0";

    std::string hexagon[9] = {
        space[2] + "|" + temp + "|--" + temp + "--|" + temp + "|",
        space[2] + "/            \\",
        space[0] + temp + space[3] + temp + space[2] + temp,
        space[0] + "/" + space[2] + resource + resourceSpace + "\\",
        "|" + temp + "|" + space[4] + temp + space[4] + "|" + temp + "|",
        space[0] + "\\                /",
        space[0] + temp + space[4] + space[3] + temp,
        space[2] + "\\            /",
        space[2] + "|" + temp + "|--" + temp + "--|" + temp + "|"
    };

    // for (int i = 0; i < 9; i++) {
    //     std::cout << hexagon[i] << std::endl;
    // }

    std::string hexagonTopRight = hexagon[0] + space[4] + temp + "  ";

    std::cout << tab[2] << hexagon[0] << std::endl;
    std::cout << tab[2] << hexagon[1] << std::endl;
    std::cout << tab[2] << hexagon[2] << std::endl;
    std::cout << tab[2] << hexagon[3] << std::endl;

    std::cout << tab[1] << hexagonTopRight << hexagon[0] << std::endl;
    std::cout << tab[1] << hexagon[1] << "           " << hexagon[1] << std::endl;
    std::cout << tab[1] << hexagon[2] << "          " << hexagon[2] << std::endl;
    std::cout << tab[1] << hexagon[3] << "         " << hexagon[3] << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << tab[0] << hexagonTopRight << hexagonTopRight << hexagon[0] << std::endl;
        std::cout << tab[0] << hexagon[1] << "           " << hexagon[1] << "           " << hexagon[1] << std::endl;
        std::cout << tab[0] << hexagon[2] << "          " << hexagon[2] << "          " << hexagon[2] << std::endl;
        std::cout << tab[0] << hexagon[3] << "         " << hexagon[3] << "         " << hexagon[3] << std::endl;

        std::cout << tab[0] << hexagon[4] << "--" << temp << "--" << hexagon[4] << "--" << temp << "--" << hexagon[4] << std::endl;
        std::cout << tab[0] << hexagon[5] << "         " << hexagon[5] << "         " << hexagon[5] << std::endl;
        std::cout << tab[0] << space[0] << temp << "          " << hexagon[2] << "          " << hexagon[2] << "             " << temp << std::endl;
        std::cout << tab[0] << space[2] << "\\" << "         " << hexagon[3] << "         " << hexagon[3] << "            " << "/" << std::endl;
    }

    std::cout << tab[0] << hexagonTopRight << hexagonTopRight << hexagon[0] << std::endl;

    std::cout << tab[1] << hexagon[5] << "         " << hexagon[5] << std::endl;
    std::cout << tab[1] << hexagon[6] << space[3] + temp + "  " << hexagon[6] << std::endl;
    std::cout << tab[1] << hexagon[7] << space[2] + resource + resourceSpace << "\\            /" << std::endl;
    std::cout << tab[1] << hexagon[8] << space[4] << temp << "  " << hexagon[8] << std::endl;

    std::cout << tab[2] << hexagon[5] << std::endl;
    std::cout << tab[2] << hexagon[6] << std::endl;
    std::cout << tab[2] << hexagon[7] << std::endl;
    std::cout << tab[2] << hexagon[8] << std::endl;
}
