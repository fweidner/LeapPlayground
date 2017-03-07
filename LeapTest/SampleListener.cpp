#include "SampleListener.h"

#include <iostream>

using namespace Leap;

void SampleListener::onConnect(const Controller& controller)
{
	std::cout << "Connected" << std::endl;
}

void SampleListener::onFrame(const Controller& controller)
{
	//std::cout << "Frame available" << std::endl;

	Frame frame = controller.frame();


	int i = 0;
	if (true)
	{

		FingerList fingers = frame.fingers();
		if (fingers.isEmpty())
		{
			return;
		}
		FingerList fingers_ext = fingers.extended();
		for (auto it = fingers_ext.begin(); it != fingers_ext.end(); it++)
		{
			if((*it).type() != Finger::TYPE_THUMB)
			{
				
				i += 1;
			}
		}
	}

	GestureList gestures_ = frame.gestures();
	for (auto it = gestures_.begin(); it != gestures_.end(); ++it)
	{
		if (Gesture::TYPE_KEY_TAP == (*it).type())
		{
			KeyTapGesture keytapGesture = KeyTapGesture((*it));
			//std::cout << keytapGesture.toString() << " - " << keytapGesture.pointables().count() << std::endl;

			keytapGesture.pointables().count();

			std::cout << "Select entry " << i << std::endl;;

		}
	}





#if 0

	

	//std::cout << gestures_.count() << std::endl;
	for (auto it = gestures_.begin(); it != gestures_.end(); ++it)
	{
		switch ((*it).type())
		{
		case Gesture::TYPE_CIRCLE:
		{
			CircleGesture circleGesture = CircleGesture((*it));

			std::string clockwiseness = "";

			std::cout << circleGesture.progress() << std::endl;


			if (circleGesture.pointable().direction().angleTo(circleGesture.normal()) <= Leap::PI / 2)
			{
				clockwiseness = "clockwise";
			}
			else
			{
				clockwiseness = "counterclockwise";
			}

			//std::cout << (*it).toString() << " - " << clockwiseness << std::endl;

			break;
		}
		case Gesture::TYPE_SWIPE:
		{
			SwipeGesture swipeGesture = Leap::SwipeGesture(*it);

			Vector swipeDirection = swipeGesture.direction();

			//std::cout << (*it).toString() << " - " << swipeDirection << std::endl;

			if (frame.hands().count() == 1)
			{
				Hand firstHand = frame.hands()[0];


				Vector up = firstHand.palmNormal();
				if (up.x < 0.1f && up.z < 0.1f && up.y >0.7)
				{
				}
				std::cout << firstHand.toString() << " - " << firstHand.palmNormal() << std::endl;;

			}
			break;
		}
		case Gesture::TYPE_KEY_TAP:
		{
			KeyTapGesture keytapGesture = KeyTapGesture((*it));
			std::cout << keytapGesture.toString() << " - " << keytapGesture.pointables().count() << std::endl;

			keytapGesture.pointables().count();
		}
		default:
			break;
		}


		if ((*it).type() == Leap::Gesture::TYPE_SWIPE) {


		}
	}

#endif
}