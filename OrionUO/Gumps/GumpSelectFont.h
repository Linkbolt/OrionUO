// MIT License
// Copyright (C) August 2016 Hotride

#pragma once

class CGumpSelectFont : public CGump
{
private:
    static const int ID_GSF_FONTS = 1;

    SELECT_FONT_GUMP_STATE m_State{ SFGS_OPT_POPUP };

public:
    CGumpSelectFont(uint32_t serial, short x, short y, SELECT_FONT_GUMP_STATE state);
    virtual ~CGumpSelectFont();

    void UpdateContent();

    GUMP_RADIO_EVENT_H;
};
