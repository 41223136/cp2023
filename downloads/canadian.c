#include <stdio.h>
#include <gd.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400
#define RED 255, 0, 0
#define WHITE 255, 255, 255

void drawCanadianFlag() {
    gdImagePtr img;
    FILE *pngout;

    // 創建一個寬度為600，高度為400的圖像
    img = gdImageCreate(WIDTH, HEIGHT);

    // 設置背景色為白色
    int white = gdImageColorAllocate(img, WHITE);

    // 畫一個大紅色的矩形，代表加拿大國旗的底色
    int red = gdImageColorAllocate(img, RED);
    gdImageFilledRectangle(img, 0, 0, WIDTH, HEIGHT, red);

    // 畫一個垂直的白色矩形，代表加拿大國旗的垂直紅色圖案
    int x = WIDTH / 3;
    int y = 0;
    int height = HEIGHT;

    gdImageFilledRectangle(img, x, y, x + WIDTH / 3, y + height, white);

    // 將圖片保存到文件中
    pngout = fopen("./../images/canadian_flag.png", "wb");
    gdImagePng(img, pngout);

    // 釋放內存
    gdImageDestroy(img);
    fclose(pngout);
}

int main() {
    drawCanadianFlag();

    return 0;
}
