package application;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

public class SampleController {

    @FXML
    private Button btn_2;

    @FXML
    private Button btn_1;

    @FXML
    private Button btn_3;

    @FXML
    void showInst() {
    	
    }

    @FXML
    void showDept() {
    	try {
			AnchorPane root = (AnchorPane)FXMLLoader.load(getClass().getResource("sample2.fxml"));
			Stage stg = new Stage();
			Scene scene = new Scene(root,600,800);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			stg.setScene(scene);
			stg.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
    }

    @FXML
    void showExit() {
    	Platform.exit();
    	System.exit(0);
    }

}
