#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title) {
        this->width = width;
        this->height = height;
        this->title = title;

        if (!initializeGLFW()) {
            // La GLFW non è stata inizializzata correttamente
            // Puoi gestire l'errore qui
            return;
        }

        if (!createWindow()) {
            // La finestra OpenGL non è stata creata correttamente
            // Puoi gestire l'errore qui
            return;
        }

        if (!initializeGLEW()) {
            // GLEW non è stato inizializzato correttamente
            // Puoi gestire l'errore qui
            return;
        }
    }

    ~Window() {
        glfwTerminate();
    }

    bool isOpen() {
        return !glfwWindowShouldClose(window);
    }

    void swapBuffers() {
        glfwSwapBuffers(window);
    }

private:
    int width;
    int height;
    const char* title;
    GLFWwindow* window;

    bool initializeGLFW() {
        if (!glfwInit()) {
            // Inizializzazione di GLFW fallita
            return false;
        }
        return true;
    }

    bool createWindow() {
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!window) {
            // Creazione della finestra OpenGL fallita
            return false;
        }
        glfwMakeContextCurrent(window);
        return true;
    }

    bool initializeGLEW() {
        GLenum glewError = glewInit();
        if (glewError != GLEW_OK) {
            // Inizializzazione di GLEW fallita
            return false;
        }
        return true;
    }
};

int main() {
    Window window(800, 600, "OpenGL Window");

    while (window.isOpen()) {
        // Logic and rendering here
        window.swapBuffers();
        glfwPollEvents();
    }

    return 0;
}
