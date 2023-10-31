#ifndef GAME_ENGINE
#define GAME_ENGINE
#include "SceneManager.cpp"
#include "data/MainMenuScene.cpp"
#include "internal/ThreadPool.cpp"
#include "internal/Window.cpp"
#include "setting.h"

class GameEngine {
private:
    //function principali per gioco

    /**
     * \brief Inizializza il gioco e la finestra.
     */
    void init();

    /**
     * \brief Ciclo principale del gioco.
     */
    void loop();
    
    Window window;
    SceneManager sceneManager;
    ThreadPool threadPool;
public:
    GameEngine(/* args */){}
    virtual ~GameEngine(){}

    /**
     * \brief Funzione di avvio del gioco.
     *
     * Questa funzione inizializza il gioco e avvia il ciclo principale.
     */
    void start() {
        init();
        loop();
    }
};

void GameEngine::init(){
    //creo la finestra
    window.create(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);

    //inserisco come prima scena il menu principale
    sceneManager.pushScene(new MainMenuScene());
}

void GameEngine::loop(){
    while(window.isOpen()) {
        // Gestione dell'input
        threadPool.addTask([this]() {
            sceneManager.getCurrentScene()->input();
        });

        // Aggiornamento dello stato del gioco
        threadPool.addTask([this]() {
            sceneManager.getCurrentScene()->update();
        });

        // Renderizzazione
        threadPool.addTask([this]() {
            sceneManager.getCurrentScene()->render();
        });

        // Altri compiti

        //threadPool.waitAll(); // Attendi il completamento di tutti i compiti
    }
}
#endif