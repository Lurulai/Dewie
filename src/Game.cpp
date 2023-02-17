//
// Created by saritak on 16-2-23.
//

#include "../inc/Game.h"

// ________________________________________________

Game::Game() : videoMode(800, 600) {
    this->InitialiseVariables();
    this->InitialiseWindow();
    this->InitialiseSlimes();
}

Game::~Game() {
    delete this->window;
}

// ________________________________________________

void Game::InitialiseWindow() {
    this->window = new sf::RenderWindow(this->videoMode,
                                        "Dewie",
                                        sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(30);
}

void Game::InitialiseVariables() {
    this->window = nullptr;
    this->slimeScore = 0;
    this->slimeSpawnTimer = 0.f;
    this->slimeMaximumSpawnTimerValue = 100.f;
    this->maximumSlimesAllowed = 5;
}

void Game::InitialiseSlimes() {

    /* ========================================================================================== ~
    * TODO: make sure that game characters are their own class, and not just functions.
    * for instance, we would have a slime class which creates slime objects.
    ~ ========================================================================================== */

    this->slime.setSize(sf::Vector2f(100.f, 100.f));
    this->slime.setPosition(sf::Vector2f(100.f, 100.f));
    this->slime.setScale(0.5f, 0.5f);
    this->slime.setFillColor(sf::Color::Red);
}

// ________________________________________________

bool Game::IsRunning() const {
    if (this->window != nullptr) {
        return this->window->isOpen();
    }
}

// ________________________________________________

void Game::SpawnSlime() {
    this->slime.setPosition(static_cast<float>(std::rand() % static_cast<int>(this->window->getSize().x - this->slime.getSize().x)),
                            static_cast<float>(std::rand() % static_cast<int>(this->window->getSize().y - this->slime.getSize().y)));
    this->slime.setFillColor(sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255, 255));
    this->slimes.emplace_back(this->slime);
}

void Game::Update() {
    this->PollEvents();
    this->UpdateMousePosition();
    this->UpdateCurrentSlimes();
}

void Game::PollEvents() {
    // event polling
    while(this->window->pollEvent(this->event)) {
        switch(this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::UpdateCurrentSlimes() {
    // update slimes whenever a new slime is spawned
    if (this->slimes.size() < maximumSlimesAllowed) {
        if (this->slimeSpawnTimer >= this->slimeMaximumSpawnTimerValue) {
            this->SpawnSlime();
            this->slimes.emplace_back(this->slime);
            this->slimeSpawnTimer = 0.f;
        } else {
            this->slimeSpawnTimer += 1.f;
        }
    }

    for (auto &slimey : this->slimes) {
        slimey.move(0.1f, 0.1f);
    }
}

void Game::UpdateMousePosition() {
    this->mousePositionOnWindow = sf::Mouse::getPosition(*this->window);
}

void Game::Render() {
    this->window->clear(sf::Color::Black);
    // render items
    this->RenderSlimes();

    this->window->display();
}

void Game::RenderSlimes() {
    // render slimes
}
