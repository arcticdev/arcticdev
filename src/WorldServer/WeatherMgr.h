/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2014 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

#define WEATHER_DENSITY_UPDATE 0.05f

class WeatherInfo;
class WeatherMgr;

// Weather defines
enum WeatherTypes
{
	 WEATHER_TYPE_NORMAL			= 0, // NORMAL
	 WEATHER_TYPE_FOG				= 1, // FOG --> current value irrelant
	 WEATHER_TYPE_RAIN				= 2, // RAIN
	 WEATHER_TYPE_HEAVY_RAIN		= 4, // HEAVY_RAIN
	 WEATHER_TYPE_SNOW				= 8, // SNOW
	 WEATHER_TYPE_SANDSTORM			= 16 // SANDSTORM
};

enum WeatherSounds
{
	 WEATHER_NOSOUND				= 0,
	 WEATHER_RAINLIGHT				= 8533,
	 WEATHER_RAINMEDIUM				= 8534,
	 WEATHER_RAINHEAVY				= 8535,
	 WEATHER_SNOWLIGHT				= 8536,
	 WEATHER_SNOWMEDIUM				= 8537,
	 WEATHER_SNOWHEAVY				= 8538,
	 WEATHER_SANDSTORMLIGHT			= 8556,
	 WEATHER_SANDSTORMMEDIUM		= 8557,
	 WEATHER_SANDSTORMHEAVY			= 8558
};

void BuildWeatherPacket(WorldPacket * data, uint32 Effect, float Density );
uint32 GetSound(uint32 Effect, float Density);

class WeatherMgr :  public Singleton < WeatherMgr >
{
public:
	WeatherMgr();
	~WeatherMgr();

	void LoadFromDB();
	void SendWeather(Player* plr);

private:
	std::map<uint32, WeatherInfo* > m_zoneWeathers;
};

class WeatherInfo : public EventableObject
{
	friend class WeatherMgr;
public:
	WeatherInfo();
	~WeatherInfo();

	void BuildUp();
	void Update();
	void SendUpdate();
	void SendUpdate(Player* plr);

protected:
	void _GenerateWeather();

	uint32 m_zoneId;

	uint32 m_totalTime;
	uint32 m_currentTime;

	float m_maxDensity;
	float m_currentDensity;

	uint32 m_currentEffect;
	std::map<uint32, uint32> m_effectValues;
};

#define sWeatherMgr WeatherMgr::getSingleton()
