﻿/***********************************************************************************
**
** PathNode.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "PathNode.h"
//----------------------------------------------------------------------------------
//------------------------------------CPathObject-----------------------------------
//----------------------------------------------------------------------------------
CPathObject::CPathObject(const int &z, const char &height, const char &surface)
: CBaseQueueItem(), m_Z(z), m_Height(height), m_Surface(surface)
{
}
//----------------------------------------------------------------------------------
CPathObject::~CPathObject()
{
}
//----------------------------------------------------------------------------------
//------------------------------------CPathNode-------------------------------------
//----------------------------------------------------------------------------------
CPathNode::CPathNode()
: m_Parent(NULL), m_X(0), m_Y(0), m_Z(0), m_Used(false), m_Cost(0),
m_Direction(0), m_DistFromStartCost(0), m_DistFromGoalCost(0)
{
}
//----------------------------------------------------------------------------------
CPathNode::~CPathNode()
{
	m_Parent = NULL;
}
//----------------------------------------------------------------------------------
void CPathNode::Reset()
{
	m_Parent = NULL;
	m_Used = false;
	m_X = m_Y = m_Z = m_Direction = m_Cost = m_DistFromStartCost = m_DistFromGoalCost = 0;
}
//----------------------------------------------------------------------------------
