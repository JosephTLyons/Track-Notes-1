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
    void startDemoTimer();
    void timerCallback() override;
};

#endif /* DemoTimer_hpp */
