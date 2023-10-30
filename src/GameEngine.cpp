#include "internal/Window.cpp"

#include "setting.h"

class GameEngine {
private:
    //function principali per gioco
    void input();
    void draw();
    void init();
    void update();
    void loop();
    
    Window w(1280,720,"Ciao mondo");
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
    w.create();
}