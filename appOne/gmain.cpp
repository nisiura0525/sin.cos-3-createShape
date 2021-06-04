#include"libOne.h"
int createTriangle() {
    struct SHAPE_VERTEX vertices[3];
    //シェープ形、バーテックス頂点、バーテックスの複数形はバーティシーズ
    //3の頂点を決める
    vertices[0].x = 0;
    vertices[0].y = -1;
    vertices[1].x = -1;
    vertices[1].y = 1;
    vertices[2].x = 1;
    vertices[2].y = 1;
    return createShape(vertices, 3);
}
int createPolygon () {
    const int num = 5;
    struct SHAPE_VERTEX vertices[num];
    angleMode(DEGREES);
    float deg = 360 / num;
    for (int i = 0;i < num;i++) {
        vertices[i].x = sin(deg*i);
        vertices[i].y = -cos(deg*i);
    }
    return createShape(vertices, num); //shape関数に値を返す関数
}
int createStar() {
    const int num = 10;
    struct SHAPE_VERTEX vertices[num];
    angleMode(DEGREES);
    float deg = 360 / num;
    for (int i = 0;i < num;i++) {
        float radius = 0.5f + 0.5f * (i % 2);//0.5下げたいから余りを使う
        vertices[i].x = sin(deg * i)*radius;
        vertices[i].y = cos(deg * i)*radius;
    }
    return createShape(vertices, num); //shape関数に値を返す関数
}
int createHeart() {
    const int num = 60;
    struct SHAPE_VERTEX vertices[num];
    angleMode(DEGREES);
    float deg = 360.0f / num;
    for (int i = 0;i < num;i++) {
        float t = i * deg;
        vertices[i].x = pow(sin(t), 3);
        vertices[i].y = -(
            13 * cos(t) -
            5 * cos(2 * t) -
            2 * cos(3 * t) -
            1 * cos(4 * t)) / 16;
    }
    return createShape(vertices, num); //shape関数に値を返す関数
}
void gmain() {
    window(1000, 1000);
    int idx = createHeart(); 
    float deg = 0;
    angleMode(DEGREES);
    while (notQuit) {
        clear(200);
        if (isTrigger(KEY_SPACE)) {
            idx = createHeart();
        }
        if (isTrigger(KEY_A)) {
            idx = createStar();
        }
        if (isTrigger(KEY_D)) {
            idx = createPolygon();
        }
        deg += 1;
        fill(255, 220, 227);
        strokeWeight(4);
        shape(idx, 500, 500, deg, 400);

    }
}
/*
#include"libOne.h"
int createTriangle() {
    struct SHAPE_VERTEX vertices[3];
    vertices[0].x = 0;
    vertices[0].y = -1;
    vertices[1].x = 0.5;
    vertices[1].y = 1;
    vertices[2].x = -0.5;
    vertices[2].y = 1;
    return createShape(vertices, 3);
}
void gmain() {
    window(1000, 1000);
    int idx = createTriangle();
    float px = 500, py = 500, deg = 0, scale = 200;
    angleMode(DEGREES);
    while (notQuit) {
        //deg += 1;
        clear(200);
        strokeWeight(5);
        fill(0, 255, 255);
        shape(idx, px, py, deg, scale);
    }
}
*/
