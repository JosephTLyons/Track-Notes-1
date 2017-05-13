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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TrackNotesAudioProcessorEditor::TrackNotesAudioProcessorEditor (TrackNotesAudioProcessor &p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (trackNotes = new Label ("trackNotesLabel",
                                               TRANS("Track Notes")));
    trackNotes->setFont (Font (48.70f, Font::plain).withTypefaceStyle ("Regular"));
    trackNotes->setJustificationType (Justification::centredTop);
    trackNotes->setEditable (false, false, false);
    trackNotes->setColour (TextEditor::textColourId, Colours::black);
    trackNotes->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String());

    addAndMakeVisible (textEditor2 = new TextEditor ("new text editor"));
    textEditor2->setMultiLine (false);
    textEditor2->setReturnKeyStartsNewLine (false);
    textEditor2->setReadOnly (false);
    textEditor2->setScrollbarsShown (true);
    textEditor2->setCaretVisible (true);
    textEditor2->setPopupMenuEnabled (true);
    textEditor2->setText (String());

    addAndMakeVisible (textEditor3 = new TextEditor ("new text editor"));
    textEditor3->setMultiLine (false);
    textEditor3->setReturnKeyStartsNewLine (false);
    textEditor3->setReadOnly (false);
    textEditor3->setScrollbarsShown (true);
    textEditor3->setCaretVisible (true);
    textEditor3->setPopupMenuEnabled (true);
    textEditor3->setText (String());

    addAndMakeVisible (textEditor4 = new TextEditor ("new text editor"));
    textEditor4->setMultiLine (false);
    textEditor4->setReturnKeyStartsNewLine (false);
    textEditor4->setReadOnly (false);
    textEditor4->setScrollbarsShown (true);
    textEditor4->setCaretVisible (true);
    textEditor4->setPopupMenuEnabled (true);
    textEditor4->setText (String());


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TrackNotesAudioProcessorEditor::~TrackNotesAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    trackNotes = nullptr;
    textEditor = nullptr;
    textEditor2 = nullptr;
    textEditor3 = nullptr;
    textEditor4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TrackNotesAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff2a2a2a));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TrackNotesAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    trackNotes->setBounds (0, 0, 400, 56);
    textEditor->setBounds (200, 96, 200, 48);
    textEditor2->setBounds (200, 152, 200, 48);
    textEditor3->setBounds (200, 208, 200, 48);
    textEditor4->setBounds (0, 264, 400, 128);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TrackNotesAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="TrackNotesAudioProcessor &amp;p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="400" initialHeight="400">
  <BACKGROUND backgroundColour="ff2a2a2a"/>
  <LABEL name="trackNotesLabel" id="92aa8337c9826f3e" memberName="trackNotes"
         virtualName="" explicitFocusOrder="0" pos="0 0 400 56" edTextCol="ff000000"
         edBkgCol="0" labelText="Track Notes" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="48.700000000000002842" kerning="0" bold="0" italic="0"
         justification="12"/>
  <TEXTEDITOR name="new text editor" id="13c8f94f4dbdbdb0" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="200 96 200 48" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="271d4ec88d19c39d" memberName="textEditor2"
              virtualName="" explicitFocusOrder="0" pos="200 152 200 48" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="922d9385abd5851a" memberName="textEditor3"
              virtualName="" explicitFocusOrder="0" pos="200 208 200 48" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="769d422c67fe7990" memberName="textEditor4"
              virtualName="" explicitFocusOrder="0" pos="0 264 400 128" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
