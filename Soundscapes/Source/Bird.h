/*
  ==============================================================================

    Birds.h
    Created: 29 Jul 2023
    Author:  Giacomo Loparco

  ==============================================================================
*/

#pragma once

class Bird
{
public:
    // Constructor, taking in sample rate
    Bird(double sampleRate);
    // Get next sample in the song
    double* nextSample();
    // Is the object done
    bool isDone();
private:
    // Whether the bird object is currently active
    bool active = false;
    double freq = 0.0, duration = 0.0, sawSpeed = 0.0, setSampleRate = 0.0;
    double level = 0.0, angleDelta = 0.0, angleCurrent = 0.0, direction = 0.0;
    double sawDelta = 0.0;
    double sawBounds [2] = {1.0, 10.0};
    double pitchBounds [2] = {500.0, 1000.0};
    double levelBounds [2] = {0.1, 0.8};
    double durationBounds [2] = {1.0, 10.0};
};
