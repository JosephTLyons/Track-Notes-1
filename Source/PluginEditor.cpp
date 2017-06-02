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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
#include "ImageWindow.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TrackNotesAudioProcessorEditor::TrackNotesAudioProcessorEditor (TrackNotesAudioProcessor &p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..

    // Link image pointer in editor class with image holder in processor class
    imageOnePtr        = &p.imageOne;
    imageTwoPtr        = &p.imageTwo;
    imageOnePathPtr    = &p.imageOnePath;
    imageTwoPathPtr    = &p.imageTwoPath;
    imageOneMissingPtr = &p.imageOneMissing;
    imageTwoMissingPtr = &p.imageTwoMissing;

    // Point TextEditors Ptrs of editor class to actual GUI TextEditors in processor class
    addAndMakeVisible (performersNameEditorPtr = &p.performersNameEditor);
    performersNameEditorPtr->setMultiLine (false);
    performersNameEditorPtr->setReturnKeyStartsNewLine (false);
    performersNameEditorPtr->setReadOnly (false);
    performersNameEditorPtr->setScrollbarsShown (true);
    performersNameEditorPtr->setCaretVisible (true);
    performersNameEditorPtr->setPopupMenuEnabled (true);
    performersNameEditorPtr->setColour (TextEditor::backgroundColourId, Colour (0xff565454));
    performersNameEditorPtr->setColour (TextEditor::highlightColourId, Colours::black);
    performersNameEditorPtr->setColour (TextEditor::outlineColourId, Colour (0xff565454));

    addAndMakeVisible (instrumentPlayedEditorPtr = &p.instrumentPlayedEditor);
    instrumentPlayedEditorPtr->setMultiLine (false);
    instrumentPlayedEditorPtr->setReturnKeyStartsNewLine (false);
    instrumentPlayedEditorPtr->setReadOnly (false);
    instrumentPlayedEditorPtr->setScrollbarsShown (true);
    instrumentPlayedEditorPtr->setCaretVisible (true);
    instrumentPlayedEditorPtr->setPopupMenuEnabled (true);
    instrumentPlayedEditorPtr->setColour (TextEditor::backgroundColourId, Colour (0xff565454));
    instrumentPlayedEditorPtr->setColour (TextEditor::highlightColourId, Colours::black);
    instrumentPlayedEditorPtr->setColour (TextEditor::outlineColourId, Colour (0xff565454));

    addAndMakeVisible (microphonesUsedEditorPtr = &p.microphonesUsedEditor);
    microphonesUsedEditorPtr->setMultiLine (false);
    microphonesUsedEditorPtr->setReturnKeyStartsNewLine (false);
    microphonesUsedEditorPtr->setReadOnly (false);
    microphonesUsedEditorPtr->setScrollbarsShown (true);
    microphonesUsedEditorPtr->setCaretVisible (true);
    microphonesUsedEditorPtr->setPopupMenuEnabled (true);
    microphonesUsedEditorPtr->setColour (TextEditor::backgroundColourId, Colour (0xff565454));
    microphonesUsedEditorPtr->setColour (TextEditor::highlightColourId, Colours::black);
    microphonesUsedEditorPtr->setColour (TextEditor::outlineColourId, Colour (0xff565454));

    addAndMakeVisible (timestampedNotesEditorPtr = &p.timestampedNotesEditor);
    timestampedNotesEditorPtr->setMultiLine (true);
    timestampedNotesEditorPtr->setReturnKeyStartsNewLine (true);
    timestampedNotesEditorPtr->setReadOnly (false);
    timestampedNotesEditorPtr->setScrollbarsShown (true);
    timestampedNotesEditorPtr->setCaretVisible (true);
    timestampedNotesEditorPtr->setPopupMenuEnabled (true);
    timestampedNotesEditorPtr->setColour (TextEditor::backgroundColourId, Colour (0xff565454));
    timestampedNotesEditorPtr->setColour (TextEditor::highlightColourId, Colours::black);
    timestampedNotesEditorPtr->setColour (TextEditor::outlineColourId, Colour (0xff565454));

    addAndMakeVisible (generalNotesEditorPtr = &p.generalNotesEditor);
    generalNotesEditorPtr->setMultiLine (true);
    generalNotesEditorPtr->setReturnKeyStartsNewLine (true);
    generalNotesEditorPtr->setReadOnly (false);
    generalNotesEditorPtr->setScrollbarsShown (true);
    generalNotesEditorPtr->setCaretVisible (true);
    generalNotesEditorPtr->setPopupMenuEnabled (true);
    generalNotesEditorPtr->setColour (TextEditor::backgroundColourId, Colour (0xff565454));
    generalNotesEditorPtr->setColour (TextEditor::highlightColourId, Colours::black);
    generalNotesEditorPtr->setColour (TextEditor::outlineColourId, Colour (0xff565454));

    // Set up text editor font sizes
    fontSize = 20;
    performersNameEditorPtr->setFont(fontSize);
    instrumentPlayedEditorPtr->setFont(fontSize);
    microphonesUsedEditorPtr->setFont(fontSize);
    timestampedNotesEditorPtr->setFont(fontSize);
    generalNotesEditorPtr->setFont(fontSize);

    // Update TextEditors after font size change
    performersNameEditorPtr->setText(performersNameEditorPtr->getText());
    instrumentPlayedEditorPtr->setText(instrumentPlayedEditorPtr->getText());
    microphonesUsedEditorPtr->setText(microphonesUsedEditorPtr->getText());
    timestampedNotesEditorPtr->setText(timestampedNotesEditorPtr->getText());
    generalNotesEditorPtr->setText(generalNotesEditorPtr->getText());

    //[/Constructor_pre]

    addAndMakeVisible (trackNotesLabel = new Label ("trackNotesLabel",
                                                    TRANS("Track Notes")));
    trackNotesLabel->setFont (Font ("Arial", 48.70f, Font::plain).withTypefaceStyle ("Regular"));
    trackNotesLabel->setJustificationType (Justification::centredTop);
    trackNotesLabel->setEditable (false, false, false);
    trackNotesLabel->setColour (Label::textColourId, Colours::white);
    trackNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    trackNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (performersNameLabel = new Label ("performersNameLabel",
                                                        TRANS("Performer\'s Name:")));
    performersNameLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    performersNameLabel->setJustificationType (Justification::centredLeft);
    performersNameLabel->setEditable (false, false, false);
    performersNameLabel->setColour (TextEditor::textColourId, Colours::black);
    performersNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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

    addAndMakeVisible (timestampedNotesLabel = new Label ("timestampedNotesLabel",
                                                          TRANS("Timestamped Notes:")));
    timestampedNotesLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    timestampedNotesLabel->setJustificationType (Justification::centredLeft);
    timestampedNotesLabel->setEditable (false, false, false);
    timestampedNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    timestampedNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (insertTimeStampButton = new TextButton ("insertTimeStampButton"));
    insertTimeStampButton->setButtonText (TRANS("Insert Timestamp"));
    insertTimeStampButton->addListener (this);
    insertTimeStampButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

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

    addAndMakeVisible (generalNotesLabel = new Label ("generalNotesLabel",
                                                      TRANS("General Notes:")));
    generalNotesLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    generalNotesLabel->setJustificationType (Justification::centred);
    generalNotesLabel->setEditable (false, false, false);
    generalNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    generalNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (displayImageOneButton = new TextButton ("displayImageOneButton"));
    displayImageOneButton->setButtonText (TRANS("Image One"));
    displayImageOneButton->addListener (this);
    displayImageOneButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    addAndMakeVisible (displayImageTwoButton = new TextButton ("displayImageTwoButton"));
    displayImageTwoButton->setButtonText (TRANS("Image Two"));
    displayImageTwoButton->addListener (this);
    displayImageTwoButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    addAndMakeVisible (loadImageOneButton = new TextButton ("loadImageOneButton"));
    loadImageOneButton->setButtonText (TRANS("Load"));
    loadImageOneButton->addListener (this);
    loadImageOneButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    addAndMakeVisible (loadImageTwoButton = new TextButton ("loadImageTwoButton"));
    loadImageTwoButton->setButtonText (TRANS("Load"));
    loadImageTwoButton->addListener (this);
    loadImageTwoButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    addAndMakeVisible (removeImageOneButton = new TextButton ("removeImageOneButton"));
    removeImageOneButton->setButtonText (TRANS("Remove"));
    removeImageOneButton->addListener (this);
    removeImageOneButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    addAndMakeVisible (removeImageTwoButton = new TextButton ("removeImageTwoButton"));
    removeImageTwoButton->setButtonText (TRANS("Remove"));
    removeImageTwoButton->addListener (this);
    removeImageTwoButton->setColour (TextButton::buttonColourId, Colour (0xff393939));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (500, 590);


    //[Constructor] You can add your own custom stuff here..

    // Set up version number label
    versionNumberLabelString =  ProjectInfo::projectName;
    versionNumberLabelString += " v";
    versionNumberLabelString += ProjectInfo::versionString;
    versionNumberLabel->setText(versionNumberLabelString, dontSendNotification);

    // Get array of fonts on user's system
    Font::findFonts(usersFontsResults);

    //[/Constructor]
}

