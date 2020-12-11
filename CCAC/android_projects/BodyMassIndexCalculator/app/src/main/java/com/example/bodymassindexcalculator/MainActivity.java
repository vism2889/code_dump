package com.example.bodymassindexcalculator;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    int intWeight;
    int intHeight;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final EditText weight = (EditText)findViewById(R.id.editText);
        final EditText height = (EditText)findViewById(R.id.editText2);
        Button button = (Button)findViewById(R.id.button2);
        final SharedPreferences sharedPref = PreferenceManager.getDefaultSharedPreferences(this);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                intWeight = Integer.parseInt(weight.getText().toString());
                intHeight = Integer.parseInt(height.getText().toString());
                SharedPreferences.Editor editor = sharedPref.edit();
                editor.putInt("key1", intWeight);
                editor.putInt("key2",intHeight);
                editor.commit();
                startActivity(new Intent(MainActivity.this, CalcActivity.class));


            }
        });

    }


}
