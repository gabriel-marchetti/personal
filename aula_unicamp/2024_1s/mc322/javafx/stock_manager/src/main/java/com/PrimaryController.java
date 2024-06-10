package com;

import modules.Product;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;

public class PrimaryController implements Initializable {

    @FXML
    private ComboBox<Integer> cbCervejas;
    @FXML
    private ComboBox<Integer> cbSanduiches;
    @FXML
    private ComboBox<Integer> cbAzeitonas;
    @FXML
    private ComboBox<Integer> cbCopos;
    @FXML
    private Label numSanduiches;
    @FXML
    private Label numCopos;
    @FXML
    private Label numAzeitonas;
    @FXML
    private Label numCervejas;


    private List<Integer> numProdutos = new ArrayList<>();
    private ObservableList<Integer> obsQtdProdutos;

    private Product sanduiches = new Product("Sanduiches");
    private Product cervejas = new Product("Cervejas");
    private Product azeitonas = new Product("Azeitonas");
    private Product copos = new Product("Copos");

    @FXML
    private void realizaCompra(){
        Integer sanduicheQtd = convertNullToZero(cbSanduiches.getValue()),
                cervejasQtd = convertNullToZero(cbCervejas.getValue()),
                azeitonasQtd = convertNullToZero(cbAzeitonas.getValue()),
                coposQtd = convertNullToZero(cbCopos.getValue());

        sanduiches.increaseQuantity(sanduicheQtd);
        cervejas.increaseQuantity(cervejasQtd);
        azeitonas.increaseQuantity(azeitonasQtd);
        copos.increaseQuantity(coposQtd);

        atualizaLabels();
        resetCb();
    }

    private Integer convertNullToZero( Integer verify ){
        if( verify == null )
            return 0;
        return verify;
    }
    
    @FXML
    private void limpaEstoque(){
        sanduiches.setNumProducts(0);
        azeitonas.setNumProducts(0);
        cervejas.setNumProducts(0);
        copos.setNumProducts(0);

        atualizaLabels();
    }

    @Override
    public void initialize(URL url, ResourceBundle rb){
        carregarCategorias();
    }

    public void carregarCategorias(){
        for(int i = 1; i <= 5; ++i){
            numProdutos.add(i);
        }
        obsQtdProdutos = FXCollections.observableArrayList(numProdutos);

        cbAzeitonas.setItems(obsQtdProdutos);
        cbCervejas.setItems(obsQtdProdutos);
        cbCopos.setItems(obsQtdProdutos);
        cbSanduiches.setItems(obsQtdProdutos);
    }

    private void atualizaLabels(){
        numSanduiches.setText(sanduiches.getNumProducts().toString());
        numAzeitonas.setText(azeitonas.getNumProducts().toString());
        numCopos.setText(copos.getNumProducts().toString());
        numCervejas.setText(cervejas.getNumProducts().toString());
    }

    private void resetCb(){
        cbAzeitonas.setValue(null);
        cbCervejas.setValue(null);
        cbCopos.setValue(null);
        cbSanduiches.setValue(null);
    }
}
