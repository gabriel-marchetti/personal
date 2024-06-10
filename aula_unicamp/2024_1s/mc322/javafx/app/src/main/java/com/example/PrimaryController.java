package com.example;

import java.io.IOException;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class PrimaryController {

    @FXML
    private Label typeMessage;

    @FXML
    private TextField inputName;

    @FXML
    private Button messageButton;

    @FXML
    private void changeMessage( ActionEvent event ){
        String message = new String();
        message += "Olá: ";
        message += inputName.getText();

        typeMessage.setText(message);
    }
}
