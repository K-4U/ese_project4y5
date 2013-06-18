package k4unl.roomba;


import org.json.JSONObject;

import android.app.Activity;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ProgressBar;

public class manualControlPage extends Fragment {
	public manualControlPage() {
	}
	roombaListener mCallback;


	// Container Activity must implement this interface
    public interface roombaListener {
        public void sendCommand(JSONObject toSend);
        public void setMotorSpeed(int speed);
        public void drive(int left, int right);
    }

    View rootView;
    
    @Override
    public void onAttach(Activity activity) {
        super.onAttach(activity);
        
        // This makes sure that the container activity has implemented
        // the callback interface. If not, it throws an exception
        try {
            mCallback = (roombaListener) activity;
        } catch (ClassCastException e) {
            throw new ClassCastException(activity.toString()
                    + " must implement ledstripListener");
        }
    }
    
    public void setBatteryLevel(int level){
    	ProgressBar pbBattery = (ProgressBar) rootView.findViewById(R.id.pbBattery);
		pbBattery.setProgress(level);
    }

    
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		rootView = inflater.inflate(R.layout.manual_control,
				container, false);
		
		Button cmdUp = (Button) rootView.findViewById(R.id.btnUp);
		Button cmdDown = (Button) rootView.findViewById(R.id.btnDown);
		Button cmdLeft = (Button) rootView.findViewById(R.id.btnLeft);
		Button cmdRight = (Button) rootView.findViewById(R.id.btnRight);
		cmdUp.setOnTouchListener(buttonListener);
		cmdDown.setOnTouchListener(buttonListener);
		cmdLeft.setOnTouchListener(buttonListener);
		cmdRight.setOnTouchListener(buttonListener);
		return rootView;
	}
	
	
	public OnTouchListener buttonListener = new OnTouchListener() {
		public boolean onTouch(View arg0, MotionEvent event) {

			int left = 0;
			int right = 0;
			if(event.getAction() == MotionEvent.ACTION_DOWN){
				switch(arg0.getId()){
				case R.id.btnUp:
					left = 1;
					right = 1;
					break;
				case R.id.btnDown:
					left = -1;
					right = -1;
					break;
				case R.id.btnLeft:
					right = 1;
					left = -1;
					break;
				case R.id.btnRight:
					right = -1;
					left = 1;
					break;
				}
			}
			if(event.getAction() == MotionEvent.ACTION_UP || 
					event.getAction() == MotionEvent.ACTION_DOWN){
				mCallback.drive(left, right);
			}
			return false;
		}
	};
}
