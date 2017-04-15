#include "Mouse.h"

int     Mouse::Button = 0;
int     Mouse::State = 0;
Vector3 Mouse::Position = Vector3();
Vector3 Mouse::PositionOld = Vector3();
char    Mouse::DragStatusX=0;
char    Mouse::DragStatusY=0;

Mouse::Mouse() {
}

Mouse::~Mouse() {
}

void Mouse::Update() {
    updateDragStatus();
}

void Mouse::CallBack(int button, int state, int x, int y) {
    Button=button;
    State=state;
}
void Mouse::CallBackDrag(int x, int y) {
    Position.Set(x,y,0);
}

int Mouse::isDragVertical(char condition) {
    if(DragStatusY == condition){
        return 1;
    }
    return 0;
}
int Mouse::isDragHorizontal(char condition) {
    if(DragStatusX == condition){
        return 1;
    }
    return 0;
}


void Mouse::drag() {
    Vector3 vec = PositionOld - Position;
    if(vec.GetX()>0) {
        DragStatusX = MOUSE_DRAG_LEFT;
    } else if(vec.GetX()<0) {
        DragStatusX = MOUSE_DRAG_RIGHT;
    } else {
        DragStatusX =MOUSE_DRAG_NONE;
    }

    if(vec.GetY()>0) {
        DragStatusY = MOUSE_DRAG_UP;
    } else if(vec.GetY()<0) {
        DragStatusY = MOUSE_DRAG_DOWN;
    } else {
        DragStatusY =MOUSE_DRAG_NONE;
    }
}


void Mouse::updateDragStatus() {
    drag();
    PositionOld = Position;
}