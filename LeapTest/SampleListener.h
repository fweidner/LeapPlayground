#pragma once

#include <Leap.h>

namespace Leap{

class SampleListener : public Listener
{
public:
	virtual void onConnect(const Controller&);
	virtual void onFrame(const Controller&);
};
}