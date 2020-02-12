package application;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class sample2Controller {
	
	
    @FXML
    private Button btn_2;

    @FXML
    private Button btn_1;

    @FXML
    private TextField txt_1;

    @FXML
    private TextField txt_2;

    @FXML
    private Button btn_4;

    @FXML
    private Button btn_3;

    @FXML
    private TextField txt_3;

    @FXML
    void insertRow() {
    	try {
    		Connection conn = dbConnect();
    		String s1 = txt_1.getText().toString();
    		String s2 = txt_2.getText().toString();
    		int b = Integer.parseInt(txt_3.getText());
    		PreparedStatement ps = conn.prepareStatement("insert into department values('"+s1+"', '"+s2+"',"+ b +") ");
    		ps.execute();
    		System.out.println("Inserted ");
    	}catch(Exception e) {
    		System.out.println(e);
    	}
    }

    @FXML
    void deleteRow() {
    	try {
    		Connection conn = dbConnect();
    		String s1 = txt_1.getText().toString();
    		String s2 = txt_2.getText().toString();
    		int b = Integer.parseInt(txt_3.getText());
    		PreparedStatement ps = conn.prepareStatement("delete from department where dept_name='"+s1+"' ");
    		ps.execute();
    		System.out.println("Deleted");
    	}catch(Exception e) {
    		System.out.println(e);
    	}
    }

    @FXML
    void updateDept() {

    }

    @FXML
    void clearText() {
    	txt_1.clear();
    	txt_2.clear();
    	txt_3.clear();
    }
    static Connection dbConnect()
    {
    	Connection con = null;
    	try {
    		Class.forName("oracle.jdbc.driver.OracleDriver");	//ip address of server 
    		con = DriverManager.getConnection("jdbc:oracle:thin:@172.16.58.32:1521:cseorcl","A46","A46");
    	}catch(Exception e) {
    		System.out.println(e);
    	}
    	return con;
    }

}
