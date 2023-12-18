#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_japan_flag(gdImagePtr img);
void draw_red_sun(gdImagePtr img, int x, int y, int size, int color);

int main() {
    // width 3: height 2
    int width = 1200;
    // 國旗長寬比為 3:2
    int originalHeight = (int)(originalWidth * 2.0 / 3.0);
    gdImagePtr img = gdImageCreateTrueColor(originalWidth, originalHeight);
    gdImageAlphaBlending(img, 0);

    draw_japan_flag(img);

    // 新的寬度和高度以適應 "images" 資料夾
    int newWidth = 600;
    int newHeight = (int)(newWidth * 2.0 / 3.0);

    // 創立新圖片並進行縮放
    gdImagePtr resizedImage = gdImageCreateTrueColor(newWidth, newHeight);
    gdImageAlphaBlending(resizedImage, 0);
    gdImageCopyResampled(resizedImage, img, 0, 0, 0, 0, newWidth, newHeight, originalWidth, originalHeight);

  FILE *outputFile = fopen("./../images/japan_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePng(resizedImage, outputFile);
    fclose(outputFile);
    gdImageDestroy(img);
    gdImageDestroy(resizedImage);

    return 0;
}

void draw_japan_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);

    // 建立一個白色背景
    int white = gdImageColorAllocate(img, 255, 255, 255);
    gdImageFilledRectangle(img, 0, 0, width - 1, height - 1, white);

    // 繪製太陽
    int red = gdImageColorAllocate(img, 255, 0, 0);
    int center_x = width / 2;
    int center_y = height / 2;
    int radius = (int)((width * 2) / 3);
    draw_red_sun(img, center_x, center_y, radius, red);
}

void draw_red_sun(gdImagePtr img, int x, int y, int size, int color) {
  // 將圖片尺寸減半
  size = size / 2;
    gdImageArc(img, x, y, size, size, 0, 360, color);
    gdImageFillToBorder(img, x, y, color, color);
}
