/*
 ==============================================================================

 This file is part of the JUCETICE project - Copyright 2008 by Lucio Asnaghi.

 JUCETICE is based around the JUCE library - "Jules' Utility Class Extensions"
 Copyright 2004 by Julian Storer.

 ------------------------------------------------------------------------------

 JUCE and JUCETICE can be redistributed and/or modified under the terms of
 the GNU General Public License, as published by the Free Software Foundation;
 either version 2 of the License, or (at your option) any later version.

 JUCE and JUCETICE are distributed in the hope that they will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with JUCE and JUCETICE; if not, visit www.gnu.org/licenses or write to
 Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 Boston, MA 02111-1307 USA

 ------------------------------------------------------------------------------

 If you'd like to release a closed-source product which uses JUCE, commercial
 licenses are also available: visit www.rawmaterialsoftware.com/juce for
 more information.

 ==============================================================================
*/

#ifndef __JUCETICE_HELIXCOMPONENT_HEADER__
#define __JUCETICE_HELIXCOMPONENT_HEADER__

#include "HelixPlugin.h"
#include "Components/NativeEditor.h"

//==============================================================================
/**
    This is the Component that our filter will use as its UI.

*/
class HelixComponent  : public AudioProcessorEditor,
                        public AudioParameterListener,
                        public ChangeListener
{
public:

    //==============================================================================
    /** Constructor.
        When created, this will register itself with the filter for changes. It's
        safe to assume that the filter won't be deleted before this object is.
    */
    HelixComponent (HelixPlugin* const ownerFilter);

    /** Destructor. */
    ~HelixComponent ();

    //==============================================================================
    /** Standard Juce paint callback. */
    void paint (Graphics& g);

    /** Standard Juce resize callback. */
    void resized ();

    //==============================================================================
    /** Our demo filter is a ChangeBroadcaster, and will call us back when one of
        its parameters changes.
    */
    void changeListenerCallback (void* source);

    /** Parameter listener callback */
    void parameterChanged (AudioParameter* parameter, const int index);

private:

    //==============================================================================
    friend class HelixPlugin;

    Viewport* mainComponent;
    MidiKeyboardComponent* midiKeyboard;

    TooltipWindow tooltipWindow;

    // handy wrapper method to avoid having to cast the filter to a DemoJuceFilter
    // every time we need it..
    HelixPlugin* getFilter() const throw()  { return (HelixPlugin*) getAudioProcessor(); }
};


#endif // __JUCETICE_VECTORCOMPONENT_H
