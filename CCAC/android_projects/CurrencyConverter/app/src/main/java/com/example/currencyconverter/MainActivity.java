package com.example.currencyconverter;

import android.os.Bundle;
import android.provider.MediaStore;
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
import java.util.Currency;

public class MainActivity extends AppCompatActivity {




    double euroEx = 0.898136;
    double mexicanEx = 19.5010;
    double canadianEx = 1.35296;

    double initialVal;
    double convertedVal;
    String convertedVal_ = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        getSupportActionBar().setDisplayShowHomeEnabled(true);
        getSupportActionBar().setLogo(R.mipmap.ic_launcher);
        getSupportActionBar().setDisplayUseLogoEnabled(true);


        final EditText dollars = (EditText)findViewById(R.id.editText);
        final RadioButton EU = (RadioButton)findViewById(R.id.euros_);
        final RadioButton MEX = (RadioButton)findViewById(R.id.pesos_);
        final RadioButton CAN = (RadioButton)findViewById(R.id.canadian_);
        final TextView result = (TextView)findViewById(R.id.resultView);

        Button calc = (Button)findViewById(R.id.button2);

        calc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DecimalFormat usCurr = new DecimalFormat("$ ###,###.##");
                DecimalFormat euroCurr = new DecimalFormat("€ ###,###.##");
                DecimalFormat pesoCurr = new DecimalFormat("₱ ###,###.##");
                DecimalFormat canadianCurr = new DecimalFormat("CAD $###,###.##");



                if ((dollars.getText().toString()).matches("")) {
                    Toast.makeText(MainActivity.this, "Please enter an amount!", Toast.LENGTH_LONG).show();
                    result.setText("No U.S. Dollar Amount Specified");
                } else {
                    initialVal = Double.parseDouble(dollars.getText().toString());
                    if (initialVal >= 100000.0){
                        Toast.makeText(MainActivity.this, "Cannot Exceed $100,000 !!", Toast.LENGTH_LONG).show();
                    } else {

                        if (EU.isChecked()){
                            convertedVal = initialVal * euroEx;
                            convertedVal_ = euroCurr.format(convertedVal) + " Euros";
                        }

                        if (MEX.isChecked()){
                            convertedVal = initialVal * mexicanEx;
                            convertedVal_ = pesoCurr.format(convertedVal) + " Pesos";

                        }

                        if (CAN.isChecked()){
                            convertedVal = initialVal * canadianEx;
                            convertedVal_ = canadianCurr.format(convertedVal) + " Canadain Dollars";
                        }
                        if (EU.isChecked() != true && MEX.isChecked() != true && CAN.isChecked() != true){
                            Toast.makeText(MainActivity.this, "Please Pick a Conversion Currency !!", Toast.LENGTH_LONG).show();
                            result.setText("No Selection Made!");
                        } else {
                            result.setText(usCurr.format(initialVal) + " U.S dollars is " + convertedVal_);
                        }

                    }
                }

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
