package com;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class PrimaryController {

    @FXML
    private Label labelMessage;
    @FXML
    private Label labelTypeName;

    @FXML
    private TextField txtNome;

    @FXML
    private Button buttonHelloWorld_button;

    @FXML
    private void buttonHelloWorld_action( ActionEvent event ){
        System.out.println("You clicked me!");
        String message = "Olá: " + txtNome.getText();
        message = message.toUpperCase();

        labelMessage.setText(message);
    } 
    
}
