package com.example.amtrak;

import android.app.TimePickerDialog;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.text.format.DateFormat;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Calendar;



public class MainActivity extends AppCompatActivity {

    private TextView tripMinutes;
    private String reservation;
    private int hours;
    int intMinutes;
    String arrival_time;

    String meal;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tripMinutes = (TextView)findViewById(R.id.textView5);
        Button button = (Button)findViewById(R.id.button);
        Button button1 = (Button)findViewById(R.id.button2);
        final SharedPreferences sharedPref = PreferenceManager.getDefaultSharedPreferences(this);



        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new TimePickerDialog(MainActivity.this, d,c.get(Calendar.HOUR_OF_DAY),c.get(Calendar.MINUTE), DateFormat.is24HourFormat(getApplicationContext())).show();


            }
        });

        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                intMinutes = Integer.parseInt(tripMinutes.getText().toString());
                c.add(Calendar.MINUTE, intMinutes);
                arrival_time = android.text.format.DateFormat.format("kk:mm", c.getTime()).toString();
                SharedPreferences.Editor editor = sharedPref.edit();
                editor.putString("key1", reservation);
                editor.putInt("key2", hours);
                editor.putInt("key3", intMinutes);
                editor.putString("key4", arrival_time);
                editor.commit();
                startActivity(new Intent(MainActivity.this, ResultsActivity.class));

            }
        });
    }


    Calendar c = Calendar.getInstance();


    //TimePicker.setCurrentHour(Calendar.getInstance().get(Calendar.HOUR_OF_DAY));
    //DateFormat fmtDate = DateFormat.getDateInstance();
    NumberFormat curr = new DecimalFormat("$###,###.##");
    final TimePickerDialog.OnTimeSetListener d = new TimePickerDialog.OnTimeSetListener() {



        @Override
        public void onTimeSet(TimePicker view, int hour, int minute) {
            c.set(Calendar.HOUR_OF_DAY, hour);
            c.set(Calendar.MINUTE, minute);




            if (Integer.parseInt(android.text.format.DateFormat.format("kk", c.getTime()).toString()) == 23
                    && Integer.parseInt(android.text.format.DateFormat.format("mm", c.getTime()).toString())> 59){
                reservation = "Invalid time" + "\n" + "Please select a time between 00:00 - 23:59";

            }else {
                reservation = "Trip begins at  "+ android.text.format.DateFormat.format("kk:mm", c.getTime()) + "." + "\n";

                hours =  Integer.parseInt(android.text.format.DateFormat.format("kk", c.getTime()).toString());
            }

            //miles = Integer.parseInt(truckMiles.getText().toString());


        }
    };




}
