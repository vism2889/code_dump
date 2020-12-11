package com.example.piggybank;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

import java.text.DecimalFormat;

public class ActionScreen extends AppCompatActivity {
    double numQuarters;
    double numDimes;
    double numNickles;
    double numPennies;
    String savingOption;
    double totalCash;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_action_screen);

        final EditText quart = (EditText)findViewById(R.id.editText);
        final EditText dime = (EditText)findViewById(R.id.editText2);
        final EditText nick = (EditText)findViewById(R.id.editText3);
        final EditText penn = (EditText)findViewById(R.id.editText4);
        final Spinner group = (Spinner)findViewById(R.id.spinner);

        Button calc = (Button)findViewById(R.id.button2);
        calc.setOnClickListener(new View.OnClickListener() {
            final TextView result = ((TextView)findViewById(R.id.textView2));
            @Override
            public void onClick(View v) {
                numQuarters = Double.parseDouble(quart.getText().toString());
                numDimes = Double.parseDouble(dime.getText().toString());
                numNickles = Double.parseDouble(nick.getText().toString());
                numPennies = Double.parseDouble(penn.getText().toString());
                DecimalFormat currency = new DecimalFormat("$###,###.##");
                savingOption = group.getSelectedItem().toString();
                totalCash = ((numQuarters * 25.0)+(numDimes * 10.0)+(numNickles * 5.0)+(numPennies))/100.0;
                result.setText("You are "+ savingOption + " " + currency.format(totalCash));
            }
        });

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


    }

}
