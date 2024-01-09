#include <stdio.h>
#include <gd.h>
#include <math.h>

// 定义PI值
#define PI 3.14159265358979323846

// 定义角度转弧度的宏
#define DEG_TO_RAD(angle) ((angle) * PI / 180.0)

// 绘制半圆的函数
void drawHalfCircle(gdImagePtr image, int x, int y, int radius, int color) {
    double angle = 0.0;

    for (int i = 0; i < 180; ++i) {
        int xPos = x + radius * cos(DEG_TO_RAD(i));
        int yPos = y - radius * sin(DEG_TO_RAD(i));  // 修正 y 坐标
        gdImageSetPixel(image, xPos, yPos, color);
    }
}

int main() {
    // 定义图像大小
    int width = 600;
    int height = 400;

    // 创建GD图像
    gdImagePtr image = gdImageCreateTrueColor(width, height);

    // 定义颜色
    int yellow = gdImageColorAllocate(image, 255, 223, 0);
    int blue = gdImageColorAllocate(image, 0, 56, 168);
    int red = gdImageColorAllocate(image, 206, 17, 38);
    int white = gdImageColorAllocate(image, 255, 255, 255);

    // 填充背景为土黄色
    gdImageFilledRectangle(image, 0, 0, width, height, yellow);

    // 画深蓝色横条
    gdImageFilledRectangle(image, 0, height / 3, width, height / 3 * 2, blue);

    // 画红色横条
    gdImageFilledRectangle(image, 0, height / 3 * 2, width, height, red);

    // 在深蓝色横条中间用白色绘制八颗星星（半圆形状）
    int starRadius = 20;
    int numStars = 8;
    int centerX = width / 2;
    int centerY = (height / 3 + height / 3 * 2) / 2;

    for (int i = 0; i < numStars; ++i) {
        // 计算星星的位置
        int angle = i * (360 / numStars);
        int x = centerX + starRadius * cos(DEG_TO_RAD(angle));
        int y = centerY - starRadius * sin(DEG_TO_RAD(angle));  // 修正 y 坐标

        // 绘制星星（半圆形状）
        drawHalfCircle(image, x, y, 10, white);
    }

    // 将图像保存为PNG文件
    FILE *outputFile = fopen("venezuela_flag_with_stars.png", "wb");
    gdImagePng(image, outputFile);
    fclose(outputFile);

    // 释放图像资源
    gdImageDestroy(image);

    return 0;
}
