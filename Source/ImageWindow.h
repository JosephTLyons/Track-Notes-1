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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ImageWindow  : public Component
{
public:
    //==============================================================================
    ImageWindow (const Image &imageSource, const int &width, const int &height);
    ~ImageWindow();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    ImageComponent imageComponent;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> pleaseLoadImageLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImageWindow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
