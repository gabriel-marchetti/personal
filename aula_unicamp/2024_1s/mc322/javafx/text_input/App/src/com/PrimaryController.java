package com;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class PrimaryController {
    @FXML
    private Label messageLabel;

    @FXML
    private TextField enterName;

    @FXML
    private Button executeButton;

    @FXML
    private void executeAction( ActionEvent event ){
        String message = "Olá: " + enterName.getText();
        message = message.toUpperCase();

        messageLabel.setText(message);        
    }

}
