package k4unl.roomba;

import org.json.JSONException;
import org.json.JSONObject;

import k4unl.roomba.manualControlPage.roombaListener;
import android.app.Activity;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

public class programPage extends Fragment {
	public programPage() {
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
                    + " must implement roombaListener");
        }
    }

    
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		View rootView = inflater.inflate(R.layout.program_page,
				container, false);
		
		//Bundle args = getArguments();
		
		Button cleanButton = (Button) rootView.findViewById(R.id.cmdClean);
		cleanButton.setOnClickListener(buttonListener);
		Button stopButton = (Button) rootView.findViewById(R.id.cmdStop);
		stopButton.setOnClickListener(buttonListener);
		Button cleanOnSpot = (Button) rootView.findViewById(R.id.cmdCleanOnSPot);
		cleanOnSpot.setOnClickListener(buttonListener);
		Button dockButton = (Button) rootView.findViewById(R.id.cmdDock);
		dockButton.setOnClickListener(buttonListener);
		
		return rootView;
	}
	
	public Button.OnClickListener buttonListener = new Button.OnClickListener() {
		JSONObject comm = new JSONObject();
		JSONObject args = new JSONObject();
		public void onClick(View arg0) {
			switch(arg0.getId()){
				case R.id.cmdClean:
					try {
						comm.put("command", "NEWMODE");
						args.put("newmode", 1);
					} catch (JSONException e) {
						e.printStackTrace();
					}
					break;
				case R.id.cmdCleanOnSPot:
					try {
						comm.put("command", "NEWMODE");
						args.put("newmode", 2);
					} catch (JSONException e) {
						e.printStackTrace();
					}
					break;
				case R.id.cmdStop:
					try {
						comm.put("command", "NEWMODE");
						args.put("newmode", 0);
					} catch (JSONException e) {
						e.printStackTrace();
					}
					break;
				case R.id.cmdDock:
					try {
						comm.put("command", "NEWMODE");
						args.put("newmode", 3);
					} catch (JSONException e) {
						e.printStackTrace();
					}
					break;
			}
			try {
				comm.put("data", args);
			} catch (JSONException e) {
				e.printStackTrace();
			}
			mCallback.sendCommand(comm);
		}
	};
}
