/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

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

    createImagePreviews();

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

    isRunningInDemoMode = true;

    if (isRunningInDemoMode)
    {
        randomNumberGenerator.setSeed (Time::currentTimeMillis());
        startDemoTimer();
    }

    //[/Constructor_pre]

    trackNotesLabel.reset (new Label ("trackNotesLabel",
                                      TRANS("Track Notes")));
    addAndMakeVisible (trackNotesLabel.get());
    trackNotesLabel->setFont (Font ("Arial", 48.70f, Font::plain).withTypefaceStyle ("Regular"));
    trackNotesLabel->setJustificationType (Justification::centredTop);
    trackNotesLabel->setEditable (false, false, false);
    trackNotesLabel->setColour (Label::textColourId, Colours::white);
    trackNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    trackNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    trackNotesLabel->setBounds (0, 0, 1005, 50);

    timestampedNotesLabel.reset (new Label ("timestampedNotesLabel",
                                            TRANS("Timestamped Notes:")));
    addAndMakeVisible (timestampedNotesLabel.get());
    timestampedNotesLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    timestampedNotesLabel->setJustificationType (Justification::centredLeft);
    timestampedNotesLabel->setEditable (false, false, false);
    timestampedNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    timestampedNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    timestampedNotesLabel->setBounds (0, 165, 218, 30);

    insertTimeStampButton.reset (new TextButton ("insertTimeStampButton"));
    addAndMakeVisible (insertTimeStampButton.get());
    insertTimeStampButton->setButtonText (TRANS("Insert Timestamp"));
    insertTimeStampButton->addListener (this);
    insertTimeStampButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    insertTimeStampButton->setBounds (218, 165, 282, 30);

    theLyonsDenSoftwareLabel.reset (new Label ("theLyonsDenSoftwareLabel",
                                               String()));
    addAndMakeVisible (theLyonsDenSoftwareLabel.get());
    theLyonsDenSoftwareLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    theLyonsDenSoftwareLabel->setJustificationType (Justification::centredLeft);
    theLyonsDenSoftwareLabel->setEditable (false, false, false);
    theLyonsDenSoftwareLabel->setColour (TextEditor::textColourId, Colours::black);
    theLyonsDenSoftwareLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    theLyonsDenSoftwareLabel->setBounds (0, 590, 500, 30);

    generalNotesLabel.reset (new Label ("generalNotesLabel",
                                        TRANS("General Notes:")));
    addAndMakeVisible (generalNotesLabel.get());
    generalNotesLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    generalNotesLabel->setJustificationType (Justification::centred);
    generalNotesLabel->setEditable (false, false, false);
    generalNotesLabel->setColour (TextEditor::textColourId, Colours::black);
    generalNotesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    generalNotesLabel->setBounds (0, 380, 1005, 30);

    displayImageOneButton.reset (new TextButton ("displayImageOneButton"));
    addAndMakeVisible (displayImageOneButton.get());
    displayImageOneButton->setButtonText (TRANS("Empty"));
    displayImageOneButton->addListener (this);
    displayImageOneButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    displayImageOneButton->setBounds (560, 95, 145, 30);

    displayImageTwoButton.reset (new TextButton ("displayImageTwoButton"));
    addAndMakeVisible (displayImageTwoButton.get());
    displayImageTwoButton->setButtonText (TRANS("Empty"));
    displayImageTwoButton->addListener (this);
    displayImageTwoButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    displayImageTwoButton->setBounds (810, 95, 145, 30);

    loadImageOneButton.reset (new TextButton ("loadImageOneButton"));
    addAndMakeVisible (loadImageOneButton.get());
    loadImageOneButton->setButtonText (TRANS("Load"));
    loadImageOneButton->addListener (this);
    loadImageOneButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    loadImageOneButton->setBounds (510, 95, 50, 30);

    loadImageTwoButton.reset (new TextButton ("loadImageTwoButton"));
    addAndMakeVisible (loadImageTwoButton.get());
    loadImageTwoButton->setButtonText (TRANS("Load"));
    loadImageTwoButton->addListener (this);
    loadImageTwoButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    loadImageTwoButton->setBounds (760, 95, 50, 30);

    removeImageOneButton.reset (new TextButton ("removeImageOneButton"));
    addAndMakeVisible (removeImageOneButton.get());
    removeImageOneButton->setButtonText (TRANS("Remove"));
    removeImageOneButton->addListener (this);
    removeImageOneButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    removeImageOneButton->setBounds (705, 95, 50, 30);

    removeImageTwoButton.reset (new TextButton ("removeImageTwoButton"));
    addAndMakeVisible (removeImageTwoButton.get());
    removeImageTwoButton->setButtonText (TRANS("Remove"));
    removeImageTwoButton->addListener (this);
    removeImageTwoButton->setColour (TextButton::buttonColourId, Colour (0xff393939));

    removeImageTwoButton->setBounds (955, 95, 50, 30);

    imagesLabel.reset (new Label ("imagesLabel",
                                  TRANS("Images:")));
    addAndMakeVisible (imagesLabel.get());
    imagesLabel->setFont (Font ("Arial", 25.00f, Font::plain).withTypefaceStyle ("Regular"));
    imagesLabel->setJustificationType (Justification::centred);
    imagesLabel->setEditable (false, false, false);
    imagesLabel->setColour (TextEditor::textColourId, Colours::black);
    imagesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    imagesLabel->setBounds (510, 60, 500, 30);

    exportMediaButton.reset (new TextButton ("exportMediaButton"));
    addAndMakeVisible (exportMediaButton.get());
    exportMediaButton->setButtonText (TRANS("Export Media"));
    exportMediaButton->addListener (this);
    exportMediaButton->setColour (TextButton::buttonColourId, Colour (0xff393939));
    exportMediaButton->setColour (TextButton::textColourOnId, Colours::white);

    exportMediaButton->setBounds (805, 595, 200, 20);

    stealthModeToggle.reset (new TextButton ("stealthModeToggle"));
    addAndMakeVisible (stealthModeToggle.get());
    stealthModeToggle->setTooltip (TRANS("This button activates \"Stealth Mode.\"  We may not always want to show the clients the notes we write about their performances, so when this button is engaged, Timestamped Notes and General Notes are hidden.  Additionally, it also deactivates the \"Insert Timestamp\" button."));
    stealthModeToggle->setButtonText (String());
    stealthModeToggle->addListener (this);
    stealthModeToggle->setColour (TextButton::buttonColourId, Colour (0xff393939));
    stealthModeToggle->setColour (TextButton::buttonOnColourId, Colours::white);
    stealthModeToggle->setColour (TextButton::textColourOnId, Colours::black);

    stealthModeToggle->setBounds (752, 595, 48, 20);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1005, 620);


    //[Constructor] You can add your own custom stuff here..

    // Reset button names to image name (this doesn't work in standalone
    // since constructor isn't called when standalone loads, because plugin is already open
    if (! processor.imageOnePath.getFullPathName().isEmpty())
        displayImageOneButton->setButtonText (processor.imageOnePath.getFileNameWithoutExtension());

    if (! processor.imageTwoPath.getFullPathName().isEmpty())
        displayImageTwoButton->setButtonText (processor.imageTwoPath.getFileNameWithoutExtension());

    setupVersionNumberlabel();

    // Get array of fonts on user's system
    Font::findFonts (usersFontsResults);

    // Set up labels
    performersNameLabelPtr->setEditable (true);
    instrumentPlayedLabelPtr->setEditable (true);
    microphonesUsedLabelPtr->setEditable (true);

    if (performersNameLabelPtr->getText().isEmpty())
        performersNameLabelPtr->setText ("Performer's Name:", dontSendNotification);

    if (instrumentPlayedLabelPtr->getText().isEmpty())
        instrumentPlayedLabelPtr->setText ("Instrument Played:", dontSendNotification);

    if (microphonesUsedLabelPtr->getText().isEmpty())
        microphonesUsedLabelPtr->setText ("Microphone(s) Used:", dontSendNotification);

    // Set up static text buttons
    staticTextSizeButtonPtr.reset (new StaticTextSizeButton);

    loadImageOneButton->setLookAndFeel (staticTextSizeButtonPtr.get());
    displayImageOneButton->setLookAndFeel (staticTextSizeButtonPtr.get());
    removeImageOneButton->setLookAndFeel (staticTextSizeButtonPtr.get());
    loadImageTwoButton->setLookAndFeel (staticTextSizeButtonPtr.get());
    displayImageTwoButton->setLookAndFeel (staticTextSizeButtonPtr.get());
    removeImageTwoButton->setLookAndFeel (staticTextSizeButtonPtr.get());

    // Set up stealth mode
    // Turn button into a toggle button
    stealthModeToggle->setClickingTogglesState (true);
    if (processor.stealthIsActivated)
    {
        activateStealthMode();
        stealthModeToggle->setToggleState (true, dontSendNotification);
    }

    // Add mouse listener to this to create dynamic text in button
    stealthModeToggle->addMouseListener (this, true);

    setFocusTabOrder();

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

    staticTextSizeButtonPtr = nullptr;

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

    g.setColour (Colours::white);
    g.setOpacity (0.3);
    g.drawLine (30, 50, 975, 50, 1);



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

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TrackNotesAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == insertTimeStampButton.get())
    {
        //[UserButtonCode_insertTimeStampButton] -- add your button handler code here..

        int hours, minutes, seconds;

        fillTimeIntervalValues (hours, minutes, seconds);

        // Copy current text from the timestamped notes editor
        String tempTextEditorString = timestampedNotesEditorPtr->getText();

        tempTextEditorString += formatAndBuildTimecode (hours, minutes, seconds);

        timestampedNotesEditorPtr->setText (tempTextEditorString);

        // Put editor into focus and then move caret to end,
        // Which is where new timestamp has been inserted
        timestampedNotesEditorPtr->grabKeyboardFocus();
        timestampedNotesEditorPtr->moveCaretToEnd();

        //[/UserButtonCode_insertTimeStampButton]
    }
    else if (buttonThatWasClicked == displayImageOneButton.get())
    {
        //[UserButtonCode_displayImageOneButton] -- add your button handler code here..

        // Display error if images are missing
        if (processor.imageOnePath.exists())
            createImageWindow (basicWindowImageTwoPtr, processor.imageOne, processor.imageOnePath);

        else
            showErrorLoadingImageWindow (processor.imageOnePath.getFullPathName());

        //[/UserButtonCode_displayImageOneButton]
    }
    else if (buttonThatWasClicked == displayImageTwoButton.get())
    {
        //[UserButtonCode_displayImageTwoButton] -- add your button handler code here..

        // Display error if images are missing
        if (processor.imageTwoPath.exists())
            createImageWindow (basicWindowImageTwoPtr, processor.imageTwo, processor.imageTwoPath);

        else
            showErrorLoadingImageWindow (processor.imageTwoPath.getFullPathName());

        //[/UserButtonCode_displayImageTwoButton]
    }
    else if (buttonThatWasClicked == loadImageOneButton.get())
    {
        //[UserButtonCode_loadImageOneButton] -- add your button handler code here..

        loadImage (processor.imageOne, processor.imageOnePath, true);

        if (! processor.imageOne.isNull())
            displayImageOneButton->setButtonText (processor.imageOnePath.getFileNameWithoutExtension());

        //[/UserButtonCode_loadImageOneButton]
    }
    else if (buttonThatWasClicked == loadImageTwoButton.get())
    {
        //[UserButtonCode_loadImageTwoButton] -- add your button handler code here..

        loadImage(processor.imageTwo, processor.imageTwoPath, false);

        if (! processor.imageTwo.isNull())
            displayImageTwoButton->setButtonText (processor.imageTwoPath.getFileNameWithoutExtension());

        //[/UserButtonCode_loadImageTwoButton]
    }
    else if (buttonThatWasClicked == removeImageOneButton.get())
    {
        //[UserButtonCode_removeImageOneButton] -- add your button handler code here..

        imagePreviewOne.setVisible (false);

        Image blankImage;
        processor.imageOnePath = "";
        processor.imageOne = blankImage;
        displayImageOneButton->setButtonText ("Empty");

        //[/UserButtonCode_removeImageOneButton]
    }
    else if (buttonThatWasClicked == removeImageTwoButton.get())
    {
        //[UserButtonCode_removeImageTwoButton] -- add your button handler code here..

        imagePreviewTwo.setVisible (false);

        Image blankImage;
        processor.imageTwoPath = "";
        processor.imageTwo = blankImage;
        displayImageTwoButton->setButtonText ("Empty");

        //[/UserButtonCode_removeImageTwoButton]
    }
    else if (buttonThatWasClicked == exportMediaButton.get())
    {
        //[UserButtonCode_exportMediaButton] -- add your button handler code here..

        FileChooser fileChooser ("Export Text",
                                 File::getSpecialLocation(File::userHomeDirectory),
                                 "*",
                                 true);


        if (fileChooser.browseForFileToSave (true))
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
            pathToSaveTextFileTo.appendText (performersNameLabelPtr->getText());
            pathToSaveTextFileTo.appendText (" " + performersNameEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText (instrumentPlayedLabelPtr->getText());
            pathToSaveTextFileTo.appendText (" " + instrumentPlayedEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText (microphonesUsedLabelPtr->getText());
            pathToSaveTextFileTo.appendText (" " + microphonesUsedEditorPtr->getText() + "\n\n");

            pathToSaveTextFileTo.appendText ("Timestamped Notes:\n");
            pathToSaveTextFileTo.appendText (timestampedNotesEditorPtr->getText().trim() + "\n\n");

            pathToSaveTextFileTo.appendText ("General Notes:\n");
            pathToSaveTextFileTo.appendText (generalNotesEditorPtr->getText().trim() + "\n\n");

            pathToSaveTextFileTo.appendText ("Image One: ");
            pathToSaveTextFileTo.appendText (processor.imageOnePath.getFileName() + "\n\n");

            pathToSaveTextFileTo.appendText ("Image Two: ");
            pathToSaveTextFileTo.appendText (processor.imageTwoPath.getFileName());

            // Copy images into folder
            processor.imageOnePath.copyFileTo (pathToSaveFolder.getFullPathName() + "/" +
                                               processor.imageOnePath.getFileName());
            processor.imageTwoPath.copyFileTo (pathToSaveFolder.getFullPathName() + "/" +
                                               processor.imageTwoPath.getFileName());
        }

        //[/UserButtonCode_exportMediaButton]
    }
    else if (buttonThatWasClicked == stealthModeToggle.get())
    {
        //[UserButtonCode_stealthModeToggle] -- add your button handler code here..

        if (stealthModeToggle->getToggleState())
            activateStealthMode();

        else
            deactivateStealthMode();

        //[/UserButtonCode_stealthModeToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void TrackNotesAudioProcessorEditor::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...

    if (stealthModeToggle->isMouseOver())
        stealthModeToggle->setButtonText ("Stealth");

    else
        stealthModeToggle->setButtonText ("");

    //[/UserCode_mouseMove]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TrackNotesAudioProcessorEditor::setupVersionNumberlabel()
{
    versionNumberString =  ": ";
    versionNumberString +=  ProjectInfo::projectName;
    versionNumberString += " v";
    versionNumberString += ProjectInfo::versionString;

    if (isRunningInDemoMode)
        versionNumberString += " - Demo Version";

    else
        versionNumberString += " - Full Version";

    theLyonsDenSoftwareLabel->setText ("The Lyons' Den Software" + versionNumberString,
                                       dontSendNotification);
}

void TrackNotesAudioProcessorEditor::loadImage (Image &image, File &imagePath, const bool &isImageOne)
{
    FileChooser fileChooser ("Export all Text",
                             File::getSpecialLocation(File::userHomeDirectory),
                             "*",
                             true);


    // Launch browser window and only if they pick a image do we set the image path
    if (fileChooser.browseForFileToOpen())
    {
        // Set imagePath
        imagePath = fileChooser.getResult();

        // Get image
        image = ImageCache::getFromFile (fileChooser.getResult());
    }

    createImagePreviews();
}

void TrackNotesAudioProcessorEditor::createImagePreviews()
{
    imagePreviewOne.setVisible(false);
    imagePreviewOne.setImage(processor.imageOne);
    imagePreviewOne.setBounds(510, 130, 245, 245);
    addAndMakeVisible(imagePreviewOne);

    imagePreviewTwo.setVisible(false);
    imagePreviewTwo.setImage(processor.imageTwo);
    imagePreviewTwo.setBounds(760, 130, 245, 245);
    addAndMakeVisible(imagePreviewTwo);
}

void TrackNotesAudioProcessorEditor::createImageWindow (SafePointer<BasicWindow> &basicWindowPtr,
                                                        Image &image, File &imagePath)
{
    // Don't allow multiple copies of this window to be made
    if (basicWindowPtr == NULL)
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

        if (! image.isNull())
        {
            basicWindowPtr->setSize(width, height);
            basicWindowPtr->centreWithSize(width, height);
        }

        else
            basicWindowPtr->centreWithSize(basicWindowPtr->getWidth(), basicWindowPtr->getHeight());

        basicWindowPtr->setVisible(true);
    }

    // If window is open already and display button is clicked again, window will be deleted
    else
        delete basicWindowPtr;
}

void TrackNotesAudioProcessorEditor::showErrorLoadingImageWindow (const String &path)
{
    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                 "Image Missing: ",
                                 path + "\n\nPlease load image again.");
}

