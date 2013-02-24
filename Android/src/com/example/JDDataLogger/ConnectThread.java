package com.example.JDDataLogger;

/**
 * Created with IntelliJ IDEA.
 * User: john
 * Date: 2/23/13
 * Time: 8:38 PM
 * To change this template use File | Settings | File Templates.
 */

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

import java.io.IOException;
import java.util.UUID;

/**
 * This thread runs while attempting to make an outgoing connection
 * with a device. It runs straight through; the connection either
 * succeeds or fails.
 */
public class ConnectThread extends Thread {
    private static final UUID SerialPortServiceClass_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    private BluetoothSocket mmSocket;
    private BluetoothAdapter mAdapter;
    private ConnectionListener listener;

    public ConnectThread(BluetoothAdapter adapter, BluetoothDevice device, ConnectionListener listener) {
        mAdapter = adapter;
        this.listener = listener;
        BluetoothSocket tmp = null;

        // Get a BluetoothSocket for a connection with the
        // given BluetoothDevice
        try {
            tmp = device.createRfcommSocketToServiceRecord(SerialPortServiceClass_UUID);
        } catch (Exception e) {
            listener.ConnectionFailure("Create Error - " + e.getMessage());
        }

        mmSocket = tmp;
    }

    public void run() {
        setName("ConnectThread");

        // Always cancel discovery because it will slow down a connection
//        if (mAdapter.isDiscovering()) {
//            mAdapter.cancelDiscovery();
//        }

        // Make a connection to the BluetoothSocket
        try {
            // This is a blocking call and will only return on a
            // successful connection or an exception
            mmSocket.connect();
        } catch (IOException e) {
            listener.ConnectionFailure("Connect Error - " + e.getMessage());
            // Close the socket
            try {
                mmSocket.close();
            } catch (IOException e2) {
                listener.ConnectionFailure("Close Error - " + e2.getMessage());
            }
            // Start the service over to restart listening mode
            //BluetoothSerialService.this.start();
            return;
        }

        listener.ConnectionSuccess(mmSocket);
    }

    public void cancel() {
        try {
            mmSocket.close();
        } catch (IOException e) {
        }
    }
}
