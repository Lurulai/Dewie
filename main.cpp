//
// Created by saritak on 14/02/2023.
//

#include "Game.h"

int main() {
    std::srand(static_cast<unsigned>(time(nullptr)));

    // initialise game engine
    Game dewie;

    // run the program as long as the window is open
    while (dewie.IsRunning()) {
        // update the game.
        dewie.Update();

        // render the game
        dewie.Render();
    }

    return 0;
}