TrackNotesAudioProcessorEditor::~TrackNotesAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

    performersNameEditorPtr = nullptr;
    instrumentPlayedEditorPtr = nullptr;
    microphonesUsedEditorPtr = nullptr;
    timestampedNotesEditorPtr = nullptr;
    generalNotesEditorPtr = nullptr;

    // Normal C++ Pointers
    delete basicWindowImageOnePtr;
    delete basicWindowImageTwoPtr;
    basicWindowImageOnePtr = nullptr;
    basicWindowImageTwoPtr = nullptr;

    // Dont delete these pointers because they're objects are owned and used by processor class
    imageOnePathPtr = nullptr;
    imageTwoPathPtr = nullptr;
    imageOneMissingPtr = nullptr;
    imageTwoMissingPtr = nullptr;

    //[/Destructor_pre]

    trackNotesLabel = nullptr;
    performersNameLabel = nullptr;
    instrumentPlayedLabel = nullptr;
    microphonesUsedLabel = nullptr;
    timestampedNotesLabel = nullptr;
    insertTimeStampButton = nullptr;
    versionNumberLabel = nullptr;
    theLyonsDenSoftware = nullptr;
    generalNotesLabel = nullptr;
    displayImageOneButton = nullptr;
    displayImageTwoButton = nullptr;
    loadImageOneButton = nullptr;
    loadImageTwoButton = nullptr;
    removeImageOneButton = nullptr;
    removeImageTwoButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    //[/Destructor]
}

