#include "setting.h"

class GameEngine {
private:
    //function principali per gioco
    void input();
    void draw();
    void init();
    void update();
    void loop();
    
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