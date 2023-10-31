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
    
    Window w;
public:
    GameEngine(/* args */){}
    virtual ~GameEngine(){}

    /**
     * \brief starting function
     *
     */
    void start() {
        init();
        loop();
    }
};

void GameEngine::init(){
    w.create(SCREEN_WIDTH,SCREEN_HEIGHT,GAME_NAME);
}

void GameEngine::loop(){
    while (w.isOpen())
    {
        // Logic and rendering here
    }
}