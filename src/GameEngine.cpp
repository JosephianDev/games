#include "internal/Window.cpp"
//#include "internal/Thread.cpp"
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

        
    }
}