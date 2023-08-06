#pragma once

#include <JuceHeader.h>
#include "Director.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    void buttonClicked ();

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    double setSampleRate = 0.0, angleDelta = 0.0, angleCurrent = 0.0;
    juce::TextButton btnAddBird;
    Director soundDir;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
