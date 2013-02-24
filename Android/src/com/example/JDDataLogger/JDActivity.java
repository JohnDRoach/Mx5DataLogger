package com.example.JDDataLogger;

import android.app.Activity;
import android.widget.Toast;

/**
 * Created with IntelliJ IDEA.
 * User: john
 * Date: 2/23/13
 * Time: 11:51 PM
 * To change this template use File | Settings | File Templates.
 */
public class JDActivity extends Activity {

    protected void BrownToast(String message) {
        Toast.makeText(getApplicationContext(), message, Toast.LENGTH_SHORT).show();
    }

    protected <T> T Get(int id) {
        return (T) findViewById(id);
    }
}
