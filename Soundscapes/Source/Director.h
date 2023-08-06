/*
  ==============================================================================

    Director.h
    Created: 1 Aug 2023 2:15:44pm
    Author:  Giacomo Loparco

  ==============================================================================
*/

#pragma once
#include "Bird.h"
#include <vector>

class Director
{
public:
    // Constructor, only takes in sample rate
    Director();
    Director(double sampleRate);
    // Get all samples from current objects
    void SR(double sampleRate);
    double* nextSampleAll();
    // Create a new object (debug, will be automatic in future)
    void createBird();
private:
    // Stored metadata
    double setSampleRate = 0.0;
    // Sound variable
    std::vector<Bird> vSounds;
};
