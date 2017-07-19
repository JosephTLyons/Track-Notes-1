//
//  DemoTimer.hpp
//  Track Notes
//
//  Created by Joseph Lyons on 7/19/17.
//
//

#ifndef DemoTimer_hpp
#define DemoTimer_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class DemoTimer : private Timer
{
private:
    Array<TextEditor *> textEditorPtrArray;
    
public:
    DemoTimer();
    ~DemoTimer();
    void setTextEditorPtrArray(Array<TextEditor *> textEditorPtrArrayInput);
    void timerCallback() override;
};

#endif /* DemoTimer_hpp */
