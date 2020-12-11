package com.example.wildgingerdinnerdelivery;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.DatePicker;
import android.widget.TextView;
import android.widget.TimePicker;

import java.sql.Time;
//import java.text.DateFormat;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Calendar;
import java.util.Timer;
import android.text.format.DateFormat;

public class MainActivity extends AppCompatActivity {

    private TextView reservation;
    String meal;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        reservation = (TextView)findViewById(R.id.txtReservation);
        Button button = (Button)findViewById(R.id.btnDate);
        final CheckBox check1 = (CheckBox)findViewById(R.id.chkBox1);
        final CheckBox check2 = (CheckBox)findViewById(R.id.chkBox2);
        final CheckBox check3 = (CheckBox)findViewById(R.id.chkBox3);
        final CheckBox check4 = (CheckBox)findViewById(R.id.chkBox4);

        check1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (check1.isChecked()) {
                    check2.setChecked(false);
                    check3.setChecked(false);
                    check4.setChecked(false);
                }
            }
        });

        check2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (check2.isChecked()) {
                    check1.setChecked(false);
                    check3.setChecked(false);
                    check4.setChecked(false);
                }
            }
        });

        check3.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (check3.isChecked()) {
                    check2.setChecked(false);
                    check1.setChecked(false);
                    check4.setChecked(false);
                }
            }
        });

        check4.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (check4.isChecked()) {
                    check2.setChecked(false);
                    check3.setChecked(false);
                    check1.setChecked(false);
                }
            }
        });
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new TimePickerDialog(MainActivity.this, d,c.get(Calendar.HOUR_OF_DAY),c.get(Calendar.MINUTE),DateFormat.is24HourFormat(getApplicationContext())).show();
                if (check1.isChecked()){
                    meal = "Korean Dinner";

                }
                if (check2.isChecked()){
                    meal = "Japanese Dinner";
                }
                if (check3.isChecked()){
                    meal = "Vietnamese Dinner";
                }
                if (check4.isChecked()){
                    meal = "Ethiopian Dinner";
                }


            }
        });
    }

    Calendar c = Calendar.getInstance();
    //DateFormat fmtDate = DateFormat.getDateInstance();
    NumberFormat curr = new DecimalFormat("$###,###.##");
    final TimePickerDialog.OnTimeSetListener d = new TimePickerDialog.OnTimeSetListener() {
        @Override
        public void onTimeSet(TimePicker view, int hour, int minute) {
            c.set(Calendar.HOUR_OF_DAY, hour);
            c.set(Calendar.MINUTE, minute);



            if (Integer.parseInt(android.text.format.DateFormat.format("hh", c.getTime()).toString()) > 11
                    || Integer.parseInt(android.text.format.DateFormat.format("hh", c.getTime()).toString())< 5){
                reservation.setText("Invalid time" + "\n" + "Please select a time between 5pm and 11pm");
            } else {
                reservation.setText("Your " + meal + " will be delivered tonight at " + "\n" + android.text.format.DateFormat.format("hh:mm a", c.getTime()));
            }
        }
    };

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
