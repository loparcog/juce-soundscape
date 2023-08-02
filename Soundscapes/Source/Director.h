/*
  ==============================================================================

    Director.h
    Created: 1 Aug 2023 2:15:44pm
    Author:  Giacomo Loparco

  ==============================================================================
*/

#pragma once
#include "Bird.h"

class Director
{
public:
    // Constructor, only takes in sample rate
    Director(double sampleRate);
    // Get all samples from current objects
    double* nextSampleAll();
    // Create a new object (debug, will be automatic in future)
    void createBird();
private:
    // Stored metadata
    double setSampleRate = 0.0;
    // TODO: Make this a general sound object container
    // How would I make that dynamic for different sound objects..?
    // Maybe make a set amount of each object at all times..?
    birdSound = 0;
};
