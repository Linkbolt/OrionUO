﻿// MIT License
// Copyright (C) September 2016 Hotride

#pragma once

class CPlugin : public CBaseQueueItem
{
private:
    uint32_t m_Flags{ 0 };

public:
    CPlugin(uint32_t flags);
    virtual ~CPlugin();

    bool CanParseRecv() { return (m_Flags & PLUGIN_FLAGS_PARSE_RECV); }
    bool CanParseSend() { return (m_Flags & PLUGIN_FLAGS_PARSE_SEND); }
    bool CanRecv() { return (m_Flags & PLUGIN_FLAGS_RECV); }
    bool CanSend() { return (m_Flags & PLUGIN_FLAGS_SEND); }
    bool CanWindowProc() { return (m_Flags & PLUGIN_FLAGS_WINDOW_PROC); }
    bool CanClientAccess() { return (m_Flags & PLUGIN_FLAGS_CLIENT_ACCESS); }
    bool CanEnterWorldRender() { return (m_Flags & PLUGIN_FLAGS_GAME_WORLD_DRAW); }
    bool CanEnterSceneRender() { return (m_Flags & PLUGIN_FLAGS_SCENE_DRAW); }
    bool CanEnterWorldMapRender() { return (m_Flags & PLUGIN_FLAGS_WORLD_MAP_DRAW); }

    PLUGIN_INTERFACE *m_PPS;
};

class CPluginManager : public CBaseQueue
{
public:
    CPluginManager();
    virtual ~CPluginManager() {}

    uint32_t WindowProc(WindowHandle hWnd, uint32_t msg, void *data1, void *data2);
    bool PacketRecv(uint8_t *buf, size_t size);
    bool PacketSend(uint8_t *buf, size_t size);
    void Disconnect();
    void WorldDraw();
    void SceneDraw();
    void WorldMapDraw();
};

extern CPluginManager g_PluginManager;
