//
// Created by giacomo on 27/06/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_OBSERVER_H
#define LAB_PROGRAMMAZIONE_2023_OBSERVER_H

class Observer {
protected:
    virtual ~Observer() = default;

public:
    virtual void update() = 0;
};

#endif //LAB_PROGRAMMAZIONE_2023_OBSERVER_H
