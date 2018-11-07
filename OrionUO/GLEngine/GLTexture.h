// MIT License
// Copyright (C) August 2016 Hotride

#pragma once

typedef vector<uint8_t> HIT_MAP_TYPE;

class CGLTexture
{
public:
    //!Габариты текстуры
    short Width = 0;
    short Height = 0;

    short ImageOffsetX = 0;
    short ImageOffsetY = 0;

    short ImageWidth = 0;
    short ImageHeight = 0;

    //!Буфер вершин
    GLuint VertexBuffer = 0;

    //!Буфер вершин для зеркального отображения анимации
    GLuint MirroredVertexBuffer = 0;

    CGLTexture();
    virtual ~CGLTexture();

    GLuint Texture = 0;

    HIT_MAP_TYPE m_HitMap;

    virtual void Draw(int x, int y, bool checktrans = false);
    virtual void Draw(int x, int y, int width, int height, bool checktrans = false);

    virtual void DrawRotated(int x, int y, float angle);

    virtual void DrawTransparent(int x, int y, bool stencil = true);

    virtual bool Select(int x, int y, bool pixelCheck = true);

    virtual void Clear();
};