void TrackNotesAudioProcessorEditor::fillTimeIntervalValues (int &hours, int &minutes, int &seconds)
{
    // Convert time into hours, minutes, and seconds
    int totalSeconds = processor.positionInformation.timeInSeconds;

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

String TrackNotesAudioProcessorEditor::formatAndBuildTimecode (const int &hours,
                                                               const int &minutes,
                                                               const int &seconds)
{
    String tempString;

    // Don't insert newline on first timestamp
    if (! timestampedNotesEditorPtr->isEmpty())
        tempString += "\n";

    tempString += "@ ";
    tempString += formatTimeInterval(hours);
    tempString += ":";
    tempString += formatTimeInterval(minutes);
    tempString += ":";
    tempString += formatTimeInterval(seconds);
    tempString += " - ";

    return tempString;
}

String TrackNotesAudioProcessorEditor::formatTimeInterval (const int &timeInterval)
{
    String tempString;

    if (timeInterval < 10)
        tempString += "0";

    tempString += timeInterval;

    return tempString;
}

void TrackNotesAudioProcessorEditor::scaleImageDimensionsIfTooLarge (int &imageWidth,
                                                                     int &imageHeight)
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
    if ((widthDifference > 0) && (heightDifference > 0))
        return;

    // Scale the image based on whichever dimension is closer to the edge of the screen.
    // The dimension that is closest to the edge of the screen is the one with the smallest difference.
    if (widthDifference < heightDifference)
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

void TrackNotesAudioProcessorEditor::activateStealthMode()
{
    processor.stealthIsActivated = true;

    hideTextAndDisableEditor (*timestampedNotesEditorPtr);
    hideTextAndDisableEditor (*generalNotesEditorPtr);

    insertTimeStampButton->setInterceptsMouseClicks (false, false);
}

void TrackNotesAudioProcessorEditor::hideTextAndDisableEditor (TextEditor &textEditor)
{
    String tempTextHolder = "\n\n\n\n\n\n\n\n\n\n";
    tempTextHolder += textEditor.getText();
    textEditor.setText(tempTextHolder, dontSendNotification);
    textEditor.moveCaretToTop(false);
    textEditor.setScrollbarsShown(false);
    textEditor.setReadOnly(true);
    textEditor.setInterceptsMouseClicks(false, false);
}

void TrackNotesAudioProcessorEditor::deactivateStealthMode()
{
    processor.stealthIsActivated = false;

    showTextAndEnableEditor (*timestampedNotesEditorPtr);
    showTextAndEnableEditor (*generalNotesEditorPtr);

    insertTimeStampButton->setInterceptsMouseClicks (true, true);
}

void TrackNotesAudioProcessorEditor::showTextAndEnableEditor (TextEditor &textEditor)
{
    String tempTextHolder = textEditor.getText();
    tempTextHolder = tempTextHolder.trimStart();
    textEditor.setText(tempTextHolder);
    textEditor.moveCaretToTop(false);
    textEditor.setScrollbarsShown(true);
    textEditor.setReadOnly(false);
    textEditor.setInterceptsMouseClicks(true, true);
}

void TrackNotesAudioProcessorEditor::setFocusTabOrder()
{
    // Set up tap order
    performersNameEditorPtr->setExplicitFocusOrder (1);
    instrumentPlayedEditorPtr->setExplicitFocusOrder (2);
    microphonesUsedEditorPtr->setExplicitFocusOrder (3);
    timestampedNotesEditorPtr->setExplicitFocusOrder (4);
    generalNotesEditorPtr->setExplicitFocusOrder (5);
    performersNameLabelPtr->setExplicitFocusOrder (6);
    instrumentPlayedLabelPtr->setExplicitFocusOrder (7);
    microphonesUsedLabelPtr->setExplicitFocusOrder (8);

    // Remove keyboard focus from these elements so that they are not included in tap order
    loadImageOneButton->setWantsKeyboardFocus (false);
    displayImageOneButton->setWantsKeyboardFocus (false);
    removeImageOneButton->setWantsKeyboardFocus (false);
    loadImageTwoButton->setWantsKeyboardFocus (false);
    displayImageTwoButton->setWantsKeyboardFocus (false);
    removeImageTwoButton->setWantsKeyboardFocus (false);
    insertTimeStampButton->setWantsKeyboardFocus (false);
    stealthModeToggle->setWantsKeyboardFocus (false);
    exportMediaButton->setWantsKeyboardFocus (false);
}

void TrackNotesAudioProcessorEditor::startDemoTimer()
{
    int minutes      = 20;
    int seconds      = minutes * 60;
    int milliseconds = seconds * 1000;

    startTimer (milliseconds);
}

void TrackNotesAudioProcessorEditor::timerCallback()
{
    int randomNumber = randomNumberGenerator.nextInt(5);
    String demoText = "Track Notes Demo Version.";

    if (randomNumber == 0)
        performersNameEditorPtr->setText (demoText);

    else if (randomNumber == 1)
        instrumentPlayedEditorPtr->setText (demoText);

    else if (randomNumber == 2)
        microphonesUsedEditorPtr->setText (demoText);

    else if (randomNumber == 3)
        timestampedNotesEditorPtr->setText (demoText);

    else
        generalNotesEditorPtr->setText (demoText);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TrackNotesAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public TextEditor::Listener, private Timer"
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
         fontsize="48.7" kerning="0.0" bold="0" italic="0" justification="12"/>
  <LABEL name="timestampedNotesLabel" id="358938facaa251fc" memberName="timestampedNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 165 218 30" edTextCol="ff000000"
         edBkgCol="0" labelText="Timestamped Notes:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="insertTimeStampButton" id="2d604f6be40451a7" memberName="insertTimeStampButton"
              virtualName="" explicitFocusOrder="0" pos="218 165 282 30" bgColOff="ff393939"
              buttonText="Insert Timestamp" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="theLyonsDenSoftwareLabel" id="d0cfddad51f6f3" memberName="theLyonsDenSoftwareLabel"
         virtualName="" explicitFocusOrder="0" pos="0 590 500 30" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="generalNotesLabel" id="c170b98fbe39594f" memberName="generalNotesLabel"
         virtualName="" explicitFocusOrder="0" pos="0 380 1005 30" edTextCol="ff000000"
         edBkgCol="0" labelText="General Notes:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial"
         fontsize="25.0" kerning="0.0" bold="0" italic="0" justification="36"/>
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
         focusDiscardsChanges="0" fontname="Arial" fontsize="25.0" kerning="0.0"
         bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="exportMediaButton" id="ab681e4541856006" memberName="exportMediaButton"
              virtualName="" explicitFocusOrder="0" pos="805 595 200 20" bgColOff="ff393939"
              textColOn="ffffffff" buttonText="Export Media" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="stealthModeToggle" id="7779c3978e827c01" memberName="stealthModeToggle"
              virtualName="" explicitFocusOrder="0" pos="752 595 48 20" tooltip="This button activates &quot;Stealth Mode.&quot;  We may not always want to show the clients the notes we write about their performances, so when this button is engaged, Timestamped Notes and General Notes are hidden.  Additionally, it also deactivates the &quot;Insert Timestamp&quot; button."
              bgColOff="ff393939" bgColOn="ffffffff" textColOn="ff000000" buttonText=""
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

