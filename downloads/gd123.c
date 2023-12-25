#include <stdio.h>
#include <gd.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400

void drawEUFlag(const char* filename) {
    gdImagePtr img;
    FILE *pngout;
    int blue, yellow, white, bg;

    // 建立新的圖片
    img = gdImageCreate(WIDTH, HEIGHT);

    // 定義顏色
    bg = gdImageColorAllocate(img, 255, 255, 255);  // 白色背景
    blue = gdImageColorAllocate(img, 0, 0, 255);     // 藍色
    yellow = gdImageColorAllocate(img, 255, 255, 0);  // 黃色
    white = gdImageColorAllocate(img, 255, 255, 255); // 白色

    // 填充背景色
    gdImageFilledRectangle(img, 0, 0, WIDTH, HEIGHT, bg);

    // 繪製藍色方塊
    gdImageFilledRectangle(img, 0, 0, WIDTH / 3, HEIGHT / 2, blue);

    // 設定星星的半徑和間距
    int starRadius = 15;
    int starSpacing = 40;

    // 計算星星的起始位置
    int startX = WIDTH / 3 + starSpacing / 2;
    int startY = starSpacing / 2;

    // 繪製星星
    for (int i = 0; i < 12; i++) {
        int x = startX + (i % 4) * starSpacing;
        int y = startY + (i / 4) * starSpacing;
        gdImageFilledEllipse(img, x, y, starRadius, starRadius, yellow);
    }

    // 將圖片輸出到文件
    pngout = fopen(filename, "wb");
    gdImagePng(img, pngout);
    fclose(pngout);

    // 釋放記憶體
    gdImageDestroy(img);
}

int main() {
    drawEUFlag("eu_flag.png");
    return 0;
}
