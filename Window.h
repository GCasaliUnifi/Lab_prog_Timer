//
// Created by giacomo on 26/06/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_WINDOW_H
#define LAB_PROGRAMMAZIONE_2023_WINDOW_H

#include<wx/frame.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>
#include <wx/button.h>

#include "SubjectTimer.h"
#include "ClockDisplay.h"
#include "DateDisplay.h"
#include "TimerDisplay.h"

class Window : public wxFrame {
public:
    explicit Window(const wxString& title);

    void OnAboutInfo(wxCommandEvent &ev);
    void OnButtonClick(wxCommandEvent &ev);
private:
    SubjectTimer* dateTimeData;
    wxButton * playButton;
    wxButton * pauseButton;
};


#endif //LAB_PROGRAMMAZIONE_2023_WINDOW_H
