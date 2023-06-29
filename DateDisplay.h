//
// Created by giacomo on 27/06/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_DATEDISPLAY_H
#define LAB_PROGRAMMAZIONE_2023_DATEDISPLAY_H

#include <wx/window.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>

#include "Observer.h"
#include "SubjectTimer.h"

class DateDisplay : public Observer, public wxWindow {
public:
    DateDisplay(SubjectTimer *dateTimeData, wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxPanelNameStr);

    void update() override;
private:
    SubjectTimer* dateTimeData;
    wxTextCtrl* dateDisplayTMP;


    unsigned short day, month;
    int year;
};

#endif //LAB_PROGRAMMAZIONE_2023_DATEDISPLAY_H
