#include "ladder.h"

int main(int argc, char *argv[]) {

    verify_word_ladder();

}

// g++ -std=c++20 -o exec src/ladder_main.cpp src/ladder.cpp
// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./exec