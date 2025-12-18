#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

struct LayerSelection {
    char axis;
    int layer;
    LayerSelection() : axis('x'), layer(0) {}
};

class InputHandler {
public:
    static void handleKeyboard(unsigned char key, int x, int y);
    static void handleMouse(int button, int state, int x, int y);
    static void printControls();
    
    static LayerSelection& getSelection() { return s_selection; }
    
private:
    static LayerSelection s_selection;
};

#endif // INPUT_HANDLER_H
