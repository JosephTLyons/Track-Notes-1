/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "BasicWindow.cpp"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TrackNotesAudioProcessorEditor  : public AudioProcessorEditor,
                                        public TextEditorListener,
                                        public ButtonListener
{
public:
    //==============================================================================
    TrackNotesAudioProcessorEditor (TrackNotesAudioProcessor &p);
    ~TrackNotesAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void loadImage(Image &image, File &imagePath);
    void createImageWindow(SafePointer<BasicWindow> &basicWindowPtr, Image &image, File &imagePath);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    TrackNotesAudioProcessor& processor;
    String versionNumberLabelString;
    int fontSize;
    Array<Font> usersFontsResults;

    //SafePointer<ImageComponent> imageComponentOnePtr;
    //SafePointer<ImageComponent> imageComponentTwoPtr;
    File *imageOnePathPtr, *imageTwoPathPtr;
    Image *imageOnePtr, *imageTwoPtr;

    SafePointer<TextEditor> performersNameEditorPtr;
    SafePointer<TextEditor> instrumentPlayedEditorPtr;
    SafePointer<TextEditor> microphonesUsedEditorPtr;
    SafePointer<TextEditor> timestampedNotesEditorPtr;
    SafePointer<TextEditor> generalNotesEditorPtr;

    SafePointer<BasicWindow> basicWindowImageOnePtr;
    SafePointer<BasicWindow> basicWindowImageTwoPtr;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> trackNotesLabel;
    ScopedPointer<Label> performersNameLabel;
    ScopedPointer<Label> instrumentPlayedLabel;
    ScopedPointer<Label> microphonesUsedLabel;
    ScopedPointer<Label> timestampedNotesLabel;
    ScopedPointer<TextButton> insertTimeStampButton;
    ScopedPointer<Label> versionNumberLabel;
    ScopedPointer<Label> theLyonsDenSoftware;
    ScopedPointer<Label> generalNotesLabel;
    ScopedPointer<TextButton> displayImageOneButton;
    ScopedPointer<TextButton> displayImageTwoButton;
    ScopedPointer<TextButton> loadImageOneButton;
    ScopedPointer<TextButton> loadImageTwoButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackNotesAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
