/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __WEATHERMGR_H
#define __WEATHERMGR_H

#define WEATHER_DENSITY_UPDATE 0.05f

class WeatherInfo;
class WeatherMgr;

void   BuildWeatherPacket(WorldPacket * data, uint32 Effect, float Density );
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

class WeatherInfo : public EventableObject, public std::tr1::enable_shared_from_this<WeatherInfo>
{
	friend class WeatherMgr;
public:
	WeatherInfo();
	~WeatherInfo();

	void Destructor();

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

#endif
