package k4unl.roomba;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Timer;
import java.util.TimerTask;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.os.NetworkOnMainThreadException;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.view.ViewPager;
import android.util.Log;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.Toast;

@SuppressLint("HandlerLeak")
public class MainActivity extends FragmentActivity implements manualControlPage.roombaListener{
	SectionsPagerAdapter mSectionsPagerAdapter;
	ViewPager mViewPager;
	
	Socket sck;
	//PrintWriter sckOut;
	DataOutputStream sckOut;
	DataInputStream sckIn;
	
	Boolean connected;
	Handler handler = new Handler();
	ProgressDialog connectDialog;
	AlertDialog.Builder alertDialogBuilder;
	
	public static final int MESSAGE_ERROR = 1;
	public static final int MESSAGE_TOAST = 2;
	public static final int MESSAGE_UPDATERGB = 3;
	public static final int MESSAGE_UPDATEFADE = 4;
	public static final String MESSAGE_SETRGB = "SETRGB";
	public static final String TOAST = "toast";
	public static final String ERROR = "error";
	public static final String TAG = "MainActivity";
	
	public int batteryMax = 0;
	public int batteryCurrent = 0;
	public int batteryLevel = 0;
	
	public int motorSpeed = 100;
	public String IPToConnect;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		// Create the adapter that will return a fragment for each of the three
		// primary sections of the app.
		mSectionsPagerAdapter = new SectionsPagerAdapter(
				getSupportFragmentManager());

		// Set up the ViewPager with the sections adapter.
		mViewPager = (ViewPager) findViewById(R.id.pager);
		mViewPager.setAdapter(mSectionsPagerAdapter);
		
		AlertDialog.Builder alert = new AlertDialog.Builder(this);

		alert.setTitle("Connect");
		alert.setMessage("Please enter IP Address");

		// Set an EditText view to get user input 
		final EditText input = new EditText(this);
		alert.setView(input);

