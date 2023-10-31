#ifndef WINDOW
#define WINDOW
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
private:
    int width;
    int height;
    const char *title;
    GLFWwindow *window;

    bool init(){
        // Inizializzazione di GLFW
        if (!glfwInit())
        {
            // Inizializzazione di GLFW fallita
            std::cerr << "Error: Failed to initialize GLFW" << std::endl;
            return false;
        }

        // Inizializzazione di GLEW
        GLenum glewError = glewInit();
        if (glewError != GLEW_OK)
        {
            // Inizializzazione di GLEW fallita
            std::cerr << "Error: Failed to initialize GLEW" << std::endl;
            return false;
        }
        return true;
    }
public:
    Window(){
        if (!init()){
            // La GLFW o la GLEW non sono state inizializzate correttamente
            std::cerr << "Error: Unable to initialize OpenGL Libs" << std::endl;
            return;
        }
    }

    ~Window() {
        glfwTerminate();
    }

    bool create(int w, int h, const char *t) {
        width = w;
        height = h;
        title = t;

        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if(!window) {
            // Creazione della finestra OpenGL fallita
            std::cerr << "Error: Failed to create the OpenGL window" << std::endl;
            return false;
        }

        glfwMakeContextCurrent(window); // Imposta il contesto OpenGL

        return true;
    }

    bool isOpen() {
        // Chiamiamo swapBuffers() per aggiornare la visualizzazione
        glfwSwapBuffers(window);
        // Chiamiamo glfwPollEvents() per gestire gli eventi
        glfwPollEvents();

        return !glfwWindowShouldClose(window);
    }

    // Setter per il titolo
    void setTitle(const char *newTitle) {
        title = newTitle;
        glfwSetWindowTitle(window, title);
    }

    // Getter per il titolo
    const char *getTitle() const {
        return title;
    }

    void setSize(int newWidth, int newHeight){
        width = newWidth;
        height = newHeight;
        glfwSetWindowSize(window, newWidth, newHeight);
    }

    std::vector<int> getSize() const {
        int windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);

        return {windowWidth,windowHeight};
    }
};
#endif