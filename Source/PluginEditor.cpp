/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FabPluginAudioProcessorEditor::FabPluginAudioProcessorEditor (FabPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    driveAttatchment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "DRIVE", driveKnob );
    volumeAttatchment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "VOLUME", volumeKnob );
    blendAttatchment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "BLEND", blendKnob );
    rangeAttatchment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "RANGE", rangeKnob );
    
    setSize (800, 400);
    
    addAndMakeVisible(driveKnob);
    addAndMakeVisible(rangeKnob);
    addAndMakeVisible(blendKnob);
    addAndMakeVisible(volumeKnob);
    
    driveKnob.setSliderStyle(juce::Slider::Rotary);
    driveKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 30, 25);
    
    
    rangeKnob.setSliderStyle(juce::Slider::Rotary);
    rangeKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 30, 25);
    
    
    blendKnob.setSliderStyle(juce::Slider::Rotary);
    blendKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 30, 25);
    
    
    volumeKnob.setSliderStyle(juce::Slider::Rotary);
    volumeKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 30, 25);
    

    
}

FabPluginAudioProcessorEditor::~FabPluginAudioProcessorEditor()
{
}

//==============================================================================
void FabPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);

    
    Image background = ImageCache::getFromMemory (BinaryData::osqpic_jpg, BinaryData::osqpic_jpgSize);
        g.drawImageAt (background, 0, 0);
    
    driveKnob.setBounds(60, 225, 150, 150);
    rangeKnob.setBounds(235, 225, 150, 150);
    blendKnob.setBounds(410, 225, 150, 150);
    volumeKnob.setBounds(585, 225, 150, 150);
}

void FabPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
