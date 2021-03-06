﻿// MIT License
// Copyright (C) August 2016 Hotride

CIndexObject::CIndexObject()
{
}

CIndexObject::~CIndexObject()
{
    DEBUG_TRACE_FUNCTION;
    if (Texture != nullptr)
    {
        delete Texture;
        Texture = nullptr;
    }
}

CIndexObjectLand::CIndexObjectLand()
    : CIndexObject()
{
}

CIndexObjectLand::~CIndexObjectLand()
{
}

CIndexObjectStatic::CIndexObjectStatic()
    : CIndexObject()
{
}

CIndexObjectStatic::~CIndexObjectStatic()
{
}

CIndexSound::CIndexSound()
    : CIndexObject()
{
}

CIndexSound::~CIndexSound()
{
}

CIndexMulti::CIndexMulti()
    : CIndexObject()
{
}

CIndexMulti::~CIndexMulti()
{
}

CIndexLight::CIndexLight()
    : CIndexObject()
{
}

CIndexLight::~CIndexLight()
{
}

CIndexGump::CIndexGump()
    : CIndexObject()
{
}

CIndexGump::~CIndexGump()
{
}

CIndexAnimation::CIndexAnimation()
{
}

CIndexAnimation::~CIndexAnimation()
{
}

CIndexMusic::CIndexMusic()
{
}

CIndexMusic::~CIndexMusic()
{
}

void CIndexObject::ReadIndexFile(size_t address, PBASE_IDX_BLOCK ptr, const uint16_t id)
{
    Address = ptr->Position;
    DataSize = ptr->Size;

    if (Address == 0xFFFFFFFF || (DataSize == 0) || DataSize == 0xFFFFFFFF)
    {
        Address = 0;
        DataSize = 0;
    }
    else
    {
        Address = Address + address;
    }

    ID = id;
};

void CIndexMulti::ReadIndexFile(size_t address, PBASE_IDX_BLOCK ptr, const uint16_t id)
{
    CIndexObject::ReadIndexFile(address, ptr, id);
    if (g_PacketManager.GetClientVersion() >= CV_7090)
    {
        Count = (uint16_t)(DataSize / sizeof(MULTI_BLOCK_NEW));
    }
    else
    {
        Count = (uint16_t)(DataSize / sizeof(MULTI_BLOCK));
    }
};

void CIndexLight::ReadIndexFile(size_t address, PBASE_IDX_BLOCK ptr, const uint16_t id)
{
    CIndexObject::ReadIndexFile(address, ptr, id);
    PLIGHT_IDX_BLOCK realPtr = (PLIGHT_IDX_BLOCK)ptr;
    Width = realPtr->Width;
    Height = realPtr->Height;
};

void CIndexGump::ReadIndexFile(size_t address, PBASE_IDX_BLOCK ptr, const uint16_t id)
{
    CIndexObject::ReadIndexFile(address, ptr, id);
    PGUMP_IDX_BLOCK realPtr = (PGUMP_IDX_BLOCK)ptr;
    Width = realPtr->Width;
    Height = realPtr->Height;
};
