//
// Created by Jedrzej on 12/15/2020.
//

#ifndef OCULUSTELEOP_BUTTONS_H
#define OCULUSTELEOP_BUTTONS_H

#include "VrApi_Input.h"
#include <string>
#include "OculusTeleop.h"

namespace OVRFW {

    class Buttons {

    public:
        void update_buttons(
                ovrInputStateTrackedRemote remoteInputState, const ovrHandedness controllerHand);
        std::string current_to_string(char side) const;

        // Add haptics control
        void trigger_haptic(char side, float intensity, float duration_ms) {
            if (side == 'l') {
                leftHapticState_.HapticState = HAPTICS_SIMPLE;
                leftHapticState_.HapticSimpleValue = intensity;
            } else if (side == 'r') {
                rightHapticState_.HapticState = HAPTICS_SIMPLE;
                rightHapticState_.HapticSimpleValue = intensity;
            }
        }
        DeviceHapticState get_haptic_state(char side) const {
            return side == 'l' ? leftHapticState_ : rightHapticState_;
        }

    private:
        ovrInputStateTrackedRemote leftRemoteInputState_;
        ovrInputStateTrackedRemote rightRemoteInputState_;
        DeviceHapticState leftHapticState_;
        DeviceHapticState rightHapticState_;
    };

}


#endif //OCULUSTELEOP_BUTTONS_H
