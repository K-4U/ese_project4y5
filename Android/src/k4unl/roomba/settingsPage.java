package k4unl.roomba;

import k4unl.roomba.manualControlPage.roombaListener;
import android.app.Activity;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;

public class settingsPage extends Fragment {
	public settingsPage() {
	}
	roombaListener mCallback;
	
	
	@Override
    public void onAttach(Activity activity) {
        super.onAttach(activity);
        Log.i("DERP","Attached settings");
        
        // This makes sure that the container activity has implemented
        // the callback interface. If not, it throws an exception
        try {
            mCallback = (roombaListener) activity;
        } catch (ClassCastException e) {
            throw new ClassCastException(activity.toString()
                    + " must implement ledstripListener");
        }
    }

    
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		View rootView = inflater.inflate(R.layout.settings,
				container, false);
		
		//Bundle args = getArguments();
		SeekBar motorSpeed = (SeekBar) rootView.findViewById(R.id.sbMotorSpeed);
		motorSpeed.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {			
			@Override
			public void onProgressChanged(SeekBar arg0, int arg1, boolean arg2) {
				mCallback.setMotorSpeed(arg0.getProgress());
			}

			@Override
			public void onStartTrackingTouch(SeekBar arg0) {
				
			}

			@Override
			public void onStopTrackingTouch(SeekBar arg0) {
				
			}
		});
		
		/*fadeSwitch = (Switch) rootView.findViewById(R.id.swFade);
		fadeSwitch.setChecked(args.getBoolean("fade"));
		fadeSwitch.setOnCheckedChangeListener(fadeListener);
		*/
		return rootView;
	}
}
