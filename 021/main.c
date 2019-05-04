#include <stdio.h>
#include <stdlib.h>
//021 結構(structure)練習，圖形計算
//2019/05/04 PM. 07:28 IBOTIAndy
//----------struct_shape----------
typedef struct{
    int radius;     //半徑
}circle_s;          //圓

typedef struct{
    int length;     //長
    int width;      //寬
}rectangle_s;       //矩形

typedef struct{
    int length;     //邊長
}square_s;          //正方形

typedef struct{
    int bottom;     //底
    int height;     //高
    int hypotenuse; //斜邊
}triangle_s;        //三角形

typedef union{      //共用空間
    circle_s C;     //圓形
    rectangle_s R;  //矩形
    square_s S;     //正方形
    triangle_s T;   //三角形
}shape_u;           //圖形

typedef struct{
    char name;      //圖形種類
    shape_u shape;  //圖形
    int perimeter;  //周長
}shape_s;
//---------/struct_shape----------

typedef struct{
    shape_u shape[100]; //圖形陣列
    int n;              //圖形數量
    int totalPerimeter; //總周長
}shapeArray_s;          //圖形陣列

//----------input-----------------
void input(shapeArray_s *shapes){}
//---------/input-----------------

//----------math------------------
void math(shapeArray_s *shapes){}
//---------/math------------------

void output(shapeArray_s shapes){}

int main(){
    shapeArray_s shapes;    //一個放圖形的陣列
    input(&shapes);         //輸入
    math(&shapes);          //計算
    output(shapes);         //輸出
//    printf("Hello world!\n");
    return 0;
}
