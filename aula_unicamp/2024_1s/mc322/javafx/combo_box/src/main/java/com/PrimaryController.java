package com;

import model.Categoria;
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

public class PrimaryController implements Initializable{

    @FXML
    private ComboBox<Categoria> cbCategorias;
    private List<Categoria> categorias = new ArrayList<>();
    private ObservableList<Categoria> obsCategoria;

    @Override
    public void initialize( URL url, ResourceBundle rb){
        carregarCategorias();
    }

    @FXML
    private void pegarSelecionado(){
        Categoria categoria = cbCategorias.getSelectionModel().getSelectedItem();

        System.out.println("ID: " + categoria.getId() + " --- " + "NOME: " + categoria.getNome());
    }

    public void carregarCategorias(  ){
        Categoria categoria1 = new Categoria(1, "Bebidas");
        Categoria categoria2 = new Categoria(2, "Comidas");
        Categoria categoria3 = new Categoria(3, "Cervejas");
        Categoria categoria4 = new Categoria(4, "Frutas");
    
        categorias.add(categoria1);
        categorias.add(categoria2);
        categorias.add(categoria3);
        categorias.add(categoria4);

        // Transformando em Observable List.
        obsCategoria = FXCollections.observableArrayList(categorias);

        cbCategorias.setItems(obsCategoria);
    }
}
