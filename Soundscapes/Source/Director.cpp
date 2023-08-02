/*
  ==============================================================================

    Director.cpp
    Created: 1 Aug 2023 2:15:44pm
    Author:  Giacomo Loparco

  ==============================================================================
*/

#include "Director.h"

// Constructor
Director::Director(double sampleRate)
{
    setSampleRate = sampleRate;
}

double* Director::nextSampleAll()
{
    // Check if we have a bird object
    if (birdSound != 0)
    {
        // Get the sample
    }
    return nullptr;
}

void Director::createBird()
{
    birdSound = Bird(setSampleRate);
}
