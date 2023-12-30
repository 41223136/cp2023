#include <stdio.h>
#include <gd.h>
#include <stdlib.h>

void drawBoldLine(gdImagePtr im, int x1, int y1, int x2, int y2, int color, int thickness) {
    for (int i = 0; i < thickness; ++i) {
        gdImageLine(im, x1, y1 + i, x2, y2 + i, color);
    }
}

int main() {
    // 设置国旗的尺寸
    int width = 300;
    int height = 200;

    // 创建图像
    gdImagePtr im;
    im = gdImageCreate(width, height);

    // 设置颜色
    int white = gdImageColorAllocate(im, 255, 255, 255);
    int red = gdImageColorAllocate(im, 255, 0, 0);

    // 填充红色背景
    gdImageFilledRectangle(im, 0, 0, width - 1, height - 1, red);

    // 绘制白色十字
    int crossWidth = 30;
    int crossHeight = 5;
    int crossThickness = 3;  // 设置十字的粗细

    int crossX = (width - crossWidth) / 2;
    int crossY = (height - crossHeight) / 2;

    // 垂直部分
    drawBoldLine(im, crossX, crossY, crossX + crossWidth, crossY + crossHeight, white, crossThickness);

    // 水平部分
    drawBoldLine(im, crossX, crossY, crossX + crossWidth, crossY + crossHeight, white, crossThickness);

    // 保存图像到文件
    FILE *outFile;
    outFile = fopen("./../images/swiss_flag.png", "wb");
    if (outFile == NULL) {
        fprintf(stderr, "Cannot open output file\n");
        return 1;
    }

    gdImagePng(im, outFile);
    fclose(outFile);

    // 释放内存
    gdImageDestroy(im);

    return 0;
}
