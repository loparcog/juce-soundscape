#include "MainComponent.h"
#include "Director.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(btnAddBird);
    btnAddBird.setButtonText("Add a Bird");
    btnAddBird.onClick = [this] {buttonClicked(); };
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

// Deconstructor
MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    //btnAddBird.removeListener (this);
    shutdownAudio();
    
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    setSampleRate = sampleRate;
    auto cyclesPerSample = 500.0 / setSampleRate;
    angleDelta = cyclesPerSample * 2.0 * juce::MathConstants<double>::pi;
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // When no sounds, use bufferToFill.clearActiveBufferRegion();
    auto level = 0.125f;
    auto* leftBuffer  = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
    auto* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);

    for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
    {
        auto currentSample = (float) std::sin (angleCurrent);
        angleCurrent += angleDelta;
        leftBuffer[sample]  = currentSample * level;
        rightBuffer[sample] = currentSample * level;
    }
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::buttonClicked()
{
    std::cout << "Button!";
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    btnAddBird.setBounds (10, 10, getWidth() - 20, 40);
}
