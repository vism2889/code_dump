package com.example.bodymassindexcalculator;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.TextView;

public class CalcActivity extends AppCompatActivity {
    int bmiConstant = 703;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calc);
        TextView txtOutput = (TextView)findViewById(R.id.bmiOutput);
        SharedPreferences sharedPref = PreferenceManager.getDefaultSharedPreferences(this);
        int intWeight = sharedPref.getInt("key1", 0);
        int intHeight = sharedPref.getInt("key2", 0);
        float bodyindex;

        bodyindex = (intWeight * bmiConstant)/(intHeight * intHeight);
        txtOutput.setText("Your BMI is:  " + bodyindex);

    }

}
