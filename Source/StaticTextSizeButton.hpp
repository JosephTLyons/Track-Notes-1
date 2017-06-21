//
//  StaticTextSizeButton.hpp
//  Track Notes
//
//  Created by Joseph Lyons on 6/20/17.
//
//

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
