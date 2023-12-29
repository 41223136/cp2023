#include <stdio.h>
#include <gd.h>

int main() {
    FILE *out;
    gdImagePtr im;
    int black, white, red;

    /* 創建一個寬度為300，高度為150的圖像 */
    im = gdImageCreate(300, 150);

    /* 定義顏色 */
    white = gdImageColorAllocate(im, 255, 255, 255);
    black = gdImageColorAllocate(im, 0, 0, 0);
    red = gdImageColorAllocate(im, 255, 0, 0);

    /* 填充背景色為紅色 */
    gdImageFilledRectangle(im, 0, 0, 300, 150, red);

    /* 畫出一個白色的垂直長條，代表旗桿 */
    gdImageFilledRectangle(im, 50, 0, 55, 150, white);

    /* 填充一個黑色的矩形，代表楓葉 */
    gdImageFilledRectangle(im, 100, 50, 180, 100, black);

    /* 保存圖像到文件中 */
    out = fopen("./../images/canadian_flag.png", "wb");
    gdImagePng(im, out);
    fclose(out);

    /* 釋放記憶體 */
    gdImageDestroy(im);

    return 0;
}
