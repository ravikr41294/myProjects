package com.socket.multiclient;

/*
 * Student Class--- Used to store student's data
 * It Works as a Storage for student record
 * The data is stored from a local file.....data.txt 
*/
public class Student {

	String username;
	String password;
	Double javaMarks;
	
	
	
	public Student() {
		super();
		// TODO Auto-generated constructor stub
	}



	public String getUsername() {
		return username;
	}



	public void setUsername(String username) {
		this.username = username;
	}



	public String getPassword() {
		return password;
	}



	public void setPassword(String password) {
		this.password = password;
	}



	public Double getJavaMarks() {
		return javaMarks;
	}



	public void setJavaMarks(Double javaMarks) {
		this.javaMarks = javaMarks;
	}



	public Student(String username, String password, Double javaMarks) {
		super();
		this.username = username;
		this.password = password;
		this.javaMarks = javaMarks;
	}



	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "The Student Details are::\n"+"Name = "+getUsername()+"\nPassword = "
				+getPassword()+"\nMarks = "+getJavaMarks()+"\n"
				;
	}


	

}