#ifndef Mouse_CLASS_H
#define Mouse_CLASS_H
#include "Vector3.h"
#include <iostream>
#include <stdio.h>

class Mouse
{
    static int Button;
    static int State;
    static Vector3 Position;
    static Vector3 PositionOld;
    static char DragStatusX;
    static char DragStatusY;
public:
    static void Update();
    static void CallBack(int button, int state, int x, int y);
    static void CallBackDrag(int x, int y);
    static int isDragHorizontal(char condition);
    static int isDragVertical(char condition);
private:
    Mouse();
    ~Mouse();

    static void drag();
    static void updateDragStatus();
};

#define MOUSE_DRAG_LEFT     -1
#define MOUSE_DRAG_RIGHT    1
#define MOUSE_DRAG_UP       -1
#define MOUSE_DRAG_DOWN     1
#define MOUSE_DRAG_NONE     0

#endif