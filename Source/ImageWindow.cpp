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
//[/Headers]

#include "ImageWindow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ImageWindow::ImageWindow (const Image &imageSource, const int &width, const int &height)
{
    //[Constructor_pre] You can add your own custom stuff here..

    imageComponent.setImage(imageSource);
    imageComponent.setBounds(0, 0, width, height);
    addAndMakeVisible(imageComponent);

    //[/Constructor_pre]

    pleaseLoadImageLabel.reset (new Label ("pleaseLoadImageLabel",
                                           TRANS("Please Load an Image")));
    addAndMakeVisible (pleaseLoadImageLabel.get());
    pleaseLoadImageLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    pleaseLoadImageLabel->setJustificationType (Justification::centred);
    pleaseLoadImageLabel->setEditable (false, false, false);
    pleaseLoadImageLabel->setColour (TextEditor::textColourId, Colours::black);
    pleaseLoadImageLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    pleaseLoadImageLabel->setBounds (0, 0, 150, 150);


    //[UserPreSize]

    // Don't display "Please Load an Image" label if image exists
    if(!imageComponent.getImage().isNull())
        pleaseLoadImageLabel->setVisible(false);

    //[/UserPreSize]

    setSize (150, 150);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ImageWindow::~ImageWindow()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    pleaseLoadImageLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ImageWindow::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff373737));

    //[UserPaint] Add your own custom painting code here..

    //[/UserPaint]
}

void ImageWindow::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

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

<JUCER_COMPONENT documentType="Component" className="ImageWindow" componentName=""
                 parentClasses="public Component" constructorParams="const Image &amp;imageSource, const int &amp;width, const int &amp;height"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="150" initialHeight="150">
  <BACKGROUND backgroundColour="ff373737"/>
  <LABEL name="pleaseLoadImageLabel" id="e03244b80f680d50" memberName="pleaseLoadImageLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 150 150" edTextCol="ff000000"
         edBkgCol="0" labelText="Please Load an Image" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

