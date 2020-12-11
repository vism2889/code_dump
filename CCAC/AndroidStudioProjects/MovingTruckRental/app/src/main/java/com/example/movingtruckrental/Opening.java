package com.example.movingtruckrental;

import android.content.Intent;
import android.os.Bundle;
import android.app.Activity;

import java.util.Timer;
import java.util.TimerTask;

public class Opening extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_opening);

        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                finish();
                startActivity(new Intent(Opening.this, MainActivity.class));

            }
        };
        Timer opening = new Timer();
        opening.schedule(task, 3000);
    }

}
