package k4unl.roomba;

import java.util.ArrayList;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

class logEntry{
	public String Time;
	public String Entry;
	public logEntry(String Time, String Entry) {
	    this.Time = Time;
	    this.Entry = Entry;
	}
}

public class logArrayAdapter extends ArrayAdapter<logEntry> {
  private final Context context;
  private final ArrayList<logEntry> values = new ArrayList<logEntry>();
  
  public logArrayAdapter(Context context) {
    super(context, R.layout.log_row_layout);
    this.context = context;
  }
  
  @Override
  public void add(logEntry entry){
	  this.values.add(entry);
	  notifyDataSetChanged();
  }
  @Override
  public void clear(){
	  this.values.clear();
	  super.notifyDataSetChanged();
  }
  
  @Override
  public void notifyDataSetChanged(){
	  super.notifyDataSetChanged();
  }
  
  public boolean hasEntry(logEntry toCheck){
	  return this.values.contains(toCheck);
  }

  public int getCount(){
	  return this.values.size();
  }
  
  @Override
  public View getView(int position, View convertView, ViewGroup parent) {
    LayoutInflater inflater = (LayoutInflater) context
        .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    View rowView = inflater.inflate(R.layout.log_row_layout, parent, false);
    TextView lblTime = (TextView) rowView.findViewById(R.id.lblTime);
    TextView lblEntry = (TextView) rowView.findViewById(R.id.lblEntry);
    lblTime.setText(values.get(position).Time);
    lblEntry.setText(values.get(position).Entry);
    
    return rowView;
  }
} 