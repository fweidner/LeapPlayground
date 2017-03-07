#include <iostream>
#include <string.h>
#include "Leap.h"

#include "SampleListener.h"

using namespace Leap;

int main(int argc, char** argv) {

	SampleListener listener;

	Controller controller;

	//controller.enableGesture(Gesture::TYPE_CIRCLE);

	//controller.enableGesture(Gesture::TYPE_SWIPE);

	controller.enableGesture(Gesture::TYPE_KEY_TAP);
	


	controller.addListener(listener);

	// Keep this process running until Enter is pressed
	std::cout << "Press Enter to quit..." << std::endl;
	std::cin.get();

	controller.removeListener(listener);

	return 0;
}