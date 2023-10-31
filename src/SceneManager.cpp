class SceneManager {
private:
    std::vector<Scene *> sceneStack;

public:
    void pushScene(Scene *scene) {
        if(!sceneStack.empty()) {
            sceneStack.back()->cleanup();
        }
        sceneStack.push_back(scene);
        scene->init();
    }

    void popScene() {
        if(!sceneStack.empty()) {
            Scene *scene = sceneStack.back();
            scene->cleanup();
            sceneStack.pop_back();
        }
    }

    void updateCurrentScene() {
        if(!sceneStack.empty()) {
            sceneStack.back()->update();
        }
    }

    void renderCurrentScene() {
        if(!sceneStack.empty()) {
            sceneStack.back()->render();
        }
    }
};