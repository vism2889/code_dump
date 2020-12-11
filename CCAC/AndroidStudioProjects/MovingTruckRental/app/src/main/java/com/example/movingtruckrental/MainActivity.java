package com.example.movingtruckrental;

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
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.RadioButton;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    float costOfTruck;
    int miles;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = (Button)findViewById(R.id.button);

        final RadioButton check1 = (RadioButton) findViewById(R.id.radioButton);
        final RadioButton check2 = (RadioButton) findViewById(R.id.radioButton2);
        final RadioButton check3 = (RadioButton) findViewById(R.id.radioButton3);

        final EditText truckMiles = (EditText)findViewById(R.id.editText);
        final SharedPreferences sharedPref = PreferenceManager.getDefaultSharedPreferences(this);


        check1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (check1.isChecked()) {
                    check2.setChecked(false);
                    check3.setChecked(false);

                }
            }
        });

        check2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (check2.isChecked()) {
                    check1.setChecked(false);
                    check3.setChecked(false);

                }
            }
        });

        check3.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (check3.isChecked()) {
                    check2.setChecked(false);
                    check1.setChecked(false);

                }
            }
        });


        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (check1.isChecked()){
                    costOfTruck = 19.95f;
                }
                if (check2.isChecked()){
                    costOfTruck = 29.95f;
                }
                if (check3.isChecked()) {
                    costOfTruck = 39.95f;
                }

                miles = Integer.parseInt(truckMiles.getText().toString());
                SharedPreferences.Editor editor = sharedPref.edit();
                editor.putInt("key1", miles);
                editor.putFloat("key2", costOfTruck);
                editor.commit();
                startActivity(new Intent(MainActivity.this, CostActivity.class));

            }
        });
    }

}
