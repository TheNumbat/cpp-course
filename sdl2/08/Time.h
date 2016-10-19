#pragma once

#include <map>
#include <string>
#include <SDL.h>

class timer {
	timer(Uint64 s, Uint64 p, bool perf);
	~timer();

	Uint64 start;
	Uint64 pause;
	Uint64 lag;
	bool isPerfCounter;

	friend class Time;
};

class Time
{
public:
	ENGINE_API Time();
	ENGINE_API ~Time();

	bool init();
	bool kill();

	ENGINE_API bool addTimer(const std::string& tID, bool startPaused = false);
	ENGINE_API bool addPerfCounter(const std::string& tID, bool startPaused = false);

	ENGINE_API bool remove(const std::string& tID);

	ENGINE_API bool addCallback(u32(*callback)(u32, void*), u32 delay, void* param, bool save = false, const std::string& cID = "");
	ENGINE_API bool removeCallback(const std::string& cID);

	ENGINE_API bool pause(const std::string& tID);
	ENGINE_API bool resume(const std::string& tID);
	ENGINE_API bool reset(const std::string& tID);
	ENGINE_API bool toggle(const std::string& tID);

	ENGINE_API Uint64 get(const std::string& tID);

	ENGINE_API Uint64 getPerfFreq();
	ENGINE_API Uint64 ticksSinceStart();
	ENGINE_API Uint64 perfSinceStart();

private:
	std::map<std::string, timer*> timers;
	std::map<std::string, u32> callbacks;
	bool good;
};

