package com.example.paintcalculator;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    double gallon = 250.00;
    double wallHeight;
    double wallCirc;
    double squareFeet;
    double amountNeeded;
    String groupChoice;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        final EditText circ = (EditText)findViewById(R.id.roomCirc);
        final EditText height = (EditText)findViewById(R.id.height);
        final Spinner group = (Spinner)findViewById(R.id.txtGroup);
        Button calc = (Button) findViewById(R.id.button);
        calc.setOnClickListener(new View.OnClickListener() {
            final TextView result = ((TextView)findViewById(R.id.txtResult));
            @Override
            public void onClick(View v) {
                wallCirc = Double.parseDouble(circ.getText().toString());
                wallHeight = Double.parseDouble(height.getText().toString());
                squareFeet = (wallCirc * wallHeight);
                amountNeeded = squareFeet / gallon;
                groupChoice = group.getSelectedItem().toString();
                result.setText(amountNeeded +" gallons of " + groupChoice + " Paint" );
            }
        });



    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
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
