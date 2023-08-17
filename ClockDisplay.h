//
// Created by giacomo on 27/06/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_CLOCKDISPLAY_H
#define LAB_PROGRAMMAZIONE_2023_CLOCKDISPLAY_H

#include <iostream>

#include <wx/window.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>

#include "Observer.h"
#include "SubjectTimer.h"

class ClockDisplay : public Observer, public wxWindow {
public:
    ClockDisplay(SubjectTimer *dateTimeData, wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxPanelNameStr);

    void update() override;
private:
    SubjectTimer* dateTimeData;
    wxTextCtrl* clockDisplayTMP;
    unsigned short hour, minute, second;
};


#endif //LAB_PROGRAMMAZIONE_2023_CLOCKDISPLAY_H
