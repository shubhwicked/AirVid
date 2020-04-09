//
// Created by Shubham on 2020-11-28.
//

#ifndef MOBISOFT_PLAYER_EVENT_OBSERVER_H
#define MOBISOFT_PLAYER_EVENT_OBSERVER_H

namespace mobisoft {

class PlayerEventObserver {

public:
    virtual void OnComplete() = 0;
};

}

#endif //MOBISOFT_PLAYER_EVENT_OBSERVER_H
