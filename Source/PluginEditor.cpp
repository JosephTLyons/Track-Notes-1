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
    addAndMakeVisible (performersNameEditorPtr   = &p.performersNameEditor);
    addAndMakeVisible (instrumentPlayedEditorPtr = &p.instrumentPlayedEditor);
    addAndMakeVisible (microphonesUsedEditorPtr  = &p.microphonesUsedEditor);
    addAndMakeVisible (timestampedNotesEditorPtr = &p.timestampedNotesEditor);
    addAndMakeVisible (generalNotesEditorPtr     = &p.generalNotesEditor);

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

    addAndMakeVisible (theLyonsDenSoftwareLabel = new Label ("theLyonsDenSoftwareLabel",
                                                             String()));
    theLyonsDenSoftwareLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    theLyonsDenSoftwareLabel->setJustificationType (Justification::centredLeft);
    theLyonsDenSoftwareLabel->setEditable (false, false, false);
    theLyonsDenSoftwareLabel->setColour (TextEditor::textColourId, Colours::black);
    theLyonsDenSoftwareLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (generalNotesLabel = new Label ("generalNotesLabel",
                                                      TRANS("General Notes:")));
    generalNotesLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    generalNotesLabel->setJustificationType (Justification::centred);
    generalNotesLabel->setEditable (false, false, false);
    generalNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    generalNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (displayImageOneButton = new TextButton ("displayImageOneButton"));
    displayImageOneButton->setButtonText (TRANS("Empty"));
    displayImageOneButton->addListener (this);
    displayImageOneButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    addAndMakeVisible (displayImageTwoButton = new TextButton ("displayImageTwoButton"));
    displayImageTwoButton->setButtonText (TRANS("Empty"));
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

    addAndMakeVisible (imagesLabel = new Label ("imagesLabel",
                                                TRANS("Images:")));
    imagesLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    imagesLabel->setJustificationType (Justification::centred);
    imagesLabel->setEditable (false, false, false);
    imagesLabel->setColour (TextEditor::textColourId, Colours::black);
    imagesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (exportMediaButton = new TextButton ("exportMediaButton"));
    exportMediaButton->setButtonText (TRANS("Export Media"));
    exportMediaButton->addListener (this);
    exportMediaButton->setColour (TextButton::buttonColourId, Colour (0xff393939));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (500, 635);


    //[Constructor] You can add your own custom stuff here..

    // Reset button names to image name (this doesn't work in standalone
    // since constructor isn't called when standalone loads, because plugin is already open
    if(!imageOnePathPtr->getFullPathName().isEmpty())
    {
        displayImageOneButton->setButtonText(imageOnePathPtr->getFileNameWithoutExtension());
    }

    if(!imageTwoPathPtr->getFullPathName().isEmpty())
    {
        displayImageTwoButton->setButtonText(imageTwoPathPtr->getFileNameWithoutExtension());
    }

    // Set up version number label
    versionNumberString =  " - ";
    versionNumberString +=  ProjectInfo::projectName;
    versionNumberString += " v";
    versionNumberString += ProjectInfo::versionString;
    theLyonsDenSoftwareLabel->setText("The Lyons' Den Software" + versionNumberString, dontSendNotification);

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
    theLyonsDenSoftwareLabel = nullptr;
    generalNotesLabel = nullptr;
    displayImageOneButton = nullptr;
    displayImageTwoButton = nullptr;
    loadImageOneButton = nullptr;
    loadImageTwoButton = nullptr;
    removeImageOneButton = nullptr;
    removeImageTwoButton = nullptr;
    imagesLabel = nullptr;
    exportMediaButton = nullptr;


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
    theLyonsDenSoftwareLabel->setBounds (0, 605, 300, 30);
    generalNotesLabel->setBounds (0, 355, 500, 30);
    displayImageOneButton->setBounds (50, 580, 150, 20);
    displayImageTwoButton->setBounds (300, 580, 150, 20);
    loadImageOneButton->setBounds (0, 580, 50, 20);
    loadImageTwoButton->setBounds (250, 580, 50, 20);
    removeImageOneButton->setBounds (200, 580, 50, 20);
    removeImageTwoButton->setBounds (450, 580, 50, 20);
    imagesLabel->setBounds (0, 545, 500, 30);
    exportMediaButton->setBounds (300, 610, 200, 20);
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
        
        int hours, minutes, seconds;
        
        fillTimeIntervalValues(hours, minutes, seconds);

        // Copy current text from the timestamped notes editor
        String tempTextEditorString = timestampedNotesEditorPtr->getText();

        tempTextEditorString += formatAndBuildTimecode(hours, minutes, seconds);

        timestampedNotesEditorPtr->setText(tempTextEditorString);

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
            // Set this bool to false so that error message won't show a second time
            *imageOneMissingPtr = false;

            // Set displayImage button text to file name
            displayImageOneButton->setButtonText(imageOnePathPtr->getFileNameWithoutExtension());

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
            // Set this bool to false so that error message won't show a second time
            *imageTwoMissingPtr = false;

            // Set displayImage button text to file name
            displayImageTwoButton->setButtonText(imageTwoPathPtr->getFileNameWithoutExtension());

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
        displayImageOneButton->setButtonText("Empty");

        //[/UserButtonCode_removeImageOneButton]
    }
    else if (buttonThatWasClicked == removeImageTwoButton)
    {
        //[UserButtonCode_removeImageTwoButton] -- add your button handler code here..
        Image blankImage;

        *imageTwoPathPtr = "";
        *imageTwoPtr     = blankImage;
        displayImageTwoButton->setButtonText("Empty");

        //[/UserButtonCode_removeImageTwoButton]
    }
    else if (buttonThatWasClicked == exportMediaButton)
    {
        //[UserButtonCode_exportMediaButton] -- add your button handler code here..

        FileChooser fileChooser ("Export Text",
                                 File::getSpecialLocation(File::userHomeDirectory),
                                 "*",
                                 true);


        if(fileChooser.browseForFileToSave(true))
        {
            // Create folder
            File pathToSaveFolder(fileChooser.getResult());
            pathToSaveFolder.createDirectory();

            // Create path to .txt file with same name as the save folder
            File pathToSaveTextFileTo = pathToSaveFolder;
            pathToSaveTextFileTo = pathToSaveTextFileTo.getFullPathName() + "/" +
            pathToSaveTextFileTo.getFileName() + ".txt";

            // Save all text
            pathToSaveTextFileTo.appendText("Performer's Name: ");
            pathToSaveTextFileTo.appendText(performersNameEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText("Instrument Played: ");
            pathToSaveTextFileTo.appendText(instrumentPlayedEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText("Microphone(s) Used: ");
            pathToSaveTextFileTo.appendText(microphonesUsedEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText("Timestamped Notes: \n");
            pathToSaveTextFileTo.appendText(timestampedNotesEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText("General Notes: \n");
            pathToSaveTextFileTo.appendText(generalNotesEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText("Image One: ");
            pathToSaveTextFileTo.appendText(imageOnePathPtr->getFileName() + "\n\n");

            pathToSaveTextFileTo.appendText("Image Two: ");
            pathToSaveTextFileTo.appendText(imageTwoPathPtr->getFileName());

            // Copy images into folder
            imageOnePathPtr->copyFileTo(pathToSaveFolder.getFullPathName() + "/" + imageOnePathPtr->getFileName());
            imageTwoPathPtr->copyFileTo(pathToSaveFolder.getFullPathName() + "/" + imageTwoPathPtr->getFileName());
        }

        //[/UserButtonCode_exportMediaButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TrackNotesAudioProcessorEditor::loadImage(Image &image, File &imagePath)
{
    FileChooser fileChooser ("Export all Text",
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

void TrackNotesAudioProcessorEditor::fillTimeIntervalValues(int &hours, int &minutes, int &seconds)
{
    // Make struct
    AudioPlayHead::CurrentPositionInfo positionInformation;
    
    // Pass struct and fill it
    getAudioProcessor()->getPlayHead()->getCurrentPosition(positionInformation);
    
    // Convert time into hours, minutes, and seconds
    int totalSeconds = positionInformation.timeInSeconds;
    
    const int secondsPerHour   = 3600;
    const int secondsPerMinute = 60;
    
    // Calculate hours
    hours = totalSeconds / secondsPerHour;
    
    // Deduct hours (in seconds) from total
    totalSeconds -= (hours * secondsPerHour);
    
    // Calculate minutes
    minutes = totalSeconds / secondsPerMinute;
    
    // Deduct minutes (in seconds) from total
    totalSeconds -= (minutes * secondsPerMinute);
    
    // Leftover is seconds
    seconds = totalSeconds;
}

String TrackNotesAudioProcessorEditor::formatAndBuildTimecode(const int &hours,
                                                              const int &minutes,
                                                              const int &seconds)
{
    String tempString;

    // Don't insert newline on first timestamp
    if(!timestampedNotesEditorPtr->isEmpty())
    {
        tempString += "\n";
    }

    tempString += "@ ";
    tempString += formatTimeInterval(hours);
    tempString += ":";
    tempString += formatTimeInterval(minutes);
    tempString += ":";
    tempString += formatTimeInterval(seconds);
    tempString += " - ";

    return tempString;
}

String TrackNotesAudioProcessorEditor::formatTimeInterval(const int &timeInterval)
{
    String tempString;

    if(timeInterval < 10)
    {
        tempString += "0";
    }

    tempString += timeInterval;

    return tempString;
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
                 fixedSize="1" initialWidth="500" initialHeight="635">
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
  <LABEL name="theLyonsDenSoftwareLabel" id="d0cfddad51f6f3" memberName="theLyonsDenSoftwareLabel"
         virtualName="" explicitFocusOrder="0" pos="0 605 300 30" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="generalNotesLabel" id="c170b98fbe39594f" memberName="generalNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 355 500 30" edTextCol="ff000000"
         edBkgCol="0" labelText="General Notes:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25" kerning="0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="displayImageOneButton" id="a8b273a63654dd33" memberName="displayImageOneButton"
              virtualName="" explicitFocusOrder="0" pos="50 580 150 20" bgColOff="ff393939"
              buttonText="Empty" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="displayImageTwoButton" id="49cbe3c0cc417d1e" memberName="displayImageTwoButton"
              virtualName="" explicitFocusOrder="0" pos="300 580 150 20" bgColOff="ff393939"
              buttonText="Empty" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="loadImageOneButton" id="b3cf03e99303b480" memberName="loadImageOneButton"
              virtualName="" explicitFocusOrder="0" pos="0 580 50 20" bgColOff="ff393939"
              buttonText="Load" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="loadImageTwoButton" id="c76f47c5a5ad9793" memberName="loadImageTwoButton"
              virtualName="" explicitFocusOrder="0" pos="250 580 50 20" bgColOff="ff393939"
              buttonText="Load" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="removeImageOneButton" id="c4e0c098ca1c7a0c" memberName="removeImageOneButton"
              virtualName="" explicitFocusOrder="0" pos="200 580 50 20" bgColOff="ff393939"
              buttonText="Remove" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="removeImageTwoButton" id="6b14eed5f55e2af7" memberName="removeImageTwoButton"
              virtualName="" explicitFocusOrder="0" pos="450 580 50 20" bgColOff="ff393939"
              buttonText="Remove" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="imagesLabel" id="3f296d22943adc31" memberName="imagesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 545 500 30" edTextCol="ff000000"
         edBkgCol="0" labelText="Images:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Arial" fontsize="25" kerning="0"
         bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="exportMediaButton" id="ab681e4541856006" memberName="exportMediaButton"
              virtualName="" explicitFocusOrder="0" pos="300 610 200 20" bgColOff="ff393939"
              buttonText="Export Media" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
