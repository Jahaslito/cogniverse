//
// Created by JOAN on 02/01/2022.
//

#ifndef SPLASHSCREEN_BMPLOADER_H
#define SPLASHSCREEN_BMPLOADER_H


#include <Windows.h>

class BmpLoader
{
public:
    unsigned char* textureData;
    int iWidth, iHeight;

    BmpLoader(const char*);
    ~BmpLoader();

private:
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
};

#endif //SPLASHSCREEN_BMPLOADER_H

