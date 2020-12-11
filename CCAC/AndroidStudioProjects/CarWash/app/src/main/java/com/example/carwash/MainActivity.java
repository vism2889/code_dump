package com.example.carwash;

import android.content.Context;
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

    double numWashes;
    double baseExCost = 10.99;
    double baseBothCost = 15.99;
    double discountEx = 8.99;
    double discountBoth = 12.99;
    double totalCost;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        getSupportActionBar().setDisplayShowHomeEnabled(true);
        getSupportActionBar().setLogo(R.mipmap.ic_launcher);
        getSupportActionBar().setDisplayUseLogoEnabled(true);

        final EditText washNum = (EditText)findViewById(R.id.editText);
        final RadioButton ex = (RadioButton)findViewById(R.id.radioButton);
        final RadioButton both = (RadioButton)findViewById(R.id.radioButton2);
        final TextView result = (TextView)findViewById(R.id.textView2);
        Button calculate = (Button)findViewById(R.id.button);


        calculate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DecimalFormat currency = new DecimalFormat("$###,###");
                DecimalFormat washFormat = new DecimalFormat("##");
                if ((washNum.getText().toString()).matches("")) {
                    Toast.makeText(MainActivity.this, "Please enter a value!", Toast.LENGTH_LONG).show();
                } else {
                    numWashes = Double.parseDouble(washNum.getText().toString());

                }

                if (numWashes>= 12.0){
                    // Discount


                    if (ex.isChecked()){
                        totalCost = numWashes * discountEx;

                    } else {
                        totalCost = numWashes * discountBoth;
                    }
                } else {
                    // No discount
                    Toast.makeText(MainActivity.this, "Purchase 12 or more Washes to get a Discount!", Toast.LENGTH_LONG).show();
                    if (ex.isChecked()){
                        totalCost = numWashes * baseExCost;
                    } else {
                        totalCost = numWashes * baseBothCost;
                    }
                }
                result.setText(currency.format(totalCost) + " For " + washFormat.format(numWashes) + " washes!");
            }

        } );
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
