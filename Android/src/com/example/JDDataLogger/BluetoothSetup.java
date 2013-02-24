package com.example.JDDataLogger;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.*;

import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

/**
 * Created with IntelliJ IDEA.
 * User: john
 * Date: 2/23/13
 * Time: 10:58 PM
 * To change this template use File | Settings | File Templates.
 */
public class BluetoothSetup extends JDActivity implements AdapterView.OnItemClickListener {
    BluetoothAdapter adapter;
    ListView pairedDevicesView;
    Set<BluetoothDevice> pairedDevices;

    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.bluetoothsetup);

        pairedDevicesView = this.Get(R.id.PairedDevicesList);
        pairedDevicesView.setOnItemClickListener(this);

        adapter = BluetoothAdapter.getDefaultAdapter();

        if (adapter.isEnabled()) {
            findPairedDevicesAndDisplay();
        } else {
            enableBluetooth();
        }
    }

    private void enableBluetooth() {
        Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
        startActivityForResult(enableBtIntent, 123);
    }

    private void findPairedDevicesAndDisplay() {
        pairedDevices = adapter.getBondedDevices();
        // If there are paired devices

        if (pairedDevices.size() > 0) {
            List<String> deviceNames = new LinkedList<String>();
            // Loop through paired devices
            for (BluetoothDevice device : pairedDevices) {
                // Add the name and address to an array adapter to show in a ListView
                deviceNames.add(device.getName());
            }

            ArrayAdapter adapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, deviceNames);
            pairedDevicesView.setAdapter(adapter);
        }
    }

    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == 123 && resultCode == RESULT_OK) {
            findPairedDevicesAndDisplay();
        } else {
            finish();
        }
    }

    @Override
    public void onItemClick(AdapterView<?> adapterView, View view, int position, long identifier) {
        String deviceName = pairedDevicesView.getItemAtPosition(position).toString();

        for(BluetoothDevice device : pairedDevices) {
            if(device.getName().equals(deviceName)) {
                Intent intent = new Intent();
                intent.putExtra("SelectedBluetoothDevice", device);
                setResult(RESULT_OK, intent);
                finish();
            }
        }
    }
}
