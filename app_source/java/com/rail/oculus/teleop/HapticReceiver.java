package com.rail.oculus.teleop;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

public class HapticReceiver extends BroadcastReceiver {
    private static final String TAG = "HapticReceiver";

    @Override
    public void onReceive(Context context, Intent intent) {
        if (intent.getAction().equals("com.rail.oculus.teleop.HAPTIC")) {
            String side = intent.getStringExtra("side");
            float intensity = intent.getFloatExtra("intensity", 0.0f);
            int duration = intent.getIntExtra("duration", 0);

            Log.i(TAG, "Received haptic command: side=" + side + " intensity=" + intensity + " duration=" + duration);

            // Call our native method to trigger the haptic feedback
            MainActivity.triggerHaptic(side.charAt(0), intensity, duration);
        }
    }
}