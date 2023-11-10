#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
//#define SINGLE_COLOR_MODE

//int width = 2268, height = 1104;
int width = 1500, height = 700; // so that the data wouldn't exceed the screen
//std::vector<float> rectWidth, rectHeight;
//int width = 700, height = 1500;
char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
float minSize = 3, maxSize = 100;

float randomFloat()
{
    return (float)(rand()) / (float)(RAND_MAX);
}

int randomInt(int a, int b)
{
    if (a > b)
        return randomInt(b, a);
    if (a == b)
        return a;
    return a + (rand() % (b - a));
}

float randomFloat(int a, int b)
{
    if (a > b)
        return randomFloat(b, a);
    if (a == b)
        return a;

    return (float)randomInt(a, b) + randomFloat();
}

void quadRand(int n)
{
    std::vector<float> quadX1, quadY1/*, quadX2, quadY2*/;
    puts("//random quadratics");
    printf("constexpr float quadX1[] = {");
    for (int i = 0; i < n; ++i)
    {
        float x1 = randomFloat(0, width);
        printf("%.3f, ", x1);
        quadX1.push_back(x1);
    }
    puts("};");

    printf("constexpr float quadY1[] = {");
    for (int i = 0; i < n; ++i)
    {
        float y1 = randomFloat(0, height);
        printf("%.3f, ", y1);
        quadY1.push_back(y1);
    }
    puts("};");

    printf("constexpr float quadX2[] = {");
    for (int i = 0; i < n; ++i)
    {
        float dx = randomFloat(-10, 10);
        float x2 = dx + quadX1[i];
        printf("%.3f, ", x2);
        //quadX2.push_back(x2);
    }
    puts("};");

    printf("constexpr float quadY2[] = {");
    for (int i = 0; i < n; ++i)
    {
        float dy = randomFloat(-10, 10);
        float y2 = dy + quadY1[i];
        printf("%.3f, ", y2);
        //quadY2.push_back(y2);
    }
    puts("};");
    printf("constexpr float quadX3[] = {");
    for (int i = 0; i < n; ++i)
    {
        float dx = randomFloat(-10, 10);
        float x3 = dx + quadX1[i];
        printf("%.3f, ", x3);
    }
    puts("};");

    printf("constexpr float quadY3[] = {");
    for (int i = 0; i < n; ++i)
    {
        float dy = randomFloat(-10, 10);
        float y3 = dy + quadY1[i];
        printf("%.3f, ", y3);
    }
    puts("};");
    printf("constexpr int quadRandLength = %d;\n", n);
}

void rectRand(int n)
{
    puts("//random rectangles");
    printf("constexpr float rectX[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(0, width));
    }
    puts("};");

    printf("constexpr float rectY[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(0, height));
    }
    puts("};");

    printf("constexpr float rectW[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(3, 10));
    }
    puts("};");

    printf("constexpr float rectH[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(3, 10));
    }
    puts("};");
    printf("constexpr int rectRandLength = %d;\n", n);
}

void rcRectRand(int n)
{
    puts("//random round cornered rectangles");
    printf("constexpr float rcRectX[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(0, width));
    }
    puts("};");

    printf("constexpr float rcRectY[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(0, height));
    }
    puts("};");

    std::vector<float> rectWidth, rectHeight;

    printf("constexpr float rcRectW[] = {");
    for (int i = 0; i < n; ++i)
    {
        float width = randomFloat(3, 10);
        printf("%.3f, ", width);
        rectWidth.push_back(width);
    }
    puts("};");

    printf("constexpr float rcRectH[] = {");
    for (int i = 0; i < n; ++i)
    {
        float height = randomFloat(3, 10);
        printf("%.3f, ", height);
        rectHeight.push_back(height);
    }
    puts("};");

    printf("constexpr float rcRectRx[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(0, rectWidth[i] / 2));
    }
    puts("};");

    printf("constexpr float rcRectRy[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(0, rectHeight[i] / 2));
    }
    puts("};");
    printf("constexpr int rcRectRandLength = %d;\n", n);
}

void ovalRand(int n)
{
    puts("//random ovals");
    printf("constexpr float ovalX[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", maxSize + randomFloat(0, width));
    }
    puts("};");

    printf("constexpr float ovalY[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", maxSize + randomFloat(0, height));
    }
    puts("};");

    printf("constexpr float ovalW[] = {");
    for (int i = 0; i < n; ++i)
    {
        //printf("%.3f, ", randomFloat(10, 30));
        printf("%.3f, ", randomFloat(minSize, maxSize));
    }
    puts("};");

    printf("constexpr float ovalH[] = {");
    for (int i = 0; i < n; ++i)
    {
        //printf("%.3f, ", randomFloat(10, 30));
        printf("%.3f, ", randomFloat(minSize, maxSize));
    }
    puts("};");
    printf("constexpr int ovalRandLength = %d;\n", n);
}

void charRand(int n)
{
    puts("//random characters");
    printf("constexpr char charactersRand[] = \"");
    for (int i = 0; i < n; ++i)
    {
        int index = randomInt(0, sizeof(alphabet) - 1);
        printf("%c", alphabet[index]);
        if (((i % 5000) == 0) && (i != 0))
        {
            puts("\"");
            printf("\"");
        }
    }
    puts("\";");
    printf("constexpr float charPosX[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(0, width));
    }
    puts("};");

    printf("constexpr float charPosY[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(0, height));
    }
    puts("};");
    printf("constexpr float charSize[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3f, ", randomFloat(0, 20));
    }
    puts("};");
    printf("constexpr int charRandLength = %d;\n", n);
}

void colorRand(int n)
{
#ifdef SINGLE_COLOR_MODE
    int rP = 255, gP = 0, bP = 0; // color parameters
    puts("//random paint colors");
    printf("constexpr int paintR[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%d, ", rP);
    }
    puts("};");

    printf("constexpr int paintG[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%d, ", gP);
    }
    puts("};");

    printf("constexpr int paintB[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%d, ", bP);
    }
    puts("};");

    printf("constexpr int colorRandLength = %d;\n", n);
#else
    puts("//random paint colors");
    printf("constexpr int paintR[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%d, ", randomInt(0, 256));
    }
    puts("};");

    printf("constexpr int paintG[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%d, ", randomInt(0, 256));
    }
    puts("};");

    printf("constexpr int paintB[] = {");
    for (int i = 0; i < n; ++i)
    {
        printf("%d, ", randomInt(0, 256));
    }
    puts("};");

    printf("constexpr int colorRandLength = %d;\n", n);
#endif // SINGLE_COLOR_MODE
}


int main()
{
	srand(time(0));
    FILE* stream;
    freopen_s(&stream, "randomData.h", "w", stdout);
    int n = 10;
    puts("#pragma once");
    quadRand(n);
    rectRand(n);
    rcRectRand(n);
    ovalRand(n);
    charRand(n);
    colorRand(n);
    return 0;
}

