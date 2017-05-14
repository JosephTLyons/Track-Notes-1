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

    addAndMakeVisible (trackNotesLabel = new Label ("trackNotesLabel",
                                                    TRANS("Track Notes")));
    trackNotesLabel->setFont (Font ("Arial", 48.70f, Font::plain).withTypefaceStyle ("Regular"));
    trackNotesLabel->setJustificationType (Justification::centredTop);
    trackNotesLabel->setEditable (false, false, false);
    trackNotesLabel->setColour (Label::textColourId, Colours::white);
    trackNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    trackNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (performersNameEditor = new TextEditor ("performersNameEditor"));
    performersNameEditor->setMultiLine (false);
    performersNameEditor->setReturnKeyStartsNewLine (false);
    performersNameEditor->setReadOnly (false);
    performersNameEditor->setScrollbarsShown (true);
    performersNameEditor->setCaretVisible (true);
    performersNameEditor->setPopupMenuEnabled (true);
    performersNameEditor->setColour (TextEditor::backgroundColourId, Colour (0xff565454));
    performersNameEditor->setColour (TextEditor::highlightColourId, Colours::black);
    performersNameEditor->setColour (TextEditor::outlineColourId, Colour (0xff565454));
    performersNameEditor->setText (String());

    addAndMakeVisible (instrumentPlayedEditor = new TextEditor ("instrumentPlayedEditor"));
    instrumentPlayedEditor->setMultiLine (false);
    instrumentPlayedEditor->setReturnKeyStartsNewLine (false);
    instrumentPlayedEditor->setReadOnly (false);
    instrumentPlayedEditor->setScrollbarsShown (true);
    instrumentPlayedEditor->setCaretVisible (true);
    instrumentPlayedEditor->setPopupMenuEnabled (true);
    instrumentPlayedEditor->setColour (TextEditor::backgroundColourId, Colour (0xff565454));
    instrumentPlayedEditor->setColour (TextEditor::highlightColourId, Colours::black);
    instrumentPlayedEditor->setColour (TextEditor::outlineColourId, Colour (0xff565454));
    instrumentPlayedEditor->setText (String());

    addAndMakeVisible (generalNotesEditor = new TextEditor ("new text editor"));
    generalNotesEditor->setMultiLine (true);
    generalNotesEditor->setReturnKeyStartsNewLine (true);
    generalNotesEditor->setReadOnly (false);
    generalNotesEditor->setScrollbarsShown (true);
    generalNotesEditor->setCaretVisible (true);
    generalNotesEditor->setPopupMenuEnabled (true);
    generalNotesEditor->setColour (TextEditor::backgroundColourId, Colour (0xff565454));
    generalNotesEditor->setColour (TextEditor::highlightColourId, Colours::black);
    generalNotesEditor->setColour (TextEditor::outlineColourId, Colour (0xff565454));
    generalNotesEditor->setText (String());

    addAndMakeVisible (performersNameLabel = new Label ("performersNameLabel",
                                                        TRANS("Performer\'s Name:")));
    performersNameLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    performersNameLabel->setJustificationType (Justification::centredLeft);
    performersNameLabel->setEditable (false, false, false);
    performersNameLabel->setColour (TextEditor::textColourId, Colours::black);
    performersNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (microphonesUsedEditor = new TextEditor ("microphonesUsedEditor"));
    microphonesUsedEditor->setMultiLine (false);
    microphonesUsedEditor->setReturnKeyStartsNewLine (false);
    microphonesUsedEditor->setReadOnly (false);
    microphonesUsedEditor->setScrollbarsShown (true);
    microphonesUsedEditor->setCaretVisible (true);
    microphonesUsedEditor->setPopupMenuEnabled (true);
    microphonesUsedEditor->setColour (TextEditor::backgroundColourId, Colour (0xff565454));
    microphonesUsedEditor->setColour (TextEditor::highlightColourId, Colours::black);
    microphonesUsedEditor->setColour (TextEditor::outlineColourId, Colour (0xff565454));
    microphonesUsedEditor->setText (String());

    addAndMakeVisible (instrumentPlayedLabel = new Label ("instrumentPlayedLabel",
                                                          TRANS("Instrument Played:")));
    instrumentPlayedLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    instrumentPlayedLabel->setJustificationType (Justification::centredLeft);
    instrumentPlayedLabel->setEditable (false, false, false);
    instrumentPlayedLabel->setColour (TextEditor::textColourId, Colours::black);
    instrumentPlayedLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (microphonesUsedLabel = new Label ("microphonesUsedLabel",
                                                         TRANS("Microphone(s) Used:")));
    microphonesUsedLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    microphonesUsedLabel->setJustificationType (Justification::centredLeft);
    microphonesUsedLabel->setEditable (false, false, false);
    microphonesUsedLabel->setColour (TextEditor::textColourId, Colours::black);
    microphonesUsedLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (generalNotesLabel = new Label ("generalNotesLabel",
                                                      TRANS("General Notes:")));
    generalNotesLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    generalNotesLabel->setJustificationType (Justification::centredLeft);
    generalNotesLabel->setEditable (false, false, false);
    generalNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    generalNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (grabTimeButton = new TextButton ("grabTimeButton"));
    grabTimeButton->setButtonText (TRANS("Grab Playhead Time"));
    grabTimeButton->addListener (this);
    grabTimeButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    addAndMakeVisible (versionNumberLabel = new Label ("versionNumberLabel",
                                                       String()));
    versionNumberLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    versionNumberLabel->setJustificationType (Justification::centredRight);
    versionNumberLabel->setEditable (false, false, false);
    versionNumberLabel->setColour (TextEditor::textColourId, Colours::black);
    versionNumberLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (theLyonsDenSoftware = new Label ("theLyonsDenSoftware",
                                                        TRANS("The Lyons\' Den Software")));
    theLyonsDenSoftware->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    theLyonsDenSoftware->setJustificationType (Justification::centredLeft);
    theLyonsDenSoftware->setEditable (false, false, false);
    theLyonsDenSoftware->setColour (TextEditor::textColourId, Colours::black);
    theLyonsDenSoftware->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (500, 500);


    //[Constructor] You can add your own custom stuff here..

    // Set up text editor font sizes
    fontSize = 20;
    performersNameEditor->setFont(fontSize);
    instrumentPlayedEditor->setFont(fontSize);
    microphonesUsedEditor->setFont(fontSize);
    generalNotesEditor->setFont(fontSize);

    // Set up version number label
    versionNumberLabelString =  ProjectInfo::projectName;
    versionNumberLabelString += " v";
    versionNumberLabelString += ProjectInfo::versionString;
    versionNumberLabel->setText(versionNumberLabelString, dontSendNotification);

    //[/Constructor]
}