//==============================================================================
void TrackNotesAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff373737));

    //[UserPaint] Add your own custom painting code here..

    g.setColour(Colours::white);
    g.setOpacity(0.3);
    g.drawLine(30, 50, 470, 50, 1);

    //[/UserPaint]
}

void TrackNotesAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..

    performersNameEditorPtr->setBounds (218, 60, 282, 30);
    instrumentPlayedEditorPtr->setBounds (218, 95, 282, 30);
    microphonesUsedEditorPtr->setBounds (218, 130, 282, 30);
    timestampedNotesEditorPtr->setBounds (0, 200, 500, 150);
    generalNotesEditorPtr->setBounds (0, 390, 500, 150);

    //[/UserPreResize]

    trackNotesLabel->setBounds (0, 0, 500, 50);
    performersNameLabel->setBounds (0, 60, 218, 30);
    instrumentPlayedLabel->setBounds (0, 95, 218, 30);
    microphonesUsedLabel->setBounds (0, 130, 218, 30);
    timestampedNotesLabel->setBounds (0, 165, 218, 30);
    insertTimeStampButton->setBounds (218, 165, 282, 30);
    versionNumberLabel->setBounds (250, 560, 250, 30);
    theLyonsDenSoftware->setBounds (0, 560, 250, 30);
    generalNotesLabel->setBounds (0, 355, 500, 30);
    displayImageOneButton->setBounds (50, 540, 150, 20);
    displayImageTwoButton->setBounds (300, 540, 150, 20);
    loadImageOneButton->setBounds (0, 540, 50, 20);
    loadImageTwoButton->setBounds (250, 540, 50, 20);
    removeImageOneButton->setBounds (200, 540, 50, 20);
    removeImageTwoButton->setBounds (450, 540, 50, 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TrackNotesAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == insertTimeStampButton)
    {
        //[UserButtonCode_insertTimeStampButton] -- add your button handler code here..

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

        String temp = timestampedNotesEditorPtr->getText();

        // FORMAT AND BUILD TIMECODE
        // Don't insert newline on first timestamp
        if(!timestampedNotesEditorPtr->isEmpty())
        {
            temp += "\n";
        }

        temp += "@ ";

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

        timestampedNotesEditorPtr->setText(temp);

        // Put editor into focus and then move caret to end,
        // Which is where new timestamp has been inserted
        timestampedNotesEditorPtr->grabKeyboardFocus();
        timestampedNotesEditorPtr->moveCaretToEnd();

        //[/UserButtonCode_insertTimeStampButton]
    }
    else if (buttonThatWasClicked == displayImageOneButton)
    {
        //[UserButtonCode_displayImageOneButton] -- add your button handler code here..

        // Display error if images are missing
        if(*imageOneMissingPtr)
        {
            showErrorLoadingImageWindow(imageOnePathPtr->getFullPathName());
        }

        else
        {
            createImageWindow(basicWindowImageOnePtr, *imageOnePtr, *imageOnePathPtr);
        }

        //[/UserButtonCode_displayImageOneButton]
    }
    else if (buttonThatWasClicked == displayImageTwoButton)
    {
        //[UserButtonCode_displayImageTwoButton] -- add your button handler code here..

        // Display error if images are missing
        if(*imageTwoMissingPtr)
        {
            showErrorLoadingImageWindow(imageTwoPathPtr->getFullPathName());
        }

        else
        {
            createImageWindow(basicWindowImageTwoPtr, *imageTwoPtr, *imageTwoPathPtr);
        }

        //[/UserButtonCode_displayImageTwoButton]
    }
    else if (buttonThatWasClicked == loadImageOneButton)
    {
        //[UserButtonCode_loadImageOneButton] -- add your button handler code here..

        loadImage(*imageOnePtr, *imageOnePathPtr);

        if(!imageOnePtr->isNull())
        {
            *imageOneMissingPtr = false;
            
            // Logic is, if window is open, trigger display button twice on a newly loaded image
            // This will keep the window open and reload the new image
            // If the window is closed, only trigger display button once, which also opens it
            if(basicWindowImageOnePtr != nullptr)
            {
                displayImageOneButton->triggerClick();
            }
            
            displayImageOneButton->triggerClick();
        }

        //[/UserButtonCode_loadImageOneButton]
    }
    else if (buttonThatWasClicked == loadImageTwoButton)
    {
        //[UserButtonCode_loadImageTwoButton] -- add your button handler code here..

        loadImage(*imageTwoPtr, *imageTwoPathPtr);

        if(!imageTwoPtr->isNull())
        {
            *imageTwoMissingPtr = false;
            
            // Logic is, if window is open, trigger display button twice on a newly loaded image
            // This will keep the window open and reload the new image
            // If the window is closed, only trigger display button once, which also opens it
            if(basicWindowImageTwoPtr != nullptr)
            {
                displayImageTwoButton->triggerClick();
            }
            
            displayImageTwoButton->triggerClick();
        }

        //[/UserButtonCode_loadImageTwoButton]
    }
    else if (buttonThatWasClicked == removeImageOneButton)
    {
        //[UserButtonCode_removeImageOneButton] -- add your button handler code here..
        
        Image blankImage;
        
        *imageOnePathPtr = "";
        *imageOnePtr     = blankImage;
        
        //[/UserButtonCode_removeImageOneButton]
    }
    else if (buttonThatWasClicked == removeImageTwoButton)
    {
        //[UserButtonCode_removeImageTwoButton] -- add your button handler code here..
        Image blankImage;
        
        *imageTwoPathPtr = "";
        *imageTwoPtr     = blankImage;
        
        //[/UserButtonCode_removeImageTwoButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TrackNotesAudioProcessorEditor::loadImage(Image &image, File &imagePath)
{
    FileChooser fileChooser ("Choose an image...",
                             File::getSpecialLocation(File::userHomeDirectory),
                             "*",
                             true);


    // Launch browser window and only if they pick a image do we set the image path
    if(fileChooser.browseForFileToOpen())
    {
        // Set imagePath
        imagePath = fileChooser.getResult();

        // Get image
        image = ImageCache::getFromFile(fileChooser.getResult());
    }
}

void TrackNotesAudioProcessorEditor::createImageWindow(SafePointer<BasicWindow> &basicWindowPtr,
                                                       Image &image, File &imagePath)
{
    // Don't allow multiple copies of this window to be made
    if(basicWindowPtr == NULL)
    {
        basicWindowPtr = new BasicWindow(imagePath.getFileNameWithoutExtension(), Colours::grey, DocumentWindow::allButtons);

        basicWindowPtr->setUsingNativeTitleBar(true);
        basicWindowPtr->setContentOwned(new ImageWindow(image), true);
        basicWindowPtr->setAlwaysOnTop(true);

        if(!image.isNull())
        {
            basicWindowPtr->setSize(image.getWidth(), image.getHeight());
            basicWindowPtr->setTopLeftPosition(0, 0);
        }

        else
        {
            basicWindowPtr->setSize(basicWindowPtr->getWidth(), basicWindowPtr->getHeight());
        }

        basicWindowPtr->setVisible(true);
    }

    // If window is open already and display button is clicked again, window will be deleted
    else
    {
        delete basicWindowPtr;
    }
}
void TrackNotesAudioProcessorEditor::showErrorLoadingImageWindow(const String &path)
{
    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                 "Image Missing: ",
                                 path + "\n\nPlease load image again.");
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TrackNotesAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public TextEditorListener"
                 constructorParams="TrackNotesAudioProcessor &amp;p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="500" initialHeight="590">
  <BACKGROUND backgroundColour="ff373737"/>
  <LABEL name="trackNotesLabel" id="92aa8337c9826f3e" memberName="trackNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 500 50" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Track Notes" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="48.700000000000002842" kerning="0" bold="0" italic="0"
         justification="12"/>
  <LABEL name="performersNameLabel" id="aaab96b158ed2434" memberName="performersNameLabel"
         virtualName="" explicitFocusOrder="0" pos="0 60 218 30" edTextCol="ff000000"
         edBkgCol="0" labelText="Performer's Name:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25" kerning="0" bold="0" italic="0" justification="33"/>
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
  <LABEL name="timestampedNotesLabel" id="358938facaa251fc" memberName="timestampedNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 165 218 30" edTextCol="ff000000"
         edBkgCol="0" labelText="Timestamped Notes:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25" kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="insertTimeStampButton" id="2d604f6be40451a7" memberName="insertTimeStampButton"
              virtualName="" explicitFocusOrder="0" pos="218 165 282 30" bgColOff="ff393939"
              buttonText="Insert Timestamp" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="versionNumberLabel" id="3348cbd74595514b" memberName="versionNumberLabel"
         virtualName="" explicitFocusOrder="0" pos="250 560 250 30" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="34"/>
  <LABEL name="theLyonsDenSoftware" id="d0cfddad51f6f3" memberName="theLyonsDenSoftware"
         virtualName="" explicitFocusOrder="0" pos="0 560 250 30" edTextCol="ff000000"
         edBkgCol="0" labelText="The Lyons' Den Software" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="generalNotesLabel" id="c170b98fbe39594f" memberName="generalNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 355 500 30" edTextCol="ff000000"
         edBkgCol="0" labelText="General Notes:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25" kerning="0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="displayImageOneButton" id="a8b273a63654dd33" memberName="displayImageOneButton"
              virtualName="" explicitFocusOrder="0" pos="50 540 150 20" bgColOff="ff393939"
              buttonText="Image One" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="displayImageTwoButton" id="49cbe3c0cc417d1e" memberName="displayImageTwoButton"
              virtualName="" explicitFocusOrder="0" pos="300 540 150 20" bgColOff="ff393939"
              buttonText="Image Two" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="loadImageOneButton" id="b3cf03e99303b480" memberName="loadImageOneButton"
              virtualName="" explicitFocusOrder="0" pos="0 540 50 20" bgColOff="ff393939"
              buttonText="Load" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="loadImageTwoButton" id="c76f47c5a5ad9793" memberName="loadImageTwoButton"
              virtualName="" explicitFocusOrder="0" pos="250 540 50 20" bgColOff="ff393939"
              buttonText="Load" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="removeImageOneButton" id="c4e0c098ca1c7a0c" memberName="removeImageOneButton"
              virtualName="" explicitFocusOrder="0" pos="200 540 50 20" bgColOff="ff393939"
              buttonText="Remove" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="removeImageTwoButton" id="6b14eed5f55e2af7" memberName="removeImageTwoButton"
              virtualName="" explicitFocusOrder="0" pos="450 540 50 20" bgColOff="ff393939"
              buttonText="Remove" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
