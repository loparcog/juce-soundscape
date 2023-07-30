/*
  ==============================================================================

    Birds.h
    Created: 29 Jul 2023
    Author:  Giacomo Loparco

  ==============================================================================
*/

#pragma once

class Bird{
public:
    Bird(double sampleRate);
    double* nextSong();
    bool isDone();
private:
    double freq = 0.0, duration = 0.0, sawSpeed = 0.0, setSampleRate = 0.0;
    double level = 0.0, angleDelta = 0.0, direction = 0.0;
    double sawBounds [2] = {1.0, 10.0};
    double pitchBounds [2] = {500.0, 1000.0};
    double levelBounds [2] = {0.1, 0.8};
    double durationBounds [2] = {1.0, 10.0};
};
