
#include "time.h"

timer::timer(Uint64 s, Uint64 p, bool perf) {
	start = s;
	pause = p;
	isPerfCounter = perf;
	lag = 0;
}

timer::~timer() {}

Time::Time() {
	good = false;
}

Time::~Time() {
	for (auto i : timers)
		delete i.second;
	for (auto i : callbacks)
		removeCallback(i.first);
}

bool Time::init() {
	
	if (good) {
		return false;
	}

	int result = SDL_InitSubSystem(SDL_INIT_TIMER);
	if (result != 0) {
		return false;
	}

	good = true;
	return true;
}

bool Time::kill() {

	if (!good) {
		return false;
	}

	SDL_QuitSubSystem(SDL_INIT_TIMER);

	good = false;
	return true;
}

bool Time::addTimer(const std::string& tID, bool startPaused) {
	
	if (timers.find(tID) != timers.end()) {
		return false;
	}

	Uint64 currentTime = ticksSinceStart();
	timer* newT = new timer(currentTime, startPaused ? currentTime : 0, false);
	
	timers.insert({tID, newT});
	return true;
}

bool Time::addPerfCounter(const std::string& tID, bool startPaused) {

	if (timers.find(tID) != timers.end()) {
		return false;
	}

	Uint64 currentTime = perfSinceStart();
	timer* newPC = new timer(currentTime, startPaused ? currentTime : 0, true);
	
	timers.insert({tID, newPC});
	return true;
}

bool Time::remove(const std::string& tID) {

	auto entry = timers.find(tID);
	if (entry == timers.end()) {
		return false;
	}

	delete entry->second;
	timers.erase(entry);
	return true;
}

bool Time::addCallback(Uint32(*callback)(Uint32, void*), Uint32 delay, void* param, bool save, const std::string& tID) {

	if (save && tID == "") {
		return false;
	}

	if (save && callbacks.find(tID) != callbacks.end()) {
		return false;
	}

	SDL_TimerID result = SDL_AddTimer(delay,(SDL_TimerCallback)callback,param);
	if (result == 0) {
		return false;
	}

	if (save) {
		callbacks.insert({tID, result});
	}
	return true;
}

bool Time::removeCallback(const std::string& tID) {

	auto entry = callbacks.find(tID);
	if (entry == callbacks.end()) {
		return false;
	}

	int result = SDL_RemoveTimer(entry->second);
	callbacks.erase(entry);
	if (result == 0) {
		return false;
	}

	return true;
}

bool Time::pause(const std::string& tID) {
	
	auto entry = timers.find(tID);
	if (entry == timers.end()) {
		return false;
	}

	if (entry->second->pause) {
		return false;
	}

	if (entry->second->isPerfCounter)
		entry->second->pause = perfSinceStart() - entry->second->pause - entry->second->start;
	else
		entry->second->pause = ticksSinceStart() - entry->second->pause - entry->second->start;

	return true;
}

bool Time::resume(const std::string& tID) {

	auto entry = timers.find(tID);
	if (entry == timers.end()) {
		return false;
	}

	if (!entry->second->pause) {
		return false;
	}

	if (entry->second->isPerfCounter)
		entry->second->lag = perfSinceStart() - entry->second->pause - entry->second->start;
	else
		entry->second->lag = ticksSinceStart() - entry->second->pause - entry->second->start;
	
	entry->second->pause = 0;
	return true;
}

bool Time::reset(const std::string& tID) {

	auto entry = timers.find(tID);
	if (entry == timers.end()) {
		return false;
	}

	if (entry->second->isPerfCounter)
		entry->second->start = perfSinceStart();
	else
		entry->second->start = ticksSinceStart();

	entry->second->pause = 0;
	entry->second->lag = 0;
	return true;
}

bool Time::toggle(const std::string& tID) {

	auto entry = timers.find(tID);
	if (entry == timers.end()) {
		return false;
	}

	if (entry->second->pause)
		resume(tID);
	else
		pause(tID);

	return true;
}

Uint64 Time::get(const std::string& tID) {

	auto entry = timers.find(tID);
	if (entry == timers.end()) {
		return -1;
	}

	if (entry->second->pause)
		return entry->second->pause;

	if (entry->second->isPerfCounter)
		return perfSinceStart() - entry->second->start - entry->second->lag;
	else
		return ticksSinceStart() - entry->second->start - entry->second->lag;
}

Uint64 Time::getPerfFreq() {
	return SDL_GetPerformanceFrequency();
}

Uint64 Time::ticksSinceStart() {
	return SDL_GetTicks();
}

Uint64 Time::perfSinceStart() {
	return SDL_GetPerformanceCounter();
}

