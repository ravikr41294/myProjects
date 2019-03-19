package com.socket.multiclient;

/*
 * Student Client Class that calls up the socket opened by server.
 * It sends Username and Password to GUI created.
 * The server in turn returns the marks of the student.
 * .....
 * .....
 * .....
 * .....
 * We can run Multiple Clients by running this class multiple times.
 * ----
 * ----
 * ----
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class StudentClient {

	//Driver Class to run the Client instances multiple time
	public static void main(String args[]) throws IOException {

		InetAddress address = InetAddress.getLocalHost();//gets the IP address
		Socket s1 = null;
		String line = null;
		BufferedReader br = null;
		BufferedReader is = null;
		PrintWriter os = null;

		try {
			s1 = new Socket(address, 8888);
			br = new BufferedReader(new InputStreamReader(System.in));
			is = new BufferedReader(new InputStreamReader(s1.getInputStream()));
			os = new PrintWriter(s1.getOutputStream());
		} catch (IOException e) {
			e.printStackTrace();
			System.err.print("IO Exception");
		}

		System.out.println("Client Address : " + address);
		List<String> UIElements = createGUI();//stores UIElements
		StudentServer sc = new StudentServer();

		String response = null;
		try {
			//calls to server for marks
			line = sc.getMarksFromServer(UIElements.get(0), UIElements.get(1), Integer.parseInt(UIElements.get(2)));
			System.out.println(line);
			while (line.compareTo("QUIT") != 0) {
				os.println(line);
				os.flush();
				response = is.readLine();
				
				String msg = "Your Marks in Java is:\t" + response + " out of 100";
				JDialog.setDefaultLookAndFeelDecorated(true);
				JFrame parent = new JFrame();
				JOptionPane.showMessageDialog(parent, msg);
				
				System.out.println("Server Response to Client : " + response);
				System.out.println("Exiting this Client Thread");
				System.exit(0);				
				//Exits the client call once marks is obtained.
			}

		} catch (IOException e) {
			e.printStackTrace();
			System.out.println("Socket Read Error");
		}

		finally {
//Closing all inputstream,ouputstream, buffered reader and socket instances.....
			is.close();
			os.close();
			br.close();
			s1.close();
			System.out.println("Connection Closed Completely");
		}

	}

	private static List<String> createGUI() {
		// TODO Auto-generated method stub

		// GUI To enter Username and Password
		List<String> UIElements = new ArrayList<>();
		JTextField username = new JTextField();
		JTextField password = new JPasswordField();
		Object[] message = { "Username:", username, "Password:", password };

		int option = JOptionPane.showConfirmDialog(null, message, "Student Login", JOptionPane.OK_CANCEL_OPTION);

		UIElements.add(username.getText());
		UIElements.add(password.getText());
		UIElements.add(String.valueOf(option));

		return UIElements;

	}
}
