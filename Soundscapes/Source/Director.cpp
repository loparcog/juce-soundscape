/*
  ==============================================================================

    Director.cpp
    Created: 1 Aug 2023 2:15:44pm
    Author:  Giacomo Loparco

  ==============================================================================
*/

#include "Director.h"
#include <vector>

// Constructor
Director::Director(double sampleRate)
{
    setSampleRate = sampleRate;
}

double* Director::nextSampleAll()
{
    double static buffer [2] = {0,0};
    // Loop through sound vector
    for (int i = 0; i < vSounds.size(); i++)
    {
        // Get the waveform to send out
        double *currentSample = vSounds[i].nextSample();
        buffer[0] = *currentSample * 0.2;
        buffer[1] = *(currentSample + 1) * 0.2;
    }
    
    return buffer;
}

void Director::createBird()
{
    vSounds.push_back(Bird(setSampleRate));
}
