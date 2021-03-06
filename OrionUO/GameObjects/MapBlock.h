// MIT License
// Copyright (C) August 2016 Hotride

#pragma once

class CMapBlock : public CBaseQueueItem
{
public:
    uint32_t Index = 0;
    uint32_t LastAccessTime = 0;
    short X = 0;
    short Y = 0;

private:
    //Получить Z координату ландшафта
    char GetLandZ(int x, int y, int map);

    //Проверить объект ландшафта на "растягиваемость" при рендере
    bool TestStretched(int x, int y, char z, int map, bool recurse);

public:
    CMapBlock(int index);
    virtual ~CMapBlock();

    //Данные блока
    CMapObject *Block[8][8];

    //Добавить объект
    CMapObject *AddObject(CMapObject *obj, int x, int y);

    //Получить указатель на объект ландшафта
    CLandObject *GetLand(int x, int y);

    //Добавить объект в очередь рендера
    void AddRender(CRenderWorldObject *item, int x, int y);

    //Получить начало очереди рендера
    CRenderWorldObject *GetRender(int x, int y);

    //Получить цвет точки для радара
    uint16_t GetRadarColor(int x, int y);

    //Сконструировать вершины текстур ландшафта
    void CreateLandTextureRect();

    bool HasNoExternalData();
};
