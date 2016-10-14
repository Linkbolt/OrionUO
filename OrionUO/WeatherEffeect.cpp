﻿/***********************************************************************************
**
** WeatherEffect.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "WeatherEffect.h"
//----------------------------------------------------------------------------------
CWeatherEffect::CWeatherEffect()
: m_SpeedX(0), m_SpeedY(0), m_X(0), m_Y(0), m_SpeedAngle(0.0f), m_SpeedMagnitude(0.0f)
{
	m_ID = RandomInt(2000);

	m_ScaleRatio = (float)(m_ID % 20) / 13.0f;
}
//----------------------------------------------------------------------------------
