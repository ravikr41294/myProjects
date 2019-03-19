package com.socket.multiclient;
/*Student Server!!
 *Class that represents server which can run multiple clients
 * running on multiple separate threads
*/

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import javax.swing.JDialog;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class StudentServer {

	public static Integer PORT_NUM;

	@SuppressWarnings("resource")
	public static void main(String args[]) {

		String message = "Hi Welcome to our Student Records Server.\n"
				+ "Give Username and Password and We will return Your Marks\n" + "Do you want to start the server?";

		//......Creates Dialog to confirm to run the server.....//
		
		JDialog.setDefaultLookAndFeelDecorated(true);
		
		int response = JOptionPane.showConfirmDialog(null, message, "!!Confirm!!", JOptionPane.YES_NO_OPTION,
				JOptionPane.QUESTION_MESSAGE);

		if (response == JOptionPane.NO_OPTION) {
			System.out.println("Closing Program....Server Not Started by User");
			System.exit(0);
		}

		if (response == JOptionPane.CLOSED_OPTION) {
			System.out.println("Server Terminated");
			System.exit(0);
		}
		if (response == JOptionPane.YES_OPTION) {
			System.out.println("Starting the Server");
		}

		Socket s = null;
		ServerSocket ss2 = null;
		System.out.println("Server Listening......");
		try {
			ss2 = new ServerSocket(8888); // can also use static final PORT_NUM , when defined

		} catch (IOException e) {
			e.printStackTrace();
			System.out.println("Server Error");

		}

		while (true) {
			try {
				s = ss2.accept();
				System.out.println("Connection Established");
				ServerThread st = new ServerThread(s);
				st.start();

			}

			catch (Exception e) {
				e.printStackTrace();
				System.out.println("Connection Error");

			}
		}

	}
//Method that computes and sends Marks to client....!!!!
	public String getMarksFromServer(String name, String pass, int option) {

		File file = new File("src\\data");
		Double finalMarks = null;
		List<Student> studentsList = new ArrayList<>();

		Scanner sc = null;
		try {
			sc = new Scanner(file);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		String str;
		while (sc.hasNextLine()) {

			str = sc.nextLine();
			String[] studentdetail = str.split(",");
			Student student = new Student(studentdetail[0], studentdetail[1], Double.parseDouble(studentdetail[2]));
			studentsList.add(student);

		}

		sc.close();

		if (option == JOptionPane.OK_OPTION) {

			String emptyErrmsg = "Empty Submission...Please Enter Some Data";
			if (name.isEmpty() || pass.isEmpty()) {
				JDialog.setDefaultLookAndFeelDecorated(true);
				JOptionPane.showMessageDialog(null, emptyErrmsg, "Login Failed", JOptionPane.INFORMATION_MESSAGE);
				return "QUIT";
			}

			boolean namecheck = false;
			boolean passcheck = false;
			int index = 0;
			for (int i=0;i<studentsList.size();i++) {

				boolean nameValidtion = name.equals(studentsList.get(i).getUsername());
				boolean passValidtion = pass.equals(studentsList.get(i).getPassword());

				if ((nameValidtion && passValidtion)) {

					namecheck = true;
					passcheck = true;
					index=i;
					break;

				} else {
					namecheck = false;
					passcheck = false;
				}

			}

			System.out.println("Final Check with Index:: " + index);

			if (!(namecheck == true && passcheck == true)) {

				JDialog.setDefaultLookAndFeelDecorated(true);
				JOptionPane.showMessageDialog(null, "Invalid Username/Password!!!", "Login Failed",
						JOptionPane.INFORMATION_MESSAGE);
				System.out.println("Invalid Username or Password, Run Another Instance ");
				return "QUIT" + "" + "";
			} else {

				finalMarks = studentsList.get(index).getJavaMarks();
				System.out.println("Marks for the " + finalMarks);
				return String.valueOf(finalMarks);

			}

		} else {
			System.out.println("Login Canceled");
			return "QUIT";
		}

	}

}
