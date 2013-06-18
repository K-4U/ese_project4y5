package k4unl.roomba;

import org.json.JSONArray;
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
import android.widget.TextView;

public class logginPage extends Fragment {
	public logginPage() {
	}
	roombaListener mCallback;
	
	View rootView;
	
	@Override
    public void onAttach(Activity activity) {
        super.onAttach(activity);
        Log.i("DERP","Attached logginPage");
        
        // This makes sure that the container activity has implemented
        // the callback interface. If not, it throws an exception
        try {
            mCallback = (roombaListener) activity;
        } catch (ClassCastException e) {
            throw new ClassCastException(activity.toString()
                    + " must implement roombaListener");
        }
    }

    public void setLogs(JSONArray logs){
    	TextView txtLogs = (TextView) rootView.findViewById(R.id.txtLog);
    	txtLogs.setText("");
    	for (int i = logs.length(); i > 0; i--) {
    		JSONObject log = new JSONObject();
			try {
				log = logs.getJSONObject(i);
			} catch (JSONException e) {
				e.printStackTrace();
			}
    		try {
				txtLogs.setText(log.getString("Time") + " " + log.getString("Entry")
						+ txtLogs.getText());
			} catch (JSONException e) {
				e.printStackTrace();
			}
    	}
    }
	
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		rootView = inflater.inflate(R.layout.logging_page,
				container, false);
		
		Bundle args = getArguments();
		
		
		/*fadeSwitch = (Switch) rootView.findViewById(R.id.swFade);
		fadeSwitch.setChecked(args.getBoolean("fade"));
		fadeSwitch.setOnCheckedChangeListener(fadeListener);
		*/
		return rootView;
	}
}
