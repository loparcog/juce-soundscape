/*
  ==============================================================================

    Birds.cpp
    Created: 29 Jul 2023
    Author:  Giacomo Loparco

  ==============================================================================
*/

#include "Bird.h"
//#include <random>
#include <cmath>

Bird::Bird(double sampleRate)
{
    // Set the sample rate
    setSampleRate = sampleRate;
    // TODO: Set random values based on ranges
    // Base frequency of the call, lowest note hit
    freq = 400;
    // Volume (0-1)
    level = 0.3;
    // Length in seconds
    duration = 5.0 * setSampleRate;
    // Pitch modulation period (time for mod to cycle in seconds)
    sawSpeed = 1.0;
    // Direction, dictating how far left (0) or right (1) it is
    direction = 0.5;
    sawDelta = 200;
    
    // Set the angle increment needed for the call waveform
    angleDelta = (freq / setSampleRate) * 2.0 * M_PI;
}

bool Bird::isDone()
{
    if (duration == 0)
    {
        return true;
    }
    return false;
}

double * Bird::nextSample()
{
    // Array to return values for left (0) and right (1) channels
    static double sampleReturn [2];
    // Why are we casting like this..?
    auto currentSample = (float) sin(angleCurrent);
    angleCurrent += angleDelta;
    angleDelta = ((freq + sawDelta) / setSampleRate) * 2.0 * M_PI;
    sawDelta -= 0.01;
    if (sawDelta < 0)
    {
        sawDelta = 200;
    }
    // Divide the sample w.r.t level and direction
    // TODO: Add direction into the equation, did a .5 thing and it felt weird
    sampleReturn[0] = currentSample * level;
    sampleReturn[1] = currentSample * level;
    /*if (--duration == 0)
    {
        return sampleReturn;
    }*/
    return sampleReturn;
}
