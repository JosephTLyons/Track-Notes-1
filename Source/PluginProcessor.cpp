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
    // Create an outer XML element..
    XmlElement xml ("trackNotes");
    
    // add some attributes to it..
    xml.setAttribute ("performersName", performersNameEditor.getText());
    xml.setAttribute ("instrumentPlayed", instrumentPlayedEditor.getText());
    xml.setAttribute ("microphonesUsed", microphonesUsedEditor.getText());
    xml.setAttribute ("timestampedNotes", timestampedNotesEditor.getText());
    xml.setAttribute ("generalNotes", generalNotesEditor.getText());
    
    // Image one XML attribute
    if(!imageComponentOne.getImage().isNull())
    {
        format.writeImageToStream (imageComponentOne.getImage() , memoryOutput);
        MemoryBlock imageData (memoryOutput.getData(), memoryOutput.getDataSize());
        xml.setAttribute ("imageOne", imageData.toBase64Encoding());
    }
    
    // Image two XML attribute
    if(!imageComponentTwo.getImage().isNull())
    {
        format.writeImageToStream (imageComponentTwo.getImage(), memoryOutput);
        MemoryBlock imageData (memoryOutput.getData(), memoryOutput.getDataSize());
        xml.setAttribute ("imageTwo", imageData.toBase64Encoding());
    }
    
    // Use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xml, destData);
}

void TrackNotesAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // This getXmlFromBinary() helper function retrieves our XML from the binary blob..
    ScopedPointer<XmlElement> xml (getXmlFromBinary (data, sizeInBytes));
    
    if (xml != nullptr)
    {
        // make sure that it's actually our type of XML object..
        if (xml->hasTagName ("trackNotes"))
        {
            // ok, now pull our strings
            performersNameEditor.setText(xml->getStringAttribute("performersName"));
            instrumentPlayedEditor.setText(xml->getStringAttribute("instrumentPlayed"));
            microphonesUsedEditor.setText(xml->getStringAttribute("microphonesUsed"));
            timestampedNotesEditor.setText(xml->getStringAttribute("timestampedNotes"));
            generalNotesEditor.setText(xml->getStringAttribute("generalNotes"));
            
            imageOneMemoryBlock.fromBase64Encoding(xml->getStringAttribute("imageOne"));
            imageTwoMemoryBlock.fromBase64Encoding(xml->getStringAttribute("imageTwo"));
            
            memoryInput = new MemoryInputStream(imageOneMemoryBlock.getData(),
                                                imageOneMemoryBlock.getSize(),
                                                false);
            
            imageOne = ImageFileFormat::loadFrom(*memoryInput);
            
            delete memoryInput;
            memoryInput = new MemoryInputStream(imageTwoMemoryBlock.getData(),
                                                imageTwoMemoryBlock.getSize(),
                                                false);
            
            imageTwo = ImageFileFormat::loadFrom(*memoryInput);
            delete memoryInput;
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TrackNotesAudioProcessor();
}
