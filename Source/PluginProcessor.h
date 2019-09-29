/*
  ==============================================================================
  Copyright 2013-2017 Joseph Lyons
  
  This file is part of Track Notes.
 
  Track Notes is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
 
  Track Notes is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with Track Notes.  If not, see <http://www.gnu.org/licenses/>.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class TrackNotesAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    TrackNotesAudioProcessor();
    ~TrackNotesAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    AudioPlayHead::CurrentPositionInfo positionInformation;

    String performersNameString;
    String instrumentPlayedString;
    String microphonesUsedString;
    String timestampedNotesString;
    String generalNotesString;

    File imageOnePath, imageTwoPath;
    Image imageOne, imageTwo;

    String performersNameLabelString;
    String instrumentPlayedLabelString;
    String microphonesUsedLabelString;

    bool stealthIsActivated;
    
private:
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackNotesAudioProcessor)
};
