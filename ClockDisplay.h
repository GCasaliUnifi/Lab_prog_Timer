//
// Created by giacomo on 27/06/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_CLOCKDISPLAY_H
#define LAB_PROGRAMMAZIONE_2023_CLOCKDISPLAY_H


#include <wx/frame.h>

#include "Observer.h"

class ClockDisplay : public Observer, public wxFrame {
public:
    virtual void update() override;
};


#endif //LAB_PROGRAMMAZIONE_2023_CLOCKDISPLAY_H
