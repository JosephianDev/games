#include "internal/Window.cpp"
#include "internal/Thread.cpp"
#include "setting.h"

class GameEngine {
private:
    //function principali per gioco

    /**
     * \brief Gestisce l'input del gioco.
     */
    void input();

    /**
     * \brief Disegna gli elementi del gioco.
     */
    void draw();

    /**
     * \brief Inizializza il gioco e la finestra.
     */
    void init();

    /**
     * \brief Aggiorna lo stato del gioco.
     */
    void update();

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
    float rotationAngle = 0.0f;

    while(window.isOpen()) {
        glEnable(GL_DEPTH_TEST);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Calcola la trasformazione di rotazione
        rotationAngle += 0.5f;
        if(rotationAngle > 360.0f) {
            rotationAngle -= 360.0f;
        }
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

        // Disegna la piramide
        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // Ripeti per le altre facce...

        glEnd();
    }
}