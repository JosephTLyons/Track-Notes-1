/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
TrackNotesAudioProcessor::TrackNotesAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

TrackNotesAudioProcessor::~TrackNotesAudioProcessor()
{
}

//==============================================================================
const String TrackNotesAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TrackNotesAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TrackNotesAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double TrackNotesAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TrackNotesAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TrackNotesAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TrackNotesAudioProcessor::setCurrentProgram (int index)
{
}

const String TrackNotesAudioProcessor::getProgramName (int index)
{
    return {};
}

void TrackNotesAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TrackNotesAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void TrackNotesAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TrackNotesAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TrackNotesAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool TrackNotesAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TrackNotesAudioProcessor::createEditor()
{
    return new TrackNotesAudioProcessorEditor (*this);
}

//==============================================================================
void TrackNotesAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // Here's an example of how you can use XML to make it easy and more robust:
    
    // Create an outer XML element..
    XmlElement xml ("MYPLUGINSETTINGS");
    
    // add some attributes to it..
    xml.setAttribute ("performersName", performersNameEditorPtr->getText());
    xml.setAttribute ("instrumentPlayed", instrumentPlayedEditorPtr->getText());
    xml.setAttribute ("microphonesUsed", microphonesUsedEditorPtr->getText());
    xml.setAttribute ("generalNotes", generalNotesEditorPtr->getText());
    
    // Store the values of all our parameters, using their param ID as the XML attribute
    for (int i = 0; i < getNumParameters(); ++i)
        if (AudioProcessorParameterWithID* p = dynamic_cast<AudioProcessorParameterWithID*> (getParameters().getUnchecked(i)))
            xml.setAttribute (p->paramID, p->getValue());
    
    // then use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xml, destData);
    
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TrackNotesAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    // This getXmlFromBinary() helper function retrieves our XML from the binary blob..
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    
    if (xmlState != nullptr)
    {
        // make sure that it's actually our type of XML object..
        if (xmlState->hasTagName ("MYPLUGINSETTINGS"))
        {
            // ok, now pull our strings
            
//            *performersNameEditorPtr->setText(xmlState->getStringAttribute("performersName", *performersNameEditorPtr-getT);)
//            *instrumentPlayedEditorPtr = xmlState->getStringAttribute("instrumentPlayed", *instrumentPlayedEditorPtr);
//            *microphonesUsedString = xmlState->getStringAttribute("microphonesUsed", *microphonesUsedString);
//            *generalNotesString = xmlState->getStringAttribute("generalNotes", *generalNotesString);
            
            // Now reload our parameters..
            for (int i = 0; i < getNumParameters(); ++i)
                if (AudioProcessorParameterWithID* p = dynamic_cast<AudioProcessorParameterWithID*> (getParameters().getUnchecked(i)))
                    p->setValue ((float) xmlState->getDoubleAttribute (p->paramID, p->getValue()));
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TrackNotesAudioProcessor();
}
