#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//021 結構(structure)練習，圖形計算
//2019/05/06 AM. 00:36 IBOTIAndy
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
    shape_s shape[100]; //圖形陣列
    int n;              //圖形數量
    int totalPerimeter; //總周長
}shapeArray_s;          //圖形陣列

//----------input-----------------
void setCircle(circle_s *circle, int radius){   //輸入圓形的資料
    circle->radius = radius;    //半徑
}

void setRectangle(rectangle_s *rectangle, int length, int width){   //輸入矩形的資料
    rectangle->length = length; //長
    rectangle->width = width;   //寬
}

void setSquare(square_s *square, int length){   //輸入正方形的資料
    square->length = length;    //邊長
}

void setTriangle(triangle_s *triangle, int bottom, int height, int hypotenuse){ //輸入三角形的資料
    triangle->bottom = bottom;          //底
    triangle->height = height;          //高
    triangle->hypotenuse = hypotenuse;  //斜邊
}

int changeType(char *cutString){    //將字串改為整數
    int i=0, ans=0;
    while(cutString[i] != '\0'){                    //直到字串處理完
        ans = (ans * 10) + (cutString[i] - '0');    //將字串轉為數字 先將自己*10 再加上個位數
        i = i + 1;
    }
    return ans; //回傳結果
}

void setShape(shape_s *shape, char name, char *string){ //設定圖形
    char *cutString;                    //切割字串用
    int i=0, number[3]={0};
    shape->name = name;                 //設定名稱
    cutString = strtok(string, " ");    //切割輸入的數字
    while(cutString != NULL){               //直到切割完
        number[i] = changeType(cutString);  //將字串轉為整數
        cutString = strtok(NULL, " ");      //繼續切割字串
        i = i + 1;
    }
    if(name == 'C'){        //圓形
        setCircle(&(shape->shape.C), number[0]);
    }
    else if(name == 'R'){   //矩形
        setRectangle(&(shape->shape.R), number[0], number[1]);
    }
    else if(name == 'S'){   //正方形
        setSquare(&(shape->shape.S), number[0]);
    }
    else if(name == 'T'){   //三角形
        setTriangle(&(shape->shape.T), number[0], number[1], number[2]);
    }
}

void input(shapeArray_s *shapes){   //輸入
//    enum stringCut : int {shapeName=0, number1=2, number2=4, number3=6};
    char inputString[10]="";
    char selectShap=' ';
    int i=0, n=0;
    scanf("%d%c", &n, &selectShap); //輸入圖形的數量
    shapes->n = n;                  //將圖形數量記錄起來
    for(i=0; i < n; i++){                                                   //直到輸入完 (圖形數量)
        gets(inputString);                                                  //取整行
        setShape(&(shapes->shape[i]), inputString[0], (inputString + 2));   //設定圖形
//        printf("%d", shapes->shape[i].shape.C.radius);
    }
}

void inputView(shapeArray_s shapes){    //檢查輸入有沒有錯
    int i=0;
    for(i=0; i < shapes.n; i++){                                //看全部的圖形
        printf("%c:", shapes.shape[i].name);                    //輸出圖形種類
        if(shapes.shape[i].name == 'C'){                        //圓形
            printf("%d ", shapes.shape[i].shape.C.radius);      //半徑
        }
        else if(shapes.shape[i].name == 'R'){                   //矩形
            printf("%d ", shapes.shape[i].shape.R.length);      //長
            printf("%d ", shapes.shape[i].shape.R.width);       //寬
        }
        else if(shapes.shape[i].name == 'S'){                   //正方形
            printf("%d ", shapes.shape[i].shape.S.length);      //邊常
        }
        else if(shapes.shape[i].name == 'T'){                   //三角形
            printf("%d ", shapes.shape[i].shape.T.bottom);      //底
            printf("%d ", shapes.shape[i].shape.T.height);      //高
            printf("%d ", shapes.shape[i].shape.T.hypotenuse);  //斜邊
        }
        printf("\n");
    }
}
//---------/input-----------------

//----------math------------------
int mathCircle(circle_s *circle){   //計算圓形的周長
    int PI=0, ans=0;
    PI = 4;             //PI 設為 4
    ans = circle->radius * 2 * PI; //直徑 * PI
    return ans;
}

int mathRectangle(rectangle_s *rectangle){   //計算矩形的周長
    int ans=0;
    ans = (rectangle->length * 2) + (rectangle->width * 2); //長 + 長 + 寬 + 寬
    return ans;
}

int mathSquare(square_s *square){   //計算正方形的周長
    int ans=0;
    ans = square->length * 4;    //邊長 * 4
    return ans;
}

int mathTriangle(triangle_s *triangle){   //計算三角形的周長
    int ans=0;
    ans = triangle->bottom + triangle->height + triangle->hypotenuse;    //三邊的和
    return ans;
}

int mathPerimeter(shape_s *shape){ //計算周長
    if(shape->name == 'C'){         //圓形
        return mathCircle(&(shape->shape.C));
    }
    else if(shape->name == 'R'){    //矩形
        return mathRectangle(&(shape->shape.R));
    }
    else if(shape->name == 'S'){    //正方形
        return mathSquare(&(shape->shape.S));
    }
    else if(shape->name == 'T'){    //三角形
        return mathTriangle(&(shape->shape.T));
    }
    return 0;
}

void math(shapeArray_s *shapes){    //計算
    int i=0, total=0;
    for(i=0; i < shapes->n; i++){                           //直到輸入完 (圖形數量)
        total = total + mathPerimeter(&(shapes->shape[i])); //計算圖形的周長
    }
    shapes->totalPerimeter = total; //將總周長記錄下來
}
//---------/math------------------

void output(shapeArray_s shapes){}

int main(){
    shapeArray_s shapes;    //一個放圖形的陣列
    input(&shapes);         //輸入
//    inputView(shapes);      //輸入測試
    math(&shapes);          //計算
    output(shapes);         //輸出
//    printf("Hello world!\n");
    return 0;
}
