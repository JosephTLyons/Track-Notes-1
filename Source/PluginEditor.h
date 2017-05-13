/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TrackNotesAudioProcessorEditor  : public AudioProcessorEditor,
                                        public ButtonListener
{
public:
    //==============================================================================
    TrackNotesAudioProcessorEditor (TrackNotesAudioProcessor &p);
    ~TrackNotesAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    TrackNotesAudioProcessor& processor;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> trackNotesLabel;
    ScopedPointer<TextEditor> textEditor;
    ScopedPointer<TextEditor> textEditor2;
    ScopedPointer<TextEditor> textEditor4;
    ScopedPointer<Label> performersNameLabel;
    ScopedPointer<TextEditor> textEditor3;
    ScopedPointer<Label> instrumentPlayedLabel;
    ScopedPointer<Label> microphonesUsedLabel;
    ScopedPointer<Label> generalNotesLabel;
    ScopedPointer<TextButton> grabTimeButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackNotesAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
