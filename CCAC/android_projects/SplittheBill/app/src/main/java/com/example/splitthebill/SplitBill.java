package com.example.splitthebill;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.text.DecimalFormat;

public class SplitBill extends AppCompatActivity {
    double totalCost;
    double gratuity;
    double numPeople;
    double perPerson;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_split_bill);
        final EditText people = (EditText)findViewById(R.id.numPeeps);
        final EditText cost = (EditText)findViewById(R.id.Cost);
        Button split = (Button)findViewById(R.id.buttonSplits);
        split.setOnClickListener(new View.OnClickListener() {
            final TextView result = ((TextView)findViewById(R.id.resultText));
            @Override
            public void onClick(View v) {
                numPeople = Double.parseDouble(people.getText().toString());
                totalCost = Double.parseDouble(cost.getText().toString());
                gratuity =  (totalCost * 0.18);
                totalCost = gratuity + totalCost;
                perPerson = totalCost/numPeople;
                DecimalFormat currency = new DecimalFormat("$###,###.##");
                result.setText(currency.format(gratuity) + " Tip,  " + currency.format(perPerson) + " Per Person");
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
