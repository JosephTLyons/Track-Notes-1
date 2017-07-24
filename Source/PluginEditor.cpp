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

    pluginIsRunningInDemoMode = false;

    #if DEMO_MODE
        pluginIsRunningInDemoMode = true;
    #endif

    // Link image pointer in editor class with image holder in processor class
    imageOnePtr        = &processor.imageOne;
    imageTwoPtr        = &processor.imageTwo;
    imageOnePathPtr    = &processor.imageOnePath;
    imageTwoPathPtr    = &processor.imageTwoPath;
    imageOneMissingPtr = &processor.imageOneMissing;
    imageTwoMissingPtr = &processor.imageTwoMissing;
    stealthIsActivated = &processor.stealthIsActivated;

    createImagePreview(true);
    createImagePreview(false);

    // Link playhead info struct
    positionInformationPtr = &processor.positionInformation;

    // Point TextEditors Ptrs of editor class to actual GUI TextEditors in processor class
    addAndMakeVisible (performersNameEditorPtr   = &processor.performersNameEditor);
    addAndMakeVisible (instrumentPlayedEditorPtr = &processor.instrumentPlayedEditor);
    addAndMakeVisible (microphonesUsedEditorPtr  = &processor.microphonesUsedEditor);
    addAndMakeVisible (timestampedNotesEditorPtr = &processor.timestampedNotesEditor);
    addAndMakeVisible (generalNotesEditorPtr     = &processor.generalNotesEditor);

    // Link labels
    addAndMakeVisible (performersNameLabelPtr   = &processor.performersNameLabel);
    addAndMakeVisible (instrumentPlayedLabelPtr = &processor.instrumentPlayedLabel);
    addAndMakeVisible (microphonesUsedLabelPtr  = &processor.microphonesUsedLabel);

    //[/Constructor_pre]

    addAndMakeVisible (trackNotesLabel = new Label ("trackNotesLabel",
                                                    TRANS("Track Notes")));
    trackNotesLabel->setFont (Font ("Arial", 48.70f, Font::plain).withTypefaceStyle ("Regular"));
    trackNotesLabel->setJustificationType (Justification::centredTop);
    trackNotesLabel->setEditable (false, false, false);
    trackNotesLabel->setColour (Label::textColourId, Colours::white);
    trackNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    trackNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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
    exportMediaButton->setColour (TextButton::textColourOnId, Colours::white);

    addAndMakeVisible (stealthModeToggle = new TextButton ("stealthModeToggle"));
    stealthModeToggle->setTooltip (TRANS("This curious little button activates \"Stealth Mode.\"  We may not always want to show the clients the notes we write about their performances, so when this button is engaged, Timestamped Notes and General Notes are hidden."));
    stealthModeToggle->setButtonText (String());
    stealthModeToggle->addListener (this);
    stealthModeToggle->setColour (TextButton::buttonColourId, Colour (0xff393939));
    stealthModeToggle->setColour (TextButton::buttonOnColourId, Colours::white);
    stealthModeToggle->setColour (TextButton::textColourOnId, Colours::black);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1005, 620);


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

    setupVersionNumberlabel();

    // Get array of fonts on user's system
    Font::findFonts(usersFontsResults);

    // Set up labels
    performersNameLabelPtr->setEditable(true);
    instrumentPlayedLabelPtr->setEditable(true);
    microphonesUsedLabelPtr->setEditable(true);

    if(performersNameLabelPtr->getText().isEmpty())
    {
        performersNameLabelPtr->setText("Performer's Name:", dontSendNotification);
    }

    if(instrumentPlayedLabelPtr->getText().isEmpty())
    {
        instrumentPlayedLabelPtr->setText("Instrument Played:", dontSendNotification);
    }

    if(microphonesUsedLabelPtr->getText().isEmpty())
    {
        microphonesUsedLabelPtr->setText("Microphone(s) Used:", dontSendNotification);
    }

    // Set up static text buttons
    staticTextSizeButton = new StaticTextSizeButton;
    loadImageOneButton->setLookAndFeel(staticTextSizeButton);
    displayImageOneButton->setLookAndFeel(staticTextSizeButton);
    removeImageOneButton->setLookAndFeel(staticTextSizeButton);
    loadImageTwoButton->setLookAndFeel(staticTextSizeButton);
    displayImageTwoButton->setLookAndFeel(staticTextSizeButton);
    removeImageTwoButton->setLookAndFeel(staticTextSizeButton);

    // Set up stealth mode
    // Turn button into a toggle button
    stealthModeToggle->setClickingTogglesState(true);
    if(*stealthIsActivated)
    {
        activateStealthMode(*timestampedNotesEditorPtr);
        activateStealthMode(*generalNotesEditorPtr);
        stealthModeToggle->setToggleState(true, dontSendNotification);
    }

    // Add mouse listener to this to create dynamic text in button
    stealthModeToggle->addMouseListener(this, true);

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

    performersNameLabelPtr = nullptr;
    instrumentPlayedLabelPtr = nullptr;
    microphonesUsedLabelPtr = nullptr;

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
    stealthModeToggle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    //[/Destructor]
}

