package com.example.movingtruckrental;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.widget.ImageView;
import android.widget.TextView;

import java.text.DecimalFormat;

public class CostActivity extends AppCompatActivity {
    float totalCost;
    String rentalType;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cost);
        TextView paymentInfo = (TextView)findViewById(R.id.textView2);
        TextView truckInfo = (TextView)findViewById(R.id.textView6);
        ImageView truck = (ImageView)findViewById(R.id.imgTruck);
        SharedPreferences sharedPref = PreferenceManager.getDefaultSharedPreferences(this);
        int miles = sharedPref.getInt("key1",0);
        float costOfTruck = sharedPref.getFloat("key2",0);
        float costPerMile = 0.99f;

        totalCost = costOfTruck + (miles * costPerMile);
        DecimalFormat currency = new DecimalFormat("$###,###.##");

        if (costOfTruck == 19.95f){
            truck.setImageResource(R.drawable.struckk);
            //truckInfo.setText("You selected a 10-foot moving truck");
            rentalType = "10";
        } else if (costOfTruck == 29.95f) {
            truck.setImageResource(R.drawable.mtruckk);
            //truckInfo.setText("You selected a 17-foot moving truck");
            rentalType = "17";
        } else if (costOfTruck == 39.95f) {
            truck.setImageResource(R.drawable.ltruckk);
            //truckInfo.setText("You selected a 26-foot moving truck");
            rentalType = "26";
        }
        truckInfo.setText("You selected a " + rentalType +"-foot moving truck.  It will appear similar to what is pictured below.");
        paymentInfo.setText("It will be " + currency.format(totalCost) + " to travel " + miles + " miles in a " + rentalType + "-foot truck." );

    }

}
