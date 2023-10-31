#include "internal/Window.cpp"
#include "internal/Thread.cpp"
#include "setting.h"

class GameEngine {
private:
    //function principali per gioco
    void input();
    void draw();
    void init();
    void update();
    void loop();
    
    Window window;
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
    window.create(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
}

void GameEngine::loop(){
    while(window.isOpen()) {
        // Logic and rendering here
    }
}