		alert.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
		public void onClick(DialogInterface dialog, int whichButton) {
			IPToConnect= input.getText().toString();
			//Do something with value!
			
			showConnectDialog();
			Thread cThread = new Thread(new ClientThread());
		    cThread.start();
		  }
		});

		alert.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
		  public void onClick(DialogInterface dialog, int whichButton) {
		    // Canceled.
		  }
		});

		alert.show();

	}
	
	public void showConnectDialog(){
		connectDialog = new ProgressDialog(this);
        connectDialog.setProgressStyle(ProgressDialog.STYLE_SPINNER);
        connectDialog.setMessage("Connecting...");
        connectDialog.setCancelable(false);
        connectDialog.show();
	}
	
	public void showToast(String msg){
    	Context context = getApplicationContext();
    	int duration = Toast.LENGTH_SHORT;

    	Toast.makeText(context, msg, duration).show();
    }
    
    public void showError(String error){
    	alertDialogBuilder = new AlertDialog.Builder(this);
    	alertDialogBuilder.setTitle("Error!");
    	alertDialogBuilder.setMessage(error);
    	alertDialogBuilder.setPositiveButton("Ok",new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int id) {
                System.exit(1);
            }
        });
    	alertDialogBuilder.show();
    }
    
    public void Sleep(Integer ms){
		try {
			Thread.sleep(ms);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
    
	public final Handler mHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
            case MESSAGE_TOAST:
                Toast.makeText(getApplicationContext(), msg.getData().getString(TOAST),
                               Toast.LENGTH_SHORT).show();
                break;
            case MESSAGE_ERROR:
            	showError(msg.getData().getString(ERROR));
            	break;
        	}
        }
    };
	
	public class ClientThread implements Runnable {
    	public void showError(String strError){
    		Message msg = mHandler.obtainMessage(MESSAGE_ERROR);
    		Bundle bundle = new Bundle();
            bundle.putString(ERROR, strError);
            msg.setData(bundle);
            mHandler.sendMessage(msg);
    	}
    	
    	public void showToast(String message){
    		Message msg = mHandler.obtainMessage(MESSAGE_TOAST);
    		Bundle bundle = new Bundle();
    		bundle.putString(TOAST, message);
    		msg.setData(bundle);
    		mHandler.sendMessage(msg);
    	}
    	
        public void run() {
        	Looper.prepare();
        	
        	Log.i("Socket","Trying to connect");
        	try{
    	    	sck = new Socket(IPToConnect, 1337);
    	    	sckIn = new DataInputStream(sck.getInputStream());
    	    	sckOut = new DataOutputStream(sck.getOutputStream());
    	    	connected = true;
            } catch (NetworkOnMainThreadException e){
            	connectDialog.dismiss();
            	showError("");
            	//System.exit(1);
            	connected = false;
    	    } catch (UnknownHostException e) {
    	    	connectDialog.dismiss();
    	    	showError("Unknown host");
    	    	Log.i("Socket","Unknown host!");
    	    	//System.exit(1);
    	    	connected = false;
    	    } catch  (IOException e) {
    	    	connectDialog.dismiss();
    	    	showError(e.getMessage());
    	    	Log.i("Socket","No I/O " + e.getMessage());
    	    	//System.exit(1);
    	    	connected = false;
    	    }
        	boolean startup = true;
    	    if(connected){
	    	    Log.i("Socket","Connected!");
	    	    showToast("Connected!");
	    	    connectDialog.dismiss();
				/*byte[] buff = {(byte) 255, (byte) 2};
	    	    try{
	    	    	sckOut.write(buff); //Ask for current color
	    	    }catch (IOException e){
	    	    	Log.e("Socket", "Cannot ask for color: " + e.getMessage());
	    	    }*/
	    	    TimerTask sdGet = new getSensorData();
	    	    new Timer().scheduleAtFixedRate(sdGet, 0, 500);
    	    }else{
    	    	//showError("Not connected!");
    	    }
            try {
            	int depth = 0;
            	boolean inString = false;
            	String buffer = "";
                while (connected) {
                    byte recvByte = 0;
                    
                    recvByte = sckIn.readByte();
                    if(recvByte == '"'){
                    	inString = !inString;
                    }
                    if(!inString){
	                    if(recvByte == '{' || recvByte == '['){
	                    	depth = depth + 1;
	                    }else if(recvByte == '}' || recvByte == ']'){
	                    	depth = depth - 1;
	                    }
                    }
                    buffer += (char)recvByte;
                    if(depth == 0){
                    	JSONObject command = new JSONObject(buffer);
                        String cmdS = command.getString("command");
                        Log.i("SOCKET",command.toString());
                        if(cmdS == "EVENT"){
                        	JSONObject ev = command.getJSONObject("data");
                        	if(ev.getString("type") == "SENSORDATA"){
                        		//Create percentage for battery
                        		JSONArray sensors = ev.getJSONObject("data").getJSONArray("Sensors");
                        		for (int i = 0; i < sensors.length(); i++) {
                        			JSONObject sensor = sensors.getJSONObject(i);
                        			if(sensor.getInt("id") == 25){
                        				batteryCurrent = sensor.getInt("value");
                        			}else if(sensor.getInt("id") == 26){
                        				batteryMax = sensor.getInt("value");
                        			}
                        		}
                        		setBatteryLevel();
                        		
                        	}
                        }
                        buffer = "";
                    }
                }
                sck.close();
                connected = false;
                Log.d("ClientActivity", "C: Closed.");
            } catch (Exception e) {
                Log.e("ClientActivity", "C: Error", e);
                connected = false;
            }
        }
    }
	
	void setBatteryLevel(){
		batteryLevel = (batteryMax / batteryCurrent) * 100;
		ProgressBar pbBattery = (ProgressBar) findViewById(R.id.pbBattery);
		pbBattery.setProgress(batteryLevel);
	}
	
	class getSensorData extends TimerTask {
		   public void run() {
			   JSONObject comm = new JSONObject();
			   JSONObject args = new JSONObject();
			   String command = "SENDSENSORDATAREQUEST";
			   try {
				   comm.put("command", command);
				   JSONArray sensors = new JSONArray();
				   sensors.put(25);
				   sensors.put(26);
				   args.put("Sensors",sensors);
				   comm.put("data", args);
			   } catch (JSONException e) {
				   e.printStackTrace();
			   }
			   sendCommand(comm);
		   }
		}

	
	@Override
	protected void onStop() {
        super.onStop();
        try {
             // make sure you close the socket upon exiting
        	connected = false;
             sck.close();
         } catch (IOException e) {
             e.printStackTrace();
         }
    }

	/**
	 * A {@link FragmentPagerAdapter} that returns a fragment corresponding to
	 * one of the sections/tabs/pages.
	 */
	public class SectionsPagerAdapter extends FragmentPagerAdapter {
		ArrayList<String> fragments = new ArrayList<String>();
		FragmentManager fm;
		
		public SectionsPagerAdapter(FragmentManager fm) {
			super(fm);
			this.fm = fm;
		}
		
		public Fragment getFragment(int position){
			return fm.findFragmentByTag(getFragmentTag(position));
		}

		private String getFragmentTag(int pos){
		    return "android:switcher:"+R.id.pager+":"+pos;
		}
		
		@Override
		public Fragment getItem(int position) {
			Fragment fragment = null;
			Bundle args = new Bundle();
			switch(position){
				case 0:
					fragment = new manualControlPage();
					fragments.add(0, fragment.getTag());
					break;
				case 1:
					fragment = new programPage();
					fragments.add(1,fragment.getTag());
					break;
				case 2:
					fragment = new settingsPage();
					fragment.setArguments(args);
					fragments.add(2, fragment.getTag());
					break;	
			}
			return fragment;
		}

		@Override
		public int getCount() {
			return 3;
		}

		@Override
		public CharSequence getPageTitle(int position) {
			Locale l = Locale.getDefault();
			switch (position) {
			
			case 0:
				return getString(R.string.title_manual).toUpperCase(l);
			case 1:
				return getString(R.string.title_program).toUpperCase(l);
			case 2:
				return getString(R.string.title_settings).toUpperCase(l);
			}
			return null;
		}
	}

	@Override
	public void sendCommand(JSONObject toSend) {
		try {
			String str = toSend.toString();
			byte[] arr = str.getBytes("UTF-8");
			Log.i("MSG", toSend.toString());
			sckOut.write(arr);
			sckOut.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void setMotorSpeed(int speed) {
		this.motorSpeed = speed;
	}

	@Override
	public void drive(int left, int right) {
		JSONObject comm = new JSONObject();
		JSONObject args = new JSONObject();
		String command = "SETMOTORSPEED";
		try {
			comm.put("command", command);
			args.put("Left", left * this.motorSpeed);
			args.put("Right", right * this.motorSpeed);
			comm.put("data", args);
		} catch (JSONException e) {
			e.printStackTrace();
		}
		this.sendCommand(comm);
	}
}