//==============================================================================
void TrackNotesAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff373737));

    {
        int x = 510, y = 130, width = 245, height = 245;
        Colour fillColour = Colour (0xff565454);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 760, y = 130, width = 245, height = 245;
        Colour fillColour = Colour (0xff565454);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..

    g.setColour(Colours::white);
    g.setOpacity(0.3);
    g.drawLine(30, 50, 975, 50, 1);



    //[/UserPaint]
}

void TrackNotesAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..

    performersNameEditorPtr->setBounds (218, 60, 282, 30);
    instrumentPlayedEditorPtr->setBounds (218, 95, 282, 30);
    microphonesUsedEditorPtr->setBounds (218, 130, 282, 30);
    timestampedNotesEditorPtr->setBounds (0, 200, 500, 175);
    generalNotesEditorPtr->setBounds (0, 415, 1010, 175);

    performersNameLabelPtr->setBounds (0, 60, 218, 30);
    instrumentPlayedLabelPtr->setBounds (0, 95, 218, 30);
    microphonesUsedLabelPtr->setBounds (0, 130, 218, 30);

    //[/UserPreResize]

    trackNotesLabel->setBounds (0, 0, 1005, 50);
    timestampedNotesLabel->setBounds (0, 165, 218, 30);
    insertTimeStampButton->setBounds (218, 165, 282, 30);
    theLyonsDenSoftwareLabel->setBounds (0, 590, 500, 30);
    generalNotesLabel->setBounds (0, 380, 1005, 30);
    displayImageOneButton->setBounds (560, 95, 145, 30);
    displayImageTwoButton->setBounds (810, 95, 145, 30);
    loadImageOneButton->setBounds (510, 95, 50, 30);
    loadImageTwoButton->setBounds (760, 95, 50, 30);
    removeImageOneButton->setBounds (705, 95, 50, 30);
    removeImageTwoButton->setBounds (955, 95, 50, 30);
    imagesLabel->setBounds (510, 60, 500, 30);
    exportMediaButton->setBounds (805, 595, 200, 20);
    stealthModeToggle->setBounds (752, 595, 48, 20);
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

        loadImage(*imageOnePtr, *imageOnePathPtr, true);

        if(!imageOnePtr->isNull())
        {
            // Set this bool to false so that error message won't show a second time
            *imageOneMissingPtr = false;

            // Set displayImage button text to file name
            displayImageOneButton->setButtonText(imageOnePathPtr->getFileNameWithoutExtension());
        }

        //[/UserButtonCode_loadImageOneButton]
    }
    else if (buttonThatWasClicked == loadImageTwoButton)
    {
        //[UserButtonCode_loadImageTwoButton] -- add your button handler code here..

        loadImage(*imageTwoPtr, *imageTwoPathPtr, false);

        if(!imageTwoPtr->isNull())
        {
            // Set this bool to false so that error message won't show a second time
            *imageTwoMissingPtr = false;

            // Set displayImage button text to file name
            displayImageTwoButton->setButtonText(imageTwoPathPtr->getFileNameWithoutExtension());
        }

        //[/UserButtonCode_loadImageTwoButton]
    }
    else if (buttonThatWasClicked == removeImageOneButton)
    {
        //[UserButtonCode_removeImageOneButton] -- add your button handler code here..

        imagePreviewOne.setVisible(false);

        Image blankImage;
        *imageOnePathPtr = "";
        *imageOnePtr     = blankImage;
        displayImageOneButton->setButtonText("Empty");

        //[/UserButtonCode_removeImageOneButton]
    }
    else if (buttonThatWasClicked == removeImageTwoButton)
    {
        //[UserButtonCode_removeImageTwoButton] -- add your button handler code here..

        imagePreviewTwo.setVisible(false);

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
            // Also, trim text of editors to keep from saving newlines that may be added during stealth mode
            pathToSaveTextFileTo.appendText(performersNameLabelPtr->getText());
            pathToSaveTextFileTo.appendText(" " + performersNameEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText(instrumentPlayedLabelPtr->getText());
            pathToSaveTextFileTo.appendText(" " + instrumentPlayedEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText(microphonesUsedLabelPtr->getText());
            pathToSaveTextFileTo.appendText(" " + microphonesUsedEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText("Timestamped Notes:\n");
            pathToSaveTextFileTo.appendText(timestampedNotesEditorPtr->getText().trim() + "\n\n");

            pathToSaveTextFileTo.appendText("General Notes:\n");
            pathToSaveTextFileTo.appendText(generalNotesEditorPtr->getText().trim() + "\n\n");

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
    else if (buttonThatWasClicked == stealthModeToggle)
    {
        //[UserButtonCode_stealthModeToggle] -- add your button handler code here..

        if(stealthModeToggle->getToggleState())
        {
            activateStealthMode(*timestampedNotesEditorPtr);
            activateStealthMode(*generalNotesEditorPtr);
            *stealthIsActivated = true;
        }

        else
        {
            deactivateStealthMode(*timestampedNotesEditorPtr);
            deactivateStealthMode(*generalNotesEditorPtr);
            *stealthIsActivated = false;
        }

        //[/UserButtonCode_stealthModeToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void TrackNotesAudioProcessorEditor::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
    if(stealthModeToggle->isMouseOver())
    {
        stealthModeToggle->setButtonText("Stealth");
    }

    else
    {
        stealthModeToggle->setButtonText("");
    }
    //[/UserCode_mouseMove]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TrackNotesAudioProcessorEditor::setupVersionNumberlabel()
{
    versionNumberString =  ": ";
    versionNumberString +=  ProjectInfo::projectName;
    versionNumberString += " v";
    versionNumberString += ProjectInfo::versionString;

    if(pluginIsRunningInDemoMode)
    {
        versionNumberString += " - Demo Version";
    }

    else
    {
        versionNumberString += " - Full Version";
    }

    theLyonsDenSoftwareLabel->setText("The Lyons' Den Software" + versionNumberString, dontSendNotification);
}

void TrackNotesAudioProcessorEditor::loadImage(Image &image, File &imagePath, const bool &isImageOne)
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

    createImagePreview(isImageOne);
}

void TrackNotesAudioProcessorEditor::createImagePreview(const bool &isImageOne)
{
    if(isImageOne)
    {
        imagePreviewOne.setVisible(false);
        imagePreviewOne.setImage(*imageOnePtr);
        imagePreviewOne.setBounds(510, 130, 245, 245);
        addAndMakeVisible(imagePreviewOne);
    }
    else
    {
        imagePreviewTwo.setVisible(false);
        imagePreviewTwo.setImage(*imageTwoPtr);
        imagePreviewTwo.setBounds(760, 130, 245, 245);
        addAndMakeVisible(imagePreviewTwo);
    }
}

void TrackNotesAudioProcessorEditor::createImageWindow(SafePointer<BasicWindow> &basicWindowPtr,
                                                       Image &image, File &imagePath)
{
    // Don't allow multiple copies of this window to be made
    if(basicWindowPtr == NULL)
    {
        int height = image.getHeight();
        int width  = image.getWidth();
        scaleImageDimensionsIfTooLarge(width, height);

        basicWindowPtr = new BasicWindow(imagePath.getFileNameWithoutExtension(),
                                         Colours::grey,
                                         DocumentWindow::closeButton |
                                         DocumentWindow::minimiseButton);

        basicWindowPtr->setUsingNativeTitleBar(true);
        basicWindowPtr->setContentOwned(new ImageWindow(image, width, height), true);
        basicWindowPtr->setAlwaysOnTop(true);

        if(!image.isNull())
        {
            basicWindowPtr->setSize(width, height);
            basicWindowPtr->centreWithSize(width, height);
        }

        else
        {
            basicWindowPtr->centreWithSize(basicWindowPtr->getWidth(), basicWindowPtr->getHeight());
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
    // Convert time into hours, minutes, and seconds
    int totalSeconds = positionInformationPtr->timeInSeconds;

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

void TrackNotesAudioProcessorEditor::scaleImageDimensionsIfTooLarge(int &imageWidth, int &imageHeight)
{
    // Get desktop dimensions
    int screenWidth  = Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getWidth();
    int screenHeight = Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight();

    // Trim vertically and horizontally to account for docks, taskbars, menus, and whatnot
    screenWidth  -= 100;
    screenHeight -= 100;

    // Get difference
    int widthDifference  = screenWidth - imageWidth;
    int heightDifference = screenHeight - imageHeight;

    // Leave function if image is smaller than screen size - essentially, do nothing
    if((widthDifference > 0) && (heightDifference > 0))
    {
        return;
    }

    // Scale the image based on whichever dimension is closer to the edge of the screen.
    // The dimension that is closest to the edge of the screen is the one with the smallest difference.
    if(widthDifference < heightDifference)
    {
        float imageAspectRatio = screenWidth / (float) imageWidth;

        // Set image width to screen width and scale height appropriately
        imageWidth = screenWidth;
        imageHeight *= imageAspectRatio;
    }

    else
    {
        float imageAspectRatio = screenHeight / (float) imageHeight;

        // Set image height to screen height and scale width appropriately
        imageHeight = screenHeight;
        imageWidth *= imageAspectRatio;
    }
}

void TrackNotesAudioProcessorEditor::activateStealthMode(TextEditor &textEditor)
{
    String tempTextHolder = "\n\n\n\n\n\n\n\n\n\n";
    tempTextHolder += textEditor.getText();
    textEditor.setText(tempTextHolder, dontSendNotification);
    textEditor.moveCaretToTop(false);
    textEditor.setScrollbarsShown(false);
    textEditor.setReadOnly(true);
}

void TrackNotesAudioProcessorEditor::deactivateStealthMode(TextEditor &textEditor)
{
    String tempTextHolder = textEditor.getText();
    tempTextHolder = tempTextHolder.trimStart();
    textEditor.setText(tempTextHolder);
    textEditor.moveCaretToTop(false);
    textEditor.setScrollbarsShown(true);
    textEditor.setReadOnly(false);
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
                 fixedSize="1" initialWidth="1005" initialHeight="620">
  <METHODS>
    <METHOD name="mouseMove (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff373737">
    <RECT pos="510 130 245 245" fill="solid: ff565454" hasStroke="0"/>
    <RECT pos="760 130 245 245" fill="solid: ff565454" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="trackNotesLabel" id="92aa8337c9826f3e" memberName="trackNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 1005 50" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Track Notes" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="48.700000000000002842" kerning="0" bold="0" italic="0"
         justification="12"/>
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
         virtualName="" explicitFocusOrder="0" pos="0 590 500 30" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="generalNotesLabel" id="c170b98fbe39594f" memberName="generalNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 380 1005 30" edTextCol="ff000000"
         edBkgCol="0" labelText="General Notes:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25" kerning="0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="displayImageOneButton" id="a8b273a63654dd33" memberName="displayImageOneButton"
              virtualName="" explicitFocusOrder="0" pos="560 95 145 30" bgColOff="ff393939"
              buttonText="Empty" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="displayImageTwoButton" id="49cbe3c0cc417d1e" memberName="displayImageTwoButton"
              virtualName="" explicitFocusOrder="0" pos="810 95 145 30" bgColOff="ff393939"
              buttonText="Empty" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="loadImageOneButton" id="b3cf03e99303b480" memberName="loadImageOneButton"
              virtualName="" explicitFocusOrder="0" pos="510 95 50 30" bgColOff="ff393939"
              buttonText="Load" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="loadImageTwoButton" id="c76f47c5a5ad9793" memberName="loadImageTwoButton"
              virtualName="" explicitFocusOrder="0" pos="760 95 50 30" bgColOff="ff393939"
              buttonText="Load" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="removeImageOneButton" id="c4e0c098ca1c7a0c" memberName="removeImageOneButton"
              virtualName="" explicitFocusOrder="0" pos="705 95 50 30" bgColOff="ff393939"
              buttonText="Remove" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="removeImageTwoButton" id="6b14eed5f55e2af7" memberName="removeImageTwoButton"
              virtualName="" explicitFocusOrder="0" pos="955 95 50 30" bgColOff="ff393939"
              buttonText="Remove" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="imagesLabel" id="3f296d22943adc31" memberName="imagesLabel"
         virtualName="" explicitFocusOrder="0" pos="510 60 500 30" edTextCol="ff000000"
         edBkgCol="0" labelText="Images:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Arial" fontsize="25" kerning="0"
         bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="exportMediaButton" id="ab681e4541856006" memberName="exportMediaButton"
              virtualName="" explicitFocusOrder="0" pos="805 595 200 20" bgColOff="ff393939"
              textColOn="ffffffff" buttonText="Export Media" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="stealthModeToggle" id="7779c3978e827c01" memberName="stealthModeToggle"
              virtualName="" explicitFocusOrder="0" pos="752 595 48 20" tooltip="This curious little button activates &quot;Stealth Mode.&quot;  We may not always want to show the clients the notes we write about their performances, so when this button is engaged, Timestamped Notes and General Notes are hidden."
              bgColOff="ff393939" bgColOn="ffffffff" textColOn="ff000000" buttonText=""
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
