/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

using namespace juce;

//==============================================================================
/**
*/



//==============================================================================



class FabPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    FabPluginAudioProcessorEditor (FabPluginAudioProcessor&);
    ~FabPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FabPluginAudioProcessor& audioProcessor;
    
    Slider driveKnob;
    Slider rangeKnob;
    Slider blendKnob;
    Slider volumeKnob;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FabPluginAudioProcessorEditor)
    
public:
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> driveAttatchment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> rangeAttatchment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> blendAttatchment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> volumeAttatchment;
    
};
