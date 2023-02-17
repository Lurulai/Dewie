//
// Created by saritak on 16-2-23.
//

#ifndef DEWIE_GAME_H
#define DEWIE_GAME_H

#include <vector>
#include <random>
#include <ctime>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/*
    Class that acts as the game engine.
    This is a wrapper class that will be used to initialise the game.
 */

class Game {
private /* variables */:
    sf::RenderWindow* window{};
    sf::VideoMode videoMode;
    sf::Event event{};
    sf::Vector2i mousePositionOnWindow;

    // game logic
    unsigned int slimeScore{};
    float slimeSpawnTimer{};
    float slimeMaximumSpawnTimerValue{};
    unsigned int maximumSlimesAllowed{};

    /* ========================================================================================== ~
    *   TODO: split between main elements and the game itself, i.e., slimes are part of the game,
    *   but not the main elements; however, the render window is a main element.
    ~ ========================================================================================== */

    // game objects
    sf::RectangleShape slime;
    std::vector<sf::RectangleShape> slimes;

public /* variables */:

    // ________________________________________________

private /* functions */:
    void InitialiseVariables();
    void InitialiseWindow();
    void InitialiseSlimes();

public /* functions */:
    Game();
    ~Game();

    bool IsRunning() const;

    void SpawnSlime();

    void Update();
    void PollEvents();
    void UpdateCurrentSlimes();
    void UpdateMousePosition();

    void Render();
    void RenderSlimes();
};


#endif //DEWIE_GAME_H
