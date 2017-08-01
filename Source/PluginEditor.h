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

  Created with Projucer version: 5.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "StaticTextSizeButton.hpp"
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

    void setupVersionNumberlabel();
    void loadImage(Image &image, File &imagePath, const bool &isImageOne);
    void createImageWindow(SafePointer<BasicWindow> &basicWindowPtr, Image &image, File &imagePath);
    void showErrorLoadingImageWindow(const String &path);
    void fillTimeIntervalValues(int &hours, int &minutes, int &seconds);
    String formatAndBuildTimecode(const int &hours, const int &minutes, const int &seconds);
    String formatTimeInterval(const int &timeInterval);
    void createImagePreview(const bool &isImageOne);
    void scaleImageDimensionsIfTooLarge(int &imageWidtht, int &imageHeight);
    void activateStealthMode();
    void deactivateStealthMode();
    void hideTextAndDisableEditor(TextEditor &textEditor);
    void showTextAndEnableEditor(TextEditor &textEditor);
    void setFocusTabOrder();


    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void mouseMove (const MouseEvent& e) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    TrackNotesAudioProcessor& processor;
    String versionNumberString;
    Array<Font> usersFontsResults;

    File *imageOnePathPtr, *imageTwoPathPtr;
    Image *imageOnePtr, *imageTwoPtr;
    bool *imageOneMissingPtr, *imageTwoMissingPtr;
    ImageComponent imagePreviewOne, imagePreviewTwo;

    bool pluginIsRunningInDemoMode;
    bool *stealthIsActivatedPtr;

    SafePointer<TextEditor> performersNameEditorPtr;
    SafePointer<TextEditor> instrumentPlayedEditorPtr;
    SafePointer<TextEditor> microphonesUsedEditorPtr;
    SafePointer<TextEditor> timestampedNotesEditorPtr;
    SafePointer<TextEditor> generalNotesEditorPtr;

    SafePointer<Label> performersNameLabelPtr;
    SafePointer<Label> instrumentPlayedLabelPtr;
    SafePointer<Label> microphonesUsedLabelPtr;

    SafePointer<BasicWindow> basicWindowImageOnePtr;
    SafePointer<BasicWindow> basicWindowImageTwoPtr;

    ScopedPointer<StaticTextSizeButton> staticTextSizeButton;

    AudioPlayHead::CurrentPositionInfo *positionInformationPtr;

    TooltipWindow toolTipWindow;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> trackNotesLabel;
    ScopedPointer<Label> timestampedNotesLabel;
    ScopedPointer<TextButton> insertTimeStampButton;
    ScopedPointer<Label> theLyonsDenSoftwareLabel;
    ScopedPointer<Label> generalNotesLabel;
    ScopedPointer<TextButton> displayImageOneButton;
    ScopedPointer<TextButton> displayImageTwoButton;
    ScopedPointer<TextButton> loadImageOneButton;
    ScopedPointer<TextButton> loadImageTwoButton;
    ScopedPointer<TextButton> removeImageOneButton;
    ScopedPointer<TextButton> removeImageTwoButton;
    ScopedPointer<Label> imagesLabel;
    ScopedPointer<TextButton> exportMediaButton;
    ScopedPointer<TextButton> stealthModeToggle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackNotesAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
