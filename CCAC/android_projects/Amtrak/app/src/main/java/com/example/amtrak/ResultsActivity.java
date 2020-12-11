package com.example.amtrak;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.text.DecimalFormat;

public class ResultsActivity extends AppCompatActivity {


        String rentalType;
        @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_results);
            TextView paymentInfo = (TextView)findViewById(R.id.textView2);
            //TextView truckInfo = (TextView)findViewById(R.id.textView6);
            //ImageView truck = (ImageView)findViewById(R.id.imgTruck);
            SharedPreferences sharedPref = PreferenceManager.getDefaultSharedPreferences(this);
            String miles = sharedPref.getString("key1","reservation");
            int costOfTruck = sharedPref.getInt("key2",0);
            int minutes = sharedPref.getInt("key3",0);
            String arrival = sharedPref.getString("key4", "arrival_time");
            ImageView image = (ImageView)findViewById(R.id.imageView4);


            if (costOfTruck < 4){
                Toast.makeText(ResultsActivity.this, "Red-Eye Arrival", Toast.LENGTH_LONG).show();
                image.setImageResource(R.drawable.trainsleep);
            } else {
                image.setImageResource(R.drawable.amtraklogo);

            }

            paymentInfo.setText(miles + "Your trip will last " + minutes + " minutes." + "\n" + "  You will arrive at " + arrival + ".");

        }

    }
