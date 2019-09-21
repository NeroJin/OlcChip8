#pragma once
#include <Windows.h>

class SimpleTimer
{
private:
	__int64 freq;
	__int64 startTime;
	__int64 lastTime;
	double targetElapsedTime = 1000;

public:
	SimpleTimer()
	{

	}

	void SetTargetElapsedTimer(double time)
	{
		targetElapsedTime = time;
	}

	void Start()
	{
		LARGE_INTEGER li;
		QueryPerformanceFrequency(&li);
		freq = double(li.QuadPart) / 1000.0;
		QueryPerformanceCounter(&li);
		startTime = li.QuadPart;
	}

	void Restart()
	{
		startTime = lastTime;
	}

	bool CheckTargetTimer()
	{
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		lastTime = double(li.QuadPart);
		if ((lastTime - startTime) >= (targetElapsedTime * freq))
			return true;
		else
			return false;
	}
};