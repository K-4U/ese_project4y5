package k4unl.roomba;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import k4unl.roomba.manualControlPage.roombaListener;
import android.app.Activity;
import android.os.Bundle;
import android.support.v4.app.ListFragment;
import android.util.Log;

public class logginPage extends ListFragment {
	public logginPage() {
	}
	roombaListener mCallback;
	logArrayAdapter adapter;
	
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
    	if(adapter != null){
    		adapter.clear();
    		for (int i = logs.length()-1; i >= 0; i--) {
	    		JSONObject log = new JSONObject();
				try {
					log = logs.getJSONObject(i);
				} catch (JSONException e) {
					e.printStackTrace();
				}
	    		try {
	    			
	    			logEntry nLog = new logEntry(log.getString("Time"), log.getString("Entry"));
//	    			if(!adapter.hasEntry(nLog)){
	    				adapter.add(nLog);
	//    			}
				} catch (JSONException e) {
					e.printStackTrace();
				}
	    	}
    	}
    }
	
	@Override
	public void onActivityCreated(Bundle savedInstanceState) {
		super.onActivityCreated(savedInstanceState);
		//Bundle args = getArguments();
	    adapter = new logArrayAdapter(getActivity());
	    setListAdapter(adapter);
		/*fadeSwitch = (Switch) rootView.findViewById(R.id.swFade);
		fadeSwitch.setChecked(args.getBoolean("fade"));
		fadeSwitch.setOnCheckedChangeListener(fadeListener);
		*/
	}
}
