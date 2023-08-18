//
// Created by giacomo on 18/08/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_TIMERDISPLAY_H
#define LAB_PROGRAMMAZIONE_2023_TIMERDISPLAY_H

#include <wx/window.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>

#include "Observer.h"
#include "SubjectTimer.h"

class TimerDisplay : public Observer, public wxWindow {
public:
    TimerDisplay(SubjectTimer *dateTimeData, wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxPanelNameStr);

    void update() override;
private:
    SubjectTimer* dateTimeData;
    wxTextCtrl* timerDisplayTMP;
    unsigned short hour, minute, second;

};


#endif //LAB_PROGRAMMAZIONE_2023_TIMERDISPLAY_H
