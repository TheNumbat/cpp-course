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
	Time();
	~Time();

	bool init();
	bool kill();

	bool addTimer(const std::string& tID, bool startPaused = false);
	bool addPerfCounter(const std::string& tID, bool startPaused = false);

	bool remove(const std::string& tID);

	bool addCallback(Uint32(*callback)(Uint32, void*), Uint32 delay, void* param, bool save = false, const std::string& cID = "");
	bool removeCallback(const std::string& cID);

	bool pause(const std::string& tID);
	bool resume(const std::string& tID);
	bool reset(const std::string& tID);
	bool toggle(const std::string& tID);

	Uint64 get(const std::string& tID);

	Uint64 getPerfFreq();
	Uint64 ticksSinceStart();
	Uint64 perfSinceStart();

private:
	std::map<std::string, timer*> timers;
	std::map<std::string, Uint32> callbacks;
	bool good;
};

