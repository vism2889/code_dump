package com.example.floorfinisher;

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
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;

import java.text.DecimalFormat;

public class MainActivity extends AppCompatActivity {

    double width;
    double length;
    double totalTiles;
    double totalArea;
    double inches;
    double largeTile = 1.5;
    double smallTile = 1;
    double foot = 1;
    String tileSelection;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final EditText lengthVal = (EditText)findViewById(R.id.editText);
        final EditText widthVal = (EditText)findViewById(R.id.editText2);
        final RadioButton largeSelction = (RadioButton)findViewById(R.id.radioButton2);
        final RadioButton smallSelction = (RadioButton)findViewById(R.id.radioButton);
        final TextView result = (TextView)findViewById(R.id.textView3);
        Button calc = (Button)findViewById(R.id.button);

        calc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DecimalFormat form = new DecimalFormat("###,###");

                if ((lengthVal.getText().toString()).matches("")) {
                    Toast.makeText(MainActivity.this, "Please enter a value!", Toast.LENGTH_LONG).show();
                } else {
                    length = Double.parseDouble(lengthVal.getText().toString());

                }
                if ((widthVal.getText().toString()).matches("")) {
                    Toast.makeText(MainActivity.this, "Please enter a value!", Toast.LENGTH_LONG).show();
                } else {
                    width = Double.parseDouble(widthVal.getText().toString());

                }
                totalArea = width*length;
                inches = totalArea*foot;
                if (largeSelction.isChecked() != true && smallSelction.isChecked() != true){
                    Toast.makeText(MainActivity.this, "Please Make a Selection!", Toast.LENGTH_LONG).show();
                } else {
                    if (largeSelction.isChecked()){
                        totalTiles = inches/largeTile;
                        tileSelection = " (18 X 18) inch tiles.";
                    } else {
                        totalTiles = inches/smallTile;
                        tileSelection = " (12 X 12) inch tiles.";
                    }
                    result.setText("For a room of " + form.format( Math.ceil(totalArea)) + " square feet you will need " + form.format(Math.ceil(totalTiles)) + tileSelection);

                }


            }
        });

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


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
