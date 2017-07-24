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

#ifndef StaticTextSizeButton_hpp
#define StaticTextSizeButton_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class StaticTextSizeButton : public LookAndFeel_V4
{
private:
    
public:
    void drawButtonText (Graphics& g, TextButton& button, bool /*isMouseOverButton*/, bool /*isButtonDown*/)
    {
        // Only change made - changed previously value to 20
        // Since I want the same text size that was present when the buttons were 20 pixles high
        Font font (getTextButtonFont (button, 20));
        g.setFont (font);
        g.setColour (button.findColour (button.getToggleState() ? TextButton::textColourOnId
                                        : TextButton::textColourOffId)
                     .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f));
        
        const int yIndent = jmin (4, button.proportionOfHeight (0.3f));
        const int cornerSize = jmin (button.getHeight(), button.getWidth()) / 2;
        
        const int fontHeight = roundToInt (font.getHeight() * 0.6f);
        const int leftIndent  = jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft() ? 4 : 2));
        const int rightIndent = jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
        const int textWidth = button.getWidth() - leftIndent - rightIndent;
        
        if (textWidth > 0)
            g.drawFittedText (button.getButtonText(),
                              leftIndent, yIndent, textWidth, button.getHeight() - yIndent * 2,
                              Justification::centred, 2);
    }
};
#endif /* StaticTextSizeButton_hpp */