TrackNotesAudioProcessorEditor::~TrackNotesAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    trackNotesLabel = nullptr;
    performersNameEditor = nullptr;
    instrumentPlayedEditor = nullptr;
    generalNotesEditor = nullptr;
    performersNameLabel = nullptr;
    microphonesUsedEditor = nullptr;
    instrumentPlayedLabel = nullptr;
    microphonesUsedLabel = nullptr;
    generalNotesLabel = nullptr;
    grabTimeButton = nullptr;
    versionNumberLabel = nullptr;
    theLyonsDenSoftware = nullptr;


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

    g.setColour(Colours::white);
    g.setOpacity(0.2);
    g.drawLine(30, 50, 470, 50, 1);

    //[/UserPaint]
}

void TrackNotesAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    trackNotesLabel->setBounds (0, 0, 500, 50);
    performersNameEditor->setBounds (218, 60, 282, 30);
    instrumentPlayedEditor->setBounds (218, 95, 282, 30);
    generalNotesEditor->setBounds (0, 200, 500, 270);
    performersNameLabel->setBounds (0, 60, 218, 30);
    microphonesUsedEditor->setBounds (218, 130, 282, 30);
    instrumentPlayedLabel->setBounds (0, 95, 218, 30);
    microphonesUsedLabel->setBounds (0, 130, 218, 30);
    generalNotesLabel->setBounds (0, 165, 218, 30);
    grabTimeButton->setBounds (218, 165, 282, 30);
    versionNumberLabel->setBounds (250, 470, 250, 30);
    theLyonsDenSoftware->setBounds (0, 470, 250, 30);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TrackNotesAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == grabTimeButton)
    {
        //[UserButtonCode_grabTimeButton] -- add your button handler code here..

        // Make pointer
        AudioProcessor *audioProcessorPtr = getAudioProcessor();

        // Make struct
        AudioPlayHead::CurrentPositionInfo positionInformation;

        // Pass struct and fill it
        audioProcessorPtr->getPlayHead()->getCurrentPosition(positionInformation);

        // Convert time into minutes and seconds;
        int totalSeconds = positionInformation.timeInSeconds;
        int hours        = totalSeconds / 3600;
        int minutes      = totalSeconds / 60;
        int seconds      = totalSeconds % 60;

        String temp = generalNotesEditor->getText();

        // Format and build timecode
        temp += "\n@ ";

        if(hours < 10)
        {
            temp += "0";
        }

        temp += hours;
        temp += ":";

        if(minutes < 10)
        {
            temp += "0";
        }

        temp += minutes;
        temp += ":";

        if(seconds < 10)
        {
            temp += "0";
        }

        temp += seconds;
        temp += " - ";

        generalNotesEditor->setText(temp);

        // Put editor into focus and then move caret to end,
        // Which is where new timestamp has been inserted
        generalNotesEditor->grabKeyboardFocus();
        generalNotesEditor->moveCaretToEnd();

        //[/UserButtonCode_grabTimeButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
                 fixedSize="1" initialWidth="500" initialHeight="500">
  <BACKGROUND backgroundColour="ff2a2a2a"/>
  <LABEL name="trackNotesLabel" id="92aa8337c9826f3e" memberName="trackNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 500 50" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Track Notes" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="48.700000000000002842" kerning="0" bold="0" italic="0"
         justification="12"/>
  <TEXTEDITOR name="performersNameEditor" id="13c8f94f4dbdbdb0" memberName="performersNameEditor"
              virtualName="" explicitFocusOrder="0" pos="218 60 282 30" bkgcol="ff565454"
              hilitecol="ff000000" outlinecol="ff565454" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="instrumentPlayedEditor" id="271d4ec88d19c39d" memberName="instrumentPlayedEditor"
              virtualName="" explicitFocusOrder="0" pos="218 95 282 30" bkgcol="ff565454"
              hilitecol="ff000000" outlinecol="ff565454" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="769d422c67fe7990" memberName="generalNotesEditor"
              virtualName="" explicitFocusOrder="0" pos="0 200 500 270" bkgcol="ff565454"
              hilitecol="ff000000" outlinecol="ff565454" initialText="" multiline="1"
              retKeyStartsLine="1" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="performersNameLabel" id="aaab96b158ed2434" memberName="performersNameLabel"
         virtualName="" explicitFocusOrder="0" pos="0 60 218 30" edTextCol="ff000000"
         edBkgCol="0" labelText="Performer's Name:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25" kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="microphonesUsedEditor" id="2a589f1f2773c14f" memberName="microphonesUsedEditor"
              virtualName="" explicitFocusOrder="0" pos="218 130 282 30" bkgcol="ff565454"
              hilitecol="ff000000" outlinecol="ff565454" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="instrumentPlayedLabel" id="959979cf5ec73f4b" memberName="instrumentPlayedLabel"
         virtualName="" explicitFocusOrder="0" pos="0 95 218 30" edTextCol="ff000000"
         edBkgCol="0" labelText="Instrument Played:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="microphonesUsedLabel" id="e982a8bc73696a9b" memberName="microphonesUsedLabel"
         virtualName="" explicitFocusOrder="0" pos="0 130 218 30" edTextCol="ff000000"
         edBkgCol="0" labelText="Microphone(s) Used:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="generalNotesLabel" id="358938facaa251fc" memberName="generalNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 165 218 30" edTextCol="ff000000"
         edBkgCol="0" labelText="General Notes:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25" kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="grabTimeButton" id="2d604f6be40451a7" memberName="grabTimeButton"
              virtualName="" explicitFocusOrder="0" pos="218 165 282 30" bgColOff="ff393939"
              buttonText="Grab Playhead Time" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="versionNumberLabel" id="3348cbd74595514b" memberName="versionNumberLabel"
         virtualName="" explicitFocusOrder="0" pos="250 470 250 30" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="34"/>
  <LABEL name="theLyonsDenSoftware" id="d0cfddad51f6f3" memberName="theLyonsDenSoftware"
         virtualName="" explicitFocusOrder="0" pos="0 470 250 30" edTextCol="ff000000"
         edBkgCol="0" labelText="The Lyons' Den Software" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
