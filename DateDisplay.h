//
// Created by giacomo on 27/06/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_DATEDISPLAY_H
#define LAB_PROGRAMMAZIONE_2023_DATEDISPLAY_H

#include <wx/window.h>

#include "Observer.h"

class DateDisplay : public Observer, public wxWindow {
public:
    virtual void update() override;
};

#endif //LAB_PROGRAMMAZIONE_2023_DATEDISPLAY_H
