//
//  DemoTimer.cpp
//  Track Notes
//
//  Created by Joseph Lyons on 7/19/17.
//
//

#include "DemoTimer.hpp"

DemoTimer::DemoTimer()
{
    
}

DemoTimer::~DemoTimer()
{
    
}

void DemoTimer::setTextEditorPtrArray(Array<TextEditor *> textEditorPtrArrayInput)
{
    textEditorPtrArray = textEditorPtrArrayInput;
}

void DemoTimer::startDemoTimer()
{
    int minutes      = 20;
    int seconds      = minutes * 60;
    int milliseconds = seconds * 1000;
    
    startTimer(milliseconds);
}

void DemoTimer::timerCallback()
{
    String demoMessage = "Track Notes Demo Version.";
    
    Random randomNumberGenerator(Time::currentTimeMillis());
    
    int randomNumber = randomNumberGenerator.nextInt(5);
    
    textEditorPtrArray[randomNumber]->setText(demoMessage);
}
